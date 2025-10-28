import os
import re
from pydantic import BaseModel, Field, field_validator
from fastapi import FastAPI, HTTPException, Response
from fastapi.responses import FileResponse # Solo para devolver el html

os.system("touch miguel_db.txt")

def obtener_ultimo_id() -> int:
    ultimo_id = 0
    try:
        with open("miguel_db.txt", "r") as archivo:
            for linea in archivo.readlines():
                linea = linea.strip()
                if not linea:
                    continue
                partes = linea.split(",")
                nuevo_id = int(partes[0].split(":")[1])
                ultimo_id = max(ultimo_id, nuevo_id)
    except IOError:
        raise HTTPException(status_code=500, detail="Error al leer el archivo de datos.")
    return ultimo_id
                

class ItemCreation(BaseModel):
    id: int = Field(default_factory= lambda: obtener_ultimo_id() + 1)
    name: str = Field(..., min_length= 3)
    price: float = Field(..., ge=10_000.0)
    stock: int = 0
    
    @field_validator("name")
    def validar_nombre(cls, v: str) -> str:
        if not re.match(r"^[a-zA-Z\s]+$", v):
            raise ValueError("El nombre solo puede contener letras y espacios.")
        return v
        
    
class ItemUpdateRequest(BaseModel):
    name: str | None = Field(None, min_length= 3)
    price: float | None = Field(None, ge=10_000.0)
    stock: int | None = None

app = FastAPI()

@app.get("/")
def main_page():
    file_path = os.path.join(os.path.dirname(__file__), "index.html")
    if not os.path.exists(file_path):
        raise HTTPException(status_code=404, detail="Archivo index.html no encontrado.")
    return FileResponse(file_path, media_type="text/html")
    # Cambiar todo por el return comentado.
    # return "API para Storage de Camisetas. By: Miguel' Store!"
    
@app.get("/items/")
def items_list() -> dict:
    inventario = {
        "quantity": 0,
        "items": list()
    }
    try:
        with open("miguel_db.txt", "r") as archivo:
            for linea in archivo:
                linea = linea.strip()
                if not linea:
                    continue
                partes = linea.split(",")
                objeto = {tipo: valor for tipo, valor in (p.split(":") for p in partes)}
                inventario["items"].append(objeto)
    except IOError:
        raise HTTPException(status_code=500, detail="Error al leer el archivo de datos.")
    inventario["quantity"] = len(inventario["items"])
    return inventario

@app.post("/items/", status_code= 201)
def create_item(item: ItemCreation):
    try:
        with open("miguel_db.txt", "a") as archivo:
            archivo.write(f"id:{item.id},name:{item.name},price:{item.price},stock:{item.stock}\n")
    except IOError:
        raise HTTPException(status_code=500, detail="Error al escribir en el archivo de datos.")

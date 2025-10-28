import os

file_name = "prueba.py"
# file_name = input("Ingresa el nombre del archivo con formato: ")

os.system(f"touch {file_name}")
py_file = open(file_name, "r+")

if not len(py_file.read()):
    print("Archivo vacio.")
    
print("----- TU CODIGO -----\n")

linea = input()
codigo_lineas = []
while linea != "exit":
    codigo_lineas.append(linea.__add__('\n'))
    linea = input()
    
if py_file.writable() and len(codigo_lineas):
    py_file.writelines(codigo_lineas)
else:
    print("No se pudo ingresar texto.")

# txt_file.write("Hola mundo!\nComo has estado?\nEspero que bien!\n") # <- Para imprimir dentro del archivo.
# print(txt_file.read()) # <- Para leer todo el archivo, o solo ciertos caracteres.
# print(txt_file.readlines(100)) <- line lee solo una linea sin importar cuantos caracteres decidamos leer, y lines lee todas las que coja los caracteres.
# print(txt_file.writable()) <- Informa si el archivo es modificable (true) o de solo lectura (false)



if not py_file.closed:
    py_file.close()
else:
    print("El archivo fue cerrado antes de final de programa.")
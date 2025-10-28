camisetas = []
with open("camisetas_db.txt", "r") as archivo:
    for linea in archivo:
        linea = linea.strip()
        partes = linea.split(",")
        camiseta = {tipo: valor for tipo, valor in (p.split(":") for p in partes)}
        camisetas.append(camiseta)
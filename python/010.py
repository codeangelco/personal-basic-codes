file = open("camisetas_db.txt", "r")

for linea in file.readlines():
    linea = linea.strip()
    if not linea:
        continue
    parts = [p.strip() for p in linea.split(',') if p.strip()]
    data = {}
    for part in parts:
        if ':' in part:
            k, v = part.split(':', 1)
            data[k.strip()] = v.strip()

    nombre = data.get('nombre', '')
    precio = None
    cantidad = None
    try:
        if 'precio' in data:
            precio = float(data['precio'])
    except ValueError:
        precio = None
    try:
        if 'cantidad' in data:
            cantidad = int(data['cantidad'])
    except ValueError:
        cantidad = None
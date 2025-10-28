import requests

json = requests.get(url="http://127.0.0.1:8000/items/")
json = json.json()

print(type(json))
print(json)
for producto in json:
    llaves = producto.keys()
    print("Otro objeto --------")
    for key in llaves:
        print(f"En {key} es -> {producto[key]}")
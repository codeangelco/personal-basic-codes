a = 1
b = 2
b = "2"

try:
    print(a+b)
except Exception as nun:
    print("Tipo:",type(nun).__name__)
    print("Mensaje:",nun.args[0])
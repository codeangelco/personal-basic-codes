def suma(a, b):
    return a + b

def resta(a, b):
    return a - b

def multiplicacion(a, b):
    return a * b

def division(a, b):
    if b == 0:
        return "ERROR: El dividendo no puede ser 0."
    return a / b

def potencia(a, b):
    return a ** b

def menu():
    print("0. Salir")
    print("1. Sumar")
    print("2. Restar")
    print("3. Multiplicar")
    print("4. Dividir")
    print("5. Elevar")
    
while True:
    menu()
    opcion = int(input("Digite la opcion deseada: "))
    
    if opcion == 0:
        print("Saliendo... 👋")
        break
    
    a = float(input("Ingrese el primer numero: "))
    b = float(input("Ingrese el segundo numero: "))
    
    if opcion == 1:
        print("Resultado:",suma(a,b))
    elif opcion == 2:
        print("Resultado:",resta(a,b))
    elif opcion == 3:
        print("Resultado:",multiplicacion(a,b))
    elif opcion == 4:
        print("Resultado:",division(a,b))
    elif opcion == 5:
        print("Resultado:",potencia(a,b))
    else:
        print("Opcion incorrecta.")
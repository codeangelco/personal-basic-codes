class Persona:
    def __init__(self, name = "", age = 0):
        self.name = name
        self.age = age 
    def __str__(self):
        return f"Nombre: {self.name} | Edad: {self.age}"
        

persona_1 = Persona()
persona_2 = Persona("Juan",18)

print(persona_1)
print(persona_2)
        
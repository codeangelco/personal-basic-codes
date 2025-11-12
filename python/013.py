letras = set("SENDMOREMONEY") # Tiene las letras del criptaritmo, pero lo guarda como un conjunto .
# print(letras)

var_doms = {letra: set(range(10)) for letra in letras} # Crea un diccionario con las letras como claves y los dígitos del 0 al 9 como valores posibles.
# print(var_doms)



# Funciones de restricción para csps de criptaritmos.

def allDif(var_doms: dict[str, set[int]],/) -> None:
    
    """
    Elimina del dominio de cada variable los valores que ya han sido asignados a otras variables,
    siempre y cuando una variable tenga un único valor posible en su dominio.
    
    ---
    
    * var_doms:
        Diccionario que contendra cada variable/letra con los valores posibles (dominio).
    
    * return:
        No devuelve nada, solo modifica el diccionario de entrada.
    """
    
    for var in var_doms.keys():
        if len(var_doms[var]) == 1:
            for var2 in var_doms.keys():
                if var != var2:
                    var_doms[var2].discard(list(var_doms[var])[0])

def GTValue(var_doms: dict[str, set[int]], var: str, value: int) -> None:
    """
    Elimina dentro del dominio de una variable los valores menores o iguales a un valor dado.
    
    ---
    
    * var_doms:
        Diccionario que contendra cada variable/letra con los valores posibles (dominio).
    * var:
        Variable/letra cuyo dominio se va a modificar.
    * value:
        Valor entero que sirve de umbral para eliminar valores del dominio.
    * return:
        No devuelve nada, solo modifica el dominio de la variable dentro del diccionario de entrada.
    """
    conjunto = set(range(value + 1))
    var_doms[var] = var_doms[var].difference(conjunto)

def LTValue(var_doms: dict[str, set[int]], var: str, value: int) -> None:
    """
    Elimina dentro del dominio de una variable los valores mayores o iguales a un valor dado.
    
    ---
    
    * var_doms:
        Diccionario que contendra cada variable/letra con los valores posibles (dominio).
    * var:
        Variable/letra cuyo dominio se va a modificar.
    * value:
        Valor entero que sirve de umbral para eliminar valores del dominio.
    * return:
        No devuelve nada, solo modifica el dominio de la variable dentro del diccionario de entrada.
    """
    conjunto = set(range(value, 10))
    var_doms[var] = var_doms[var].difference(conjunto)
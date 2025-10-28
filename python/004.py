import itertools as it

letras = set("SENDMORY")
# print(letras)
digitos = set(range(10))
# print(digitos)

permutaciones = it.permutations(digitos, len(letras))

for x in permutaciones:
    letra_valor = dict(zip(letras, x))
    print(letra_valor)
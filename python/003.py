# Creación de un conjunto en Python

mi_conjunto = {1, 7, 3, 4, 5}
mi_otro_conjunto = {6, 7, 8, 9, 10}
print(mi_conjunto)
print(mi_otro_conjunto)
print(mi_otro_conjunto.difference(mi_conjunto))
print(mi_conjunto.union(mi_otro_conjunto))

x = next(iter(mi_conjunto.intersection(mi_otro_conjunto)))
print(mi_conjunto.__contains__(x) and mi_otro_conjunto.__contains__(x))
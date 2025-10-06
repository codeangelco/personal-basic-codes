def BinarySearch(lista, left, right, k):
    while left <= right:
        mid = (left + right) // 2
        if lista[mid] == k:
            return mid
        elif lista[mid] > k:
            right = mid - 1
        else:
            left = mid + 1
    return left * -1 - 1

lista = [1, 3, 4, 6]
numeros_a_buscar = [0, 1, 2, 3, 4, 5, 6, 7]

for i in numeros_a_buscar:
    print(f"Numero {i} en la posicion {BinarySearch(lista, 0, len(lista) - 1, i)}.")


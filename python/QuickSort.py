import random
# QuickSort

separador = "----------------------------------------"
for kk in range(100):
    def qs(array):
        if len(array) <= 1:
            return array
        else:
            pivot = array[0]
            menores = [x for x in array[1:] if x <= pivot]
            mayores = [x for x in array[1:] if x > pivot]
            return qs(menores) + [pivot] + qs(mayores)
        
    arr = [random.randint(-100, 100) for x in range(10)]
    print(arr)

    print(qs(arr))
    
    print(separador)
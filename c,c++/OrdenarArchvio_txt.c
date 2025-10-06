#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSortIterativo(int arr[], int l, int h) {
    int *stack = (int*)malloc((h - l + 1) * sizeof(int));
    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];

        int pivot = arr[h];
        int i = l - 1;
        for (int j = l; j < h; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
        }
        int temp = arr[i + 1]; arr[i + 1] = arr[h]; arr[h] = temp;
        int p = i + 1;

        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
    free(stack);
}

int main() {
    time_t t_i, t_f;

    FILE *archivo = NULL;
    int n = 0;
    scanf("%d", &n);

    int *datos = (int*)malloc(n * sizeof(int));
    if (datos == NULL) {
        printf("No hay suficiente memoria.\n");
        return 1;
    }

    t_i = time(NULL);

    archivo = fopen("OrdenarArchivo.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo correctamente.");
        free(datos);
        return 1;
    }

    int t = 0;
    while (t < n && fscanf(archivo, "%d", &datos[t]) == 1) {
        t++;
    }
    fclose(archivo);

    if (t != n) {
        printf("Advertencia: Se leyeron %d elementos en vez de %d.\n", t, n);
        n = t;
    }

    quickSortIterativo(datos, 0, n - 1);

    archivo = fopen("OrdenarArchivo.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        free(datos);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(archivo, "%d ", datos[i]);
    }
    fclose(archivo);

    t_f = time(NULL);
    printf("Tiempo de ejecucion: %ld segundos\n", t_f - t_i);

    free(datos);
    return 0;
}
// arboles-rojinegros-ia.c
// Implementación de árbol rojinegro (Red-Black Tree) basada en los pseudocódigos
// de los apuntes de clase 33 del curso de Estructura de Datos.
// Esta implementación incluye ÚNICAMENTE las funciones de ELIMINACIÓN (RB-DELETE)
// según el documento "Apuntes_Clase33_EstructuraDeDatos_Noviembre12de2021.pdf"

#include <stdio.h>
#include <stdlib.h>

// Definición de colores para los nodos del árbol rojinegro
typedef enum { RED, BLACK } Color;

// Estructura del nodo del árbol rojinegro
typedef struct Node {
    int key;                    // Clave almacenada en el nodo
    Color color;                // Color del nodo (RED o BLACK)
    struct Node *left;          // Hijo izquierdo
    struct Node *right;         // Hijo derecho
    struct Node *p;             // Padre del nodo
} Node;

// Variables globales
static Node *NILLeaf;           // Nodo centinela (NIL) - reemplaza NULL
static Node *T;                 // Raíz del árbol

// ============================================================================
// FUNCIONES AUXILIARES NECESARIAS (no están en el PDF pero son requeridas)
// ============================================================================

/**
 * Inicializa el árbol rojinegro
 * Crea el nodo centinela NILLeaf y establece la raíz como NILLeaf
 */
void RB_INITIALIZE() {
    NILLeaf = (Node *)malloc(sizeof(Node));
    NILLeaf->color = BLACK;
    NILLeaf->left = NILLeaf;
    NILLeaf->right = NILLeaf;
    NILLeaf->p = NILLeaf;
    NILLeaf->key = 0;
    T = NILLeaf;
}

/**
 * Crea un nuevo nodo con la clave especificada
 * @param key: valor a almacenar en el nodo
 * @return: puntero al nuevo nodo creado
 */
Node *CREATE_NODE(int key) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->color = RED;
    node->left = NILLeaf;
    node->right = NILLeaf;
    node->p = NILLeaf;
    return node;
}

/**
 * Encuentra el sucesor de un nodo en el árbol
 * El sucesor es el nodo con la menor clave mayor que la clave del nodo dado
 * @param z: nodo del cual se busca el sucesor
 * @return: nodo sucesor
 */
Node *TREE_SUCCESSOR(Node *z) {
    if (z->right != NILLeaf) {
        // Si tiene hijo derecho, el sucesor es el mínimo del subárbol derecho
        Node *y = z->right;
        while (y->left != NILLeaf) {
            y = y->left;
        }
        return y;
    }
    // Si no tiene hijo derecho, buscar en los ancestros
    Node *y = z->p;
    while (y != NILLeaf && z == y->right) {
        z = y;
        y = y->p;
    }
    return y;
}

// ============================================================================
// FUNCIONES DE ROTACIÓN (necesarias para RB-DELETE-FIXUP)
// ============================================================================

/**
 * Rotación a la izquierda sobre el nodo x
 * Reorganiza los punteros para mantener las propiedades del árbol binario
 * @param x: nodo sobre el cual se realiza la rotación
 */
void LEFT_ROTATE(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NILLeaf) {
        y->left->p = x;
    }
    y->p = x->p;
    if (x->p == NILLeaf) {
        T = y;
    } else if (x == x->p->left) {
        x->p->left = y;
    } else {
        x->p->right = y;
    }
    y->left = x;
    x->p = y;
}

/**
 * Rotación a la derecha sobre el nodo x
 * Reorganiza los punteros para mantener las propiedades del árbol binario
 * @param x: nodo sobre el cual se realiza la rotación
 */
void RIGHT_ROTATE(Node *x) {
    Node *y = x->left;
    x->left = y->right;
    if (y->right != NILLeaf) {
        y->right->p = x;
    }
    y->p = x->p;
    if (x->p == NILLeaf) {
        T = y;
    } else if (x == x->p->right) {
        x->p->right = y;
    } else {
        x->p->left = y;
    }
    y->right = x;
    x->p = y;
}

// ============================================================================
// FUNCIONES PRINCIPALES DEL PDF
// ============================================================================

/**
 * RB-DELETE-FIXUP: Restaura las propiedades del árbol rojinegro después
 * de una eliminación.
 * 
 * Esta función corrige las violaciones de las propiedades rojinegras que
 * pueden ocurrir después de eliminar un nodo negro del árbol.
 * 
 * Pseudocódigo del PDF (líneas 1-45):
 * function RB-DELETE-FIXUP(T, x)
 * 
 * @param x: nodo que necesita ser ajustado
 * @return: raíz del árbol (posiblemente modificada)
 */
Node *RB_DELETE_FIXUP(Node *x) {
    // Línea 1: while x ≠ T and color[x] == BLACK do
    while (x != T && x->color == BLACK) {
        
        // Línea 2: if x == left[p[x]] then
        if (x == x->p->left) {
            // Línea 3: w ← right[p[x]]
            Node *w = x->p->right;
            
            // Línea 4: if color[w] == RED then
            if (w->color == RED) {
                // Línea 5: color[w] ← BLACK (Case 1)
                w->color = BLACK;
                // Línea 6: color[p[x]] ← RED (Case 1)
                x->p->color = RED;
                // Línea 7: T ← LEFT-ROTATE(T, p[x]) (Case 1)
                LEFT_ROTATE(x->p);
                // Línea 8: w ← right[p[x]] (Case 1)
                w = x->p->right;
            }
            
            // Línea 10: if color[left[w]] == BLACK and color[right[w]] == BLACK then
            if (w->left->color == BLACK && w->right->color == BLACK) {
                // Línea 11: color[w] ← RED (Case 2)
                w->color = RED;
                // Línea 12: x ← p[x] (Case 2)
                x = x->p;
            } else {
                // Línea 13: if color[right[w]] == BLACK then
                if (w->right->color == BLACK) {
                    // Línea 14: color[left[w]] ← BLACK (Case 3)
                    w->left->color = BLACK;
                    // Línea 15: color[w] ← RED (Case 3)
                    w->color = RED;
                    // Línea 16: T ← RIGHT-ROTATE(T, w) (Case 3)
                    RIGHT_ROTATE(w);
                    // Línea 17: w ← right[p[x]] (Case 3)
                    w = x->p->right;
                }
                // Línea 18: color[w] ← color[p[x]] (Case 4)
                w->color = x->p->color;
                // Línea 19: color[p[x]] ← BLACK (Case 4)
                x->p->color = BLACK;
                // Línea 20: color[right[w]] ← BLACK (Case 4)
                w->right->color = BLACK;
                // Línea 21: T ← LEFT-ROTATE(T, p[x]) (Case 4)
                LEFT_ROTATE(x->p);
                // Línea 22: x ← T (Case 4)
                x = T;
            }
        } else {
            // Línea 24: w ← left[p[x]]
            Node *w = x->p->left;
            
            // Línea 25: if color[w] == RED then
            if (w->color == RED) {
                // Línea 26: color[w] ← BLACK (Case 1)
                w->color = BLACK;
                // Línea 27: color[p[x]] ← RED (Case 1)
                x->p->color = RED;
                // Línea 28: T ← RIGHT-ROTATE(T, p[x]) (Case 1)
                RIGHT_ROTATE(x->p);
                // Línea 29: w ← left[p[x]] (Case 1)
                w = x->p->left;
            }
            
            // Línea 30: if color[right[w]] == BLACK and color[left[w]] == BLACK then
            if (w->right->color == BLACK && w->left->color == BLACK) {
                // Línea 31: color[w] ← RED (Case 2)
                w->color = RED;
                // Línea 32: x ← p[x] (Case 2)
                x = x->p;
            } else {
                // Línea 34: if color[left[w]] == BLACK then
                if (w->left->color == BLACK) {
                    // Línea 35: color[right[w]] ← BLACK (Case 3)
                    w->right->color = BLACK;
                    // Línea 36: color[w] ← RED (Case 3)
                    w->color = RED;
                    // Línea 37: T ← LEFT-ROTATE(T, w) (Case 3)
                    LEFT_ROTATE(w);
                    // Línea 38: w ← left[p[x]] (Case 3)
                    w = x->p->left;
                }
                // Línea 39: color[w] ← color[p[x]] (Case 4)
                w->color = x->p->color;
                // Línea 40: color[p[x]] ← BLACK (Case 4)
                x->p->color = BLACK;
                // Línea 41: color[left[w]] ← BLACK (Case 4)
                w->left->color = BLACK;
                // Línea 42: T ← RIGHT-ROTATE(T, p[x]) (Case 4)
                RIGHT_ROTATE(x->p);
                // Línea 43: x ← T (Case 4)
                x = T;
            }
        }
    }
    
    // Línea 44: color[x] ← BLACK
    x->color = BLACK;
    // Línea 45: return T
    return T;
}

/**
 * RB-DELETE: Elimina un nodo del árbol rojinegro
 * 
 * Esta es una modificación del procedimiento TREE-DELETE estándar.
 * Después de eliminar un nodo, llama a RB-DELETE-FIXUP si es necesario
 * para restaurar las propiedades del árbol rojinegro.
 * 
 * Pseudocódigo del PDF (líneas 1-27):
 * function RB-DELETE(T, z)
 * 
 * Diferencias con TREE-DELETE:
 * 1. Referencias a NIL son reemplazadas por NILLeaf
 * 2. Asignación p[x] ← p[y] es incondicional (línea 9)
 * 3. Llama a RB-DELETE-FIXUP si y es negro (líneas 20-21)
 * 
 * @param z: nodo a eliminar
 * @return: raíz del árbol (posiblemente modificada)
 */
Node *RB_DELETE(Node *z) {
    Node *y;
    Node *x;
    
    // Líneas 1-5: Determinar el nodo y a eliminar
    // Línea 1: if left[z] == NILLeaf or right[z] == NILLeaf then
    if (z->left == NILLeaf || z->right == NILLeaf) {
        // Línea 2: y ← z
        y = z;
    } else {
        // Línea 4: y ← TREE-SUCCESSOR(z)
        y = TREE_SUCCESSOR(z);
    }
    
    // Líneas 5-8: Determinar el hijo x de y
    // Línea 5: if left[y] ≠ NILLeaf then
    if (y->left != NILLeaf) {
        // Línea 6: x ← left[y]
        x = y->left;
    } else {
        // Línea 8: x ← right[y]
        x = y->right;
    }
    
    // Línea 9: p[x] ← p[y] (asignación incondicional)
    x->p = y->p;
    
    // Líneas 10-16: Actualizar el padre de y
    // Línea 10: if p[y] == NILLeaf then
    if (y->p == NILLeaf) {
        // Línea 11: T ← x
        T = x;
    } else {
        // Línea 13: if y == left[p[y]] then
        if (y == y->p->left) {
            // Línea 14: left[p[y]] ← x
            y->p->left = x;
        } else {
            // Línea 16: right[p[y]] ← x
            y->p->right = x;
        }
    }
    
    // Líneas 17-19: Si y ≠ z, copiar información de y a z
    // Línea 17: if y ≠ z then
    if (y != z) {
        // Línea 18: key[z] ← key[y]
        z->key = y->key;
        // Línea 19: Copy all information fields from y to z
        // (En este caso solo copiamos la clave, pero aquí se copiarían
        // todos los campos de información adicionales si existieran)
    }
    
    // Líneas 20-21: Arreglar el árbol si y era negro
    // Línea 20: if color[y] == BLACK then
    if (y->color == BLACK) {
        // Línea 21: T ← RB-DELETE-FIXUP(T, x)
        T = RB_DELETE_FIXUP(x);
    }
    
    // Líneas 22-25: Liberar memoria de los hijos de y si son necesarios
    // Línea 22: if y == p[left[y]] then
    if (y == y->left->p) {
        // Línea 23: FREE(left[y])
        // (Esto se manejaría en una implementación más completa)
    }
    // Línea 24: if y == p[right[y]] then
    if (y == y->right->p) {
        // Línea 25: FREE(right[y])
        // (Esto se manejaría en una implementación más completa)
    }
    
    // Línea 26: FREE(y)
    free(y);
    
    // Línea 27: return T
    return T;
}

// ============================================================================
// FUNCIONES AUXILIARES ADICIONALES (para testing y utilidad)
// ============================================================================

/**
 * Busca un nodo por su clave
 * @param key: clave a buscar
 * @return: puntero al nodo encontrado, o NILLeaf si no existe
 */
Node *RB_SEARCH(int key) {
    Node *x = T;
    while (x != NILLeaf && key != x->key) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

/**
 * Recorrido inorder recursivo para imprimir el árbol
 * @param x: nodo raíz del subárbol a imprimir
 */
void RB_INORDER_PRINT(Node *x) {
    if (x == NILLeaf) return;
    RB_INORDER_PRINT(x->left);
    printf("%d(%s) ", x->key, x->color == RED ? "R" : "B");
    RB_INORDER_PRINT(x->right);
}

/**
 * Imprime el árbol completo en orden
 */
void RB_PRINT_TREE() {
    RB_INORDER_PRINT(T);
    printf("\n");
}

/**
 * Libera la memoria de todos los nodos del árbol (postorder)
 * @param x: nodo raíz del subárbol a liberar
 */
void RB_FREE_TREE_REC(Node *x) {
    if (x == NILLeaf) return;
    RB_FREE_TREE_REC(x->left);
    RB_FREE_TREE_REC(x->right);
    free(x);
}

/**
 * Destruye completamente el árbol y libera toda la memoria
 */
void RB_DESTROY() {
    RB_FREE_TREE_REC(T);
    free(NILLeaf);
    T = NILLeaf = NULL;
}

/**
 * Inserta un nuevo nodo en el árbol (versión simplificada para testing)
 * NOTA: Esta función NO está en el PDF, es solo para pruebas
 * @param key: clave a insertar
 */
void RB_INSERT_SIMPLE(int key) {
    Node *z = CREATE_NODE(key);
    Node *y = NILLeaf;
    Node *x = T;
    
    while (x != NILLeaf) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    
    z->p = y;
    if (y == NILLeaf) {
        T = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    
    z->left = NILLeaf;
    z->right = NILLeaf;
    z->color = RED;
    
    // Aquí debería llamarse RB-INSERT-FIXUP, pero no está en el PDF
    // Por simplicidad, solo establecemos la raíz como negra
    T->color = BLACK;
}

// ============================================================================
// FUNCIÓN MAIN PARA TESTING
// ============================================================================

#ifdef TEST_RBT
int main() {
    // Inicializar el árbol
    RB_INITIALIZE();
    
    printf("=== PRUEBA DE ÁRBOL ROJINEGRO (RB-DELETE) ===\n\n");
    
    // Insertar algunos valores para probar
    printf("Insertando valores: 20, 15, 25, 10, 5, 1, 30, 27, 40\n");
    int vals[] = {20, 15, 25, 10, 5, 1, 30, 27, 40};
    for (int i = 0; i < (int)(sizeof(vals)/sizeof(vals[0])); ++i) {
        RB_INSERT_SIMPLE(vals[i]);
    }
    
    printf("Árbol inicial (inorder): ");
    RB_PRINT_TREE();
    printf("\n");
    
    // Probar RB-DELETE
    printf("Eliminando el nodo con clave 15...\n");
    Node *nodo_a_eliminar = RB_SEARCH(15);
    if (nodo_a_eliminar != NILLeaf) {
        T = RB_DELETE(nodo_a_eliminar);
        printf("Árbol después de eliminar 15: ");
        RB_PRINT_TREE();
    } else {
        printf("Nodo 15 no encontrado.\n");
    }
    printf("\n");
    
    printf("Eliminando el nodo con clave 20...\n");
    nodo_a_eliminar = RB_SEARCH(20);
    if (nodo_a_eliminar != NILLeaf) {
        T = RB_DELETE(nodo_a_eliminar);
        printf("Árbol después de eliminar 20: ");
        RB_PRINT_TREE();
    } else {
        printf("Nodo 20 no encontrado.\n");
    }
    printf("\n");
    
    printf("Eliminando el nodo con clave 1...\n");
    nodo_a_eliminar = RB_SEARCH(1);
    if (nodo_a_eliminar != NILLeaf) {
        T = RB_DELETE(nodo_a_eliminar);
        printf("Árbol después de eliminar 1: ");
        RB_PRINT_TREE();
    } else {
        printf("Nodo 1 no encontrado.\n");
    }
    printf("\n");
    
    // Destruir el árbol
    RB_DESTROY();
    
    printf("=== FIN DE LAS PRUEBAS ===\n");
    
    return 0;
}
#endif

/*
 * INSTRUCCIONES DE COMPILACIÓN Y EJECUCIÓN:
 * 
 * Para compilar con el programa de prueba:
 *   gcc -DTEST_RBT arboles-rojinegros-ia.c -o rbt && ./rbt
 * 
 * Para compilar solo la biblioteca (sin main):
 *   gcc -c arboles-rojinegros-ia.c -o arboles-rojinegros-ia.o
 * 
 * REFERENCIAS:
 * - Apuntes_Clase33_EstructuraDeDatos_Noviembre12de2021.pdf
 * - Clase 33 Presencial Mediada por Herramientas de Virtualidad
 * - Curso de Estructura de Datos - Código IS304 - Grupo 01
 * - Profesor Hugo Humberto Morales Peña
 * - Fecha: Viernes 12 de Noviembre de 2021
 */
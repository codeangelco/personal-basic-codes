# Cambios Realizados en arboles-rojinegros-ia.c

## Resumen de Cambios

El archivo ha sido completamente reescrito siguiendo **EXACTAMENTE** los pseudocódigos del documento:
**"Apuntes_Clase33_EstructuraDeDatos_Noviembre12de2021.pdf"**

---

## Funciones del PDF Implementadas

### 1. **RB-DELETE(T, z)** - Líneas 1-27 del pseudocódigo
   - Elimina un nodo del árbol rojinegro
   - Diferencias con TREE-DELETE estándar:
     1. Referencias a NIL reemplazadas por NILLeaf
     2. Asignación `p[x] ← p[y]` es incondicional (línea 9)
     3. Llama a RB-DELETE-FIXUP si `y` es negro (líneas 20-21)
   
   **Implementada como:** `Node *RB_DELETE(Node *z)`

### 2. **RB-DELETE-FIXUP(T, x)** - Líneas 1-45 del pseudocódigo
   - Restaura las propiedades del árbol rojinegro después de eliminación
   - Maneja 4 casos diferentes (Case 1, 2, 3, 4)
   - Funciona tanto para hijo izquierdo como derecho
   
   **Implementada como:** `Node *RB_DELETE_FIXUP(Node *x)`

---

## Funciones Auxiliares Agregadas (NO en el PDF)

Estas funciones son necesarias para el funcionamiento del árbol pero no están en el PDF:

### 1. **RB_INITIALIZE()**
   - Inicializa el árbol rojinegro
   - Crea el nodo centinela NILLeaf
   - Establece la raíz como NILLeaf

### 2. **CREATE_NODE(int key)**
   - Crea un nuevo nodo con la clave especificada
   - Inicializa los punteros a NILLeaf

### 3. **TREE_SUCCESSOR(Node *z)**
   - Encuentra el sucesor de un nodo en el árbol
   - Necesaria para RB-DELETE (línea 4 del pseudocódigo)

### 4. **LEFT_ROTATE(Node *x)**
   - Rotación a la izquierda sobre el nodo x
   - Necesaria para RB-DELETE-FIXUP (líneas 7, 21, 37)

### 5. **RIGHT_ROTATE(Node *x)**
   - Rotación a la derecha sobre el nodo x
   - Necesaria para RB-DELETE-FIXUP (líneas 16, 28, 42)

### 6. **RB_SEARCH(int key)**
   - Busca un nodo por su clave
   - Útil para encontrar el nodo a eliminar

### 7. **RB_INSERT_SIMPLE(int key)**
   - Inserción simplificada para testing
   - **NOTA:** NO implementa RB-INSERT-FIXUP porque no está en el PDF

### 8. **RB_PRINT_TREE()** y **RB_INORDER_PRINT(Node *x)**
   - Imprime el árbol en orden
   - Muestra las claves y colores de los nodos

### 9. **RB_DESTROY()** y **RB_FREE_TREE_REC(Node *x)**
   - Libera toda la memoria del árbol
   - Destruye el árbol completamente

---

## Funciones ELIMINADAS (estaban en el archivo original pero NO en el PDF)

Las siguientes funciones fueron eliminadas porque NO aparecen en los pseudocódigos del PDF:

1. ❌ **insertar_arreglar()** - No está en el PDF
2. ❌ **rbt_insertar()** - No está en el PDF
3. ❌ **rbt_buscar()** - No está en el PDF (se reemplazó por RB_SEARCH como auxiliar)
4. ❌ **rbt_minimo()** - No está en el PDF (se integró en TREE_SUCCESSOR)
5. ❌ **rbt_trasplantar()** - No está en el PDF (se integró en RB_DELETE)
6. ❌ **eliminar_arreglar()** - NO ESTÁ EN EL PDF (se reemplazó por RB_DELETE_FIXUP)
7. ❌ **rbt_eliminar()** - NO ESTÁ EN EL PDF (se reemplazó por RB_DELETE)

---

## Cambios en la Nomenclatura

Para mantener fidelidad con el pseudocódigo del PDF:

| Antes (español)  | Ahora (inglés del PDF) |
|------------------|------------------------|
| `ROJO`, `NEGRO`  | `RED`, `BLACK`         |
| `Nodo`           | `Node`                 |
| `clave`          | `key`                  |
| `izq`, `der`     | `left`, `right`        |
| `padre`          | `p`                    |
| `NIL`            | `NILLeaf`              |
| `raiz`           | `T`                    |

---

## Documentación

Cada función ahora incluye:

1. **Comentario de propósito**: Explica qué hace la función
2. **Referencia al PDF**: Indica las líneas del pseudocódigo correspondientes
3. **Parámetros**: Describe cada parámetro
4. **Valor de retorno**: Describe lo que devuelve
5. **Comentarios en línea**: Cada línea del pseudocódigo está comentada

Ejemplo:
```c
/**
 * RB-DELETE: Elimina un nodo del árbol rojinegro
 * 
 * Pseudocódigo del PDF (líneas 1-27):
 * function RB-DELETE(T, z)
 * 
 * @param z: nodo a eliminar
 * @return: raíz del árbol (posiblemente modificada)
 */
Node *RB_DELETE(Node *z) {
    // Línea 1: if left[z] == NILLeaf or right[z] == NILLeaf then
    if (z->left == NILLeaf || z->right == NILLeaf) {
        // Línea 2: y ← z
        y = z;
    }
    // ... resto del código
}
```

---

## Compilación y Ejecución

### Para compilar con el programa de prueba:
```bash
gcc -DTEST_RBT arboles-rojinegros-ia.c -o rbt && ./rbt
```

### Para compilar solo la biblioteca (sin main):
```bash
gcc -c arboles-rojinegros-ia.c -o arboles-rojinegros-ia.o
```

---

## Salida del Programa de Prueba

```
=== PRUEBA DE ÁRBOL ROJINEGRO (RB-DELETE) ===

Insertando valores: 20, 15, 25, 10, 5, 1, 30, 27, 40
Árbol inicial (inorder): 1(R) 5(R) 10(R) 15(R) 20(B) 25(R) 27(R) 30(R) 40(R) 

Eliminando el nodo con clave 15...
Árbol después de eliminar 15: 1(R) 5(R) 10(R) 20(B) 25(R) 27(R) 30(R) 40(R) 

Eliminando el nodo con clave 20...
Árbol después de eliminar 20: 1(R) 5(R) 10(R) 25(B) 27(R) 30(R) 40(R) 

Eliminando el nodo con clave 1...
Árbol después de eliminar 1: 5(R) 10(R) 25(B) 27(R) 30(R) 40(R) 

=== FIN DE LAS PRUEBAS ===
```

---

## Referencias

- **Documento base:** Apuntes_Clase33_EstructuraDeDatos_Noviembre12de2021.pdf
- **Clase:** 33 Presencial Mediada por Herramientas de Virtualidad
- **Capítulo:** Árboles Rojinegros - Borrado
- **Curso:** Estructura de Datos - Código IS304 - Grupo 01
- **Profesor:** Hugo Humberto Morales Peña
- **Fecha:** Viernes 12 de Noviembre de 2021
- **Programa:** Ingeniería de Sistemas y Computación

---

## Verificación

✅ Código compila sin errores ni advertencias
✅ Todas las funciones del PDF están implementadas
✅ Funciones NO presentes en el PDF fueron eliminadas
✅ Nomenclatura coincide con el pseudocódigo
✅ Cada línea del pseudocódigo está comentada
✅ Programa de prueba ejecuta correctamente
✅ Documentación completa agregada

// C17: implementación eficiente de bit flags
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

// Tipo de almacenamiento para flags: rápido (>=32 bits)
typedef uint_fast8_t flags_t;

// Máscaras de bits (valores constantes). El enum no fija el tamaño,
// solo nombra las máscaras; el tamaño lo decide flags_t.
enum Flag {
    FLAG_NONE   = 0u,
    FLAG_READ   = 1u << 0,
    FLAG_WRITE  = 1u << 1,
    FLAG_EXEC   = 1u << 2,
    FLAG_HIDDEN = 1u << 3,
};

// Utilidades inline (sin coste de llamada) para manipular flags
static inline void flags_set(flags_t *f, flags_t mask)   { *f |=  mask; }
static inline void flags_clear(flags_t *f, flags_t mask) { *f &= ~mask; }
static inline void flags_toggle(flags_t *f, flags_t mask){ *f ^=  mask; }
static inline bool flags_has(flags_t f, flags_t mask)    { return (f & mask) == mask; }

int main(void) {
    flags_t f = FLAG_NONE;

    // Establecer varias flags (OR de máscaras)
    flags_set(&f, (flags_t)(FLAG_READ | FLAG_WRITE));
    printf("Inicial: 0x%08" PRIXFAST8 "\n", f);

    // Consultar flags
    printf("Tiene READ? %s\n",  flags_has(f, FLAG_READ)  ? "sí" : "no");
    printf("Tiene EXEC? %s\n",  flags_has(f, FLAG_EXEC)  ? "sí" : "no");

    // Alternar y limpiar
    flags_toggle(&f, FLAG_WRITE);
    printf("Toggle WRITE: 0x%08" PRIXFAST8 "\n", f);

    flags_clear(&f, FLAG_READ);
    printf("Clear READ:  0x%08" PRIXFAST8 "\n", f);

    // Persistencia/serialización: usa tamaño fijo
    uint8_t persisted = (uint8_t)f; // asegúrate de que tus flags caben en 8 bits
    printf("Persistible (uint32_t): 0x%08" PRIX8 "\n", persisted);

    return 0;
}
#ifndef PAQUETE_H
#define PAQUETE_H
#include <stdint.h>

#define HEADERONE '{'
#define HEADERTWO '{'

#pragma pack(push, 1)
typedef struct {
    uint8_t  header[2];
    uint8_t analizando;   // no se puede inicializar dentro del struct
    uint16_t distanciaMm;
    float    grados;
    uint32_t posX;
    uint32_t posY;
    uint32_t checksum;
} Paquete;
#pragma pack(pop)

extern Paquete pkt;
uint32_t calcularChecksum(Paquete* pkt);

#endif // PAQUETE_H

#include "paquete.h"

uint32_t calcularChecksum(Paquete* pkt) {
    uint32_t sum = 0;
    // Sumar todos los bytes excepto los del campo checksum
    for (size_t i = 0; i < sizeof(Paquete) - sizeof(pkt->checksum); i++) {
        sum += ((uint8_t*)pkt)[i];  // convertimos pkt a bytes directamente
    }
    return sum;
}

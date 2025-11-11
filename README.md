# Proyecto: Servidor Qt con Visualización Gráfica y Control WebSocket

Este proyecto implementa una **interfaz gráfica (GUI) en Qt** que actúa como **servidor WebSocket**.  
Permite **recibir datos binarios** desde un cliente (por ejemplo, un ESP32) y **representarlos gráficamente en un mapa 2D**, además de **enviar comandos de control** mediante botones o sliders.

---

## 🧠 Funcionalidad general

1. **Servidor WebSocket:**
   - Escucha en el **puerto 12345** en todas las interfaces (`QHostAddress::Any`).
   - Acepta conexiones desde clientes (típicamente un ESP32).
   - Recibe paquetes binarios con la estructura `Paquete` y valida encabezado y checksum.
   - Envía mensajes de texto al cliente para controlar un vehículo remoto.

2. **Visualización gráfica (QGraphicsView):**
   - Muestra los puntos recibidos (coordenadas cartesianas) en un área de 8000×8000 unidades.
   - Dibuja un vehículo (`vehiculo`) y los puntos detectados (`Punto`).
   - Permite zoom, desplazamiento y visualización de rango visible.

3. **Controles en GUI:**
   - Botones para mover el vehículo: adelante, atrás, izquierda, derecha.
   - Sliders para modificar velocidad del motor y período de muestreo.
   - Botones para limpiar puntos, analizar o resetear el sistema.
   - Checkbox para habilitar/deshabilitar movimiento.
   - Consola (`QPlainTextEdit`) para mensajes del sistema.

---

## 📡 Comunicación WebSocket

### Dirección del servidor
El programa obtiene automáticamente la dirección IP local del equipo:

```cpp
const auto addresses = QNetworkInterface::allAddresses();
for (const QHostAddress &address : std::as_const(addresses)) {
    if (address.protocol() == QAbstractSocket::IPv4Protocol && !address.isLoopback()) {
        ip = address.toString();
        break;
    }
}

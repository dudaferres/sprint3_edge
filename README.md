# 🍼 Monitor de Temperatura para Mamadeiras

Este projeto utiliza um Arduino para monitorar a temperatura de uma mamadeira e fornecer alertas visuais e sonoros quando a temperatura está fora da faixa ideal. Também é possível integrar com **Node-RED** via **MQTT** para monitoramento remoto em tempo real.

---

# 📈 Diagrama


![image](https://github.com/user-attachments/assets/f83ddfa1-9909-451f-a0fb-91a9b44eb710)


# Descrição do Diagrama

Este projeto apresenta a arquitetura de um sistema IoT utilizando Arduino UNO, comunicação via Wi-Fi, protocolo MQTT e uma aplicação web para visualização dos dados.

## 🛠️ Componentes

- **LED**: Atuador de sinalização visual.
- **DHT11**: Sensor de temperatura e umidade.
- **Buzzer**: Atuador de alerta sonoro.

Todos os dispositivos estão conectados ao **Arduino UNO**, que coleta os dados e envia via módulo **Wi-Fi**.

## 🔗 Comunicação

- O **Arduino UNO** envia os dados capturados para a internet utilizando uma conexão **Wi-Fi**.
- As informações são publicadas em um **Broker MQTT** (no caso, **HiveMQ**).
- O Broker organiza a comunicação entre o Arduino e o **Back-end**.

## 🖥️ Back-end

- O Back-end se conecta ao Broker MQTT.
- Ele recebe os dados publicados e converte as mensagens no formato **JSON**, facilitando a manipulação e integração com a aplicação web.

## 📊 Aplicação Web

- A aplicação web (Dashboard) consome os dados em formato **JSON** e exibe informações em tempo real para o usuário.
- A Dashboard permite visualizar a temperatura, umidade e status dos atuadores.

## 🔁 Fluxo Resumido

1. Sensores enviam dados para o Arduino UNO.
2. Arduino publica as informações no Broker MQTT através do Wi-Fi.
3. Back-end consome as mensagens MQTT e gera dados em JSON.
4. A aplicação Web consome o JSON e exibe no Dashboard.


---
# 🍼 Sobre o Monitor de Temperatura para Mamadeiras

## Print do projeto no Wokwi

![image](https://github.com/user-attachments/assets/b9515b9d-9ed5-44cb-94a1-e1f6c091d25a)


## Link do vídeo no Youtube explicando sobre o projeto:

---
## 🧰 Componentes Utilizados

- Arduino (Uno, Nano ou similar)  
- Sensor de temperatura DHT22  
- LED verde  
- LED vermelho  
- Buzzer  
- Resistores apropriados para os LEDs  
- Protoboard e jumpers  
- Módulo Wi-Fi (ex: ESP8266 ou ESP32) *(para uso com MQTT)*  
- Broker MQTT (local ou em nuvem)

---

## ⚙️ Funcionalidades

- Medição contínua da temperatura  
- Exibição da temperatura no Dashboard  
- Indicação visual com LEDs:  
  - 🟢 **Verde**: temperatura adequada (35°C - 37°C)  
  - 🔴 **Vermelho**: temperatura fora da faixa ideal para o bebê 
- Alerta sonoro com buzzer quando a temperatura está muito fria (<35°C) ou muito quente (>37°C)  
- Saída dos dados em formato JSON pela porta serial  
- Envio dos dados via MQTT para dashboards e automações (ex: Node-RED)

---

## 🔌 Esquema de Conexão

### 🌡️ DHT22:
- Pino de dados → Pino 6 do Arduino   

### 🔧 Outros componentes:
- LED verde → Pino 13  
- LED vermelho → Pino 12  
- Buzzer → Pino 8  

---

## 📚 Bibliotecas Necessárias

- `LiquidCrystal_I2C`  
- `ArduinoJson`  
- `DHT Sensor Library`  
- `PubSubClient` *(para MQTT)*  
- `WiFi` ou `ESP8266WiFi` *(dependendo do módulo usado)*

---

## ▶️ Como Usar

1. 🔌 Conecte todos os componentes conforme o esquema  
2. ⬆️ Carregue o sketch para o Arduino (ou ESP8266/ESP32)  
3. 💬 O display mostrará mensagens de inicialização  
4. 🌡️ A temperatura será exibida continuamente no LCD  
5. 🔴🟢 O sistema alertará visual e sonoramente se a temperatura estiver fora da faixa  
6. 📤 Os dados são enviados via Serial ou MQTT  

---

## 📡 Saída Serial (exemplo)

```json
{"Temperatura":36.5}

```
---
# Integrantes do Grupo

- Gabriela Queiroga - RM 560035
- Julia Sayuri Yokoo - RM 560541
- Maria Eduarda Ferrés - RM 560418




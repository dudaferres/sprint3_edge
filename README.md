# 🍼 Monitor de Temperatura para Mamadeiras

Este projeto utiliza um **ESP32** para monitorar a temperatura de uma mamadeira e fornecer alertas visuais e sonoros quando a temperatura está fora da faixa ideal. Também é possível integrar com **Node-RED** via **MQTT** para monitoramento remoto em tempo real.

---

# 📈 Diagrama

![image](https://github.com/user-attachments/assets/66a0b34f-a924-43cd-959f-78d2bd633e59)

# Descrição do Diagrama

Este projeto apresenta a arquitetura de um sistema IoT utilizando **ESP32**, comunicação via Wi-Fi, protocolo MQTT e uma aplicação web para visualização dos dados.

## 🛠️ Componentes

- **LED**: Atuador de sinalização visual  
- **DHT11**: Sensor de temperatura e umidade  
- **Buzzer**: Atuador de alerta sonoro  

Todos os dispositivos estão conectados ao **ESP32**, que coleta os dados e os envia através da conexão Wi-Fi.

## 🔗 Comunicação

- O **ESP32** envia os dados capturados para a internet utilizando Wi-Fi  
- As informações são publicadas em um **Broker MQTT** (ex: **HiveMQ**)  
- O Broker organiza a comunicação entre o ESP32 e o **Back-end**

## 🖥️ Back-end

- O Back-end se conecta ao Broker MQTT  
- Recebe os dados publicados e converte as mensagens no formato **JSON**, facilitando a manipulação e integração com a aplicação web

## 📊 Aplicação Web

- A aplicação web (Dashboard) consome os dados em formato **JSON** e exibe informações em tempo real para o usuário  
- A Dashboard permite visualizar a temperatura, umidade e status dos atuadores  

## 🔁 Fluxo Resumido

1. Sensores enviam dados para o ESP32  
2. ESP32 publica as informações no Broker MQTT através do Wi-Fi  
3. Back-end consome as mensagens MQTT e gera dados em JSON  
4. A aplicação Web consome o JSON e exibe no Dashboard

---

# 🍼 Sobre o Monitor de Temperatura para Mamadeiras

## Print do projeto no Wokwi

![image](https://github.com/user-attachments/assets/3306a0f4-e254-489c-9dc8-7758c44ed8f5)


## Link do vídeo no Youtube explicando sobre o projeto:

---

## 🧰 Componentes Utilizados

- **ESP32**  
- Sensor de temperatura **DHT22**  
- LED verde  
- LED vermelho  
- Buzzer  
- Resistores apropriados para os LEDs  
- Protoboard e jumpers  
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
- Pino de dados → GPIO 6 do ESP32 *(ou qualquer GPIO disponível)*

### 🔧 Outros componentes:
- LED verde → GPIO 13  
- LED vermelho → GPIO 12  
- Buzzer → GPIO 8  

---

## 📚 Bibliotecas Necessárias

- `LiquidCrystal_I2C`  
- `ArduinoJson`  
- `DHT Sensor Library`  
- `PubSubClient` *(para MQTT)*  
- `WiFi.h` *(biblioteca nativa do ESP32)*

---

## ▶️ Como Usar

1. 🔌 Conecte todos os componentes conforme o esquema  
2. ⬆️ Carregue o sketch para o ESP32  
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

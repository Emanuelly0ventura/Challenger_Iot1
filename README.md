# PetCore 🐾

Sistema IoT para monitoramento inteligente de alimentação e presença de pets utilizando ESP32, sensores ultrassônicos, MQTT, Node-RED e banco de dados SQLite.

## 📌 Sobre o Projeto

O PetCore é uma tigela inteligente desenvolvida para auxiliar no monitoramento da alimentação de animais domésticos.

O projeto utiliza sensores ultrassônicos conectados a um ESP32 para identificar:

Aproximação do pet à tigela
Quantidade de comida disponível

As informações são enviadas em tempo real utilizando o protocolo MQTT e exibidas em um dashboard no Node-RED, além de serem armazenadas em banco de dados SQLite para geração de histórico.

## ⚙️ Funcionalidades
* 🐶 Detecção de presença do pet
* 🍖 Monitoramento da quantidade de comida
* 🕒 Registro de horário em tempo real
* 📡 Comunicação MQTT
* 💾 Armazenamento em banco SQLite
* 📊 Dashboard interativo no Node-RED
* 📜 Histórico de registros utilizando tabela dinâmica

## 🛠️ Tecnologias Utilizadas
* Hardware
* ESP32
* 2 Sensores Ultrassônicos HC-SR04
* Software
* Arduino IDE
* Node-RED
* SQLite
* MQTT
* HiveMQ Cloud
* Wokwi
### Linguagens
* C++
* SQL

## 🔌 Estrutura do Sistema
ESP32 + Sensores
        →
     MQTT
        →
   HiveMQ Cloud
        →
    Node-RED
        →
 Dashboard + SQLite
 
## 📡 Tópicos MQTT
* Tópico	Função
* petcore/status →	Detecta presença do pet
* petcore/comida →	Verifica quantidade de comida
* petcore/horario → Envia horário do evento

## 🚀 Instruções de Uso

### 🔌 1. Configuração do ESP32

Conectar os sensores(Codigo do Repositorio):

### 2. Executar o Node-RED

Importe o fluxo do Node-RED e configure(sprint1.json que está no repositorio):

conexão MQTT
banco SQLite
dashboard

### 3. Iniciar o Sistema

Após iniciar:

o ESP32 enviará dados automaticamente
o dashboard exibirá:
presença do pet
status da comida
horário
histórico de registros

## 🗄️ Banco de Dados

O projeto utiliza SQLite para armazenar os registros do monitoramento.

Exemplo de consulta SQL:

SELECT 
    horario,
    status,
    comida
FROM historico_petcore
ORDER BY id DESC;

## 📊 Dashboard

O dashboard do Node-RED apresenta:

📍 Status do pet
🍖 Estado da comida
🕒 Horário atualizado
📜 Histórico em tabela dinâmica
📈 Resultados Parciais

### Até o momento, o sistema foi capaz de:

realizar conexão Wi-Fi com ESP32
enviar dados via MQTT
detectar presença do pet utilizando sensor ultrassônico
monitorar nível de comida na tigela
registrar horários utilizando NTP
armazenar informações em banco SQLite
exibir dados em dashboard em tempo real
gerar histórico organizado utilizando ui_table

Os testes realizados no Wokwi e no Node-RED apresentaram funcionamento estável na comunicação entre os componentes do sistema.

## 🧪 Simulação

O projeto foi desenvolvido e testado utilizando a plataforma Wokwi para simulação do ESP32 e sensores.

## 👩‍💻Time

Carolina nascimento gonçalves
RM564786 - 2TDSPJ

Julia sayuri kina
RM564555 - 2TDSPJ 

Emanuelly ventura do nascimento
RM562339 - 2TDSPJ

🌧️ SARA - Sistema Autônomo de Resposta a Alagamentos

O projeto SARA é um sistema IoT desenvolvido para monitorar e prever condições que indicam possíveis enchentes, através da medição de:

🌡 Temperatura do ambiente

💧 Nível da água

☀️ Clareza do ambiente (LDR)

Esses dados são coletados por sensores conectados a um ESP32, enviados via MQTT ao Node-RED, e exibidos em um dashboard em tempo real.

============================================================================================================================================

📦 Estrutura do Projeto

📁 sara-iot/
├─ wokwi/
│ ├─ esp32_sara.ino # Código do ESP32 (envia os dados via MQTT)
│ ├─ diagram.json # Arquitetura do projeto no simulador Wokwi
│ ├─ libraries.txt # Bibliotecas utilizadas
│ ├─ link.txt # Link direto para abrir o projeto no Wokwi
│ └─ sensores.jpg # Imagem ilustrativa dos sensores conectados
│
├─ node-red/
│ ├─ flows.json # Exportação completa do fluxo Node-RED
│ ├─ dashboard.png # Print do painel final
│ └─ fluxo.png # Print do fluxo no Node-RED
│
└─ README.md # Documentação do projeto

============================================================================================================================================

🛠 Tecnologias Utilizadas

ESP32 (simulado no Wokwi)

Sensores: Ultrassônico (HC-SR04), LDR, NTC (termistor)

Node-RED (MQTT e Dashboard)

HiveMQ Broker (MQTT)

JSON como formato de mensagem

============================================================================================================================================

🚀 Como Executar o Projeto

📡 Parte 1: Wokwi (Simulação do ESP32)

Opção 1: Abrindo direto pelo link

Abra o arquivo link.txt

Clique ou cole o link no navegador

Clique em "Start Simulation"

Opção 2: Criar projeto manualmente

Acesse https://wokwi.com/

Crie um novo projeto com ESP32

Copie e cole o conteúdo de diagram.json (ele vai montar os sensores automaticamente)

Depois, substitua o código pelo conteúdo de esp32_sara.ino

Clique em "Start Simulation"

💡 Obs: o ESP32 está configurado para conectar via Wi-Fi ao broker MQTT da HiveMQ e enviar os dados no tópico sara/sensores.

============================================================================================================================================

🌐 Parte 2: Node-RED

Requisitos

Node-RED instalado em sua máquina

Conexão com a internet

Importando o fluxo

Abra o Node-RED em http://localhost:1880

Clique no menu (☰) > Import

Copie o conteúdo de flows.json ou clique em "Importar arquivo"

Clique em Import e o fluxo será carregado

Clique em "Deploy" no canto superior direito

============================================================================================================================================

📊 Como abrir o dashboard do Node-RED
Após importar e deployar o fluxo no Node-RED:

No canto superior direito da interface do Node-RED, clique no botão do menu lateral (ícone de três linhas ☰).

Vá em Dashboard > View Dashboard.

Ou, simplesmente, acesse diretamente pelo navegador o endereço:

bash
Copiar
Editar
http://localhost:1880/ui
Lá você verá o painel com as informações de temperatura, nível da água e chance de chuva, todos atualizados em tempo real com base nos dados simulados pelo ESP32 no Wokwi. 🌡️💧🌦️

============================================================================================================================================

✍️ Autores

Desenvolvido por João Paulo Francisco de Oliveira[RM557410] e Marcelo Antonio Scoleso Junior [RM557481] —

Se precisar de ajuda para executar o projeto, entre em contato!

============================================================================================================================================


# CAID - Interligência artifical para detecção de câncer

## Descrição do Projeto

Este componente do projeto tem como objetivo integrar o ESP32, um microcontrolador de baixo consumo de energia, com um módulo SD Card para capturar e armazenar imagens médicas. O propósito é agilizar o processo de detecção de tumores cerebrais, enviando as imagens capturadas para a nuvem, onde serão processadas por um modelo de machine learning.

## Estrutura do Projeto

1. **ESP32:**
   - Utilização do ESP32 para aquisição de imagens a partir de dispositivos de imagem médica. (implementação futura)
   - Implementação de lógica de controle para captura de imagens em intervalos específicos. (implementação futura)

2. **SD Card:**
   - Integração de um módulo SD Card para armazenamento local das imagens.
   - Desenvolvimento de rotinas de envio dos dados contidos no SD Card.

3. **Comunicação com a Nuvem:**
   - Implementação de protocolos de comunicação (MQTT) para enviar as imagens capturadas para a nuvem.

## Configuração do Ambiente

1. **Hardware:**
   - Certifique-se de ter um ESP32 configurado e conectado aos dispositivos de imagem médica e ao módulo SD Card.

2. **Software:**
   - Instale as bibliotecas necessárias para o ESP32, incluindo aquelas relacionadas à comunicação com o SD Card e à transmissão de dados para a nuvem. São elas:

WiFi.h
WiFiClient.h
WebServer.h
uri/UriBraces.h
ArduinoJson.h
EspMQTTClient.h
SD.h

## Configuração do SD Card

![Print do Wokwi](https://github.com/TonyWillianFIAP/Edge-GS2/blob/main/img/Arquitetura.png)

1. **Formate o SD Card:**
   - Formate o SD Card para garantir a compatibilidade com o sistema de arquivos utilizado no projeto.

2. **Estrutura de Pastas:**
   - Organize as pastas no SD Card para facilitar o armazenamento e recuperação das imagens.

Link de acesso da simulação:https://wokwi.com/projects/382142903314890753

## Configuração da Nuvem

1. **Conta na Plataforma de Nuvem:**
   - Registre-se em uma plataforma de nuvem (Tago.io) para criar um local seguro para o armazenamento e processamento das imagens.

2. **Configuração das Credenciais:**
   - Configure as credenciais de acesso à nuvem no código do ESP32 para garantir uma transmissão segura.

## Uso do Sistema

1. **Início da Captura:**
   - Carregue o código no ESP32 e inicie a captura de imagens a partir dos dispositivos médicos adequados.

2. **Armazenamento Local:**
   - As imagens serão armazenadas localmente no SD Card para posterior envio.

3. **Envio para a Nuvem:**
   - As imagens armazenadas serão transmitidas para a nuvem utilizando os protocolos de comunicação configurados.

4. **Processamento na Nuvem:**
   - As imagens recebidas serão processadas por um modelo de machine learning na plataforma de nuvem para detecção de tumores cerebrais.

5. **Resultados:**
   - Os resultados do processamento, como diagnósticos e análises, estarão disponíveis na plataforma de nuvem para revisão.
  
## Integrantes:
Henrique Parra Benitez – RM551973
Tony Willian da Silva Segalin – RM550667 

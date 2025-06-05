#include <WiFi.h>
#include <PubSubClient.h>

#define TRIG_PIN  5
#define ECHO_PIN  18
#define TEMP_PIN  19  // substitui PIR pelo sensor de temperatura
#define LDR_PIN   34

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi conectado");
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32_SARA")) {
      Serial.println("MQTT conectado");
    } else {
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  // SENSOR NÍVEL
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distancia = duration * 0.034 / 2;

  String nivel;
  if (distancia < 10) nivel = "🚨 Nível PERIGOSO";
  else if (distancia < 20) nivel = "✅ Nível NORMAL";
  else nivel = "⚠️ Nível de água BAIXO";

  // SENSOR DE TEMPERATURA ANALÓGICO
  int leitura = analogRead(TEMP_PIN);
  float temperaturaC = 1 / (log(1 / (4095. / leitura - 1)) / 3950 + 1.0 / 298.15) - 273.15;
  String temperaturaStr = String(temperaturaC, 1) + "°C";

  // SENSOR LDR
  int ldr = analogRead(LDR_PIN);
  String chuva;
  if (ldr < 1000) chuva = "🌧 Alta chance";
  else if (ldr < 3000) chuva = "☁️ Baixa chance";
  else chuva = "🌞 Céu limpo";

  // JSON SIMPLES COM TEXTO
   String payload = "{";
  payload += "\"distancia\": " + String(distancia, 2) + ",";
  payload += "\"temperatura\": " + String(temperaturaC, 1) + ",";
  payload += "\"ldr\": " + String(ldr);
  payload += "}";

  Serial.println(payload);
  client.publish("sara/sensores", (char*) payload.c_str());

  delay(3000);
}
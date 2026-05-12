#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <time.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "54ebefe55d2e4a88af571fd3771fddf5.s1.eu.hivemq.cloud";

WiFiClientSecure espClient;
PubSubClient client(espClient);

#define TRIG_PIN 5
#define ECHO_PIN 18

#define TRIG_PIN2 4
#define ECHO_PIN2 16

const char* ntpServer = "pool.ntp.org";

const long gmtOffset_sec = -3 * 3600;

const int daylightOffset_sec = 0;

void setup_wifi() {

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void reconnect() {

  while (!client.connected()) {

    client.connect(
      "PetCoreESP32",
      "Emanuelly",
      "260207Ab"
    );
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);

  setup_wifi();

  espClient.setInsecure();

  client.setServer(mqtt_server, 8883);


  configTime(
    gmtOffset_sec,
    daylightOffset_sec,
    ntpServer
  );
}

void loop() {

  while (!client.connected()) {

    Serial.println("Conectando MQTT...");
  
    if(client.connect(
        "PetCoreESP32",
        "Emanuelly",
        "260207Ab")) {

      Serial.println("Conectado!");

    } else {

      Serial.print("Erro: ");
      Serial.println(client.state());

      delay(2000);
    }
  }

  client.loop();



  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  //

  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN2, LOW);

  

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration * 0.034 / 2;

  long duration1 = pulseIn(ECHO_PIN2, HIGH);

  float comida = duration1 * 0.034 / 2;



  struct tm timeinfo;

  char horario[10];

  if(getLocalTime(&timeinfo)) {

    strftime(
      horario,
      sizeof(horario),
      "%H:%M:%S",
      &timeinfo
    );

  } else {

    strcpy(horario, "SEM HORA");
  }

  //

  String distancia;

  if(distance < 120){

    distancia = "PET DETECTADO";
  } 
  
  else {

    distancia = "SEM PRESENCA";
  }

  //

  String comidas;

  if(comida > 10){

    comidas = "COM COMIDA";
  } 
  
  else {

    comidas = "SEM COMIDA";
  }


  String distanciaMQTT;

  distanciaMQTT += distancia;

  client.publish(
    "petcore/status",
    distanciaMQTT.c_str()
  );


  String horarioMQTT;

  horarioMQTT += horario;

  client.publish(
    "petcore/horario",
    horarioMQTT.c_str()
  );

  String comidaMQTT;

  comidaMQTT += comidas;

  client.publish(
    "petcore/comida",
    comidas.c_str()
  );


  delay(2000);
}
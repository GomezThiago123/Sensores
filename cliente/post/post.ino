#include <WiFi.h>
#include <HTTPClient.h>

const char *ssid = "ETEC-UBA";
const char *password = "ETEC-alumnos@UBA";
const char *serverName = "http://10.9.120.87:7000/api/sensor";

void setup() {
  pinMode(Termometro, IMPUT)
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network
  WiFi.begin(ssid, password);

  Serial.println();
  Serial.println();
  Serial.print("Waiting for WiFi... ");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    Serial.flush();
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  delay(500);
}

void loop() {
  delay(3000);
  if(WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;
    http.begin(client, serverName);
    http.addHeader("Content-Type", "application/json");
    Serial.print("Enviando dato a ");
    Serial.println(serverName);
    int valor = 145;
    String jsonStr = "{\"nombre\":\"luxometro\",\"valor\":145}";
    //char *jsonStr = "{\"nombre\":\"luxometro\",\"valor\":145}";
    int httpResponseCode = http.POST(jsonStr);
    Serial.print("Respuesta: ");
    Serial.println(httpResponseCode);
    http.end();
  } else {
    Serial.println("Desconectado");
  }
}

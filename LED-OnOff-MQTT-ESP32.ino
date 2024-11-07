#include <WiFi.h>
#include <MQTT.h> // MQTT kütüphanesi

// WiFi bilgileri
const char* ssid = "***"; // WiFi SSID
const char* password = "****"; // WiFi Şifresi

// MQTT Broker IP adresi
const char* mqtt_server = "****"; // Broker IP
WiFiClient net; // WiFiClient nesnesi
MQTTClient client;

const int ledPin = 26; // LED'in bağlı olduğu GPIO pini

void messageReceived(String &topic, String &payload) {
  Serial.print("Gelen mesaj: ");
  Serial.println(payload);
  
  // Mesaj içeriğine göre LED'i aç veya kapat
  if (payload.equals("ON")) {
    digitalWrite(ledPin, HIGH); // LED'i aç
    Serial.println("LED açıldı.");
  } else if (payload.equals("OFF")) {
    digitalWrite(ledPin, LOW); // LED'i kapat
    Serial.println("LED kapandı.");
  } else {
    Serial.println("Geçersiz mesaj."); // Hata ayıklama mesajı
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT); // LED pinini çıkış olarak ayarla
  setup_wifi(); // WiFi bağlantısını kur
  client.begin(mqtt_server, net); // MQTT istemcisini başlat
  client.onMessage(messageReceived); // Mesaj alındığında çağrılacak fonksiyonu ayarla

  // MQTT broker'ına bağlan
  if (client.connect("clientId")) {
    Serial.println("MQTT broker'a bağlandı.");
    client.subscribe("led/control"); // LED kontrol konusuna abone ol
  } else {
    Serial.print("Bağlanamadı, rc=");
    Serial.println(client.connect("clientId")); // Hata durumu
  }
}

void setup_wifi() {
  Serial.print("WiFi'ye bağlanıyor: ");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi bağlı. IP adresi: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  client.loop(); // MQTT istemcisinin güncellenmesi
}

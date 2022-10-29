#include <Wiegand.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID "4Skills"
#define WIFI_PASS "Arduino31"

WIEGAND wg;
int c;
const int httpPort = 80;
const char* host = "192.168.88.103/api";
const int addr[50]={4786353, 10161325, 11869255, 7294923, 4782139, 4800309, 4875728, 8916074, 2062392, 8084904, 8064882};

void setup() {
  Serial.begin(9600);
  //WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("IP address: "); Serial.println(WiFi.localIP());
  wg.begin();
  pinMode(7,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,INPUT_PULLUP);
  digitalWrite(7,1);
}

void loop() {

  digitalWrite(7,1);

  if(wg.available()){
    c=wg.getCode();
    WiFiClient client;
    Serial.println(wg.getCode());
    String url = "/";
    url += "?addr=";
    url += String(c);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
    if (millis() - timeout > 5000)
    { Serial.println(">>> Client Timeout !");
    client.stop(); return; } }
    while (client.available())
    { String line = client.readStringUntil('\r'); Serial.print(line);
    }
    for(int i=0;i<100;i++){
      if(c==addr[i]){
        Serial.println(1);
        digitalWrite(7,0);
        delay(3000);
        digitalWrite(7,1);
      }
    }
  }

  if(digitalRead(6)==0){
    Serial.println(1);
    digitalWrite(7,0);
    digitalWrite(4,0);
    digitalWrite(5,0);
    delay(3000);
    digitalWrite(7,1);
    digitalWrite(4,1);
    digitalWrite(5,1);
  }

}
/*
replace with your own wifi ssid const char* password = "your-password"; //replace with your own //wifi ssid password const char* host = "esp8266-shop.com";
void setup() { Serial.begin(115200); delay(10); // We start by connecting to a WiFi network Serial.println();
Serial.println(); Serial.print("Connecting to ");
Serial.println(ssid);
/* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default, would try to act as both a client and an access-point and could cause network-issues with your other WiFi-devices on your WiFi-network. */
/*
WiFi.mode(WIFI_STA);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected"); Serial.println("IP address: "); Serial.println(WiFi.localIP()); } int value = 0; void loop() { delay(5000); ++value; Serial.print("connecting to ");
Serial.println(host); // Use WiFiClient class to create TCP connections
WiFiClient client;
const int httpPort = 80;
if (!client.connect(host, httpPort)) {
Serial.println("connection failed");
return;
}*/
// We now create a URI for the request
//this url contains the informtation we want to send to the server
//if esp8266 only requests the website, the url is empty
//String url = "/";
//url += "?addr=";
/* url += param1;
url += "?param2=";
url += param2;
*/
/*
Serial.print("Requesting URL: ");
Serial.println(url); // This will send the request to the server
client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
unsigned long timeout = millis();
while (client.available() == 0) {
if (millis() - timeout > 5000)
{ Serial.println(">>> Client Timeout !");
client.stop(); return; } } // Read all the lines of the reply from server and print them to Serial
while (client.available())
{ String line = client.readStringUntil('\r'); Serial.print(line);
}
Serial.println();
Serial.println("closing connection"); }

*/

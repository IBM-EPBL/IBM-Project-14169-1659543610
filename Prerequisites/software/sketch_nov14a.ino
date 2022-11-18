#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "SMART-G";
const char* password = "10112019";

#define WT A0
#define CY D0 

String key;
#define ID "1yww18" 
#define DEVICE_TYPE "ESP8266" 
#define DEVICE_ID "SMARTWMS" 
#define TOKEN "IOT-1234567" 

char server[] = ID ".messaging.internetofthings.ibmcloud.com";
char publish_Topic1[] = "iot-2/evt/Data1/fmt/json";
char publish_Topic2[] = "iot-2/evt/Data2/fmt/json";
char authMethod[] = "use-token-auth";
char token[] = TOKEN;
char clientId[] = "d:" ID ":" DEVICE_TYPE ":" DEVICE_ID;
String inputString = "";         
bool stringComplete = false;  
WiFiClient wifiClient;
PubSubClient client(server, 1883, NULL, wifiClient);

void setup() {
    Serial.begin(115200);
//    dht.begin();
    Serial.println();
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    } 
    Serial.println("");
    Serial.println(WiFi.localIP());

    if (!client.connected()) {
        Serial.print("Reconnecting client to ");
        Serial.println(server);
        while (!client.connect(clientId, authMethod, token)) {
            Serial.print(".");
            delay(500);
        }
        Serial.println("Connected TO IBM IoT cloud!");
    }
     inputString.reserve(200);
}

long previous_message = 0;
void loop() {




 while(Serial.available())
{


  
           

  HTTPClient http;  
  String postData;  
  String key = Serial.readString();
    Serial.print(key);
  if(key.toInt()== 100)
  {  
    postData = "username=fantasy&password=596692&to=8072114401&from=FSSMSS&message=Dear user  your msg is your Controlled Bin is Full plz Clean Sent By FSMSG FSSMSS&PEID=1501563800000030506&templateid=1507162882948811640";
     Serial.print(key);
   http.begin("http://smsserver9.creativepoint.in/api.php");            
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode = http.POST(postData);   
  String payload = http.getString();
  Serial.println(payload);
  http.end();    
  delay(1000);
  }   
      

      
      

  
  



  


  Serial.print("GARBAGE LEVEL: ");
  Serial.print(key);
  Serial.print("%");
 int a=key.toInt();
       String payload = "{\"d\":{\"Name\":\"" DEVICE_ID "\"";
              payload += ",\"GARBAGE LEVEL\":";
              payload += a;
              payload += "}}";
       
        Serial.print("Sending payload: ");
        Serial.println(payload);

        if (client.publish(publish_Topic1, (char*) payload.c_str())) { 
            Serial.println("Published successfully");
        } else {
            Serial.println("Failed");
        }
 
}

    

    



}

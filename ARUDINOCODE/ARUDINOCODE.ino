#include <ESP8266WiFi.h>
 float vref = 3.3;
float resolution = vref/1023;

String apiKey = "EFEANPH3BZ2AVATN";     //  Enter your Write API key from ThingSpeak
 
const char *ssid =  "rachu";     // replace with your wifi ssid and wpa2 key
const char *pass =  "password";
const char* server = "api.thingspeak.com";
 
#define DHTPIN 0          //pin where the dht11 is connected
 
 
WiFiClient client;
 
void setup() 
{      
       Serial.begin(115200);
       delay(10);
 
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(1);
            Serial.println("not connect");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}
 
void loop() 
{
  
      
      float h =45;
      float t = 66;
      float ECG = 1;
       float temperature = analogRead(A0);
       temperature = (temperature*resolution);
        temperature = temperature*100;
       Serial.println(temperature);
              
 
                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(t);
                             postStr +="&field2=";
                             postStr += String(h);
                             postStr +="&field3=";
                             postStr += String(temperature);
                              postStr +="&field4=";
                             postStr += String(ECG);                             
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Temperature: ");
                             Serial.print(t);
                             Serial.print(" degrees Celcius, Humidity: ");
                             Serial.print(h);
                                Serial.print("body Temperature: ");
                             Serial.print(temperature);
                             Serial.print(" ecg: ");
                             Serial.print(ECG);                             
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);
  

  
}
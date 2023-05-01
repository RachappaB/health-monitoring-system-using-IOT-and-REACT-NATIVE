#include<ESP8266WiFi.h>

void setup() 
{
  Serial.begin(1200);  // put your setup code here, to run once:

  WiFi.begin("Rachappa","shantappa9945483471");//name,and password
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP Address");
  Serial.println(WiFi.localIP());
  Serial.print("MAC Address");
  Serial.println(WiFi.macAddress());
}

void loop() 
{
  // put your main code here, to run repeatedly:

}

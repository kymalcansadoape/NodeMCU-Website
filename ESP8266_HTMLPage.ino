
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
#include "main.h"
const char* ssid = "Test";
const char* password ="12345678";
ESP8266WebServer server(80);
// void withPictures(){
//   digitalWrite(2,0);
//   server.send(200,"text/html",withPic);
//   digitalWrite(2,1);
// }
void noPictures(){
  digitalWrite(2,0);
  server.send(200,"text/html",NoPic);
  digitalWrite(2,1);
}
void setup(){
  Serial.begin(115200);
  delay(10);  
  pinMode(2,OUTPUT);
  Serial.println();

  Serial.print("Connecting");
  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");

  }

  Serial.println("");
  Serial.println("Wifi Connected");
  Serial.print("Ip Address: ");
  Serial.println(WiFi.localIP());
  server.on("/",noPictures);
  // server.on("/no",noPictures);


  server.begin();
  Serial.println("HTTP server started");
  
  }


void loop(){
  server.handleClient();
}



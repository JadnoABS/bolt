#include <Wire.h>
#include <WiFi.h>
const int MPU_addr=0x68;  // endereço I2C do MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
// Informações da rede WiFi.
const char *ssid =  "NameOfNetworkTP"; // Insira seu nome de WiFi
const char *pass =  "0123456789";   // Insira sua senha WiFi
WiFiServer server(80);
long int ultimasAceleracoes[20];
int acelerou = 0;
int desacelerou = 0;
bool acelerando = false;
String readString="";

void setup(){
 Serial.begin(115200);
 Wire.begin();
 Wire.beginTransmission(MPU_addr);
 Wire.write(0x6B);  // Registro PWR_MGMT_1
 Wire.write(0);     // definido como zero (ativa o MPU-6050)
 Wire.endTransmission(true);
 Serial.println("Escreveu para IMU");
 Serial.println("Conectando à ");
 Serial.println(ssid);
 WiFi.begin(ssid, pass);
 while (WiFi.status() != WL_CONNECTED)
 {
    delay(500);
    Serial.print(".");              // imprimir ... até não estar conectado
 }
 Serial.println("");
 Serial.println("WiFi conectado");
 Serial.println("Endereço IP é: ");
 Serial.println(WiFi.localIP());
 server.begin();
 Serial.println("Servidor iniciado");
}

void loop(){
  mpu_read();
  WiFiClient client = server.available();
  if (client) 
  {                             
    Serial.println("new client"); 
    Serial.println(client.read());         
    String currentLine = "";      //Armazenando os dados de entrada na string
    while (client.connected()) 
    {            
      if (client.available())     //se houver alguns dados do cliente disponíveis
      {                
          char c = client.read();

         //if HTTP request has ended             // ler um byte
          if (c == '\n')                       // verifique o caractere de nova linha,
          {                     
            if (currentLine.length() == 0)      //se a linha estiver em branco, significa que é o fim da solicitação HTTP do cliente
            {     
              client.print("<html><title> ESP32 WebServer</title><meta charset=\"utf-8\"/></html>");
              client.print("<body bgcolor=\"#E6E6FA\"><h1 style=\"text-align: center; color: blue\"> ESP32 WebServer </h1>");
              client.print("<script>setTimeout(()=>{location.reload()}, 1000)</script>");
              client.print("<p style=\"text-align: left; color: red; font-size:150% \">Valores do acelerômetro: ");
              client.print("<p style=\"text-align: left; font-size:150% \">AcX: ");
              
              client.print(AcX);
              client.print("<br/>AcY: ");
              client.print(AcY);
              client.print("<br/>AcZ: ");
              client.print(AcZ);
              client.print("<p style=\"text-align: left; color: red; font-size:150% \">Valores do giroscópio: ");
              client.print("<p style=\"text-align: left; font-size:150% \">GyX: ");
              client.print(GyX);
              client.print("<br/>GyY: ");
              client.print(GyY);
              client.print("<br/>GyZ: ");
              client.print(GyZ);
              client.print("<p style=\"text-align: left; color: red; font-size:150% \">Acelerações: ");
              client.print(acelerou);
              client.print("</p><p style=\"text-align: left; color: red; font-size:150% \">Desacelerações: ");
              client.print(desacelerou);
              client.print("</p></body>");        
              break;  // sair do loop while:
            } else { // se você obteve uma nova linha, limpe currentLine:
              currentLine = "";
            }
          } else if (c != '\r') { // se você tiver qualquer outra coisa além de um caractere de retorno de carro,
            currentLine += c;     // adicione-o ao final da currentLine
          }
          readString="";
        }
      }
   }
}
void mpu_read(){
 Wire.beginTransmission(MPU_addr);
 Wire.write(0x3B);  // começando com o registro 0x3B (ACCEL_XOUT_H)
 Wire.endTransmission(false);
 Wire.requestFrom(MPU_addr,14,true);  // solicitar um total de 14 registros
 AcX=Wire.read()<<8|Wire.read();      // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
 AcY=Wire.read()<<8|Wire.read();      // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
 AcZ=Wire.read()<<8|Wire.read();      // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
 GyX=Wire.read()<<8|Wire.read();      // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
 GyY=Wire.read()<<8|Wire.read();      // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
 GyZ=Wire.read()<<8|Wire.read();      // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  if (!acelerando && AcX > 25000) {
    acelerou++;
    acelerando = true;
    };
    if (acelerando && AcX < 17000) {
      desacelerou++;
      acelerando = false;
    }

 
 Serial.print("Valores do acelerômetro: \n");
 Serial.print("AcX: "); 
 Serial.print(AcX); 
 Serial.print("\nAcY: "); 
 Serial.print(AcY); 
 Serial.print("\nAcZ: "); 
 Serial.print(AcZ);   
 Serial.print("\nValores do giroscópio: \n");
 Serial.print("GyX: "); 
 Serial.print(GyX); 
 Serial.print("\nGyY: "); 
 Serial.print(GyY); 
 Serial.print("\nGyZ: "); 
 Serial.print(GyZ);
 Serial.print("\n");
 delay(500);
}

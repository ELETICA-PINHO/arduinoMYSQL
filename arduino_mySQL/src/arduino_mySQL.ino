#include <SPI.h>
#include <Ethernet.h>
byte mac      [] = {0x00,0xAA,0xBB,0xCC,0xDE,0x02};
byte servidor [] = {192,168,0,109};
#define portaHTTP 80
//char servidor [] = ""; //
EthernetClient clienteArduino;

//======================================================================================
//sensores
/////gggggg

float sensor1 = 1;
float sensor2 = 2;
float sensor3 = 3;
//======================================================================================
void setup(){
  Serial.begin(9600);
  Ethernet.begin(mac);

  if(Ethernet.begin(mac) == 0 ){
    Serial.println("Falha ao conectar a rede ");
    Ethernet.begin(mac);
  }
  Serial.print("conectado a rede, no ip: ");
  Serial.println(Ethernet.localIP());
}

void loop(){
  if(clienteArduino.available()){
    char dados_Return = clienteArduino.read();
    Serial.print(dados_Return);
  }

  if(!clienteArduino.connected()){
    
    clienteArduino.stop();
  }

  char comando = Serial.read();


  if(comando == '1') {
	  sensor1 ++;
	  sensor2 ++;
	  sensor3 ++;

      Serial.println("conectando ao Servidor e enviado os dados: ");
	  Serial.print("Sensor1: ");
	  Serial.println(sensor1);
	  Serial.print("Sensor2: ");
	  Serial.println(sensor2);
	  Serial.print("Sensor3: ");
	  Serial.println(sensor3);

      
    if(clienteArduino.connect(servidor,portaHTTP)){
      
     //clienteArduino.println("GET /arduino1/teste.html HTTP/1.0");
	 //http://192.168.0.109/Dados_teste/teste.php?s1=20&s2=10&s3=15

    clienteArduino.print("GET /Dados_teste/salvar.php");
	  clienteArduino.print("?s1=");
	  clienteArduino.print(sensor1);
	  clienteArduino.print("&s2=");
	  clienteArduino.print(sensor2);
	  clienteArduino.print("&s3=");
	  clienteArduino.print(sensor3);
	  clienteArduino.println(" HTTP/1.0");

      clienteArduino.println("HOST: 192.168.0.109 ");
      clienteArduino.println("Connection: Close");
      clienteArduino.println();
    

    }else{
      Serial.println("Falha na conexão com servidor");
    }
  }
  
}
////////////////////////
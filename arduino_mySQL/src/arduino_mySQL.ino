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
      Serial.println("conectando ao Servidor");
      
    if(clienteArduino.connect(servidor,portaHTTP)){
      
     //clienteArduino.println("GET /arduino1/teste.html HTTP/1.0");
      clienteArduino.println("GET /Dados_teste/teste.php HTTP/1.0");
      clienteArduino.println("HOST: 192.168.0.109 ");
      clienteArduino.println("Connection: Close");
      clienteArduino.println();
    

    }else{
      Serial.println("Falha na conexão com servidor");
    }
  }
  
}
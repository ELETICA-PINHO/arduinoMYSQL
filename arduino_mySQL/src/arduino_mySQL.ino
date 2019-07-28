#include <SPI.h>
#include <Ethernet.h>
byte mac      [] = {0x00,0xAA,0xBB,0xCC,0xDE,0x02};
byte servidor [] = {192, 168, 0, 115};
//char servidor [] = ""; //
EthernetClient clienteArduino;

//======================================================================================
//sensores
/////gggggg
//======================================================================================
void setup(){
	Serial.begin(9600);
	Ethernet.begin(mac);

	if(Ethernet.begin(mac) ==0 ){
		Serial.println("Falha ao conectar a rede ");
		Ethernet.begin(mac);
	}
	Serial.print("conectado a rede , no ip: ");
	Serial.println(Ethernet.localIP());
}

void loop(){

    
}

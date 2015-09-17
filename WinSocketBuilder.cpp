#include"WinSocketBuilder.h"
WSADATA WinSocketBuilder::wsaData;
 WinSocketBuilder WinSocketBuilder::newInstance(){
	 int result=WSAStartup(MAKEWORD(2, 2), &wsaData);
	 if (result != SUCCESS){
		 throw ERROR_RESULT;
	 }
	 return  WinSocketBuilder();
}

 WinSocketBuilder WinSocketBuilder::setSocketType(int socketType){
	 this->socketType = socketType;
	 return *this;
 }

 WinSocketBuilder WinSocketBuilder::setProtocol(int protocolType){
	 this->protocolType = protocolType;
	 return *this;
 }
 WinSocketBuilder WinSocketBuilder::setAddressFamily(int addressFamily){
	 this->addressFamily = addressFamily;
	 return *this;
 }
 SOCKET WinSocketBuilder::build(){
	  SOCKET mSocket= socket(addressFamily, socketType, protocolType);
	  if (mSocket == INVALID_SOCKET){
		  throw WSAGetLastError();
	  }
	  return mSocket;
 }
 WinSocketBuilder::~WinSocketBuilder(){

 }
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SerialPort.h"

using namespace std;

//Portname must contain these backslashes, and remember to replace the following com port
char *port_name = "\\\\.\\COM2";

//String for incoming data
char incomingData[MAX_DATA_LENGTH];

//Evealuate Function
void test(string data)
{
  //RFID ID's for testing
  if(data == "2496848485551705465575149324968484855517054655751493" || data == "24968484855517054655751493" || data == "249684848555170546557514932496848485551705465575149324968484855517054655751493")
    {
      cout << "Test" << endl;
    }
}

int main()
{
  SerialPort arduino(port_name);
  if(arduino.isConnected())
    {
      cout << "Connection Established" << endl;
    }
  else
    {
      cout << "ERROR, check port name";
    }
  
  while(arduino.isConnected())
    {
      //Check if data has been read or not
      int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);
      //prints out data
      cout << incomingData << endl;
      //wait a bit
      Sleep(10000);
      if (incomingData[0] != '\0')
        {
          break;
        }
    }
  test(string(incomingData));
}
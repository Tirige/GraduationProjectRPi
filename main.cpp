/* 
 * File:   main.cpp
 * Author: IT College
 *
 * Created on 2015/08/10, 18:51
 */

#include <cstdlib>
#include <iostream>

#include "CommunicationManager.h"
#include "GpsSensor.h"
#include "MovieServerManager.h"

#include "wiringPi.h"
#include "wiringSerial.h"




void setup();
void loop();
void wiring_setup();

/*
 * 
 */

int serial_arduino;//Arduinoとの通信id

void setup()
{
    std::cout << "setup start" << std::endl; //debug
    wiring_setup();
    std::cout << "setup finish" << std::endl; //debug
}
void loop()
{
    std::cout << "loop_start" << std::endl; //debug
    while(1){
        CommunicationManager CM;
    CM.Arduino_Communication_Get();
    CM.Arduino_Communication_Send();
    //ホストPCとの通信に利用する　内部にBlueTooth,Wifiを持っている。
    CM.Host_Communication_Get();
    CM.Host_Communication_Send();
    
    std::cout << std::endl;//debugのため
    
    GpsSensor GS;
    GS.Gps_sensor_get();
    
    MovieServerManager MSM;
    MSM.Camera_Command();
    MSM.Server_Command();
        break;
    }
    std::cout << "loop_finish" << std::endl; //debug
}

void wiring_setup()
{
    std::cout << "wiringPi setup" << std::endl; //debug
    if(wiringPiSetup() == -1){
        std::cout << "wiringPi setup error" << std::endl;
    }else{ 
        serial_arduino = serialOpen("/dev/ttyUSB0",9600);//ls /dev/tty* にて確認できたUSB番号を入れる。
        if(serial_arduino < 0){//USBがつながらない場合はsudo rebootするとできるようになるかも
            std::cout << "wiringPi OK! but I can not open serialport" << std::endl;
        }else{
            std::cout << "wiringPi setup All finish" << std::endl;
        }
    }
}

int main(int argc, char** argv) {

    std::cout << "RPiDrone_Start" << std::endl; //debug
    return 0;
}


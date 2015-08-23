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
void communication_test();

CommunicationManager CM;
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

void communication_test(){
    //ここを弄ってほしいです
    //やってほしい事はcommunication_test内の　追加・修正
    //追加部分
        //Raspberry →　Host のための文章格納 (log)
    std::string str_host_get_test;
    
    while(!str_host_get_test.empty()){               //文字列が検出されるまでループ
      str_host_get_test= CM.Host_Communication_Get();
    }
    
    if(str_host_get_test == "up"){
        CM.Arduino_Communication_Send("up");
    }else if(str_host_get_test == "down"){
        CM.Arduino_Communication_Send("up");
    }else if(str_host_get_test == "hover"){
        CM.Arduino_Communication_Send("up");
    }else if(str_host_get_test == "take off"){
        CM.Arduino_Communication_Send("up");
    }else if(str_host_get_test == "land"){
        CM.Arduino_Communication_Send("up");
    }else{
        //error
        std::cout << "error read" << std::endl; //debug
        std::cout << "str_get_test" << std::endl; //debug
        return;
    }
    //エラーが検出された場合ここにはこない
    std::cout << "send finish" << std::endl; //debug
    
    
    //Arduinoからの受信処理
    std::string str_ard_get_test;
    while(!str_ard_get_test.empty()){               //文字列が検出されるまでループ
      str_ard_get_test= CM.Arduino_Communication_Get();
    }
    //受信したものをどこに置こうか？
    //とりあえず　logとして書き出す処理を入れる。
   
    
    return;
};

int main(int argc, char** argv) {

    std::cout << "RPiDrone_Start" << std::endl; //debug
    //test
    communication_test();
    
    return 0;
}


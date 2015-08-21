//通信制御クラス
//説明　　通信命令の総括クラスです。
//記載更新日/更新人物　0729/萩原

#include "CommunicationManager.h"
#include <fstream>
#include <iostream>




void CommunicationManager::Arduino_Communication_Get()
{
    std::cout << "Arduino_Get" << std::endl;
    int my_getchars;
    //serial_arduinoはmainにて宣言された物
    if(serialDataAvail(serial_arduino) > 0){
            delay(100);
            while(serialDataAvail(serial_arduino)){
                my_getchars = serialGetchar(serial_arduino);
                std::cout << (char)my_getchars;//本来はここに変数を置き記録する。
            }
            std::cout << std::endl;
    }
};

void CommunicationManager::Arduino_Communication_Send()
{
    std::cout << "Arduino_Send" << std::endl;
};

std::string CommunicationManager::Host_Communication_Get()
{
    //行数
    long i=0;
    long j=0;
    std::cout << "Host_Get" << std::endl;
    //ファイルの読み取り
    std::ifstream ifs1("/home/pi/myfiles/instruction/instruction.txt");
    std::ifstream ifs2("/home/pi/myfiles/instruction/instruction.txt");
    
    if (ifs1.fail())
    {
        std::cerr << "file_get_false" << std::endl;
       
    }
    if (ifs2.fail())
    {
        std::cerr << "file_get_false" << std::endl;
       
    }
    
    std::string str;
    std::string last_str;
    
    while (getline(ifs1, str))
    {
        std::cout << "[" << str << "]" << std::endl;
        i++;
    }
    
    while (getline(ifs2, str))
    {
        j++;
        if(j=i-1){
            last_str = str;
        }
    }
    
    std::cout<<last_str<< std::endl;

    
    
    return last_str;

};

void CommunicationManager::Host_Communication_Send()
{
    std::cout << "Host_Send" << std::endl;
    BCM.Bluetooth_send();
    WCM.Wifi_Send();
};







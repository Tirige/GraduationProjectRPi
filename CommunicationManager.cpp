//通信制御クラス
//説明　　通信命令の総括クラスです。
//記載更新日/更新人物　0729/萩原

#include "CommunicationManager.h"



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

void CommunicationManager::Host_Communication_Get()
{
    std::cout << "Host_Get" << std::endl;

};

void CommunicationManager::Host_Communication_Send()
{
    std::cout << "Host_Send" << std::endl;
    BCM.Bluetooth_send();
    WCM.Wifi_Send();
};







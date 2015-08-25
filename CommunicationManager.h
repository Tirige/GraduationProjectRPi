/* 
 * File:   CommunicationManager.h
 * Author: IT College
 *
 * Created on 2015/07/29, 13:45
 */

#ifndef COMMUNICATIONMANAGER_H
#define	COMMUNICATIONMANAGER_H

//デバッグに必要な物
#include <iostream>

#include "BluetoothCommunicationManager.h"
#include "WifiCommunicationManager.h"
#include "wiringPi.h"
#include "wiringSerial.h"
#include <string>


extern int serial_arduino;//Arduinoとの通信id

class CommunicationManager{
public:
    BluetoothCommunicationManager BCM;
    WifiCommunicationManager WCM;
    std::string Arduino_Communication_Get();
    void Arduino_Communication_Send(std::string send_string);
    void Host_Communication_Send();
    std::string Host_Communication_Get();
};

#endif	/* COMMUNICATIONMANAGER_H */

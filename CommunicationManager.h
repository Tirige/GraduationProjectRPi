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


extern int serial_arduino;//Arduinoとの通信id

class CommunicationManager{
public:
    BluetoothCommunicationManager BCM;
    WifiCommunicationManager WCM;
    void Arduino_Communication_Send();
    void Arduino_Communication_Get();
    void Host_Communication_Send();
    void Host_Communication_Get();
};

#endif	/* COMMUNICATIONMANAGER_H */


//
// Created by baptiste on 25/04/17.
//

//
// Created by baptiste on 20/03/17.
//
#include "LogManager.h"
#include "processLogger.h"

processLogger::processLogger(LogManager *logManager) : mLogManager(logManager) {}

void processLogger::operator()() {

    while (mLogManager->isItRunning()) {
        
    }

}

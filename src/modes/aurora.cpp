//
// Created by nzbr on 31.08.2019.
//

#include "include.h"
#include "aurora.h"

void auroraStep() {
    //Automatically switch mode to default on idle
    if (timestamp == (uint16_t)(lastUdpSignal+5000)) setMode(m_default);

    if (colorBuffer == nullptr) {
        colorBufferLength = 3;
        colorBuffer = (uint8_t*)malloc(sizeof(uint8_t)*colorBufferLength);
        colorBuffer[0] = 0; colorBuffer[1] = 0; colorBuffer[2] = 0;
    }

    for (int i = 0; i < LED_COUNT; i++) {
        int start = (3*i) % colorBufferLength;
        drvSetPixel(i, colorBuffer[start], colorBuffer[start+1], colorBuffer[start+2]);
    }
    drvShow();
}

void auroraFree() {
    colorBufferLength = -1;
    free(colorBuffer);
    colorBuffer = nullptr;
}
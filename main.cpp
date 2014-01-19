#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
#include <time.h>
#include <sndfile.h>
#include "SerialHandlerUnix.h"

const int BAUD_RATE = 9600;
const int SAMPLE_RATE = 44100;
const int SAMPLES = 44100;
std::string PORT = "/dev/ttyACM0";
const char* WAV_DIR = "square.wav";

void delay(int ms) {
    clock_t goal = ms + clock();
    while(goal > clock());
}

int main() {
    SF_INFO sfinfo;
    sfinfo.frames = 0;
    sfinfo.samplerate = SAMPLE_RATE;
    sfinfo.channels = 1;
    sfinfo.format = SF_FORMAT_WAV;

    SNDFILE* file;
    file = sf_open(WAV_DIR, SFM_READ, &sfinfo);

    int data_int[SAMPLES];
    sf_read_int(file, data_int, SAMPLES);

    unsigned char data[SAMPLES];
    for(unsigned int i = 0; i < SAMPLES; ++i) {
        data[i] = (float)data_int[i] / 16777216;
    }

    for(unsigned int i = 0; i < SAMPLES; ++i) {
        printf("%d\n", data[i]);
    }

	//SerialHandler serialHandler(PORT, BAUD_RATE);
    //serialHandler.writeSerial(data);
    delay(10000);

    sf_close(file);
	return 0;
}
#endif

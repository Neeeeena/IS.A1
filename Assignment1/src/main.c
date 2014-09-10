#include <stdio.h>
#include "sensor.h"

int sensorData[12];
int lowpassData[32];


int main() {


	for(int i = 0; i < 12; i++){
		sensorData[i] = getNextData();
	}


	return 0;

}

int lowPass(){
	int counter = 0;

	int sensorData0 = sensorData [(counter)%12];
	int sensorData5 = sensorData [(counter-5)%12];
	int sensorData11 = sensorData [(counter-11)%12];

	int lowpass0 = lowpassData [(counter)%32];
	int lowpass1 = lowpassData [(counter - 1)%32];

	return 2*lowpass0-lowpass1+1/32*(sensorData0-2*sensorData5+sensorData11);

	//temp = 2*lowpassData[0]-info[1]+1/32*(sensorData[0]-2*sensorData[5]+sensorData[11]);

	counter++;
}

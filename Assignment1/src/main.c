#include <stdio.h>
#include "sensor.h"

int sensorData[12];
int lowpassData[32];
int sIndex;
int lpIndex;


int main() {

	for(; sIndex < 11; sIndex++){
		sensorData[sIndex] = getNextData();
	}
	while((sensorData[sIndex%12] = getNextData())!=-1){
		printf("%d\n",lowPass());
		sIndex++;
	}

	return 0;

}

int lowPass(){

	int i = sIndex%12;

	int temp = 2*lowpassData[(lpIndex-1)%32]-lowpassData[(lpIndex-2)%32]+1/32*(sensorData[i]-2*sensorData[(5+i)%12]+sensorData[(11+i)%12]);
	lowpassData[(lpIndex)%12] = temp;
	lpIndex++;
	return temp;
	//temp = 2*lowpassData[0]-info[1]+1/32*(sensorData[0]-2*sensorData[5]+sensorData[11]);

}

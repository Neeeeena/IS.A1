#include <stdio.h>
#include "sensor.h"

int main() {
	int i0;


	i0 = getNextData();
	printf("%d\n", i0);
	i0 = getNextData();
	printf("%d\n", i0);

	return 0;

}

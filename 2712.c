#include <stdio.h>
#include <string.h>

int main () {
	int number, i, result[1000];
	char array[100];

	scanf ("%d", &number);
	getchar();

	for (i = 0; i < number; i++) {
		//getchar();
		scanf ("%s", array);
		//getchar();

		if (strlen(array) > 8)
			result[i] = 0;
		else if (array[0] < 65 || array[0] > 90 || array[1] < 65 || array[1] > 90 || array[2] < 65 || array[2] > 90 || array[3] != '-')
			result[i] = 0;
		else if (array[4] < 48 || array [4] > 57 || array[5] < 48 || array [5] > 57 || array[6] < 48 || array [6] > 57 || array[7] < 48 || array [7] > 57)
			result[i] = 0;
		else {
			if (array[7] == '1' || array[7] == '2')
				result[i] = 1;
			if (array[7] == '3' || array[7] == '4')
				result[i] = 2;
			if (array[7] == '5' || array[7] == '6')
				result[i] = 3;
			if (array[7] == '7' || array[7] == '8')
				result[i] = 4;
			if (array[7] == '9' || array[7] == '0')
				result[i] = 5;
		}
	}

	for (i = 0; i < number; i++) {
		if (result[i] == 0) {
			printf("FAILURE\n");
		}
		if (result[i] == 1) {
			printf("MONDAY\n");
		}
		if (result[i] == 2) {
			printf("TUESDAY\n");
		}
		if (result[i] == 3) {
			printf("WEDNESDAY\n");
		}
		if (result[i] == 4) {
			printf("THURSDAY\n");
		}
		if (result[i] == 5) {
			printf("FRIDAY\n");
		}
	}
	return 0;
}
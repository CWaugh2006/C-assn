#include <stdio.h>
#include <stdlib.h>

float median(float *numbers, int length){
	int i; 
	for(i = 1; i < length; i++){
		int j = i - 1;
		float swap = numbers[i];
		while (numbers[j] >= swap && j <= length){
			numbers[j-1] = numbers[j];
			j--;
		}
		numbers[j+1] = swap;
	}
	float med = 0;
	if(length % 2 == 0){
		med = (numbers[length/2] + numbers[length/2 - 1])/2;
	}
	else{
		med = numbers[length/2];
	}
	return med;
}
int main( int argc,char ** argv){
	int count = 0;
	scanf("%d", &count);
	if(count <= 0){
		return EXIT_FAILURE;
	}
	float data[count];
	int i = 0;
	while(i < count){
		float readIn = 0.0;
		scanf("\n%f", &readIn);
		data[i] = readIn;
		i = i + 1;
	}
	printf("Median is: %f\n", median(data, count));
	return EXIT_SUCCESS;
}



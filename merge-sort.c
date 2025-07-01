#include <stdio.h>
#include <math.h>

int *merge(int arr[], int rightArrIndex, int arrSize, int *mergedArr);
void printArr(int arr[], int arrSize);

int main(void) {
	int notMergedArr[] = { 7, 8, 1, 2 };
	int notMergedArrSize = sizeof(notMergedArr) / sizeof(notMergedArr[0]);
	int mergedArrSize = notMergedArrSize;
	int emptyMergedArr[mergedArrSize];
	int startIndex = 0;
	int *mergedArr = merge(notMergedArr, startIndex, mergedArrSize, emptyMergedArr);

	printArr(mergedArr, mergedArrSize);
	return 0;
}

int *merge(int arr[], int leftArrIndex, int arrSize, int *mergedArr) {
	float sum = leftArrIndex + arrSize;
	int midIndex = round( sum / (2 * 1.0f) );
	int rightArrIndex = arrSize - midIndex;
	int mergedArrIndex = 0;

	while (leftArrIndex < midIndex && rightArrIndex < arrSize) {
		int leftValue = arr[leftArrIndex];
		int rightValue = arr[rightArrIndex];

		if (leftValue < rightValue) {
			mergedArr[mergedArrIndex] = leftValue;
			leftArrIndex++;
		} else {
			mergedArr[mergedArrIndex] = rightValue;
			rightArrIndex++;
		}
		
		mergedArrIndex++;
	}

	while (leftArrIndex < midIndex) {
		int leftValue = arr[leftArrIndex];

		mergedArr[mergedArrIndex] = leftValue;
		leftArrIndex++;
		mergedArrIndex++;
	}

	while (rightArrIndex < arrSize) {
		int rightValue = arr[rightArrIndex];

		mergedArr[mergedArrIndex] = rightValue;
		rightArrIndex++;
		mergedArrIndex++;
	}

	return mergedArr;
}

void printArr(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		int number = arr[i];
		printf("%d\n", number);
	}

	printf("\n");
}

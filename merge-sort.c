#include <stdio.h>
#include <math.h>

int *merge_sort(int *unsortedArr, int unsortedArrSize, int startIndex, int arrLastPosition, int *sortedArr);
int *merge(int arr[], int startIndex, int arrLastPosition, int *mergedArr);
void printArr(int arr[], int arrSize);

int main(void) {
	/*int unsortedArrSize = sizeof(unsortedArr) / sizeof(unsortedArr[0]);
	int sortedArrSize = unsortedArrSize;
	int startIndex = 7;
	int shiftFromLeft = 4;
	int sortedArrEndIndex = sortedArrSize - shiftFromLeft;
	int newSortedArrSize = sortedArrSize - (startIndex + shiftFromLeft);
	int emptySortedArr[newSortedArrSize];
	int *sortedArr = merge(unsortedArr, startIndex, sortedArrEndIndex, emptySortedArr);
	*/

	int unsortedArr[] = { 6, 8, 7, 0, 1, 5, 9, 11, 10, 3, 12, 2, 4 };
	int unsortedArrSize = sizeof(unsortedArr) / sizeof(unsortedArr[0]);
	int sortedArrSize = unsortedArrSize;
	int emptySortedArr[sortedArrSize];
	int startIndex = 0;
	int *sortedArr = merge_sort(unsortedArr, unsortedArrSize, startIndex, sortedArrSize, emptySortedArr);

	printArr(sortedArr, sortedArrSize);
	return 0;
}

int *merge_sort(int *unsortedArr, int unsortedArrSize, int startIndex, int arrLastPosition, int *sortedArr) {
	if (startIndex < arrLastPosition) {
		int midIndex = (startIndex + arrLastPosition) / 2;

		merge_sort(unsortedArr, unsortedArrSize, startIndex + 1, midIndex, sortedArr);
		merge_sort(unsortedArr, unsortedArrSize, midIndex + 1, arrLastPosition, sortedArr);
		for (int i = 0; i < unsortedArrSize; i++) {
			sortedArr[i] = unsortedArr[i];
		}
		sortedArr = merge(sortedArr, startIndex, arrLastPosition, sortedArr);
		for (int i = 0; i < unsortedArrSize; i++) {
			unsortedArr[i] = sortedArr[i];
		}
	}

	return sortedArr;
}

int *merge(int arr[], int startIndex, int arrLastPosition, int *mergedArr) {
	int size = arrLastPosition - startIndex;
	if (size == 1) {
		mergedArr[0] = arr[startIndex];
		return mergedArr;
	}
	int midIndex = (size / 2) + startIndex;
	int rightArrIndex = midIndex;
	int mergedArrIndex = 0;

	while (startIndex < midIndex && rightArrIndex < arrLastPosition) {
		int leftValue = arr[startIndex];
		int rightValue = arr[rightArrIndex];
		printf("%d %d\n", leftValue, rightValue);

		if (leftValue < rightValue) {
			mergedArr[mergedArrIndex] = leftValue;
			startIndex++;
		} else {
			mergedArr[mergedArrIndex] = rightValue;
			rightArrIndex++;
		}
		
		mergedArrIndex++;
	}

	while (startIndex < midIndex) {
		int leftValue = arr[startIndex];

		mergedArr[mergedArrIndex] = leftValue;
		startIndex++;
		mergedArrIndex++;
	}

	while (rightArrIndex < arrLastPosition) {
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

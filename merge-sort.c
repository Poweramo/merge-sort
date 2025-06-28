#include <stdio.h>
#include <math.h>

void merge_sort(int unsortedArr[], int unsortedArrSize);
void printArr(int arr[], int arrSize);
void test(int leftUnsortedArr[], int leftUnsortedArrSize, int rightUnsortedArr[], int rightUnsortedArrSize);

int main(void) {
	int unsortedArr[] = { 6, 8, 7, 0, 1, 5, 9, 11, 10, 3, 12, 2, 4 };
	int unsortedArrSize = sizeof(unsortedArr) / sizeof(unsortedArr[0]);
	merge_sort(unsortedArr, unsortedArrSize);
	
	return 0;
}

void printArr(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		int number = arr[i];
		printf("%d\n", number);
	}
	printf("\n");
}

void merge_sort(int unsortedArr[], int unsortedArrSize) {
	if (unsortedArrSize <= 1) return;

	int halfUnsortedArrSize = round(unsortedArrSize / 2);
	int leftUnsortedArrSize = halfUnsortedArrSize;
	int rightUnsortedArrSize = halfUnsortedArrSize;
	if (unsortedArrSize % 2 == 1) leftUnsortedArrSize++;
	int leftUnsortedArr[leftUnsortedArrSize];
	int rightUnsortedArr[rightUnsortedArrSize];

	for (int i = 0; i < unsortedArrSize; i++) {
		if (i < leftUnsortedArrSize) {
			leftUnsortedArr[i] = unsortedArr[i];
		} else {
			rightUnsortedArr[i - leftUnsortedArrSize] = unsortedArr[i];
		}
	}

	merge_sort(leftUnsortedArr, leftUnsortedArrSize);
	merge_sort(rightUnsortedArr, rightUnsortedArrSize);

	int mergedArr[leftUnsortedArrSize + rightUnsortedArrSize];
	int mergedArrIndex = 0;
	int leftArrIndex = 0;
	int rightArrIndex = 0;

	while (leftArrIndex < leftUnsortedArrSize || rightArrIndex < rightUnsortedArrSize) {
		int leftNum = leftUnsortedArr[leftArrIndex];
		int rightNum = rightUnsortedArr[rightArrIndex];

		if (rightArrIndex >= rightUnsortedArrSize) {
			mergedArr[mergedArrIndex] = leftNum;
			leftArrIndex++;
		} else if (leftArrIndex >= leftUnsortedArrSize) {
			mergedArr[mergedArrIndex] = rightNum;
			rightArrIndex++;
		} else if (leftNum < rightNum) {
			mergedArr[mergedArrIndex] = leftNum;
			leftArrIndex++;
		} else {
			mergedArr[mergedArrIndex] = rightNum;
			rightArrIndex++;
		}

		mergedArrIndex++;
	}

	printArr(mergedArr, leftUnsortedArrSize + rightUnsortedArrSize);
}

void test(int leftUnsortedArr[], int leftUnsortedArrSize, int rightUnsortedArr[], int rightUnsortedArrSize) {
	int mergedArr[leftUnsortedArrSize + rightUnsortedArrSize];
	int mergedArrIndex = 0;
	int leftArrIndex = 0;
	int rightArrIndex = 0;

	while (leftArrIndex < leftUnsortedArrSize || rightArrIndex < rightUnsortedArrSize) {
		int leftNum = leftUnsortedArr[leftArrIndex];
		int rightNum = rightUnsortedArr[rightArrIndex];

		if (rightArrIndex >= rightUnsortedArrSize) {
			mergedArr[mergedArrIndex] = leftNum;
			leftArrIndex++;
		} else if (leftArrIndex >= leftUnsortedArrSize) {
			mergedArr[mergedArrIndex] = rightNum;
			rightArrIndex++;
		} else if (leftNum < rightNum) {
			mergedArr[mergedArrIndex] = leftNum;
			leftArrIndex++;
		} else {
			mergedArr[mergedArrIndex] = rightNum;
			rightArrIndex++;
		}

		mergedArrIndex++;
	}

	printArr(mergedArr, leftUnsortedArrSize + rightUnsortedArrSize);
}

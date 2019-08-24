

// Program Name: project1.cpp
// Programmer:Altaf Maknojia ID:1585971
// Assignment Number: Project #1 ordered arrays as objects
// Purpose: This program will merge 2 order arrays into one. it will count duplicates as one. it will also outoput the common valuse from the two ordered arrays. 

#include <iostream>

using namespace std;

int merge(int* a, int sizeA, int* b, int sizeB, int *result) {
	int i = 0, j = 0, count = 0;
	int last = -1;

	while (i < sizeA && j < sizeB) {
		if (a[i] < b[j]) {
			if (a[i] != last) {
				result[count++] = a[i];
				last = a[i];
			}
			i++;
		}
		else if (a[i] > b[j]) {
			if (b[j] != last) {
				result[count++] = b[j];
				last = b[j];
			}
			j++;
		}
		else {
			if (b[j] != last) {
				result[count++] = b[j];
				last = b[j];
			}
			j++;
			i++;
		}
	}

	if (i == sizeA) {
		while (j < sizeB) {
			if (b[j] != last) {
				result[count++] = b[j];
				last = b[j];
			}
			j++;
		}
	}
	else if (j == sizeB) {
		while (i < sizeA) {
			if (a[i] != last) {
				result[count++] = a[i];
				last = a[i];
			}
			i++;
		}
	}

	
	return count;
}

int common(int* a, int sizeA, int* b, int sizeB, int *result) {

	int i = 0, j = 0, count = 0;
	int last = -1;

	while (i < sizeA && j < sizeB) {
		if (a[i] < b[j]) {
			i++;
		}
		else if (a[i] > b[j]) {
			j++;
		}
		else {
			if (b[j] != last) {
				result[count++] = b[j];
				last = b[j];
			}
			j++;
			i++;
		}
	}

	return count;
}

int main() {
	int A[] = { 3, 6, 8, 8, 11, 17, 25, 34, 38, 46, 48, 48, 48, 57, 62, 69, 72, 72, 77, 83 };

	int B[] = { 5, 8, 14, 25, 31, 37, 41, 48, 48, 52, 77, 82, 94 };

	int result[100];

	cout << "Merged Array:" << endl;
	int mergedSize = merge(A, 20, B, 13, result);

	for (int i = 0; i<mergedSize; i++) {
		cout << result[i] << " ";
	}

	cout << "\n\nCommon Array:" << endl;
	int commonSize = common(A, 20, B, 13, result);

	for (int i = 0; i<commonSize; i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("PAUSE");
}

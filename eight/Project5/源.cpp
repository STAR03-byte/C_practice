#include<iostream>
using namespace std;

void selectSort(int a[],int n) {
	int i, j, index;
	for (i = 0; i <n - 1; i++) {
		index = i;
		for (j = i + 1; j < n; j++) {
			if (a[index] > a[j]) {
				index = j;
			}
		}
	int temp = a[i];
	a[i] = a[index];
	a[index] = temp;
		
	}
}

void display(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int n=9;
	int arr[9] = { 4,5,2,1,13,7,43,98,2 };

	selectSort(arr,n);
	display(arr, n);

	return 0;
}
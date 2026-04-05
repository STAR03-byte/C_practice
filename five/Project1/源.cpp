#include<iostream>
using namespace std;

void maopao(int arr[],int size) {
	int j, bound, exchange = size - 1;
       while(exchange!=0) {
	   bound = exchange;
	   exchange = 0;
		for (int j = 0; j < bound; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				exchange = j;
			}
		}
	}
}

void display(int arr[],int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[9] = { 4,5,2,1,13,7,43,98,2 };
	int size = sizeof(arr) / sizeof(arr[0]);

	display(arr,size);
	maopao(arr,size);
	display(arr, size);

	return 0;
}
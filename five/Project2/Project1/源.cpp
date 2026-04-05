#include<iostream>
using namespace std;

static void bubblesort(int *p,int size) {
	for(int i =0;i< size-1;i++){
		for (int j = 0; j < size - i - 1; j++) {
			if (p[j] > p[j + 1]) {
				int temp = p[j];
				p[j] = p[j + 1];
				p[j+1] = temp;
			}
		}
	}
}

static void display(int* p, int size) {
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}

int main(){
	int arr[10] = { 5,1,33,6,3,45,78,9,26,2 };
	int* p = arr;
	int size = sizeof(arr) / sizeof(arr[0]);

	bubblesort(arr, size);
	display(arr, size);

	return 0;
}
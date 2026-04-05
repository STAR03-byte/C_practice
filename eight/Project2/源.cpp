#include<iostream>
using namespace std;

int search(int a[], int n, int k) {
	int i = n;
	a[0] = k;
	while (a[i] != k) {
		i--;
	}
	return i;
}

void display(int a[], int n) {
	for (int i = 0; i <= n-1; i++) {
		cout << a[i] << " ";
		
	}
	cout << endl;
}

int main() {
	int a[] = { 10,21,78,44,35,89,23 };
	int result =search(a, 6, 23);
	cout << result << endl;
	display(a, 7);
	return 0;
}
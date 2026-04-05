#include<iostream>
using namespace std;

int Partition(int r[],int first,int end) {
	int temp, i = first, j = end;
	while (i<j) {
		while (i < j && r[i] <= r[j]) j--;//ÓÒ²àÉ¨Ãè
		if (i < j) {
			temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			i++;
		}
		while (i < j && r[i] <= r[j]) i++;//×ó²àÉ¨Ãè
		if (i < j) {
			temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			j--;
		}
	}
	return i;
}

void QuickSort(int r[],int first,int end) {
	if (first < end) {
		int pivot = Partition(r, first, end);//ÖáÖµÎ»ÖÃ
		QuickSort(r, first, pivot-1);//×ó²à¿ìÅÅ
		QuickSort(r, pivot + 1, end);//ÓÒ²à¿ìÅÅ
	}
}

int main() {
	int r[] = { 5, 3, 8, 4, 2, 7, 1, 6 };
	int n = sizeof(r) / sizeof(r[0]);

	QuickSort(r, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << r[i] << " ";
	}
	cout << endl;

	return 0;
}
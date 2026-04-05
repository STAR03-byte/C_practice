#include<iostream>
using namespace std;

int MaxSum(int a[], int left, int right) {
	int sum = 0, midsum = 0, leftsum = 0, rightsum = 0;
	int i, center, s1, s2, lefts, rights;
	if (left == right) {
		sum = a[left];
	}
	else {//递归划分到最小只剩一个元素
		center = (left + right) / 2;
		leftsum = MaxSum(a, left, center);
		rightsum = MaxSum(a, center + 1, right);

		s1 = 0; lefts = 0;//计算中点左侧的最大子段和 
		for (i = center; i >= left; i--) {
			lefts += a[i];
			if (lefts > s1) s1 = lefts;
		}

		s2 = 0; rights = 0;//计算中点右侧的最大子段和
		for (i = center + 1; i <= right; i++) {
			rights += a[i];
			if (rights > s2) s2 = rights;
		}

		midsum = s1 + s2;//判断中间的和是否大于左侧与右侧
		if (midsum < leftsum)sum = leftsum;
		else sum = midsum;
		if (sum < rightsum)sum = rightsum;
	}
	return sum;//结果
}

int main() {
	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int max_sum = MaxSum(arr, 0, n - 1);
	cout << "最大子数组和为: " << max_sum << endl;  // 输出应为6（子数组[4, -1, 2, 1]）


	return 0;
}
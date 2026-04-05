#include <iostream>
using namespace std;

const int MAX_N = 10000;
int arr[MAX_N];
int temp[MAX_N];

int partition(int nums[], int left, int right) {
    int pivot = nums[right];
    int i = left;
    for (int j = left; j < right; ++j) {
        if (nums[j] > pivot) {
            swap(nums[i], nums[j]);
            ++i;
        }
    }
    swap(nums[i], nums[right]);
    return i;
}

int quickSelect(int nums[], int left, int right, int k) {
    while (left <= right) {
        int pos = partition(nums, left, right);
        if (pos == k - 1) {
            return nums[pos];
        }
        else if (pos < k - 1) {
            left = pos + 1;
        }
        else {
            right = pos - 1;
        }
    }
    return -1;
}

int main() {
    int n, m;
    // 循环处理多组输入
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        for (int q = 0; q < m; ++q) {
            int k;
            cin >> k;
            if (k > n) {
                cout << -1 << endl;
            }
            else {
                for (int i = 0; i < n; ++i) temp[i] = arr[i];
                cout << quickSelect(temp, 0, n - 1, k) << endl;
            }
        }
    }

    return 0;
}

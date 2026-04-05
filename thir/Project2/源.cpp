#include <iostream>
using namespace std;

int maxSum(int a[], int left, int mid, int right) {
    int sum = 0;
    int leftSum = -1000000;
    for (int i = mid; i >= left; --i) {
        sum += a[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = -1000000;
    for (int i = mid + 1; i <= right; ++i) {
        sum += a[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSub(int a[], int left, int right) {
    if (left == right)
        return a[left];

    int mid = (left + right) / 2;

    int leftMax = maxSub(a, left, mid);
    int rightMax = maxSub(a, mid + 1, right);
    int crossMax = maxSum(a, left, mid, right);


    int maxVal = leftMax;
    if (rightMax > maxVal)
        maxVal = rightMax;
    if (crossMax > maxVal)
        maxVal = crossMax;
    return maxVal;
}

int main() {
    int n;
    while (cin >> n) {
        int a[1000]; 
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        cout << maxSub(a, 0, n - 1) << endl;
    }

    return 0;
}

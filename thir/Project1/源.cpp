#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int a[1000]; 
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int maxSum = -1000000;  
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int currentSum = 0;
                for (int k = i; k <= j; ++k) {
                    currentSum += a[k];
                }
                if (currentSum > maxSum) {
                    maxSum = currentSum;
                }
            }
        }

        cout << maxSum << endl;
    }

    return 0;
}

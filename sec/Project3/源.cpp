#include <iostream>

using namespace std;

long long count_zeros(long long n) {
    long long count = 0;
    for (long long i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x;
    while (cin >> x) {
        long long res = -1;
        long long low = 0;
        long long high = 5LL * x;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long zeros = count_zeros(mid);

            if (zeros >= x) {
                if (zeros == x) res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        cout << res << endl;
    }

    return 0;
}
#include<iostream>
using namespace std;

const int MAX = 1001;
int dp[MAX][MAX];

int main() {
    string x, y;
    cin >> x >> y;
    int n = x.length();
    int m = y.length();

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}

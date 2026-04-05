#include<iostream>
using namespace std;

const int MAXV = 10001;
int dp[MAXV];

int main() {
    int V, N;
    cin >> V >> N;

    int w[100], v[100];

    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = w[i]; j <= V; ++j) {
            if (dp[j] < dp[j - w[i]] + v[i])
                dp[j] = dp[j - w[i]] + v[i];
        }
    }

    cout << dp[V] << endl;
    return 0;
}

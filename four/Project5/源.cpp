#include<iostream>
using namespace std;

const int MAX = 21;
int dp[MAX][MAX];     
bool blocked[MAX][MAX];  

int main() {
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    int dx[9] = { 0,  2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[9] = { 0, 1, 2,  2,  1, -1, -2, -2, -1 };

    for (int i = 0; i < 9; i++) {
        int x = bx + dx[i];
        int y = by + dy[i];
        if (x >= 0 && x <= ax && y >= 0 && y <= ay) {
            blocked[x][y] = true;
        }
    }

    dp[0][0] = blocked[0][0] ? 0 : 1;

    for (int i = 0; i <= ax; i++) {
        for (int j = 0; j <= ay; j++) {
            if (blocked[i][j]) continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[ax][ay] << endl;
    return 0;
}

#include <iostream>
using namespace std;

void Hanio(int n, char A, char B, char C) {
    if (n == 1) {
        cout << A << "-->" << C << "\t";
    }
    else {
        Hanio(n - 1, A, C, B);
        cout << A << "-->" << C << "\t";
        Hanio(n - 1, B, A, C);
    }
}

int main() {
    int n = 3;  // 可修改 n 的值测试不同数量碟子的情况
    Hanio(n, 'A', 'B', 'C');
    return 0;
}

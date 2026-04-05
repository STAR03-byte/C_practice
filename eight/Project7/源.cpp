#include<iostream>
using namespace std;

void Merge(int r[], int s, int t, int m) {
    int len = t - s + 1;
    int* r1 = new int[len];
    int i = s, j = m + 1, k = 0;

    while (i <= m && j <= t) {
        if (r[i] < r[j]) {
            r1[k++] = r[i++];
        }
        else {
            r1[k++] = r[j++];
        }
    }
    while (i <= m) {
        r1[k++] = r[i++];
    }
    while (j <= t) {
        r1[k++] = r[j++];
    }
    for (i = 0; i < len; i++) {  // 修正：从0到len-1遍历r1
        r[s + i] = r1[i];         // 修正：写入r[s+i]而非r[i]
    }
    delete[] r1;
}

void mergeSort(int r[], int s, int t) {
    if (s == t) {
        return;
    }
    else {
        int m = s + (t - s) / 2;  // 优化：防止整数溢出
        mergeSort(r, s, m);
        mergeSort(r, m + 1, t);
        Merge(r, s, t, m);
    }
}

int main() {
    int r[] = { 1,3,4,2,1,6,7,8,3 };
    mergeSort(r, 0, 8);
    for (int i = 0; i <= 8; i++) {
        cout << r[i] << " ";
    }
    cout << endl;
    return 0;
}
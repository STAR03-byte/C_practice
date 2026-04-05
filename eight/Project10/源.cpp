#include<iostream>
using namespace std;

int LCS(char x[],int m,char y[],int n,char z[]) {
	int i, j, k, l[m + 1][n + 1], s[m + 1][n + 1];
	for (j = 0; j <= n; j++) {
		l[0][j] = 0;
	}
	for (i = 0; i <= m; i++) {
		l[i][0] = 0;
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (x[i] == y[i]) {
				l[i][i] = l[i - 1][j - 1]+1;
				s[i][j] = 1;
			}
			else if (l[i][j - 1] >= l[i - 1][j]) {
				l[i][j] = l[i][j - 1];
				s[i][j] = 2;
			}
			else {
				l[i][j] = l[i - 1][j];
				s[i][j] = 3;
			}
		}
	}
	i = m; j = n; k = l[m][n];
	while (i > 0 && j > 0) {
		if (s[i][j] == 1) {
			z[--k] = x[i];
			--i;
			--j;
		}
		else if (s[i][j] == 2) {
			--j;
		}
		else {
			--i;
		}
	}
	return l[m][n];
}
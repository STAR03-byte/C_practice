#include<iostream>
using namespace std;

int  BF(const string& s,const string& t) {
	int m = s.length();
	int n = t.length();
	for (int i = 0; i <= m - n; i++) {
		int j;
		for ( j = 0; j <=n; j++) {
			if (s[i + j] != t[j]) {
				break;
			}
		}
		if (j == n) {
			return i;
		}
	}
	return -1;
}

int main() {
	string s = "abdedtuhgfkbhhhs";
	string t = "tuhgf";
	int result = BF(s,t);
	cout << "开始匹配的是第:"<<result+1 <<"个字母"<< endl;
	return 0;
}


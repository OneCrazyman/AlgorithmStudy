#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int T;

int rec(int n) {
	if (n == 0) {
		return 1;
	}
	else if (n < 0) {
		return 0;
	}
	return rec(n - 1) + rec(n - 2) + rec(n - 3);
}

void sum_combination() {
	int n;
	cin >> n;
	cout << rec(n) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		sum_combination();
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;
int N;
int stair[300];
map<pair<int, bool>, int> memo;

int fullSearch(int n, bool flag) {
	auto key = make_pair(n, flag);
	if (memo.find(key) != memo.end()) {
		return memo[key];
	}
	if (n >= N) {
		return 0;
	}
	if  (flag) {
		memo[key] = (stair[n] + fullSearch(n + 2, false));
		return memo[key];
	}
	else {
		memo[key] = (stair[n] + max(fullSearch(n + 1, true), fullSearch(n + 2, false)));
		return memo[key];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = N-1; i >= 0; i--)
	{
		int n;
		cin >> n;
		stair[i] = n;
	}

	cout << fullSearch(0,0);

	return 0;
}
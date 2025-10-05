#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int T;
long long dp[101];

void calculateDp() {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i < 101; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	
	/*for (const auto& a : dp) {
		cout << a << " ";
	}*/
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	freopen("input.txt", "r", stdin);

	calculateDp();

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		cout << dp[N] << "\n";
	}
}
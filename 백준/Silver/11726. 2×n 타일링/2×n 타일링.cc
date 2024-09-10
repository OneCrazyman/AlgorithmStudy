#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int N;
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);

	cin >> N;

	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}

	cout << dp[N];
}

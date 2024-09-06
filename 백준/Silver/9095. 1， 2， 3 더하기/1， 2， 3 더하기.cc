#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

int T;
int dp[12] = { 0 };

void sum_combination() {
	int n;
	cin >> n;
	cout << dp[n] << "\n";
}

void calculate_dp() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);

	calculate_dp();
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		sum_combination();
	}
}
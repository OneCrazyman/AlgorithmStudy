#include <iostream>
using namespace std;
#define MAX_N 100'001

int N, M;
int arrN[MAX_N];
int dp[MAX_N];

void printResult() {
	for (int num = 0; num < M; num++)
	{
		int i, j;
		int result = 0;
 		cin >> i >> j;
		result = dp[j] - dp[i-1];
		cout << result << "\n";
	}
}

void calculateDp(){
	cin >> N >> M;
	dp[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		int tmp;
		cin >> tmp;
		dp[i] = dp[i - 1] + tmp;
	}
}

int main() {
	//FILE* stream;
	//freopen_s(&stream, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	calculateDp();
	printResult();
	
	return 0;
}
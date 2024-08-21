#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int arr[(int)1e6 + 1];
int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	int n;
	cin >> n;

	for (int i = 4; i <= n; i++)
	{
		arr[i] = arr[i - 1] + 1;

		//2 로 나누어진다면, 그에 따른 최솟값 비교 
		if (i % 2 == 0) {
			arr[i] = min(arr[i / 2] + 1, arr[i]);
		}

		//3 ""
		if (i % 3 == 0) {
			arr[i] = min(arr[i / 3] + 1, arr[i]);
		}
	}
	cout << arr[n];

	return 0;
}
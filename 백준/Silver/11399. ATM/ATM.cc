#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int ptrArr[1000];

	for (int i = 0; i < N; i++)
	{
		cin >> ptrArr[i];
	}
	
	sort(ptrArr, ptrArr+N);

	int result = 0, tmp = 0;

	for (int i = 0; i < N; i++) {
		tmp += ptrArr[i];
		result += tmp;
	}

	cout << result << endl;
}
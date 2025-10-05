#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<int, string> IntToString;
unordered_map<string, int> StringToInt;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i < N+1; i++)
	{
		string s;
		cin >> s;

		IntToString[i] = s;
		StringToInt[s] = i;
	}

	for (int i = 0; i < M; i++)
	{
		string w;
		cin >> w;
		
		// 숫자이면
		if (isdigit(w[0])) {
			int n = stoi(w);
			cout << IntToString[n] << "\n";
		}
		// 문자이면 
		else if (isalpha(w[0])) {
			cout << StringToInt[w] << "\n";
		}
	}
	return 0;
}
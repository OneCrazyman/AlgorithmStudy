#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	 
	int N, M;
	cin >> N;
	cin >> M;
	
	string* ptrN = new string[N];
	string* ptrM = new string[M];
	vector<string> vec;

	for (int i = 0; i < N; i++)
	{
		cin >> ptrN[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> ptrM[i];
	}

	unordered_set<string> setN(ptrN, ptrN + N);
	unordered_set<string> setM(ptrM, ptrM + M);

	for (const auto& m : setM) {
		if (setN.find(m) != setN.end()) {
			vec.push_back(m);
		}
	}

	sort(vec.begin(), vec.end());
	cout << vec.size() << "\n";

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << "\n";
	}

	return 0;
}
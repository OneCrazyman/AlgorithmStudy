#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <vector>
#include <ios>

using namespace std;
vector<pair<int, int>> vec;

void TOH(int n, int a, int b, int c) {
	if (n == 1) {
		vec.push_back(make_pair(a, c));
	}
	else {
		TOH(n - 1, a, c, b);
		vec.push_back(make_pair(a, c));
		TOH(n - 1, b, a, c);
	}
}

void Print() {
	cout << vec.size() << "\n";
	for (const auto& pair : vec) {
		cout << pair.first << " " << pair.second << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	TOH(N,1,2,3);
	Print();
	return 0;
}
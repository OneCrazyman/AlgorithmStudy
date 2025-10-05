#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>

using namespace std;
int N, M;
unordered_map<string, string> ssmap;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		ssmap[s1] = s2;
	}

	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		cout << ssmap[s] << "\n";
	}
}
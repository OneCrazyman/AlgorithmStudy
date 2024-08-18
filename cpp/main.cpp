#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_set>
#include <vector>
#include <numeric>
using namespace std;

int BIT = 0;

void add();
void remove();
void check();
void toggle();
void all();
void empty();

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	freopen("input.txt", "r", stdin);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s == "add") add();
		else if (s == "remove") remove();
		else if (s == "check") check();
		else if (s == "toggle") toggle();
		else if (s == "all") all();
		else if (s == "empty") empty();
	}
	return 0;
}

void add() {
	int i;
	cin >> i;
	BIT |= (1 << i);
}
void remove() {
	int i;
	cin >> i;
	BIT &= ~(1 << i);
}
void check() {
	int i;
	cin >> i;
	if (BIT & (1 << i)) cout << 1 << "\n";
	else cout << 0 << "\n";
}
void toggle() {
	int i;
	cin >> i;
	BIT ^= (1 << i);
}
void all() {
	BIT = (1 << 21) - 1;
}
void empty() {
	BIT = 0;
}
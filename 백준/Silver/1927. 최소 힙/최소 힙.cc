#include <iostream>
#include <queue>
using namespace std;
int N;
int main() {
	//FILE* stream;
	//freopen_s(&stream, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> min_heap;

	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		if (val == 0) {
			if (min_heap.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << min_heap.top() << "\n";
				min_heap.pop();
			}
		}
		else {
			min_heap.push(val);
		}
	}
	return 0;
}
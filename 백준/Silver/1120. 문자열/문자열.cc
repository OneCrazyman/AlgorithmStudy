#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string a;
string b;

int main() {
	//freopen("input.txt", "r", stdin);

	cin >> a >> b;

	// 결과 출력
	//std::cout << "First string: " << a << std::endl;
	//std::cout << "Second string: " << b << std::endl;

	int count;
	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= b.length() - a.length(); i++)
	{
		count = 0;
		for (int j = 0; j < a.length(); j++) {
			//cout << a[j] << " " << b[i + j] << endl;
			if (a[j] != b[i+j])
				count++;
		}
		ans = min(ans, count);
	}
	//answer
	cout << ans;
	return 0;
}
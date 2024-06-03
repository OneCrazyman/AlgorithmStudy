#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
string input;
string a;
string b;

int main() {
	//freopen("input.txt", "r", stdin);

	getline(cin, input);
	istringstream iss(input);

	iss >> a >> b;

	// 결과 출력
	//std::cout << "First string: " << a << std::endl;
	//std::cout << "Second string: " << b << std::endl;

	int count = 0;
	if (a.length() == b.length()) 
	{
		for (int i = 0; i < a.length(); i++)
			if (a[i] != b[i]) 
				count++;
	}
	else
	{
		int diff_num = b.length() - a.length();
		int min = 99999;
		for (int i = 0; i <= diff_num; i++)
		{
			count = 0;
			for (int j = 0; j < a.length(); j++) {
				//cout << a[j] << " " << b[i + j] << endl;
				if (a[j] != b[i+j])
					count++;
			}
			if (min > count) {
				min = count;
			}
		}
		count = min;
	}
	//answer
	cout << count;
	return 0;
}
/* 
1. 아이디어
	정수의 범위가 1~1000, 수열 공식대로 배열을 채우고, 원소로 직접 접근하여 무식하게 더해보자

2. 시간복잡도
	삽입할 배열 수 1+2+3+ ... n개 (1+n)*n/2 = n^2+n 만큼 삽입 
	

3. 자료구조
	int[], int sum
*/

#include <iostream>
#include <fstream>
#include <vector>
int A;
int B;
std::vector<int> arr; 

int main() {
	std::ios_base::sync_with_stdio(false);
	std::ifstream cin;
	cin.open("input.txt");

	std::cin >> A >> B;
	
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 0; j < i; j++)
		{
			arr.push_back(i);
		}
	}

	int sum = 0;
	auto it = arr.begin();
	int count = 1;
	for (;it != arr.end();++it)
	{
		if (count == A) break;
		count++;
	}
	for (int i = 0; i < B - A + 1; i++)
	{
		sum += *it;
		++it;
	}

	std::cout << sum << "\n";

	return 0;
}
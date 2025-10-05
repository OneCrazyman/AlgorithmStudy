/* 
1. ���̵��
	������ ������ 1~1000, ���� ���Ĵ�� �迭�� ä���, ���ҷ� ���� �����Ͽ� �����ϰ� ���غ���

2. �ð����⵵
	������ �迭 �� 1+2+3+ ... n�� (1+n)*n/2 = n^2+n ��ŭ ���� 
	

3. �ڷᱸ��
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
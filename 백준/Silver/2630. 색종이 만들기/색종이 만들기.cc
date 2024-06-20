#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N;
int c0 = 0;
int c1 = 0;

int fun(int** array, int row, int col, int n) {
	
	if (n == 1)
	{
		if (array[row][col] == 0) c0++;
		else c1++;
		return 1;
	}
	else
	{
		int tmp = array[row][col];
		//int count = 0;
		for (int i = row; i < row+n; i++)
		{
			for (int j = col; j < col+n; j++)
			{
				if (array[i][j] != tmp) {
					return fun(array, row, col, n / 2)
						+ fun(array, row + (n / 2), col, n / 2)
						+ fun(array, row, col + (n / 2), n / 2)
						+ fun(array, row + (n / 2), col + (n / 2), n / 2);
				}
			}
		}
		//전부 다 같다면
		if (array[row][col] == 0) c0++;
		else c1++;
		return 1;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);

	cin >> N;
	int** array = new int* [N];
	for (int i = 0; i < N; i++)
	{
		array[i] = new int[N];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> array[i][j];
		}
	}

	// 배열 출력
	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}*/

	fun(array, 0, 0, N);

	cout << c0 << endl << c1;
	return 0;
}
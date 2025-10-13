// 백준 11660

// - 아이디어
// 구간합 생성, 
// 좌표 사이 덧셈을 위해서 -> 행별 구간합 뺄셈 -> 행 갯수만큼(|y1-y2|) 전부 덧셈
// 
// - 시간복잡도
// 구간합 : N^2
// 
// 행별 구간합 뺄셈 : 상수
// 행 갯수 최악 : N 
// ---> 이걸 M번 진행 : N*M
// 
// N^2+N*M = O(N*M) = 10^8 아슬아슬하다
// 
// - 자료구조
// board : int[N][N]
// 구간합 S : int[N][N]

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
int board[1025][1025];
int S[1025][1025];
int point[100'000][4];

void CalculateSum(int point[4]);
void MakePrefixSum();
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> N >> M;

	for (int iY = 1; iY < N+1; iY++)
	{
		for (int iX = 1; iX < N+1; iX++)
		{
			std::cin >> board[iY][iX];
		}
	}

	// 구간합
	MakePrefixSum();

	// 합 계산 및 출력
	
	for (int i = 0; i < M; i++)
	{
		int x1, y1;
		int x2, y2;
		std::cin >> point[i][1] >> point[i][0];
		std::cin >> point[i][3] >> point[i][2];
	}
	
	for (int i = 0; i < M; i++)
	{
		  CalculateSum(point[i]);
	}
	return 0;
}

void CalculateSum(int point[4])
{
	int x1 = point[0];
	int y1 = point[1];
	int x2 = point[2];
	int y2 = point[3];
		
	int diff_Y = abs(y1 - y2);
	int min_Y;
	int min_X;
	int max_X;
	if (y1 < y2) min_Y = y1;
	else min_Y = y2;

	if (x1 < x2)
	{
		min_X = x1;
		max_X = x2;
	}
	else
	{
		min_X = x2;
		max_X = x1;
	}

	int curr_Y = min_Y;
	
	int sum=0;
	for (int i = 0; i < diff_Y + 1; i++)
	{
		if (min_X == 1)
		{
			sum += S[curr_Y][max_X] - S[curr_Y-1][N];
		}
		else
		{
			sum += S[curr_Y][max_X] - S[curr_Y][min_X - 1];
		}
		curr_Y++;
	}

	std::cout << sum << "\n";
}

void MakePrefixSum(){

	for (int iY = 1; iY < N + 1; iY++)
	{
		for (int iX = 1; iX < N + 1; iX++)
		{ 
			if (iX == 1)
			{
				S[iY][iX] = S[iY-1][N] + board[iY][iX];
			}
			else
			{
				S[iY][iX] = S[iY][iX - 1] + board[iY][iX];
			}
		}
	}
}

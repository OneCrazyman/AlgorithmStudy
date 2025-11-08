// - 아이디어
// 문제의 규칙대로 board를 방문 횟수로 채운다.
// r,c 행열의 값을 출력한다.
// --------------------------------- 위의 방법으로는 시간초과
// 다시 생각해보자.
// z모양으로 진행하지만 완전탐색 과정을 생략하고 각 다음 단계의 시작숫자는 매번 제곱수로 알 수 있다.
// 행,열 값이 속하는 섹터만 집중적으로 들어가면 4분의 1씩 탐색을 줄일 수 있다. log4의N이 나올것으로 예상
// 
// - 시간
// 재귀 전체순회시 2^n*2^n 일때 n은 최대 15이니, 2^15*2^15 -> 10^8 -> 완전탐색 1억 - 시간초과
// 
// - 자료구조
//
#include <iostream>

int N;
int r, c;

struct Point
{
	int x;
	int y;
};
void dfs(int n, int val)
{
	int mul = n * n / 4;
	if (n == 1) {
		std::cout << val;
		return;
	}

	int half = n / 2;
	if (r < half && c < half) { // 1
		dfs(half, val);
	}
	else if (r < half && c >= half) { // 2
		c -= half;
		dfs(half, val + mul * 1);
	}
	else if (r >= half && c < half) { // 3
		r -= half;
		dfs(half, val + mul * 2);
	}
	else if (r >= half && c >= half) { // 4
		c -= half;
		r -= half;
		dfs(half, val + mul * 3);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> N >> r >> c;
	dfs(1<<N, 0);

	return 0;
}
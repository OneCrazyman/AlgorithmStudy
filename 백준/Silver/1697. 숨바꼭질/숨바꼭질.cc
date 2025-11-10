// - 아이디어
// 최초: 그리디로 접근 
// 해결: bfs로 모든 경우 순회
// 
// - 시간
// N = 10^5
// K = 10^5
// 전체 순회해도 넉넉하다.
// 
// - 자료구조
// queue<int,int>
// 방문 및 카운트관리 배열: int[]

#include <iostream>
#include <queue>
#define MAX_LEN 100'000

int N, K;
int count[MAX_LEN+1] = {0};
std::queue<std::pair<int,int>> que;

int bfs()
{
	while (!que.empty()) {
		auto p = que.front();
		que.pop();

		auto x = p.first;
		auto add = p.second;
		
		// clipping
		if (x < 0 || x > MAX_LEN) {
			continue;
		}

		if (count[x] != 0) {
			continue;
		}

		count[x] = add++;

		if (x == K) {
			return count[x];
		}

		que.push(std::pair<int,int>(x-1,add));
		que.push(std::pair<int,int>(x+1,add));
		que.push(std::pair<int,int>(x*2,add));
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> N >> K;
	que.push(std::pair<int,int>(N,0));
	auto answer = bfs();
	std::cout << answer;
	return 0;
}
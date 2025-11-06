// 백준 7576
//
// - 아이디어
// 또 BFS다. 최단경로를 찾는 문제로 DFS는 적합하지 않다.
// BFS 순회하면서 다음 칸으로 이동할때 카운트 +1씩 증가하며, 방문한곳은 패스하면서 진행
// 
// - 시간복잡도
// 배열크기 : 10^4
// bfs 순회: O(4*N*M) = O(n*m)= 10^4
// 
// - 자료구조
// 보드:  int[100][100]
// 큐: std::queue<std::pair<int,int>>

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

int N, M;
int board[100][100];
std::queue<std::pair<int, int>> que;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int BFS()
{
	int max = 0;
	while (!que.empty()) {
		auto point = que.front();
		que.pop();
		int ox = point.first;
		int oy = point.second;
		for (int i = 0; i < 4; i++) {
			int x = ox+ dx[i];
			int y = oy+ dy[i];
			if (x < 0 || x >= M || y < 0 || y >= N) {
				continue;
			}
			if (board[y][x] == 1) {
				board[y][x] = board[oy][ox] + 1;
				max = std::max(board[y][x], max);
				if (y == N - 1 && x == M - 1) {
					return max;
				}
				que.push(std::make_pair(x,y));
			}
		}
	}
	return 0;
}



int main()
{	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> N >> M;
	std::string line;
	for (int y = 0; y < N; y++) {
		std::cin >> line;
		for (int x = 0; x < M; x++) {
			board[y][x] = static_cast<int>(line[x] - '0');
		}
	}

	que.push(std::pair<int,int>(0, 0));

	std::cout << BFS();

	

	return 0;
}
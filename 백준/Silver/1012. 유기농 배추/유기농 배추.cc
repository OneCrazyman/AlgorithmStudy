// 백준 14940
// 
// - 아이디어
//	bfs든 dfs 그래프 탐색으로 1을 찾고, 방문 여부 확인 후 전역 count up을 해준 뒤. 주변을 순회 방문 표시한다.
// 
// - 시간복잡도
//  순회 : O(m*n) = 1000
//
// - 자료구조
// 방문: bool[][]
// 보드: bool[][]

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

struct Point { int x;int y; };
constexpr int MAX_LEN = 50;

int T, M, N, K;
std::queue<Point> que;
bool board[MAX_LEN][MAX_LEN] = {0};
bool visited[MAX_LEN][MAX_LEN] = {0};

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs()
{
	while (!que.empty()) {
		auto p = que.front(); que.pop();
		for (int i = 0; i < 4; i++) {
			int x = p.x + dx[i];
			int y = p.y + dy[i];
			if (x<0 || x >= M || y<0 || y>=N)
				continue;
			if (!board[y][x] || visited[y][x])
				continue;
			visited[y][x] = true;
			que.push({ x,y });
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> T;

	for (int t = 0; t < T; t++) {
		std::cin >> M >> N >> K;
		for (int k = 0; k < K; k++) {
			int x, y;
			std::cin >> x >> y;
			board[y][x] = true;
		}
		int count = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (board[y][x] == true && visited[y][x] == false) {
					count++;
					que.push({x,y});
					bfs();
				}
			}
		}
		
		memset(visited,0,sizeof(visited));
		memset(board,0,sizeof(board));

		std::cout << count << "\n";
	}
	return 0;
}
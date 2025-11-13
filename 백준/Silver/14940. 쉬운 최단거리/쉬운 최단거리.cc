// 백준 14940
// 
// - 아이디어
//	반대로 목표지점에서 모든 각지점까지의 최단거리를 출력하면 된다
//	BFS로 지나다니며 이전 노드에서 +1을 하며 카운트업을 한다
//
//	이후 전체 순회하여 목표지점의 상하좌우를 제외한 노드값이 1인 대상을 -1로 수정한다.
//	
// - 시간복잡도
//	BFS: 최악 - 10^6, O(N*M)
//	한번 순회 : "
//  출력시 순회 : "
//  => O(N*M) = 10^6
//
// - 자료구조
//	방문 및 카운트: int[][] visited;

#include <iostream>
#include <vector>
#include <queue>

struct Point { int x;int y; };
constexpr int MAX_LEN = 1'000;
int board[MAX_LEN][MAX_LEN] = { 0 };
bool visited[MAX_LEN][MAX_LEN] = { 0 };
int N, M;
int sX, sY;
std::queue<Point> que;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs()
{
	while (!que.empty()) {
		auto p = que.front(); que.pop();
		for (int i = 0; i < 4; i++) {
			int x = p.x + dx[i];
			int y = p.y + dy[i];
			if (x<0 || x>M - 1 || y<0 || y>N - 1)
				continue;
			if (visited[y][x] || board[y][x] == 0)
				continue;
			visited[y][x] = true;
			board[y][x] = board[p.y][p.x] + 1;
			que.push({x,y});
		}
	}
}

void CheckMinusOneAndRestore()
{
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (board[y][x] == 0) continue;
			if (!visited[y][x]) {
				board[y][x] = -1;
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> N >> M;


	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			std::cin >> board[y][x];
			if (board[y][x] == 2) {
				que.push({ x,y });
				board[y][x] = 0;
				visited[y][x] = true;
				sX = x;
				sY = y;
			}
		}
	}

	bfs();

	CheckMinusOneAndRestore();

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			std::cout << board[y][x] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
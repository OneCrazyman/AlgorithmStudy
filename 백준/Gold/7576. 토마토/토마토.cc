// 백준 7576
// 
// - 아이디어
// BFS를 사용, 큐에 익은토마토(1)를 미리 PUSH한다.
// POP한 주위에 접근가능한 조건일시 현재값+1로 해당 자리의 값을 변경한다.
// * 접근가능한 조건: 안익은 토마토(0)가 있을때만
// 결과도출: 배열에서 MAX값을 확인, 해당값이 최소일수이다. (단, 1이라면 모든 토마토가 익어있는 상태로 0출력)
// (혹은 값중에 0이 존재한다면, -1을 출력)
// 
// - 시간복잡도
// 익은토마토의 최대갯수는 배열 최대갯수, 
// 그 후 BFS를 하며 더 진행하지만 최대 순회수는 시간복잡도가 같음(이미 방문하면 끝이기 때문에): O(N*M) = 10^6 OK
// 
// - 자료구조
// 토마토: INT [][]
// bfs큐: std::queue<int>

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, M;
int tomato[1000][1000];
std::queue<std::pair<int,int>> que;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void BFS()
{
	while (!que.empty()) {
		std::pair<int,int> point = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int x = dx[i] + point.first;
			int y = dy[i] + point.second;

			if (x < 0 || x >= M || y < 0 || y >= N) {
				continue;
			}

			// 주위 방문
			if (tomato[y][x] != 0) {
				continue;
			}

			tomato[y][x] = tomato[point.second][point.first] + 1;
			que.push(std::make_pair(x,y));
		}
	}
	return;
}

int main()
{	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> M >> N;

	for (int iY = 0; iY < N; iY++) {
		for (int iX = 0; iX < M; iX++) {
			std::cin >> tomato[iY][iX];
			if (tomato[iY][iX] == 1) { // 익토 삽입
				que.push(std::make_pair(iX,iY));
			}
		}
	}

	BFS();

	int max = 0;
	for (int iY = 0; iY < N; iY++) {
		for (int iX = 0; iX < M; iX++) {
			max = std::max(tomato[iY][iX],max);
			if (tomato[iY][iX] == 0) {
				std::cout << -1;
				return 0;
			}
		}
	}

	int answer = max - 1;
	if (max == 1) answer = 0;

	std::cout << answer;

	return 0;
}
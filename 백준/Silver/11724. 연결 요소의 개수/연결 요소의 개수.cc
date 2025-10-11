// 백준 11724

// - 아이디어
// [v] 간선을 입력받을때, 양쪽의 정점 리스트에 추가한다. 
// [v] 1~N까지 정점을 방문하며 재귀 DFS로 근접한 정점을 전부 방문한다.
// [v] 이때 VISITED로 이전 방문을 확인하고 RETURN FASLE
// [v] 최초 방문시 루프문으로 인접한 노드로 재귀 방문 후 RETRUN TRUE, 연결 요소 한개 발견마다 TRUE 1회
// [v] 메인에서 RETURN TRUE일때만 카운트하면 연결 요소의 개수 획득 가능

// - 시간복잡도
// 간선 읽어서 양쪽 정점리스트에 추가: M * 2
// 모든 정점을 한번씩 방문: N
// 방문여부 확인 후 DFS 재귀: N 
// (한번 방문한곳은 더이상 진행되지 않음, 한정점에 모든 정점이 연결된 경우라도, 1 + M으로 재귀 후, 나머지 N번 바로 RETURN FALSE : N+M)
// O(M+N) = O(N^2+N) = O(N^2) ,N = 10^3 N^2 = 10^6

// - 자료구조
// 정점별 간선벡터: vector<int>[]
// 방문 여부: bool[]

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

int N,M;
std::vector<int> nodeArray[1001];
bool visited[1001];

void PushNode(int node, int edge);
void DFS(int node);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> N >> M;
	
	for (int i = 0; i < M; i++)
	{
		int s, e;
		std::cin >> s >> e;
		PushNode(s, e);
		PushNode(e, s);
	}
	int count = 0;
	for (int i = 1; i < N+1; i++)
	{
		if (!visited[i])
		{
			DFS(i);
			count++;
		}
	}
	std::cout << count;
}

inline void PushNode(int node, int edge)
{
	nodeArray[node].push_back(edge);
}

void DFS(int node)
{
	visited[node] = true;

	auto it = nodeArray[node].begin();
	for (;it != nodeArray[node].end();++it)
	{
		int edge = *it;
		if (!visited[edge])
			DFS(edge);
	}
}

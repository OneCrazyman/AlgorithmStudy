#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int N, M;

void findAccessNode(bool** pptrN, bool* ptrVisited, int start) {
	//visited count up 
	ptrVisited[start] = true;
	//start 노드의 적혀있는 간선으로 노드 방문
	for (int i = 1; i < N+1; i++)
	{
		if (!ptrVisited[i] && pptrN[start][i])
			findAccessNode(pptrN, ptrVisited, i);
	}
	return;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	bool** pptrN = new bool*[N+1];
	for (int i = 0; i < N + 1; i++) {
		pptrN[i] = new bool[N + 1](); // 모든 값을 false로 초기화
	}

	for (int i = 0; i < M; i++)
	{
		int n1,n2;
		cin >> n1 >> n2;

		pptrN[n1][n2] = true;
		pptrN[n2][n1] = true;
	}

	bool* ptrVisited = new bool[N + 1]();
	//recursive
	findAccessNode(pptrN, ptrVisited, 1);

	cout << count(ptrVisited, ptrVisited + N + 1, true) - 1;

	return 0;
}
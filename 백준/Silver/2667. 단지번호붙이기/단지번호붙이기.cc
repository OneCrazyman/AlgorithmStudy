// 아이디어
//  DFS/BFS를 이용하여 방문여부 확인하여 근처 집 탐색
//  집 방문마다 1 카운트 증가
//  하나의 단지 탐색이 끝나면 (DFS가 완료되었을때) 단지 리스트에 추가
//  마지막, 단지 리스트를 오름차순으로 정렬하고 -> 개수 출력, 오름차순 출력
//  DFS를 재귀로 구현

// 시간복잡도
//  최대 25*25 타일
//  기본적인 전체 탐색 : N^2
//  주변 탐색 : N^2
//  최악의 시간: 2N^2 = O(N^2), N은 10000까지 가능

// 자료구조
//  타일: bool[][]
//  방문여부: bool[][]

#include <iostream>
#include <vector>
#include <algorithm>


int N;
int tile[25][25];
bool visited[25][25];
std::vector<int> result;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int dfs(int iX,int iY)
{
    if (tile[iY][iX] == 0 || visited[iY][iX])
        return 0;
    if (iX < 0 || iY < 0 || iX >= N || iY >= N)
        return 0;
    visited[iY][iX] = true;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += dfs(iX + dx[i],iY + dy[i]);
    }
    return sum + 1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    //FILE* pf = nullptr;
    //freopen_s(&pf, "input.txt", "r", stdin);
    //std::cin >> N;
    scanf("%d",&N);

    for (int iY = 0; iY < N; iY++)
    {
        for (int iX = 0; iX < N; iX++)
        {
            scanf("%1d",&tile[iY][iX]);
        }
    }

    for (int iY = 0; iY < N; iY++)
    {
        for (int iX = 0; iX < N; iX++)
        {
            int ret = dfs(iX, iY);
            if (ret != 0)
            {
                result.push_back(ret);
            }
        }
    }

    std::sort(result.begin(), result.end()); // 기본값 오름차순
    printf("%zu\n", result.size());
    for (auto i : result)
    {
        printf("%d\n", i);
    }
    return 0;
}
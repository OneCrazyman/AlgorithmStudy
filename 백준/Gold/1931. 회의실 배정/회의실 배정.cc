// 백준 1931

// - 아이디어
//      끝나는 시간을 기준으로 정렬한다. (stl::sort)
//      끝나는 시간이 같은 회의들 중에서 시작 시간이 짧은 회의를 확정한다.
//      -> 일종의 그리디 알고리즘
// 
// - 복잡도
//      입력 및 삽입 = O(n)
//      정렬 = O(nlogn)
//      그리디 = O(n)
//      -> O(nlogn) , N= 10^5 ,가능
// 
//  - 자료구조
//      배열: pair<start,end>[][]

#include <iostream>
#include <algorithm>
#define MAX_LEN 100'000

//struct Time { int start; int end; };
std::pair<int,int> timeBoard[MAX_LEN];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::pair<int, int> time;
        std::cin >> time.second >> time.first;
        timeBoard[i] = time;
    }

    std::sort(timeBoard, timeBoard + N);

    int currEnd = 0;
    int answer = 0;
    for (int i = 0; i < N; i++) {
        int end = timeBoard[i].first;
        int start = timeBoard[i].second;

        if (start >= currEnd) {
            answer++;
            currEnd = end;
        }
        continue;
    }
    std::cout << answer;
    return 0;
}
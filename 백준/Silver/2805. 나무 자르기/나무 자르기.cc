#include <iostream>
#include <algorithm>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m;
    //FILE* pf = nullptr;
    //freopen_s(&pf,"input.txt", "r", stdin);
    std::cin >> n >> m;
    int* tree = new int[n];
    int answer;

    // input
    for (int i = 0; i < n; i++)
    {
        std::cin >> tree[i];
    }

    int max = *std::max_element(tree,tree+n);
    

    int top = max;
    int bottom = 0;
    int curr = top / 2;
    while (1)
    {
        if (bottom > top) break;

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (tree[i] - curr > 0)
            {
                sum += tree[i] - curr;
            }
        }
        // 더 위에서 잘라야한다.
        if (sum > m)
        {
            answer = curr;
            bottom = curr+1;
            curr = (top + bottom) / 2 ;
            continue;
        }
        // 더 아래에서 잘라야한다.
        else if (sum < m)
        {
            top = curr-1;
            curr = (top + bottom) / 2;
            continue;
        }
        else if (sum == m)
        {
            answer = curr;
            break;
        }
    }

    std::cout << answer << "\n";
    delete[] tree;
    return 0;
}
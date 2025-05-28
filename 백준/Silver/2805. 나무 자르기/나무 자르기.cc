#include <iostream>
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
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> tree[i];
    }

    int max = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (tree[i] > max)
        {
            max = tree[i];
        }
    }

    int top = max;
    int bottom = 0;
    while(bottom <= top)
    {
        int mid = (bottom + top) / 2;
        long long sum = 0;

        for (size_t i = 0; i < n; i++)
        {
            if (tree[i] > mid)
            {
                sum += tree[i] - mid;
            }
        }
        // 더 위에서 잘라야한다.
        if (sum >= m)
        {
            answer = mid;
            bottom = mid + 1;
        }
        // 더 아래에서 잘라야한다.
        else
        {
            top = mid - 1;
        }
    }

    std::cout << answer << "\n";
    delete[] tree;
    return 0;
}
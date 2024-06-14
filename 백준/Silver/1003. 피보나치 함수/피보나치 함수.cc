#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
using namespace std;

int N;
vector<int> arrN;
unordered_map<int, tuple<int, int>> dp;

tuple<int, int> addValues(const tuple<int, int>& t1, const tuple<int, int>& t2) {
    return make_tuple(get<0>(t1) + get<0>(t2), get<1>(t1) + get<1>(t2));
}

tuple<int, int> fibonacci(int n) {
    if (n == 0) {
        return make_tuple(1, 0);
    }
    else if (n == 1) {
        return make_tuple(0, 1);
    }
    else if (dp.find(n) != dp.end()) {
        return dp[n];
    }
    else {
        dp[n] = addValues(fibonacci(n - 1), fibonacci(n - 2));
    }
    return dp[n];
}

int main() {
    //freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        /* code */
        int n;
        cin >> n;
        arrN.push_back(n);
    }

    for (int i = 0; i < N; i++)
    {
        // cout << arrN[i] <<endl;
        tuple<int, int> answer = fibonacci(arrN[i]);
        cout << get<0>(answer) << " " << get<1>(answer) << endl;
    }

    return 0;
}
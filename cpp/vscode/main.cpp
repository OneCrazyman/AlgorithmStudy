#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arrN;

int fibonacci(int n) {
    if (n == 0) {
        // printf("0");
        // countZero++;
        return 0;
    } else if (n == 1) {
        // printf("1");
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
	freopen("input.txt", "r", stdin);

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
        int countOne = fibonacci(arrN[i]);
        cout << countZero << " " << countOne << endl; 
        countZero = 0; //초기화
    }    
    
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm> // find 함수를 사용하기 위한 헤더
#include <cmath>     // pow 함수를 사용하기 위한 헤더
using namespace std;

int N = 3; // N을 하드코딩하여 고정된 값으로 설정
string arr[3]; // 크기가 3인 배열 선언

string color[] = {
    "black",
    "brown",
    "red",
    "orange",
    "yellow",
    "green",
    "blue",
    "violet",
    "grey",
    "white"
};

int findIndex(const string& target) {
    auto it = find(begin(color), end(color), target);
    if (it != end(color)) {
        return distance(begin(color), it); // 찾은 원소의 위치 반환
    }
    else {
        return -1; // 원소를 찾지 못한 경우 -1 반환
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    
    // 파일에서 N값을 사용하지 않고, 이미 정해진 값을 사용
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int thirdIndex = findIndex(arr[2]);
    long long ans = (findIndex(arr[0])*10 + findIndex(arr[1])) * pow(10, thirdIndex);
    cout << ans << endl;
    return 0;
}
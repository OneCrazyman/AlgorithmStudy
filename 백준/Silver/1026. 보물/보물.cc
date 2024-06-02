#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int A[50];
int B[50];
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	//for (int i = 0; i < N; i++) {
	//	cout << A[i] << " ";
	//}
	//cout << endl;
	//for (int i = 0; i < N; i++) {
	//	cout << B[i] << " ";
	//}

	//배열을 오름차순과 내림차순으로 정렬
	sort(A, A + N); //include the algorithm header
	sort(B, B + N, greater<int>());

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += A[i] * B[i];
	}

	cout << sum;

	return 0;
}
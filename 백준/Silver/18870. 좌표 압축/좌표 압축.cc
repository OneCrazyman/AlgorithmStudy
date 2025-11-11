// - 아이디어
// 입력 좌표들을 오름차순으로 정렬하고, 가장 낮은 값을 0으로 만든다음 순서대로 압축시킨다음 원래 좌표대로 출력한다.
// 
// - 시간
// 퀵정렬: O(nlogn)
// 좌표 압축: O(n)
// 순서대로 다시 출력: O(n)
// 
// - 자료구조
// map<int64,int64>

#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<std::pair<int64_t,int64_t>> arr;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	arr.reserve(1'000'000);

	std::cin >> N;

	for (int64_t i = 0; i < N; i++) {
		int64_t x;
		std::cin >> x;
		arr.push_back(std::make_pair(x,i));
	}

	std::sort(arr.begin(),arr.end());

	// 첫번째 인자 작업
	auto it = arr.begin();
	int64_t count = 0;
	int64_t prev = (*it).first;
	(*it).first = count;
	++it;

	for (;it != arr.end();++it) {
		auto current = (*it).first;
		if (current == prev) {
			// 유지
			(*it).first = count;
		}
		else {
			// +1
			(*it).first = ++count;
			prev = current;
		}
	}
	
	std::vector<int64_t> answers;
	answers.resize(N);

	for (auto& x : arr) {
		answers[x.second] = x.first;
	}

	for (int i = 0; i < N; i++) {
		std::cout << answers[i] << " ";
	}

	return 0;
}
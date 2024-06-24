#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <memory>
#include <mutex>

using namespace std;
const int MaxCount = 150000;
const int ThreadCount = 1;

//소수인지 판단
bool IsPrimeNumber(int number){
	if (number == 1) return false;
	if (number == 2 || number == 3) return true;
	for (int i = 2; i < number - 1; i++) {
		if ((number % i) == 0) {
			return false;
		}
	}
	return true;
}

//출력
void PrintNumbers(const vector<int>& primes) {
	for (int v : primes) {
		cout << v << endl;
	}
}

int main() {
	int num = 1;
	recursive_mutex num_mutex;
	vector<int> primes;
	recursive_mutex primes_mutex;

	auto t0 = chrono::system_clock::now();
	
	//작동할 워커 스레드
	vector<shared_ptr<thread>> threads;

	for (int i = 0; i < ThreadCount; i++)
	{
		//외부 변수를 참조 캡쳐하여 쓰레드를 생성 * [&] 참조 캡처 : 람다 함수 내부에서 외부 변수 자체, 실제 값을 변경할 수 있다.
		//공유 변수를 상ㅇ하는 경우, 특히 동기화일때 참조 캡처를 상ㅇ해야 동기화를 이룰 수 있다.
		shared_ptr<thread> thread(make_shared<thread>([&]() {
			//각 스레드의 메인 함수
			//값을 가져올 수 있으면 루프를 돈다.
			while (true)
			{
				int n;
				{
					//num을 락시킨다.
					lock_guard<recursive_mutex> num_lock(num_mutex);
					n = num;
					num++;
				} // 스코프를 벗어나면서 num_lock 지역 변수가 삭제되며, unlock이 자동적으로 실행된다.
				if (n >= MaxCount) break;
				if (IsPrimeNumber(n)) {
					lock_guard<recursive_mutex> primes_lock(primes_mutex);
					primes.push_back(n);
				}
			}
		}));
		//쓰레드 객체를 쓰레드 벡터에 가지고 있는다.
		threads.push_back(thread);
	}

	//모든 스레드가 일을 마칠때까지 대기한다.
	for (auto thread : threads) {
		thread->join();
	}

	auto t1 = chrono::system_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();
	cout << "Took " << duration << "milliseconds." << endl;
	
	return 0;
}
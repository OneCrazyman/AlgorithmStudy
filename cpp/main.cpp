#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <memory>
#include <mutex>

using namespace std;
const int MaxCount = 150000;
const int ThreadCount = 1;

//�Ҽ����� �Ǵ�
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

//���
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
	
	//�۵��� ��Ŀ ������
	vector<shared_ptr<thread>> threads;

	for (int i = 0; i < ThreadCount; i++)
	{
		//�ܺ� ������ ���� ĸ���Ͽ� �����带 ���� * [&] ���� ĸó : ���� �Լ� ���ο��� �ܺ� ���� ��ü, ���� ���� ������ �� �ִ�.
		//���� ������ ���ϴ� ���, Ư�� ����ȭ�϶� ���� ĸó�� ���ؾ� ����ȭ�� �̷� �� �ִ�.
		shared_ptr<thread> thread(make_shared<thread>([&]() {
			//�� �������� ���� �Լ�
			//���� ������ �� ������ ������ ����.
			while (true)
			{
				int n;
				{
					//num�� ����Ų��.
					lock_guard<recursive_mutex> num_lock(num_mutex);
					n = num;
					num++;
				} // �������� ����鼭 num_lock ���� ������ �����Ǹ�, unlock�� �ڵ������� ����ȴ�.
				if (n >= MaxCount) break;
				if (IsPrimeNumber(n)) {
					lock_guard<recursive_mutex> primes_lock(primes_mutex);
					primes.push_back(n);
				}
			}
		}));
		//������ ��ü�� ������ ���Ϳ� ������ �ִ´�.
		threads.push_back(thread);
	}

	//��� �����尡 ���� ��ĥ������ ����Ѵ�.
	for (auto thread : threads) {
		thread->join();
	}

	auto t1 = chrono::system_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();
	cout << "Took " << duration << "milliseconds." << endl;
	
	return 0;
}
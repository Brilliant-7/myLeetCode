#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
#include <thread>
#include <mutex>

using namespace std;

class ZeroEvenOdd {
private:
	int n;
	mutex _mutex;
	condition_variable _cond;
	bool nextIsZero;
	bool nextIsOdd;
	bool nextIsEven;

public:
	ZeroEvenOdd(int n) :nextIsZero(true), nextIsOdd(false), nextIsEven(false) {
		this->n = n;
	}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {

		for (int i = 0; i < this->n; i++)
		{
			std::unique_lock<std::mutex> lock(_mutex);
			_cond.wait(lock, [&]() {return this->nextIsZero; });

			printNumber(0);

			nextIsZero = false;
			if (i & 1)
				nextIsEven = true;
			else
				nextIsOdd = true;

			_cond.notify_all();
		}
	}
	void odd(function<void(int)> printNumber) {
		for (int i = 1; i <= this->n; i = i + 2)
		{
			std::unique_lock<std::mutex> lock(_mutex);
			_cond.wait(lock, [&]() {return this->nextIsOdd; });

			printNumber(i);

			nextIsZero = true;
			nextIsOdd = false;

			_cond.notify_all();
		}
	}

	void even(function<void(int)> printNumber) {
		for (int i = 2; i <= this->n; i = i + 2)
		{
			std::unique_lock<std::mutex> lock(_mutex);
			_cond.wait(lock, [&]() {return this->nextIsEven; });

			printNumber(i);

			nextIsZero = true;
			nextIsEven = false;

			_cond.notify_all();
		}
	}
};

void printNumber(int n)
{
	cout << n << endl;
}

int main()
{
	ZeroEvenOdd obj(15);

	thread t1(&ZeroEvenOdd::zero, &obj, printNumber);
	thread t2(&ZeroEvenOdd::odd, &obj, printNumber);
	thread t3(&ZeroEvenOdd::even, &obj, printNumber);

	system("pause");

	return 0;
}
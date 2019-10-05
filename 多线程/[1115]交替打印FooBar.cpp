#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
#include <thread>
#include <mutex>

using namespace std;

class FooBar
{
private:
	int n;
	std::mutex _mutex;
	std::condition_variable _cond;
	bool fooIsOk;
	bool barIsOk;

public:
	FooBar(int n) : fooIsOk(false), barIsOk(true)
	{
		this->n = n;
	}

	void foo(function<void()> printFoo)
	{

		for (int i = 0; i < n; i++)
		{
			std::unique_lock<std::mutex> lock(_mutex);
			_cond.wait(lock, [&]() -> int { return this->barIsOk; });
			barIsOk = false;
			// printFoo() outputs "foo". Do not change or remove this line.
			printFoo();
			fooIsOk = true;
			_cond.notify_one();
		}
	}

	void bar(function<void()> printBar)
	{

		for (int i = 0; i < n; i++)
		{
			std::unique_lock<std::mutex> lock(_mutex);
			_cond.wait(lock, [&]() -> int { return this->fooIsOk; });
			fooIsOk = false;
			// printBar() outputs "bar". Do not change or remove this line.
			printBar();
			barIsOk = true;
			_cond.notify_one();
		}
	}
};

void printFoo() {
	cout << "foo" << endl;
}

void printBar() {
	cout << "bar" << endl;
}

int main()
{
	FooBar foobar(10);

	std::thread t1(&FooBar::foo, &foobar, printFoo);
	std::thread t2(&FooBar::bar, &foobar, printBar);

	system("pause");

	return 0;
}
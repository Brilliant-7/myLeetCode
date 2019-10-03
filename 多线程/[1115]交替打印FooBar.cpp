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
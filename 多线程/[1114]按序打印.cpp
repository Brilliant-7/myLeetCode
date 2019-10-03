class Foo
{
public:
    Foo() : oneIsOk(false), twoIsOk(false){}

    void first(function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        std::unique_lock<std::mutex> lock(_mutex);
        oneIsOk = true;
        _cond.notify_all();
    }

    void second(function<void()> printSecond)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _cond.wait(lock, [&]() ->int {return this->oneIsOk;});

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        twoIsOk = true;
        _cond.notify_all();
    }

    void third(function<void()> printThird)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _cond.wait(lock, [&]() {return this->twoIsOk;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    std::mutex _mutex;
    std::condition_variable _cond;
    bool oneIsOk;
    bool twoIsOk;
};
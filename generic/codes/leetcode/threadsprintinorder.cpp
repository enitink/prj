#include <condition_variable>

class Foo {
public:
    Foo() :
        readyfirst(true),
        readysecond(false),
        readythird(false)
    {
        
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lk(mtxfirst);
        cvfirst.wait(lk, [=]{return this->readyfirst;});
        readyfirst = false;
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        readysecond=true;
        cvsecond.notify_one();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(mtxfirst);
        cvsecond.wait(lk, [=]{return this->readysecond;});
        readysecond = false;
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        readythird=true;
        cvthird.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(mtxfirst);
        cvthird.wait(lk, [=]{return this->readythird;});
        readysecond = false;
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        readyfirst=true;
        cvfirst.notify_one();
    }

private:
    std::mutex mtxfirst;
    std::condition_variable cvfirst;
    std::condition_variable cvsecond;
    std::condition_variable cvthird;
    bool readyfirst;
    bool readysecond;
    bool readythird;
};
#include <condition_variable>

class FooBar {
private:
    int n;

public:
    FooBar(int n) :
        readyfirst(true),
        readysecond(false)
    {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lk(mtxfirst);
            cvfirst.wait(lk, [=]{return this->readyfirst;});
            readyfirst = false;
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            readysecond=true;
            cvsecond.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lk(mtxfirst);
            cvsecond.wait(lk, [=]{return this->readysecond;});
            readysecond = false;
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            readyfirst=true;
            cvfirst.notify_one();
        }
    }
private:
    std::mutex mtxfirst;
    std::condition_variable cvfirst;
    std::condition_variable cvsecond;
    bool readyfirst;
    bool readysecond;
};
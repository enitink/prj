class ZeroEvenOdd {
private:
    int n;

public:
    ZeroEvenOdd(int n) 
        : readyfirst(true),
        readysecond(false),
        readythird(false),
        i(1)
    {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        cout << 9;
        std::unique_lock<std::mutex> lk(mtxfirst);
        cvfirst.wait(lk, [=]{return this->readyfirst;});
        readyfirst = false;
        std::cout << 0;
        if (i%2)
        {
            readysecond=true;
            cvsecond.notify_one();
        }
        else
        {
            readythird=true;
            cvthird.notify_one();
        }        
    }

    void even(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lk(mtxfirst);
        cvsecond.wait(lk, [=]{return this->readysecond;});
        readysecond = false;
        std::cout << i;
        ++i;
        readyfirst=true;
        cvfirst.notify_all();
    }

    void odd(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lk(mtxfirst);
        cvthird.wait(lk, [=]{return this->readythird;});
        readythird = false;
        std::cout << i;
        ++i;
        readyfirst=true;
        cvfirst.notify_all();
    }

private:
    std::mutex mtxfirst;
    std::condition_variable cvfirst;
    std::condition_variable cvsecond;
    std::condition_variable cvthird;
    bool readyfirst;
    bool readysecond;
    bool readythird;
    int i;
};
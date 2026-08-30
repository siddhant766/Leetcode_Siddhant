class Foo {
private:
    mutex mtx;
    condition_variable cv;
    int step = 0;

public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        step =1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[&](){
            return step == 1;
        });
        printSecond();

        // printSecond() outputs "second". Do not change or remove this line.
        // printSecond();
        step = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[&](){
            return step == 2;
        });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
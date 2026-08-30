class ZeroEvenOdd {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int curr = 1;
    bool zeroTurn = true;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&](){
                return curr > n || zeroTurn;
            });
            if(curr > n)return;
            printNumber(0);
            zeroTurn = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[&](){
                return curr > n || (!zeroTurn && curr % 2 == 0);
            });
            if(curr > n)return;

            printNumber(curr);
            curr++;

            zeroTurn = true;
            cv.notify_all();

        }
    }

    void odd(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[&](){
                return curr > n || (!zeroTurn && curr % 2 == 1);
            });
            if(curr > n )return;
            printNumber(curr);
            curr++;

            zeroTurn = true;
            cv.notify_all();
        }
    }
};
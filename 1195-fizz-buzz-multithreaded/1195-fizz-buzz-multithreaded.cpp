class FizzBuzz{
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int curr = 1;

public:
    FizzBuzz(int n){
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&](){
                return curr > n || (curr % 3 == 0 && curr % 5 != 0);
            });
            if( curr > n){
                return;
            }
            printFizz();
            curr++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&](){
                return curr > n || ( curr % 3 != 0 && curr % 5 == 0);
            });
            if(curr > n){
                return;
            }
            printBuzz();
            curr++;

            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&](){
                return curr > n || (curr % 15 == 0);
            });
            if(curr > n){
                return;
            }
            printFizzBuzz();
            curr++;

            cv.notify_all();
        }
        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&](){
                return curr > n || ( curr % 3 != 0 && curr % 5 != 0);
            });
            if(curr > n){
                return;
            }
            printNumber(curr);
            curr++;

            cv.notify_all();
        }
    }
};
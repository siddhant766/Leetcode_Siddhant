class DiningPhilosophers {
public:
    mutex forks[5];
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		int left = philosopher;
        int right = (philosopher +1) % 5;
        int first = min(left , right);
        int second = max(left,right);
        forks[first].lock();
        forks[second].lock();

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        forks[second].unlock();
        forks[first].unlock();

    }
};
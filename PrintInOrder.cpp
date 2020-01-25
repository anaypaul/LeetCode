class Foo {
public:
    int f1, f2, f3;
    Foo() {
        f1 = 0;
        f2 = 0;
        f3 = 0;
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        f1 = 1;
    }

    void second(function<void()> printSecond) {
        while(!f1){}
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        f2 = 1;
    }

    void third(function<void()> printThird) {
        while(!f2){}
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};


//Implementation using semaphore
#include<semaphore.h>
class Foo {
public:
    sem_t firstJobDone;
    sem_t secondJobDone;
    Foo() {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        sem_init(&firstJobDone, 0, 0);
        sem_init(&secondJobDone, 0, 0);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&firstJobDone);
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstJobDone);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&secondJobDone);
    }

    void third(function<void()> printThird) {
        sem_wait(&secondJobDone);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    
    }
};
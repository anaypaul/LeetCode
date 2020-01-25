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
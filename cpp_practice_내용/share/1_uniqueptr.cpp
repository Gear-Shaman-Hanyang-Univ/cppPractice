#include <iostream>
#include <memory>

class A{
    int *data;

    public:
    A(){
        std::cout << "acquire data" << std::endl;
        data = new int[100];
    }

    void some() { std::cout << "일반 포인터와 동일하게 사용가능!" << std::endl; }

    ~A(){
        std::cout << "자원을 해제함!" << std::endl;
        delete[] data;
    }
};

void do_something(){
    // 템플릿에 인자로, 포인터가 가리킬 클래스를 전달하면 된다.
    // pa 는 A 클래스의 객체를 가라키는 포인터가 된다.
    // same with, "A* pa = new A();"
    std::unique_ptr<A> pa(new A());
    pa -> some();   // A 클래스의 멤버 함수를 호출.
}

int main() { do_something(); }
// unique_ptr 은 어떠한 객체의 소유권을 의미한다.
// unique_ptr 의 레퍼런스를 사용한다는 것은 단순한 wrapper 로 사용하는 것에 불과.
// 함수 인자로 unique_ptr 을 전달하기 위해서는 포인터 주소값을 전달하면 된다.
#include <iostream>
#include <memory>

class A {
    int* data;

    public:
    A() {
        std::cout << "자원을 획득함" << std::endl;
        data = new int[100];
    }

    void some(){ std::cout << "일반 포인터와 동일하게 사용가능" << std::endl;}

    void do_sth(int a){
        std::cout << "이벤트 발생" << std::endl;
        data[0] = a;
    }

    ~A(){
        std::cout << "자원 해제" << std::endl;
        delete[] data;
    }
};

void do_something(A* ptr) { ptr -> do_sth(3);}

int main(){
    std::unique_ptr<A> pa(new A());
    do_something(pa.get());
}
#include <iostream>
#include <memory>
#include <vector>

class A {
    int* data;

    public:
    A(int i) {
        std::cout << "자원을 획득함" << std::endl;
        data = new int[100];
        data[0] = i;
    }

    void some(){ std::cout << "값 : " << data[0] << std::endl;}

    ~A(){
        std::cout << "자원 해제" << std::endl;
        delete[] data;
    }
};

int main(){
    std::vector<std::unique_ptr<A>> vec;

    // vec.push_back(std::unique_ptr<A>(new A(1)));
    vec.emplace_back(new A(1));

    vec.back() -> some();
}

// emplace_back() 은 전달된 인자를 완벽한 전달을 통해, 직접 unique_ptr<A> 의 생성자에 전달해서,
// vector 맨 뒤에 unique_ptr<A> 객체를 생성해버리게 된다.
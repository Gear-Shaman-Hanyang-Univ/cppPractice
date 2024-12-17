#include <iostream>
#include <memory>
#include <vector>

class A {
    int* data;

    public:
    A() {
        std::cout << "자원을 획득함" << std::endl;
        data = new int[100];
    }
    ~A(){
        std::cout << "소멸자 호출" << std::endl;
        delete[] data;
    }
};

int main(){
    std::vector<std::shared_ptr<A>> vec;
    
    vec.push_back(std::shared_ptr<A>(new A()));
    vec.push_back(std::shared_ptr<A>(vec[0]));
    vec.push_back(std::shared_ptr<A>(vec[1]));

    // 벡터의 첫번째 원소를 소멸 시킨다.
    std::cout << "첫 번째 소멸!" << std::endl;
    vec.erase(vec.begin());

    // 그 다음 원소를 소멸 시킨다.
    std::cout << "두 번째 소멸!" << std::endl;
    vec.erase(vec.begin());

    // 마지막 원소 소멸
    std::cout << "세 번째 소멸!" << std::endl;
    vec.erase(vec.begin());

    std::cout << "end" << std::endl;
}
#include <iostream>

int main(){
    int a = 3;
    int &another_a = a;     // 앰퍼샌드를 사용하여 a 의 참조자를 another_a 라고 정의
    // 참조자 = 별명의 역할. 변수명을 2개로 활용할 수 있는 것.
    // 참조자는 메모리 공간을 차지하지 않는다.
    
    // 포인터는 누구를 가리키든지 자유롭게 바꿀 수 있다.
    /*
    int a = 10;
    int* p = &a;    // 포인터 p 는 a 의 주소를 가리킴

    int b = 20;
    p = &b;     // p는 이제 변수 b를 가리킨다.
    */

    another_a = 5;

    std::cout << "a : " << a << std::endl;
    std::cout << "another_a : " << another_a <<std::endl;

    return 0;
}
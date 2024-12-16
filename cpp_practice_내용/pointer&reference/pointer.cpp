#include <iostream>

int change_val(int *p){ // 함수 인자로 주소를 전달.
    *p = 3;     // 전달받은 주소에 저장되어 있는 값을 3으로 변경.
    return 0;
}

int main(){
    int number = 5;     // 5 라는 4 bye 정수 기록.
    std::cout << number << std::endl;

    change_val(&number); // 앰퍼샌드 기호를 사용하여 number 변수의 주소를 전달.
    std::cout << number << std::endl;

    return 0;
}
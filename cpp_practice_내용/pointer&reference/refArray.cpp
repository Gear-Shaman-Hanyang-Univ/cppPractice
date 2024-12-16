#include <iostream>

// 레퍼런스는 메모리 상에서 공간을 차지하지 않으므로 주소가 없다.
// 따라서 주소가 없는 배열 형태의 레퍼런스는 주소를 가질 수 없는 모순이 발생.
// 다음과 같은 방식으로 배열의 레퍼런스를 구현할 수 있다.
int main(){
    int arr[3] = {1,2,3};
    int(&ref)[3] = arr;     // 크기를 지정해준 배열 ref가 arr 을 참조하도록 한다.

    ref[0] = 3;
    ref[1] = 2;
    ref[2] = 1;

    std::cout << arr[0] << arr[1] << arr[2] << std::endl;

    return 0; 
}
#include <iostream>
#include <array>
#include <cstdint>

int main(){

    // array
    int a[10];
    std::cout << sizeof(a) << std::endl;

    // 추천하는 배열 생성 방식.
    std::array<int,5> ia;
    std::cout << sizeof(ia) << std::endl;
    
    uint64_t ui8;
    float f4;
    std::array<uint8_t, 5> uia5;

    uint64_t * ui64ptr = &ui8;
    std::cout << sizeof(ui64ptr) << std::endl;
    std::cout << (uint64_t)ui64ptr << std::endl;
    return 0;
}
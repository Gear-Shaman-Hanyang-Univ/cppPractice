// 전위 증감, 후위 증감 operator 예제
#include <iostream>

class Test{
    private:
    int x;

    public:
    Test(int x) : x(x) {}
    Test(const Test& t) : x(t.x) {}

    Test& operator++(){
        x++;
        std::cout << "전위 증감 operator" << std::endl;
        return *this;
    }
    Test operator++(int){
        Test temp(*this);
        x++;
        std::cout << "후위 증감 operator" << std::endl;
        return temp;
    }

    int get_x() const {return x;}
};
void func(const Test& t) {
  std::cout << "x : " << t.get_x() << std::endl;
}

int main() {
  Test t(3);

  func(++t); // 4
  func(t++); // 4 가 출력됨
  std::cout << "x : " << t.get_x() << std::endl;
}
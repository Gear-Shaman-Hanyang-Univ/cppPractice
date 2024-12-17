// 컨테이너의 원소를 for 문으로 접근하는 패턴을 range-based for loop 라고 한다.
/*
int main() {
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);

  // range-based for 문
  for (int elem : vec) {        // elem = vec[i]; 와 동일하다.
    std::cout << "원소 : " << elem << std::endl;
  }

  return 0;
}
*/
#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec){
    // 범위 기반 for loop 사용하지 않음.
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr){
        std::cout << *itr << std::endl;
    }
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec){
    // 범위 기반 for loop 사용.
    for (const auto& elem : vec){
        std::cout << elem << std::endl;
    }
}

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    
    std::cout << "print_vector" << std::endl;
    print_vector(vec);
    std::cout << "print_vector_range_based" << std::endl;
    print_vector_range_based(vec);

    return 0;
}
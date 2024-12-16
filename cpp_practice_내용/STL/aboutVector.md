### 요약
std::vector 는 C++ 의 동적 배열을 제공하는 표준 템플릿 라이브러리 중 하나로, 배열과 달리 크기를 동적으로 관리할 수 있어서 유용하다.

### 기본 사용법
```cpp
#include <iostream>
#include <vecotr>

int main(){
    std::vector<int> vec;   // 정수형 벡터 생성

    // 값 추가
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // 출력
    for (int i = 0; i < vec.size(); i++>){
        std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
    }

    // 벡터 크기 확인
    std::cout << "벡터 크기: " << vec.size() << std::endl;

    // 값 제거
    vec.pop_back(); // 마지막 요소 제거
    std::cout << "pop_back 후 크기: " << vec.size() << std::endl;

    return 0;
}
```

### 반복자(iterator) 사용
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5}; // 초기화 리스트로 값 추가

    // 반복자 사용
    std::cout << "벡터 요소: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " "; // 반복자가 가리키는 값 출력
    }
    std::cout << std::endl;

    // 범위 기반 for문
    std::cout << "범위 기반 for문: ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### 2차원 벡터 사용
```cpp
#include <iostream>
#include <vector>

int main(){
    // 2차원 벡터 생성
    std::vector<std::vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    // 출력
    for (size_t i = 0; i < matrix.size(); ++i){
        for (size_t j = 0; j < matrix[i].size(); ++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

### sort
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // std::sort

int main() {
    std::vector<int> vec = {5, 2, 8, 1, 3};

    // 정렬
    std::sort(vec.begin(), vec.end());

    // 출력
    std::cout << "오름차순 정렬: ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // 내림차순 정렬
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    std::cout << "내림차순 정렬: ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}

```

### 벡터에 특정 조건 적용
std::remove_if 와 같은 알고리즘으로 조건에 맞는 값을 제거할 수 있다.
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // std::remove_if

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};

    // 짝수 제거
    vec.erase(
        std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }),
        vec.end()
    );

    // 출력
    std::cout << "짝수 제거 후: ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}

```

### 사용자 정의 타입 저장
사용자 정의 구조체나 클래스를 저장할 수 있다.
```cpp
#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    double grade;
};

int main() {
    std::vector<Student> students = {
        {"Alice", 20, 90.5},
        {"Bob", 22, 85.0},
        {"Charlie", 21, 88.0},
    };

    // 출력
    for (const auto& student : students) {
        std::cout << "이름: " << student.name
                  << ", 나이: " << student.age
                  << ", 점수: " << student.grade << std::endl;
    }

    return 0;
}
```
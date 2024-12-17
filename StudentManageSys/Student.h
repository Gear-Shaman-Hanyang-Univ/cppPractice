#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

// 학생 구조체 정의
struct Student {
    std::string name;
    int age;
    double grade;

    // 학생 정보를 출력하는 함수
    void print() const {
        std::cout << "이름: " << name
                  << ", 나이: " << age
                  << ", 점수: " << grade << std::endl;
    }
};

#endif // STUDENT_H

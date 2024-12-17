#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include <vector>
#include <algorithm>

// 템플릿 클래스 선언
template <typename T>
class StudentManager {
private:
    std::vector<T> items;

public:
    void add(const T& item);               // 데이터 추가
    void printAll() const;                 // 전체 출력
    double calculateAverageGrade() const; // 평균 점수 계산
    void sortByGradeDescending();         // 점수 내림차순 정렬
    T* findByName(const std::string& name); // 이름으로 검색
};

#include "StudentManager.hpp" // 템플릿 구현 포함

#endif // STUDENT_MANAGER_H

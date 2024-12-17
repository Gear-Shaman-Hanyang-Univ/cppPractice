#ifndef STUDENT_MANAGER_HPP
#define STUDENT_MANAGER_HPP

#include "StudentManager.h"

// 데이터 추가
template <typename T>
void StudentManager<T>::add(const T& item) {
    items.push_back(item);
}

// 전체 출력
template <typename T>
void StudentManager<T>::printAll() const {
    for (const auto& item : items) {
        item.print();
    }
}

// 평균 점수 계산
template <typename T>
double StudentManager<T>::calculateAverageGrade() const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.grade;
    }
    return items.empty() ? 0.0 : total / items.size();
}

// 점수 내림차순 정렬
template <typename T>
void StudentManager<T>::sortByGradeDescending() {
    std::sort(items.begin(), items.end(),
              [](const T& a, const T& b) {
                  return a.grade > b.grade;
              });
}

// 이름으로 검색
template <typename T>
T* StudentManager<T>::findByName(const std::string& name) {
    auto it = std::find_if(items.begin(), items.end(),
                           [&name](const T& item) {
                               return item.name == name;
                           });
    if (it != items.end()) {
        return &(*it);
    }
    return nullptr;
}

#endif // STUDENT_MANAGER_HPP

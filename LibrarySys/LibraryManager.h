#ifndef LIBRARY_MANAGER_H
#define LIBRARY_MANAGER_H

#include <vector>
#include <algorithm>
#include <iostream>

// 템플릿 클래스 선언
template <typename T>
class LibraryManager {
private:
    std::vector<T> items;

public:
    void add(const T& item);
    void removeById(int id);
    T* findById(int id);
    void printAll() const;
};

#include "LibraryManager.hpp" // 구현 파일 포함

#endif // LIBRARY_MANAGER_H

#ifndef LIBRARY_MANAGER_HPP
#define LIBRARY_MANAGER_HPP

#include "LibraryManager.h"

// 항목 추가
template <typename T>
void LibraryManager<T>::add(const T& item) {
    items.push_back(item);
}

// 항목 삭제
template <typename T>
void LibraryManager<T>::removeById(int id) {
    items.erase(std::remove_if(items.begin(), items.end(),
        [id](const T& item) { return item.id == id; }), items.end());
}

// 항목 검색
template <typename T>
T* LibraryManager<T>::findById(int id) {
    for (auto& item : items) {
        if (item.id == id) return &item;
    }
    return nullptr;
}

// 전체 출력
template <typename T>
void LibraryManager<T>::printAll() const {
    for (const auto& item : items) {
        item.print();
    }
}

#endif // LIBRARY_MANAGER_HPP

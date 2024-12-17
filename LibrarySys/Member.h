#ifndef MEMBER_H
#define MEMBER_H

#include <string>

struct Member {
    int id;                   // 회원 ID
    std::string name;         // 회원 이름
    int borrowedBookCount;    // 대출한 책의 수

    Member(int id, std::string name)
        : id(id), name(name), borrowedBookCount(0) {}

    void print() const {
        std::cout << "회원 ID: " << id 
                  << ", 이름: " << name 
                  << ", 대출한 책 수: " << borrowedBookCount 
                  << std::endl;
    }
};

#endif // MEMBER_H

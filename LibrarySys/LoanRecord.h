#ifndef LOAN_RECORD_H
#define LOAN_RECORD_H

#include "Book.h"    // Book 구조체 포함
#include "Member.h"  // Member 구조체 포함

struct LoanRecord {
    Book* borrowedBook;       // 대출된 책 (포인터)
    Member* borrowingMember;  // 대출한 회원 (포인터)
    LoanRecord* next;         // 다음 대출 기록

    LoanRecord(Book* book, Member* member)
        : borrowedBook(book), borrowingMember(member), next(nullptr) {}
};

#endif // LOAN_RECORD_H

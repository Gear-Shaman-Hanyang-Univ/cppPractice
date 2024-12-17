#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include "LibraryManager.h"
#include "Book.h"
#include "Member.h"
#include "LoanRecord.h"

#include <mutex>

class LibrarySystem {
private:
    LibraryManager<Book> bookManager;
    LibraryManager<Member> memberManager;
    LoanRecord* loanHead;
    std::mutex mtx;  // 동기화를 위한 뮤텍스

public:
    LibrarySystem();
    ~LibrarySystem();

    void addBook(int id, const std::string& title, const std::string& author);
    void addMember(int id, const std::string& name);

    void borrowBookThreadSafe(int bookId, int memberId);
    void returnBookThreadSafe(int bookId, int memberId);

    void printBooks() const;
    void printMembers() const;
    void printLoans() const;

private:
    void borrowBook(int bookId, int memberId);
    void returnBook(int bookId, int memberId);
};

#endif // LIBRARY_SYSTEM_H

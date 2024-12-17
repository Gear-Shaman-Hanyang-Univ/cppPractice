#include "LibrarySystem.h"
#include <iostream>

LibrarySystem::LibrarySystem() : loanHead(nullptr) {}

LibrarySystem::~LibrarySystem() {
    while (loanHead) {
        LoanRecord* temp = loanHead;
        loanHead = loanHead->next;
        delete temp;
    }
}

void LibrarySystem::addBook(int id, const std::string& title, const std::string& author) {
    bookManager.add(Book(id, title, author));
}

void LibrarySystem::addMember(int id, const std::string& name) {
    memberManager.add(Member(id, name));
}

void LibrarySystem::borrowBookThreadSafe(int bookId, int memberId) {
    std::lock_guard<std::mutex> lock(mtx);
    borrowBook(bookId, memberId);
}

void LibrarySystem::returnBookThreadSafe(int bookId, int memberId) {
    std::lock_guard<std::mutex> lock(mtx);
    returnBook(bookId, memberId);
}

void LibrarySystem::printBooks() const {
    std::cout << "==== 도서 목록 ====\n";
    bookManager.printAll();
}

void LibrarySystem::printMembers() const {
    std::cout << "==== 회원 목록 ====\n";
    memberManager.printAll();
}

void LibrarySystem::printLoans() const {
    std::cout << "==== 대출 기록 ====\n";
    LoanRecord* current = loanHead;
    while (current) {
        std::cout << "책: " << current->borrowedBook->title
                  << ", 회원: " << current->borrowingMember->name << "\n";
        current = current->next;
    }
}

void LibrarySystem::borrowBook(int bookId, int memberId) {
    Book* book = bookManager.findById(bookId);
    Member* member = memberManager.findById(memberId);

    if (!book || !member) {
        std::cout << "책 또는 회원 정보를 찾을 수 없습니다.\n";
        return;
    }

    if (book->isBorrowed) {
        std::cout << "이미 대출된 책입니다.\n";
        return;
    }

    book->isBorrowed = true;
    member->borrowedBookCount += 1;

    LoanRecord* record = new LoanRecord(book, member);
    record->next = loanHead;
    loanHead = record;

    std::cout << "대출이 성공적으로 처리되었습니다.\n";
}

void LibrarySystem::returnBook(int bookId, int memberId) {
    LoanRecord* current = loanHead;
    LoanRecord* prev = nullptr;

    while (current) {
        if (current->borrowedBook->id == bookId && current->borrowingMember->id == memberId) {
            current->borrowedBook->isBorrowed = false;
            current->borrowingMember->borrowedBookCount -= 1;

            if (prev) prev->next = current->next;
            else loanHead = current->next;

            delete current;
            std::cout << "반납이 성공적으로 처리되었습니다.\n";
            return;
        }
        prev = current;
        current = current->next;
    }

    std::cout << "대출 기록을 찾을 수 없습니다.\n";
}

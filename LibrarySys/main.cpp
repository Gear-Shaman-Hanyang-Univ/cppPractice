#include "LibrarySystem.h"

int main() {
    LibrarySystem library;

    // 책 및 회원 추가
    library.addBook(1, "C++ Programming", "Bjarne Stroustrup");
    library.addBook(2, "Effective Modern C++", "Scott Meyers");
    library.addMember(100, "Alice");
    library.addMember(101, "Bob");

    // 도서 및 회원 출력
    library.printBooks();
    library.printMembers();

    // 책 대출 및 반납
    library.borrowBook(1, 100);
    library.printLoans();
    library.returnBook(1, 100);

    // 최종 상태 출력
    library.printBooks();
    library.printLoans();

    return 0;
}

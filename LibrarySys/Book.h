#ifdef BOOK_H
#define BOOK_H

#include <string>
struct Book
{
    int id;
    std::string title;
    std::string author;
    bool isBorrowed;

    Book(int id, std::string title, std::string author)
        : id(id), title(title), author(author), isBorrowed(flse) {}

    void print() const {
       std::cout << "ID: " << id
                  << ", 제목: " << title
                  << ", 저자: " << author
                  << (isBorrowed ? " [대출 중]" : " [대출 가능]") 
                  << std::endl;
    }
};

#endif
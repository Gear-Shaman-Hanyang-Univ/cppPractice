#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <stdexcept>
using std::string;
using std::to_string;

namespace MyExcel {

// Vector class: dynamic array for strings
class Vector {
private:
    string* data;
    int capacity;
    int length;

    void resize(int new_capacity);

public:
    explicit Vector(int n = 1);
    void push_back(const string& s);
    string operator[](int i) const;
    void remove(int x);
    int size() const;
    ~Vector();
};

// Stack class for strings
class Stack {
private:
    struct Node {
        Node* prev;
        string s;
        Node(Node* prev, const string& s) : prev(prev), s(s) {}
    };

    Node* current;

public:
    Stack();
    void push(const string& s);
    string pop();
    string peek() const;
    bool is_empty() const;
    ~Stack();
};

// Base Cell class
class Table;
class Cell {
protected:
    int x, y;
    Table* table;
    string data;

public:
    Cell(const string& data, int x, int y, Table* table);
    virtual string stringify() const;
    virtual int to_numeric() const;
    virtual ~Cell() = default;
};

// Table base class
class Table {
protected:
    int max_row_size, max_col_size;
    Cell*** data_table;

    void validate_coordinates(int row, int col) const;

public:
    Table(int max_row_size, int max_col_size);
    virtual ~Table();
    void reg_cell(Cell* c, int row, int col);
    string stringify(int row, int col) const;
    virtual string print_table() const = 0;
};

// TxtTable derived class
class TxtTable : public Table {
private:
    static string repeat_char(int n, char c);
    static string col_num_to_str(int n);

public:
    TxtTable(int row, int col);
    string print_table() const override;
};

} // namespace MyExcel

#endif

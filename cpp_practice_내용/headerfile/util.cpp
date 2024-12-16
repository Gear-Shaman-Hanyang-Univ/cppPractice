#include "utils.h"
#include <iostream>

namespace MyExcel {

// Helper function: column number to string
string TxtTable::col_num_to_str(int n) {
    string result;
    do {
        result = static_cast<char>('A' + (n % 26)) + result;
        n = n / 26 - 1;
    } while (n >= 0);
    return result;
}

// Constructor and destructor implementations
TxtTable::TxtTable(int row, int col) : Table(row, col) {}

string TxtTable::print_table() const {
    string output = "   ";
    for (int col = 0; col < max_col_size; ++col) {
        output += col_num_to_str(col) + " ";
    }
    output += "\n";

    for (int row = 0; row < max_row_size; ++row) {
        output += std::to_string(row) + " ";
        for (int col = 0; col < max_col_size; ++col) {
            output += (data_table[row][col] ? data_table[row][col]->stringify() : "-") + " ";
        }
        output += "\n";
    }
    return output;
}

Table::Table(int max_row, int max_col)
    : max_row_size(max_row), max_col_size(max_col) {
    data_table = new Cell**[max_row];
    for (int i = 0; i < max_row; ++i) {
        data_table[i] = new Cell*[max_col]();
    }
}

Table::~Table() {
    for (int i = 0; i < max_row_size; ++i) {
        for (int j = 0; j < max_col_size; ++j) {
            delete data_table[i][j];
        }
        delete[] data_table[i];
    }
    delete[] data_table;
}

void Table::validate_coordinates(int row, int col) const {
    if (row < 0 || row >= max_row_size || col < 0 || col >= max_col_size) {
        throw std::out_of_range("Cell coordinates out of bounds");
    }
}

void Table::reg_cell(Cell* c, int row, int col) {
    validate_coordinates(row, col);
    delete data_table[row][col];
    data_table[row][col] = c;
}

Cell::Cell(const string& data, int x, int y, Table* table)
    : data(data), x(x), y(y), table(table) {}

string Cell::stringify() const { return data; }

int Cell::to_numeric() const {
    try {
        return std::stoi(data);
    } catch (...) {
        return 0;
    }
}

// Main function
} // namespace MyExcel

int main() {
    MyExcel::TxtTable table(5, 5);

    table.reg_cell(new MyExcel::Cell("42", 0, 0, &table), 0, 0);
    table.reg_cell(new MyExcel::Cell("Hello", 1, 1, &table), 1, 1);
    table.reg_cell(new MyExcel::Cell("123", 2, 2, &table), 2, 2);

    std::cout << table.print_table();
    return 0;
}

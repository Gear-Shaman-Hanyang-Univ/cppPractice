#include <iostream>
#include <string>

template <typename T>
class Vector{
    T* data;
    int capacity;
    int length;

    public:
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}
    ~Vector(){
        if (data){
            delete[] data;
        }
    }

    // add new element 
    void push_back(T s){
        // check the size of array
        if (capacity <= length){
            T* temp = new T[capacity * 2];
            for (int i = 0; i < length; i++){
                // transfer the ele. to new array.
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }
        // add the element 's'
        data[length] = s;
        // modify length of the array
        length++;
    }
    // detect the element using 'operator'
    T operator[](int i) {return data[i];}

    // remove the element of position 'x'
    void remove(int x){
        for (int i = x+1; i < length; i++){
            data[i-1] = data[i];
        }
        // modify length of the array
        length--;
    }
    // check the size of the array
    int size(){return length;}
}; 

int main(){
    // int 를 보관하는 벡터를 만든다.
    // <> 안에 전달하려는 것을 명시해준다. ex) Vector<std::string>
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    std::cout << "-------- int vector ----------" << std::endl;
    std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    std::cout << "-------- std::string vector -------" << std::endl;
    std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << str_vec[1] << std::endl;    
}
// 템플릿을 통해서 타입이 마치 인자 인것 처럼 사용하는 것을 generic programming
#include <iostream>
// example 1
template <typename T, unsigned int N>
class Array{
    T data[N];

    public:
    Array(T (&arr)[N]){
        for (int i = 0; i < N; i++){
            data[i] = arr[i];
        }
    }

    T* get_array(){return data;}

    unsigned int size(){return N;}

    void print_all(){
        for (int i = 0; i < N; i++){
            std::cout << data[i] << ", ";
        }
        std::cout << std::endl;
    }
};

// example 2
template <int N>
struct Factorial
{
    static const int result = N * Factorial<N-1>::result;
};

template <>
struct Factorial<1>
{
    static const int result = 1;
};



int main(){
    int arr[3] = {1,2,3};

    Array<int, 3> arr_w(arr);
    arr_w.print_all();

    std::cout << "6! = 1*2*3*4*5*6 = " << Factorial<6>::result << std::endl;
}
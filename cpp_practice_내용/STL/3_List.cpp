// 리스트는 vector와 달리 임의의 위치에 있는 원소에 바로 접근할 수 없다.
// list 컨테이너 자체에서는 시작 원소와 마지막 원소의 위치만을 기억하기 때문에, 임의의 위치에 있는 원소에 접근하기 위해서는 하나씩 링크를 따라가야 한다.
// 리스트에는 [] 나 at 함수가 아예 정의되어 있지 않다.

#include <iostream>
#include <list>

template <typename T>
void print_list(std::list<T>& lst) {
  std::cout << "[ ";
  // 전체 리스트를 출력하기 (이 역시 범위 기반 for 문을 쓸 수 있습니다)
  for (const auto& elem : lst) {
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}
int main() {
  std::list<int> lst;

  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);
  lst.push_back(40);

  std::cout << "처음 리스트의 상태 " << std::endl;
  print_list(lst);

  for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
    // 만일 현재 원소가 20 이라면
    // 그 앞에 50 을 집어넣는다.
    if (*itr == 20) {
      lst.insert(itr, 50);
    }
  }

  std::cout << "값이 20 인 원소 앞에 50 을 추가 " << std::endl;
  print_list(lst);

  for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
    // 값이 30 인 원소를 삭제한다.
    if (*itr == 30) {
      lst.erase(itr);
      break;
    }
  }

  std::cout << "값이 30 인 원소를 제거한다" << std::endl;
  print_list(lst);
}

#include "Student.h"
#include "StudentManager.h"

int main() {
    // StudentManager에 Student 타입을 지정
    StudentManager<Student> manager;

    // 학생 추가
    manager.add({"Alice", 20, 95.5});
    manager.add({"Bob", 22, 85.0});
    manager.add({"Charlie", 21, 88.0});

    // 전체 학생 출력
    std::cout << "전체 학생 목록:\n";
    manager.printAll();

    // 평균 점수 계산
    std::cout << "평균 점수: " << manager.calculateAverageGrade() << std::endl;

    // 점수 기준 정렬 후 출력
    manager.sortByGradeDescending();
    std::cout << "점수 기준 정렬 후:\n";
    manager.printAll();

    // 이름으로 학생 검색
    Student* student = manager.findByName("Bob");
    if (student) {
        std::cout << "검색된 학생:\n";
        student->print();
    } else {
        std::cout << "해당 이름의 학생을 찾을 수 없습니다.\n";
    }

    return 0;
}

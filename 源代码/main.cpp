import course_manager;
import student_manager;
import enrollment;
#include "database.h"
#include <iostream>
#include <stdexcept>

// 初始化全局数据
std::vector<Course> courses;
std::vector<Student> students;

void print_menu() {
    std::cout << "\n=== 学生选课系统 ===" << std::endl;
    std::cout << "1. 添加课程" << std::endl;
    std::cout << "2. 添加学生" << std::endl;
    std::cout << "3. 学生选课" << std::endl;
    std::cout << "4. 学生退课" << std::endl;
    std::cout << "5. 查看课程列表" << std::endl;
    std::cout << "6. 查看学生选课情况" << std::endl;
    std::cout << "0. 退出系统" << std::endl;
    std::cout << "请输入选择: ";
}

int main() {
    int choice;
    do {
        print_menu();
        std::cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    int id, credits, capacity;
                    std::string name, teacher;
                    std::cout << "输入课程ID: ";
                    std::cin >> id;
                    std::cout << "输入课程名称: ";
                    std::cin >> name;
                    std::cout << "输入教师姓名: ";
                    std::cin >> teacher;
                    std::cout << "输入学分: ";
                    std::cin >> credits;
                    std::cout << "输入容量: ";
                    std::cin >> capacity;
                    course::add_course(id, name, teacher, credits, capacity);
                    std::cout << "课程添加成功!" << std::endl;
                    break;
                }
                case 2: {
                    int id;
                    std::string name;
                    std::cout << "输入学生ID: ";
                    std::cin >> id;
                    std::cout << "输入学生姓名: ";
                    std::cin >> name;
                    student::add_student(id, name);
                    std::cout << "学生添加成功!" << std::endl;
                    break;
                }
                case 3: {
                    int student_id, course_id;
                    std::cout << "输入学生ID: ";
                    std::cin >> student_id;
                    std::cout << "输入课程ID: ";
                    std::cin >> course_id;
                    enrollment::enroll_course(student_id, course_id);
                    std::cout << "选课成功!" << std::endl;
                    break;
                }
                case 4: {
                    int student_id, course_id;
                    std::cout << "输入学生ID: ";
                    std::cin >> student_id;
                    std::cout << "输入课程ID: ";
                    std::cin >> course_id;
                    enrollment::drop_course(student_id, course_id);
                    std::cout << "退课成功!" << std::endl;
                    break;
                }
                case 5: {
                    std::cout << "\n=== 课程列表 ===" << std::endl;
                    for (const auto& c : courses) {
                        std::cout << "ID: " << c.id
                        << ", 名称: " << c.name
                        << ", 教师: " << c.teacher
                        << ", 学分: " << c.credits
                        << ", 容量: " << c.capacity
                        << ", 已选: " << c.enrolled << std::endl;
                    }
                    break;
                }
                case 6: {
                    int student_id;
                    std::cout << "输入学生ID: ";
                    std::cin >> student_id;
                    Student& s = student::get_student(student_id);
                    std::cout << "\n=== " << s.name << " 的选课情况 ===" << std::endl;
                    for (int course_id : s.selected_courses) {
                        const Course& c = course::get_course(course_id);
                        std::cout << "课程ID: " << course_id
                        << ", 名称: " << c.name
                        << ", 教师: " << c.teacher << std::endl;
                    }
                    break;
                }
                case 0:
                    std::cout << "退出系统..." << std::endl;
                    break;
                default:
                    std::cout << "无效选择，请重新输入!" << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "错误: " << e.what() << std::endl;
        }

    } while (choice != 0);

    return 0;
}

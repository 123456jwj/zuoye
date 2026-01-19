#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>

// 课程结构体
struct Course {
    int id;
    std::string name;
    std::string teacher;
    int credits;
    int capacity;
    int enrolled;
};

// 学生结构体
struct Student {
    int id;
    std::string name;
    std::vector<int> selected_courses;
};

// 全局数据存储
extern std::vector<Course> courses;
extern std::vector<Student> students;

#endif // DATABASE_H

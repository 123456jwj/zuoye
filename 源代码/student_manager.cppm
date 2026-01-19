module;
#include "database.h"
#include <stdexcept>
#include <algorithm>

export module student_manager;

export namespace student {
    // 添加新学生
    void add_student(int id, const std::string& name) {
        // 检查学生ID是否已存在
        auto it = std::find_if(students.begin(), students.end(),
                               [id](const Student& s) { return s.id == id; });

        if (it != students.end()) {
            throw std::invalid_argument("学生ID已存在");
        }

        students.push_back({id, name, {}});
    }

    // 删除学生
    void remove_student(int id) {
        auto it = std::find_if(students.begin(), students.end(),
                               [id](const Student& s) { return s.id == id; });

        if (it == students.end()) {
            throw std::invalid_argument("学生不存在");
        }

        students.erase(it);
    }

    // 获取学生信息
    Student& get_student(int id) {
        auto it = std::find_if(students.begin(), students.end(),
                               [id](const Student& s) { return s.id == id; });

        if (it == students.end()) {
            throw std::invalid_argument("学生不存在");
        }

        return *it;
    }

    // 检查学生是否已选该课程
    bool has_selected_course(int student_id, int course_id) {
        Student& s = get_student(student_id);
        auto it = std::find(s.selected_courses.begin(), s.selected_courses.end(), course_id);
        return it != s.selected_courses.end();
    }
}

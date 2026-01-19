module;
#include "database.h"
import course_manager;
import student_manager;
#include <stdexcept>

export module enrollment;

export namespace enrollment {
    // 学生选课
    void enroll_course(int student_id, int course_id) {
        // 检查课程是否存在且未满
        if (!course::is_course_full(course_id)) {
            throw std::runtime_error("课程已满");
        }

        // 检查学生是否已选该课程
        if (student::has_selected_course(student_id, course_id)) {
            throw std::runtime_error("学生已选该课程");
        }

        // 更新课程选课人数
        Course& c = const_cast<Course&>(course::get_course(course_id));
        c.enrolled++;

        // 更新学生选课列表
        Student& s = student::get_student(student_id);
        s.selected_courses.push_back(course_id);
    }

    // 学生退课
    void drop_course(int student_id, int course_id) {
        // 检查学生是否已选该课程
        if (!student::has_selected_course(student_id, course_id)) {
            throw std::runtime_error("学生未选该课程");
        }

        // 更新课程选课人数
        Course& c = const_cast<Course&>(course::get_course(course_id));
        c.enrolled--;

        // 更新学生选课列表
        Student& s = student::get_student(student_id);
        auto it = std::find(s.selected_courses.begin(), s.selected_courses.end(), course_id);
        s.selected_courses.erase(it);
    }
}

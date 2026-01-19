#include <iostream>
#include <vector>
#include <string>
#include <pqxx/pqxx>

// 前向声明
class Course;
class Teacher;
class Student;

// 课程类
class Course {
private:
    std::string courseId;
    std::string courseName;
    int credit;
    Teacher* teacher;
    std::string time;
    std::string location;
    std::vector<Student*> students;

public:
    Course(std::string id, std::string name, int credit)
        : courseId(id), courseName(name), credit(credit), teacher(nullptr) {}

    std::string getCourseInfo() const {
        return "课程ID: " + courseId + ", 课程名: " + courseName + ", 学分: " + std::to_string(credit);
    }

    void setTeacher(Teacher* t) { teacher = t; }
    void setTimeAndLocation(std::string t, std::string loc) {
        time = t;
        location = loc;
    }

    // 获取器方法
    std::string getCourseId() const { return courseId; }
    std::string getCourseName() const { return courseName; }
    int getCredit() const { return credit; }
    Teacher* getTeacher() const { return teacher; }
    std::string getTime() const { return time; }
    std::string getLocation() const { return location; }
    std::vector<Student*>& getStudents() { return students; }
};

// 学生类
class Student {
private:
    std::string studentId;
    std::string name;
    std::string major;
    std::vector<Course*> courses;

public:
    Student(std::string id, std::string n, std::string m)
        : studentId(id), name(n), major(m) {}

    void enrollCourse(Course* course) {
        courses.push_back(course);
        course->getStudents().push_back(this);
    }

    void dropCourse(Course* course) {
        for (auto it = courses.begin(); it != courses.end(); ++it) {
            if (*it == course) {
                courses.erase(it);
                break;
            }
        }
    }

    void viewCourseSchedule() const {
        std::cout << "学生" << name << "的课程表:" << std::endl;
        for (const auto& course : courses) {
            std::cout << course->getCourseInfo() << std::endl;
        }
    }

    // 获取器方法
    std::string getStudentId() const { return studentId; }
    std::string getName() const { return name; }
    std::string getMajor() const { return major; }
};

// 教师类
class Teacher {
private:
    std::string teacherId;
    std::string name;
    std::string title;
    std::string department;
    std::vector<Course*> courses;

public:
    Teacher(std::string id, std::string n, std::string t, std::string d)
        : teacherId(id), name(n), title(t), department(d) {}

    void assignCourse(Course* course) {
        courses.push_back(course);
        course->setTeacher(this);
    }

    void gradeStudent(Student* student, Course* course, double score) {
        std::cout << "教师" << name << "为学生" << student->getName() 
                  << "的课程" << course->getCourseName() << "打分: " << score << std::endl;
    }

    void generateGradeReport(Course* course) {
        std::cout << "课程" << course->getCourseName() << "的成绩报告:" << std::endl;
        for (const auto& student : course->getStudents()) {
            std::cout << student->getName() << ": 待评分" << std::endl;
        }
    }

    // 获取器方法
    std::string getTeacherId() const { return teacherId; }
    std::string getName() const { return name; }
    std::string getTitle() const { return title; }
    std::string getDepartment() const { return department; }
};

// 教学秘书类
class TeachingSecretary {
private:
    std::string secretaryId;
    std::string name;
    std::string department;

public:
    TeachingSecretary(std::string id, std::string n, std::string d)
        : secretaryId(id), name(n), department(d) {}

    Course* createCourse(std::string courseId, std::string courseName, int credit) {
        return new Course(courseId, courseName, credit);
    }

    void arrangeCourseTimeAndLocation(Course* course, std::string time, std::string location) {
        course->setTimeAndLocation(time, location);
    }

    void assignTeacherToCourse(Teacher* teacher, Course* course) {
        teacher->assignCourse(course);
    }

    // 获取器方法
    std::string getSecretaryId() const { return secretaryId; }
    std::string getName() const { return name; }
    std::string getDepartment() const { return department; }
};

class TerminalUI {
private:
    UniversityController controller;

public:
    void run() {
        std::string input;
        while (true) {
            std::cout << "\n=== 大学课程管理系统 ===" << std::endl;
            std::cout << "1. 创建课程" << std::endl;
            std::cout << "2. 学生选课" << std::endl;
            std::cout << "3. 退出" << std::endl;
            std::cout << "请选择操作: ";
            std::cin >> input;

            if (input == "1") {
                std::string courseId, courseName;
                int credit;
                std::cout << "请输入课程ID: ";
                std::cin >> courseId;
                std::cout << "请输入课程名: ";
                std::cin >> courseName;
                std::cout << "请输入学分: ";
                std::cin >> credit;
                controller.handleCourseCreation(courseId, courseName, credit);
            } else if (input == "2") {
                std::string studentId, courseId;
                std::cout << "请输入学生ID: ";
                std::cin >> studentId;
                std::cout << "请输入课程ID: ";
                std::cin >> courseId;
                controller.handleStudentEnrollment(studentId, courseId);
            } else if (input == "3") {
                break;
            } else {
                std::cout << "无效输入，请重新选择" << std::endl;
            }
        }
    }
};

int main() {
    TerminalUI ui;
    ui.run();
    return 0;
}

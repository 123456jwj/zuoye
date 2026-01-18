class UniversityController {
private:
    StudentRepository studentRepo;
    CourseRepository courseRepo;

public:
    void handleStudentEnrollment(const std::string& studentId, const std::string& courseId) {
        try {
            Student student = studentRepo.findById(studentId);
            Course course = courseRepo.findById(courseId);
            student.enrollCourse(&course);
            std::cout << "学生" << student.getName() << "成功选修课程" << course.getCourseName() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "选课失败: " << e.what() << std::endl;
        }
    }

    void handleCourseCreation(const std::string& courseId, const std::string& courseName, int credit) {
        Course course(courseId, courseName, credit);
        courseRepo.save(course);
        std::cout << "课程" << courseName << "创建成功" << std::endl;
    }
};

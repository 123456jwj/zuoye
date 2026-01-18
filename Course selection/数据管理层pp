// 基础数据访问类
class BaseRepository {
protected:
    pqxx::connection conn;

public:
    BaseRepository() : conn("dbname=university user=postgres password=password hostaddr=127.0.0.1 port=5432") {}
};

// 学生数据访问类
class StudentRepository : public BaseRepository {
public:
    void save(const Student& student) {
        pqxx::work txn(conn);
        txn.exec_params(
            "INSERT INTO students (student_id, name, major) VALUES ($1, $2, $3)",
            student.getStudentId(), student.getName(), student.getMajor()
        );
        txn.commit();
    }

    Student findById(const std::string& studentId) {
        pqxx::work txn(conn);
        pqxx::result r = txn.exec_params(
            "SELECT * FROM students WHERE student_id = $1", studentId
        );
        if (!r.empty()) {
            return Student(r[0][0].as<std::string>(), r[0][1].as<std::string>(), r[0][2].as<std::string>());
        }
        throw std::runtime_error("Student not found");
    }
};

// 课程数据访问类
class CourseRepository : public BaseRepository {
public:
    void save(const Course& course) {
        pqxx::work txn(conn);
        txn.exec_params(
            "INSERT INTO courses (course_id, course_name, credit) VALUES ($1, $2, $3)",
            course.getCourseId(), course.getCourseName(), course.getCredit()
        );
        txn.commit();
    }

    Course findById(const std::string& courseId) {
        pqxx::work txn(conn);
        pqxx::result r = txn.exec_params(
            "SELECT * FROM courses WHERE course_id = $1", courseId
        );
        if (!r.empty()) {
            return Course(r[0][0].as<std::string>(), r[0][1].as<std::string>(), r[0][2].as<int>());
        }
        throw std::runtime_error("Course not found");
    }
};

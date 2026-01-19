module;
#include "database.h"
#include <stdexcept>
#include <algorithm>

export module course_manager;

export namespace course {
    // 添加新课程
    void add_course(int id, const std::string& name, const std::string& teacher,
                    int credits, int capacity) {
        // 检查课程ID是否已存在
        auto it = std::find_if(courses.begin(), courses.end(),
                               [id](const Course& c) { return c.id == id; });

        if (it != courses.end()) {
            throw std::invalid_argument("课程ID已存在");
        }

        courses.push_back({id, name, teacher, credits, capacity, 0});
                    }

                    // 删除课程
                    void remove_course(int id) {
                        auto it = std::find_if(courses.begin(), courses.end(),
                                               [id](const Course& c) { return c.id == id; });

                        if (it == courses.end()) {
                            throw std::invalid_argument("课程不存在");
                        }

                        courses.erase(it);
                    }

                    // 获取课程信息
                    const Course& get_course(int id) {
                        auto it = std::find_if(courses.begin(), courses.end(),
                                               [id](const Course& c) { return c.id == id; });

                        if (it == courses.end()) {
                            throw std::invalid_argument("课程不存在");
                        }

                        return *it;
                    }

                    // 检查课程是否已满
                    bool is_course_full(int id) {
                        const Course& c = get_course(id);
                        return c.enrolled >= c.capacity;
                    }
}

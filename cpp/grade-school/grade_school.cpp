#include "grade_school.h"

namespace grade_school {

    school::school() {
        this->students = map<int, vector<string>>{};
    }

    void school::add(string new_student, int grade) {
        if (this->students.count(grade) == 0) {
            this->students.emplace(grade, vector<string>{new_student});
        }

        for (auto it = this->students.at(grade).begin(); it != this->students.at(grade).end(); ++it) {
            string student = *it;

            if (new_student < student) {
                this->students.at(grade).insert(it, new_student);
                return;
            } else if (new_student == student) {
                return;
            }
        }

        this->students.at(grade).emplace_back(new_student);
    }

    map<int, vector<string>> school::roster() const {
        return this->students;
    }

    vector<string> school::grade(int grade) const {
        if (this->students.count(grade) == 0) {
            return vector<string>{};
        }

        return this->students.at(grade);
    }

}  // namespace grade_school

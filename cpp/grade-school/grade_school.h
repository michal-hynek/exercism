#pragma once

#include <map>
#include <string>
#include <vector>

using namespace std;

namespace grade_school {

    class school {
        public:
            school();

            void add(string student, int grade);
            map<int, vector<string>> roster() const;
            vector<string> grade(int grade) const;
        
        private:
            map<int, vector<string>> students;
    };


}  // namespace grade_school

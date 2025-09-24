#include <array>
#include <string>
#include <vector>

const int PASSING_SCORE = 41;

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded_scores(student_scores.size());

    for (int i = 0; i < student_scores.size(); ++i) {
        rounded_scores.at(i) = static_cast<int>(student_scores.at(i));
    }

    return rounded_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int failed_students = 0;

    for (int i = 0; i < student_scores.size(); ++i) {
        if (student_scores.at(i) < PASSING_SCORE) {
            failed_students++;
        }
    }

    return failed_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int interval = (highest_score - PASSING_SCORE - 1) / 4;

    return {PASSING_SCORE, PASSING_SCORE+interval+1, PASSING_SCORE+2*interval+2, PASSING_SCORE+3*interval+3};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {

    std::vector<std::string> rankings(student_scores.size());

    for (int i = 0; i < student_names.size(); ++i) {
        rankings.at(i) = std::to_string(i+1) + ". " + student_names.at(i) + ": " + std::to_string(student_scores.at(i));
    }

    return rankings;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for (int i = 0; i < student_scores.size(); ++i) {
        if (student_scores.at(i) == 100) {
            return student_names.at(i);
        }
    }
    
    return "";
}

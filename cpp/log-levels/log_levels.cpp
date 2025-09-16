#include <string>

namespace log_line {
std::string message(std::string line) {
    int start = line.find("]: ") + 3;

    return line.substr(start);
}

std::string log_level(std::string line) {
    int start = line.find("[") + 1;
    int end = line.find("]") - 1;
    int len = end - start + 1;

    return line.substr(start, len);
}

std::string reformat(std::string line) {
    std::string message{log_line::message(line)};
    std::string log_level{log_line::log_level(line)};

    return message + " (" + log_level + ")";
}
}  // namespace log_line

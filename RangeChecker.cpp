#include <sstream>
#include <algorithm>
#include <iostream>

bool IsInRange(int number, const char* strRange) {
    std::istringstream ss(strRange);
    std::string token;
    while (std::getline(ss, token, ',')) {
        auto pos = token.find("..");
        if (pos != std::string::npos) {
            int start = std::stoi(token.substr(0, pos));
            int end = std::stoi(token.substr(pos + 2));
            if (number >= start && number <= end) {
                return true;
            }
        } else {
            int num = std::stoi(token);
            if (num == number) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::cout << std::boolalpha << IsInRange(91, "1..7, 10, 15, 50, 90..120, 200, 380") << std::endl; // true
    std::cout << std::boolalpha << IsInRange(1000, "1..7, 10, 15, 50, 90..120, 200, 380") << std::endl; // false
    return 0;
}

#include <iostream>
#include <fstream>
#include <string_view>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    const auto filename = argv[1];
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: failed to open file " << filename << "\n";
        return 1;
    }

    std::vector<int> numbers;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int number;
        while (iss >> number) {
            numbers.push_back(number);
        }
    }

    auto minmax = std::minmax_element(numbers.begin(), numbers.end());
    auto sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    auto average = static_cast<double>(sum) / numbers.size();

    std::cout << "Min: " << *minmax.first << "\n";
    std::cout << "Max: " << *minmax.second << "\n";
    std::cout << "Sum: " << sum << "\n";
    std::cout << "Average: " << average << "\n";

    return 0;
}

#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>

template<typename T>
void move_vectors(std::vector<T>& source, std::vector<T>& destination) {
    std::move(source.begin(), source.end(), std::back_inserter(destination));

    source.clear();
}

int main() {
    SetConsoleOutputCP(65001);
    std::vector<std::string> one = { "test_string1", "test_string2" };
    std::vector<std::string> two;

    move_vectors(one, two);

    for (const auto& str : two) {
        std::cout << str << std::endl;
    }

    return 0;
}

#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>

class big_integer {
public:
    big_integer() = default;
    big_integer(const std::string& str) : value(str) {}

    big_integer operator+(const big_integer& other) const {
        std::string result;
        int carry = 0;
        int i = value.size() - 1;
        int j = other.value.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += value[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += other.value[j] - '0';
                j--;
            }
            carry = sum / 10;
            result.push_back(sum % 10 + '0');
        }

        std::reverse(result.begin(), result.end());
        return big_integer(result);
    }

    big_integer operator*(int num) const {
        std::string result;
        int carry = 0;

        for (char digit : value) {
            int product = (digit - '0') * num + carry;
            carry = product / 10;
            result.push_back(product % 10 + '0');
        }

        while (carry) {
            result.push_back(carry % 10 + '0');
            carry /= 10;
        }

        std::reverse(result.begin(), result.end());
        return big_integer(result);
    }


    friend std::ostream& operator<<(std::ostream& os, const big_integer& num) {
        os << num.value;
        return os;
    }

private:
    std::string value;
};

int main() {
    SetConsoleOutputCP(65001);
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result; // 193099

    return 0;
}

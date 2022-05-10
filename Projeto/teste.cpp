#include <iostream>
#include <regex>
#include <string>

using std:: string;

int main() {
    const string text = "91101";
    string r = "^[01]+$";
    std::regex re(r);
    std::smatch match;
    bool valid = std::regex_search(text, match, re);

    if (valid) {
    std::cout << "binário válido" << std::endl;
    } else {
        std::cout << "Data inválida!!";
    }
    return 0;
}

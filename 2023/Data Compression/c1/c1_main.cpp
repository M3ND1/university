#include <iostream>
#include <string>
#include <unordered_map>

std::string fk_c1(std::string input_string) {
    std::unordered_map<char, std::string> patterns = {
        {'1', "11"},
        {'2', "011"},
        {'3', "0011"},
        {'4', "1011"},
        {'5', "00011"},
        {'6', "10011"},
        {'7', "01011"},
        {'8', "000011"},
        {'9', "100011"},
        {'A', "010011"},
        {'B', "001011"},
        {'C', "101011"},
        {'D', "0000011"},
        {'E', "1000011"},
        {'F', "0100011"}
    };

    std::string output_string;
    for (char& c : input_string) {
        output_string += patterns[c] + ' ';
    }

    return output_string;
}

int main()
{
    std::string liczba, liczba2, k;
    std::getline(std::cin, k);
    std::string output_string = fk_c1(k);
    std::cout << output_string << std::endl;

}
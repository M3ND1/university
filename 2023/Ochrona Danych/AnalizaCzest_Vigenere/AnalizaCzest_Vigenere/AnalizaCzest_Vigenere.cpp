#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <iomanip>

const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
double ic(const std::string& input) {
    int n = input.length();
    std::map<char, int> m;
    for (int i = 0; i < n; i++) {
        char c = toupper(input[i]);
        if (alphabet.find(c) != std::string::npos) {
            m[c]++;
        }
    }
    double ic = 0.0;
    for (auto f : m) {
        ic += (double)f.second * (f.second - 1);
    }
    ic /= (double)n * (n - 1);
    return ic;
}
std::vector<std::string> divideText(const std::string& input, int h)
{
    std::vector<std::string> groups(h); // for how many groups
    int index = 0;
    for (char c : input) {
        c = toupper(c);
        if (alphabet.find(c) != std::string::npos) {
            groups[index++ % h] += c;
        }
    }
    return groups;
}
std::string clearText(const std::string& input)
{
    std::string cleared_text;
    for (int i = 0; i < input.length(); i++)
    {
        char c = input[i];
        c = toupper(c);
        if (alphabet.find(c) != std::string::npos)
        {
            cleared_text += c;
        }
    }
    return cleared_text;
}

int main()
{
    std::fstream file;
    std::string input_string, password, output, actual_string;
    std::vector<std::vector<std::string>> matrix(alphabet.length(), std::vector<std::string>(alphabet.length()));

    // read input text from file
    file.open("sampleText.txt", std::ios::in);
    if (file.is_open())
    {
        while (std::getline(file, input_string))
        {
            input_string += '\n';
            actual_string += input_string;
        }
        file.close();
    }
    std::cout << std::endl;

    std::string string_actual, string_input;
    file.open("hej.txt", std::ios::in);
    if (file.is_open())
    {
        while (std::getline(file, string_input))
        {
            string_input += '\n';
            string_actual += string_input;
        }
        file.close();
    }
    std::cout << "Original Text:\n" << string_actual << std::endl;
    //clear text
    std::string cleared_text = clearText(string_actual);
    std::cout << "Cleared Text:\n" << cleared_text << std::endl;

    for (int i = 1; i <= 20; i++)
    {
        std::vector<std::string> groups = divideText(cleared_text, i);
        std::vector<double> ics;
        for (int j = 0; j < i; j++) {
            //std::cout << groups[j] << " " << std::endl;
            ics.push_back(ic(groups[j]));
        }
        double ic_avg = 0.0;
        for (int j = 0; j < i; j++) {
            ic_avg += ics[j];
        }
        ic_avg /= (double)i;
        std::cout << "H: " << i << " " << ic_avg << std::endl;
    }

    return 0;
}
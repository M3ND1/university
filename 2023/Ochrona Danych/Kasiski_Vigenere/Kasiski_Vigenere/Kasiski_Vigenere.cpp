#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

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

std::vector<int> patternSearch(const std::string& input, int min_len)
{
    std::vector<int> distances;
    for (int i = 0; i < input.length() - min_len; i++)
    {
        std::string pattern = input.substr(i, min_len);
        auto found = input.find(pattern, i + min_len);
        while (found != std::string::npos)
        {
            distances.push_back(found - i);
            found = input.find(pattern, found + 1);
        }
    }
    return distances;
}

int main()
{
    std::fstream file;
    std::string input_string, password, output, actual_string;

    file.open("zaszyfrowany.txt", std::ios::in);
    if (file.is_open())
    {
        while (std::getline(file, input_string))
        {
            input_string += '\n';
            actual_string += input_string;
        }
        file.close();
    }
    std::string cleared_text = clearText(actual_string);
    std::cout << cleared_text << std::endl;
    int min_len;
    std::cin >> min_len;
    //kaiski
    std::vector<int> distances = patternSearch(cleared_text, min_len);
    for (int i = 2; i <= 20; i++)
    {
        int count = 0;
        for (auto d : distances)
        {
            if (d % i == 0)
                count++;
        }
        std::cout << "H=" << i << ": " << count << std::endl;
    }
    //print distances
    //std::cout << "\n\n";
    for (auto d : distances)
    {
        std::cout << d << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
std::string szyf(int przesuniecie, const std::string& input, bool operacja)
{
    std::string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    std::string output_string;
    if(operacja) przesuniecie = alfabet.length() - przesuniecie;
    for (int i = 0; i < input.length(); i++)
    {
        char c = input[i];
        c = toupper(c);
        if (alfabet.find(c) != std::string::npos) {
            int index = alfabet.find(c);
            int shifted_index = (index + przesuniecie) % alfabet.length();
            char shifted_char = alfabet[shifted_index];
            output_string += shifted_char;
        }
        else
        {
            output_string += c;
        }
    }
    return output_string;
}
int main()
{
    std::fstream file;
    std::string input_string;
    std::vector<std::string> inp;
    bool action;
    char f;
    std::cout << "s by szyfrowac, d by deszyfrowac" << std::endl;
    std::cin >> f;
    jumping:
    if (f == 's')
    {
        action = false;
    }
    else if (f == 'd')
    {
        action = true;
    }
    else {
        system("cls");
        std::cout << "s by szyfrowac, d by deszyfrowac" << std::endl;
        std::cin >> f;
        goto jumping;
    }
    file.open("input.txt", std::ios::in);
    if (file.is_open())
    {
        while(std::getline(file, input_string))
        {
            input_string += '\n';
            inp.push_back(input_string);
        }
        file.close();
    }

    int p;
    std::cout << "Podaj o ile przesuniecie: ";
    std::cin >> p;
    std::cout << std::endl;
    
    file.open("output.txt", std::fstream::out);
    if (file.is_open())
    {
        for (int i = 0; i < inp.size(); i++)
        {
            file << szyf(p, inp[i], action);
        }
        file.close();
    }
    return 0;
}
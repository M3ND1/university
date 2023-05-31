#include <iostream>
#include <string>
#include <vector>
#include <fstream>
void display(std::vector<std::vector<std::string>>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            std::cout << v[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
std::string vigenere(const std::string &input, const std::vector<std::vector<std::string>>& matrix,const std::string & key, bool operacja)
{
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    std::string output_string;
    int col;
    char p;
    int j = 0;
    for (int i = 0; i < input.length(); i++)
    {
        char input_char = input[i];
        input_char = toupper(input_char);
        if (alphabet.find(input_char) != std::string::npos)
        {
            p = toupper(key[j % key.length()]);
            j++;
            col = alphabet.find(p);
            if (operacja == true)
            {
                int row = alphabet.find(input_char);
                output_string += matrix[row][col];
            }
            else {
                bool found = false;
                for(int row = 0; row < alphabet.length(); row++)
                {
                    if (matrix[row][col][0] == input_char)
                    {
                        output_string += alphabet[row];
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cerr << "Error: character not found in Vigenere matrix\n";
                    output_string += input_char;
                }
            }
        }
        else {
            output_string += input[i];
        }
    }
    return output_string;
}
int main()
{
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    std::fstream file;
    std::string input_string,password,output,actual_string;
    std::vector<std::vector<std::string>> matrix(alphabet.length(), std::vector<std::string>(alphabet.length()));
    //input_text p.1
    file.open("input.txt", std::ios::in);
    if (file.is_open())
    {
        while (std::getline(file, input_string))
        {
            input_string += '\n';
            actual_string += input_string;
        }
        file.close();
    }
    std::cout << "Podaj haslo: ";
    getline(std::cin, password);
    //coded matrix
    for (int i = 0; i < alphabet.length(); i++) {
        for (int j = 0; j < alphabet.length(); j++) {
            matrix[i][j] = alphabet[(i + j) % alphabet.length()];
        }
    }
    bool operacja;
    display(matrix);
    char input = 'm';
    while (true)
    {
        if (input == 's' || input == 'd')
        {
            break;
        }
        std::cout << "Co chcesz zrobic?\n Szyfrowac = (s), d= Deszyfr(d): ";
        std::cin >> input;
        std::cin.ignore();
    }
    if (input == 's')
    {
        operacja = true;
    }
    else if (input == 'd')
    {
        operacja = false;
    }
    file.open("output.txt", std::fstream::out);
    if (file.is_open())
    {
        file << vigenere(actual_string, matrix, password, operacja);
        file.close();
    }
    return 0;
}
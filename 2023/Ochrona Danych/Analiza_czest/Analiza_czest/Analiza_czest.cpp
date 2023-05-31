#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <iomanip>
std::string szyfr(int przesuniecie, const std::string& input, bool operacja)
{
    std::string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    std::string output_string;
    if (operacja) przesuniecie = alfabet.length() - przesuniecie;
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
void zaszyfr_tekst(std::string& actual_string)
{
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    std::map<char, int> wyst_zaszyfr;
    //wyst w zaszyfr
    for (int i = 0; i < actual_string.length(); i++)
    {
        char c = actual_string[i];
        c = toupper(c);
        if (alphabet.find(c) != std::string::npos) {
            wyst_zaszyfr[c]++;
        }
    }
    double procenty = 0.0;
    std::cout << std::fixed << std::setprecision(2);
    for (auto it = wyst_zaszyfr.cbegin(); it != wyst_zaszyfr.cend(); ++it)
    {
        std::cout << it->first << " : " << it->second << " " << " %: " << (double)((double)(it->second) / (double)actual_string.length()) << "\n";
        procenty += (double)((double)(it->second) / (double)actual_string.length());
    }
    std::cout << procenty << "\n";
}
int main()
{
    std::fstream file;
    std::string input_cipher,actual_string;
    file.open("input.txt", std::ios::in);
    if (file.is_open())
    {
        while (std::getline(file, input_cipher))
        {
            input_cipher += '\n';
            actual_string += input_cipher;
        }
        file.close();
    }
    zaszyfr_tekst(actual_string);
    std::string cipher_input, string_actual;
    file.open("input2.txt", std::ios::in);
    if (file.is_open())
    {
        while (std::getline(file, cipher_input))
        {
            cipher_input += '\n';
            string_actual += cipher_input;
        }
        file.close();
    }
    zaszyfr_tekst(string_actual);
    ////disp
    while (true) {
        int przes;
        std::cin >> przes; //how much end check it??
        std::string out = szyfr(przes, actual_string, true);
        std::cout << out << std::endl;
        std::cout << "\n\n";
    }
   

    //file.open("output.txt", std::fstream::out);
    //if (file.is_open())
    //{
    //    file << out;
    //    file.close();
    //}

}

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
//S0 = 4
//si+1=Si^2 mod M
//M=2^p-1 true when 
long long powerFunction(int base, int exp)
{
    long long sol = 1;
    while (exp--)
    {
        sol *= base;
    }
    return sol;
}
bool lehmer(int p , int prime)
{
    if (prime == 3) return true;
    long long s = 4;
    p -= 2;
    while (p--)
    {
        s = (powerFunction(s, 2) - 2)%prime;
    }
    return s == 0;
}
bool isPrimeNumber(int number) //17
{
    //9 000 000 -> 10 000 000 
    if (number == 1) false;
    if (number == 2) true;
    int n = (int)sqrt(number); //4
    for (int i = 2; i <= n; i++) //2 3 4
    {
        if (number % i == 0)  // 17 % 2 == 1 17%3 == 2 17%4 == 1
            return false;
    }
    return true;
}

int main()
{
    bool check, check_lehmer;
    int count = 0;
    //occurances
    for (unsigned long long i = 9000000; i <= 10000000; i++)
    {
        if (isPrimeNumber(i) == true)
            count++;
    }
    //Lehmer
    int count_lehmer = 0;
    for (int i = 2; i <= 32; i++)
    {
        if (isPrimeNumber(i))
        {
            //long long liczba = powerFunction(2, i)-1; //calculate Mersenne number
            long long liczba = std::pow(2, i)-1; //calculate Mersenne number
            bool lehmerBool = lehmer(i, liczba); //lehmer test
            bool dzielenieBool = isPrimeNumber(liczba); //casual divider test
            std::cout << "Lehmer p=" << i << " M=" << liczba << (lehmerBool ? " - JEST PIERWSZA\n" :" - NIE JEST PIERWSZA\n") << std::endl;
            std::cout << "Dzielenie p=" << i << " M=" << liczba << (dzielenieBool ? "- JEST PIERWSZA\n" : " - NIE JEST PIERWSZA\n") << std::endl;
        }

    }
    std::cout << "Ilosc liczb pierwszych miedzy 9mln a 10mln: " << count;
}


#include <iostream>
#include <cmath>
unsigned long long powerFunction(unsigned long long base, unsigned long long exp, unsigned long long c)
{
    unsigned long long sol = 1;
    while (exp--)
    {
        sol *= base;
        sol %= c;
    }
    return sol;
}
bool isPrimeNumber(int number)
{
    if (number == 1) false;
    if (number == 2) true;
    int n = (int)sqrt(number);
    for (int i = 2; i <= n; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int p,a,b,g;
    unsigned long long A, Ak;
    std::cout << "Podaj p: ";
    std::cin >> p;
    if (isPrimeNumber(p))
    { // p && g takie samo
        //a jakie se wymysle
        std::cout << "Podaj g: ";
        std::cin >> g;
        std::cout << std::endl << "Podaj a: ";
        std::cin >> a;
        //==
        A = powerFunction(g, a, p);
        //cout << A i daje mlodzieniakowi
        std::cout << "Liczba dla kolegi: " << A << std::endl;
        std::cout << std::endl << "Liczba od kolegi: ";
        std::cin >> b;
        std::cout << std::endl;
        Ak = powerFunction(b, a, p); // to ma wyjsc to samo
        std::cout << "Wynik: " << Ak << std::endl;
    }
    
}

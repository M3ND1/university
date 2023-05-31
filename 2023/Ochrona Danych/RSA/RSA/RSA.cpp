#include <vector>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>

unsigned long long nwd(unsigned long long e, unsigned long long phi)
{
    unsigned long long r;
    while (phi != 0)
    {
        r = e % phi;
        e = phi;
        phi = r;
    }
    return e;
}

bool isPrime(unsigned long long prime)
{
    if (prime == 1) return false;
    for (int i = 2; i <= (unsigned long long)(sqrt(prime)); i++)
        if (prime % i == 0) return false;
    return true;
}
unsigned long long pow_mod(unsigned long long a, unsigned long long b, unsigned long long c)
{
    unsigned long long sol = 1;
    while (b--)
    {
        sol *= a;
        sol %= c;
    }
    return sol;
}
unsigned long long encrypt_one(char c, unsigned long long e, unsigned long long n)
{
    return pow_mod(c, e, n);
}

std::vector<unsigned long long> encrypt(const std::string& chain, unsigned long long e, unsigned long long n)
{
    std::vector<unsigned long long> solution(chain.length());
    for (auto& c : chain)
    {
        std::cout << c;
        solution.push_back(encrypt_one(c, e, n));
    }
    return solution;
}

unsigned long long nwdEuclides(unsigned long long e, unsigned long long phi)
{
    unsigned long long tmp = phi;
    unsigned long long y = 0;
    unsigned long long x = 1;
    while (e > 1)
    {
        unsigned long long q = e / phi;
        unsigned long long t = phi;
        phi = e % phi;
        e = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += tmp;
    return x;
}

std::string decrypt(const std::vector<unsigned long long>& data, unsigned long long phi, unsigned long long e)
{
    unsigned long long d = nwdEuclides(e, phi);

    return std::string();
}

int main()
{
    unsigned long long p, q, e, phi, n, d;
    std::cout << "Podaj p,q,e:";
    //std::cin >> p>>q>>e;
    p = 23;
    q = 11;
    e = 13;

    n = p * q;
    std::cout << "here1";
    phi = (p - 1) * (q - 1);
    std::cout << "here2";
    while (1 != nwd(e, phi))
    {
        std::cout << "here3";
        while (!isPrime(e))
        {
            std::cout << "here4";
            e++;
        }
        std::cout << "done";
    }
    std::string str("lol123");
    std::vector<unsigned long long> ecrypted = encrypt(str, e, n);
    std::cout << std::endl << "Zaszyfrowane" << std::endl;
    for (const auto& i : ecrypted)
    {
        std::cout << i << ' ';
    }

    return 0;
}
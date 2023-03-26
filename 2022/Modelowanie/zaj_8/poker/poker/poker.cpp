#include <iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<random>
// Constants for the LCG
const int M = 135466;  // Modulus
const int A = 20;   // Multiplier
const int C = 13;   // Increment
#define RM (double)RAND_MAX;

int main() {
    //4
    //13`
    int N = 2000;

    std::vector<double> gen_liczby(2000);
    int x = 5;  // Seed value
    double r = 0.0;
    for (int i = 0; i < N; i++) {
        // Generate next random number
        x = (A * x + C) % M;
        r = static_cast<double>(x) / M;
        //std::cout << r << std::endl;
        gen_liczby[i] = r;
    }
    std::vector<char> cards(2000);
    //for (auto& i : gen_liczby) {
    //    std::cout << i << "\n";
    //}
    for (int i = 0; i < 2000; ++i)
    {
        if (gen_liczby[i] < 0.2) {
            cards[i] = 'A';
        }
        else if (gen_liczby[i] < 0.4) {
            cards[i] = 'B';
        }
        else if (gen_liczby[i] < 0.6) {
            cards[i] = 'C';
        }
        else if (gen_liczby[i] < 0.8) {
            cards[i] = 'D';
        }
        else {
            cards[i] = 'E';
        }
    }
    std::vector<int> howmuch(0, 400);
    for (int i = 0; i < 400; ++i)
    {
        //indexy  [0,5]
        std::cout << cards[i * 5] << cards[i * 5 + 1] << cards[i * 5 + 2] << cards[i * 5 + 3] << cards[i * 5 + 4] << std::endl;
    }
    for (auto& i : howmuch) {
        std::cout << i << " ";
    }/*
    for (int i = 0; i < N; i++) {
        double s = 1.0 * generator(M, A, C, N) / 135466;// 1.0 * gen.losuj() / 100000007
        std::cout << s;
    }*/
    return 0;
}

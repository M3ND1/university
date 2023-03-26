#include <iostream>
#include <time.h>
#include <random>


//historgram w c++, krzywa, otworz dane 
//dystrybuanta
//wygenerowac liczby policzymy wartosci 
int main() {
    double a, b, x;
    a = 2;
    b = 5;
    srand(time(NULL));
    double s1=0, s2=0, dyst=0;
    int tab[2000];
    for (int i = 0; i < 2000; i++) {
        x = a + (b - a) * rand() / float(RAND_MAX);
        s1 += x;
        s2 += (x * x);
        tab[i] = x;
        //std::cout << i << " ";
    }
    //for (int i = 0; i < 2000; i++) {
    //    std::cout << tab[i] << "\n";
    //}
    //std::cout << s1 << "\n";
    //std::cout << s2 << "\n";
    s1 = s1 / 2000;
    s2 = s2 / 2000;


    dyst = s2 - (s1 * s1);
    dyst = (b - a) / 10;

    float numer = int((x - a) / (dyst));

    std::cout << numer;




}

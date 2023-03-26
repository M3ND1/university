#include <iostream>
#include <stdio.h>    
#include <stdlib.h>    
#include <time.h>
#include <math.h>
#include <cmath>
#include <fstream>
#include <vector>


int main() {
    srand(time(NULL));
    std::fstream file;
    int sr, sr2, wynik;
    double C = 3;
    double b = 2;
    double arr[2000];
    double D, x, y;
    double xl, yl;
    if (file.good()) {
        std::cout << "Uzyskano dostep do pliku!" << std::endl;
        //tu operacje na pliku
    }
    else {
        std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
    }
    file.open("odwrocona1.txt");
    //odwrocona dystrybuanta
    for (int i = 0; i < 2000; i++) {
        D = ((double)rand() / RAND_MAX); //losowanie z przedzia�u od 0 do 1
        //x = C - (1 / b) * log(1 - ((double)rand() / RAND_MAX));
        if (D > 0 && D < 0.5) {
            x = sqrt(2 * D);
        }
        else if (D > 0.5 && D <= 1) {
            x = 2 - sqrt(2 * (1 - D));
        }
        file << x << "\n";
       /* std::cout << "x: " << x << "\n";*/
    }
    //METODA ELIMINACJI
    //int ss=0;
    file.open("eliminacja.txt");
    for (int j = 0; j < 2000; j++) {
        x = rand() % 2;
        y = rand() % 1;
        if (x >= 0 && x <= 1) {
            if (y <= x) {
                continue;

            }
            if (y > 1) {
                if (y > 2 - x) {
                    continue;
                }
                file << x << "\n";
            }
            //xl = (double)rand() % 2;
            //xl =(100-C)*(double)rand() / RAND_MAX; //0 2 x < 1 check y < x -> nie to nowa para
            //yl = C + (double)rand()/RAND_MAX; // 0 1 x > 1 check x > 2-x -> nie to nowa para
            //if (yl <= (b* exp(-b*(xl-C)))) {
            //    //file << xl << "\n";
            //    //ss++;
            //    //std::cout << xl << "\n";
            //}
            //std::cout << xl << "\n";
        }
    
        //std::cout << ss;

        file.close();
    }

    std::vector<int> liczby(10);

    //for (auto& i : liczby)
    //{
    //    i = 5;
    //}
    //for (size_t i = 0; i < liczby.size(); i++) {
    //    std::cout << liczby[i] << "\n";
    //}
}
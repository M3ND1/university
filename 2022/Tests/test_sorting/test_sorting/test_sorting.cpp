#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>


int main(){
    srand(time(NULL));
    std::ofstream input;
    input.open("input100.in");
    long n=100, x;
    input << n << "\n";
    for (int i = 1; i <= n; i++) {
        x = rand() % 100 + 1;
        input << x << " ";
        //if (i % 10 == 0) input << "\n";
    }
    input.close();
}
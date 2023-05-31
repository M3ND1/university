#include <iostream>
#include <math.h>
#include <string>
#include <vector>


using namespace std;


int main()
{
    bool x = true, y = false;
    if (~x || y) {
        std::cout << "A";
    }
    else {
        std::cout << "B";
    }
}
#include <iostream>
#include <math.h>
int tab_check[1] = {};
int squareSum(int digit);
int main() {
    using namespace std;
    unsigned int a = 1, b = 1, sum = 0, jed = 0, dz = 0;

    while (a != 0 && b != 0) {
        unsigned int howMuchA = 0, howMuchB = 0, howMuch = 0;
        tab_check[0] = { 0 };
        cin >> a >> b;
        howMuchA = squareSum(a); //100
        howMuchB = squareSum(b); //100
        cout << "howMuchA: " << howMuchA << endl;
        cout << "howMuchB: " << howMuchB << endl;

        if (howMuchA != howMuchB) {
            cout << a << " " << b << " " << 0 << endl;
        }
        else {
            cout << a << " " << b << " " << tab_check[0] << endl;
        }
    }
    return 0;
}
int squareSum(int digit) {
    unsigned int sum = 0, jed = 0, dz = 0, i = 1;
    if (digit == 100) {
        tab_check[0] += i;
        return digit/100;
    }
    while (digit < 100) {
            dz = digit / 10;
            jed = digit % 10;
            
            digit = pow(dz, 2) + pow(jed, 2);
            sum = digit;
            if (digit > 100) { continue; }
            if (digit == 100) {
                digit = 1;
                i++;
                continue;
            }
            if (digit == 1) { break; }
            i++;
    }
    tab_check[0] += i;
    return sum;
}
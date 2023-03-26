#include <iostream>
#include <string>
#include <fstream>
#include "DiagBuffer.h"
#define DIAG_ENABLE
//
#define DIAG_BUF(message) Program::buff_in(message)
#define DIAG_OUT(filename) Program::przekazanie_do_bufora(filename)
#define DIAG(message, filename) { \
    DIAG_BUF(message); \
    DIAG_OUT(filename); \
}
#define DIAG_LEV(level) Program::diag_lev(level)
#define DIAG_INDP(filename, indent) Program::F1(filename, indent)
#define DIAG_INDM(filename, indent) Program::F2(filename, indent)

int main()
{
    int x;
    std::cin >> x;
    if (x == 0) {
        DIAG_INDP("tescik.txt", 3);
        DIAG_INDM("tescik.txt", 2);
        DIAG_BUF("time_handler_1ssasdasdasdasd not allowed z indentem\n"); // do bufora
         //
        DIAG_BUF("jakis kolejny tekst bez indentu"); // do bufora
        DIAG_OUT("tescik.txt"); // przeniesienie zawarto�ci bufora do pliku
    } else {
        DIAG("Nie udalo sie", "test.txt"); // konwersja double z 4 miejscami po przecinku + konwersja int
    }

    return 0;
}

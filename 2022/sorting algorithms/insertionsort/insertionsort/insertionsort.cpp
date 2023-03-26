// insertionsort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

void insertionsort(int* tab, int n) {
    int j;
    for (int i = 1; i < n; i++) {
        j = i;
        while (j > 0) {
            if (tab[j-1] > tab[j]) {
                std::swap(tab[j], tab[j - 1]);
            }
            j -= 1;
        }
    }
}

int main() {
    int n, x;
    std::cin >> n;
    int* tab = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        tab[i] = x;
    }
    insertionsort(tab, n);
    for (int j = 0; j < n; j++) {
        std::cout << tab[j] << " ";
    }
    delete [] tab;
}
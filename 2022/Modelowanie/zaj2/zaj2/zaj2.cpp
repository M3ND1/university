// zaj2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//metoda najmniejszych kwadratów -- !!!!      
// LICZENIE WSPOLCZNYNNIKA KIERUNKOWEGO
// zaleznosc liniowa 
//regresja liiniowa

//budujemy model
// robimy przestawienie (spin) czyli chyba zamiana dowolnego i,j
//sprawdzamy jaki ma wspó³czynnik kierunkowy
// i to powinno byc robione automatycznie xD
//w oparciu o historgram robimy b
//opracowanie modelu, z koniecznoœci¹ linearyzacji --> model 4x4 jest banalny musimy zrobic wieksze tablice
//""przejrzenie" tablicy 
//minimalna energia zawzse w demonie, losowo chodzimy po tablicy
//
#include <iostream>
#include <random>
#include <time.h>

void randomFill(int **tab[][])
int main() {
    srand(time(NULL));

    int** tab = new int* [2];
    int n;
    //std::cin >> n;
    for (int i = 0; i < 2;i++) {
        tab[i] = new int[2];
    }
    for (int i = 0; i < 2; i++) {
        std::cout << tab[i] << " ";
    }
    int x = rand() % n;
    int y = rand() % n;
    std::cout << "x: " << x << ", y:" << y;
}

#include <iostream>
void bubblesort(int* tab,int n) {
    int j;
    while (n != 0) {
        for (int i = 0; i < n - 1; i++) {
            j = i + 1;
            if (tab[i] > tab[j]) {
                std::swap(tab[i], tab[j]);
            }
            else continue;
            //std::cout << std::endl;
            //for (int k = 0; k < n; k++) {
            //    std::cout << tab[k] << " ";
            //}
        }
        n -= 1;
    }
}
int main() {
    long n, x;
    std::cin>>n;
    int *tab = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        tab[i] = x;
    }
    bubblesort(tab, n);
    //std::cout << std::endl;
    for (int j = 0; j < n; j++) {
        std::cout << tab[j] << " ";
    }
    return 0;
}
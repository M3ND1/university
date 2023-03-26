#include <iostream>
void selectionsort(int* tab,int n) {
    int min;
    for(int i=0;i<n-1;i++){
    min = i;
        for (int j = i+1; j < n; j++) {
            if (tab[j] < tab[min]) {
                min = j;
            }
        }
        std::swap(tab[min], tab[i]);
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
    selectionsort(tab, n);
    //display
    for (int j = 0; j < n; j++) {
        std::cout << tab[j] << " ";
    }
}
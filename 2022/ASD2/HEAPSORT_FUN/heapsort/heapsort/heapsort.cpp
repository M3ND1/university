#include <iostream>
using namespace std;

void add(long* tab, long n);
void print(long* tab, long n);
void max_heap(long* tab, long n, long i);
void HeapSort(long* tab, long n);

int main() {
    int howMany=0;
    cin >> howMany;
    for (int j = 0; j < howMany; j++) {
        long t_size;
        cin >> t_size;
        long* tab = new long[t_size];
        for (int i = 0; i < t_size; i++) {
                tab[i] = 0;
        }
    add(tab, t_size);
    HeapSort(tab, t_size);
    cout << endl;
    print(tab, t_size);
    delete[] tab;
    cout << endl;
    }
    return 0;
}
void add(long* tab, long n) {
    long x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        tab[i] = x;
    }
}
void HeapSort(long* tab, long n) {
    int tmp = n;  
    for (int i = (n-2)/2; i >= 0; i--) {
        max_heap(tab, n, i);
    }
    for (int i = tmp - 1; i > 0; i--) {
        for (int a = 0; a < tmp; a++) {
            cout << tab[a] << " ";
        } 
        cout << endl;
        swap(tab[0], tab[i]);
        max_heap(tab, --tmp, 0);
    }
}
void max_heap(long* tab, long n, long i) {
    int root = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    if (left < n && tab[root] < tab[left]) swap(tab[root], tab[left]);
    if (right < n && tab[root] < tab[right]) swap(tab[root], tab[right]);
}
void print(long* tab, long n) {
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
}
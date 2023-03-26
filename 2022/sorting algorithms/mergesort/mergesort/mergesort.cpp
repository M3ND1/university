// mergesort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void merge(int* arrOne, int* arrTwo, int* arr, int mid, int n);
void mergesort(int* arr, int n) {
    if (n == 1)
        return;
    int length = n;
    int mid = length / 2;
    int *arrL = new int[mid];
    int *arrR = new int[length-mid];
    for (int i = 0; i < mid; i++) { // ex. 8/2 = 4 ---> [0] ... [4] = 5 elements 
        arrL[i] = arr[i];
    }
    for (int j = mid; j < length; j++) {
        arrR[j - mid] = arr[j]; 
    }
    //for (int j = 0; j < n; j++) {
    //    std::cout << arrL[j] << " " << arrR[j];
    //}
    mergesort(arrL,mid);
    mergesort(arrR,mid);
    merge(arrL, arrR,arr,mid,length);
    delete[] arrL;
    delete[] arrR;
}

void merge(int *arrOne, int *arrTwo, int *arr, int mid, int n) {
    int i=0, j=0, k=0;

    while (i < mid && j < n) {
        if (arrOne[i] <= arrTwo[j]) {
            arr[k] = arrOne[i];
            k++;
            i++;
        }
        else {
            arr[k] = arrTwo[j];
            k++;
            j++;
        }
    }
    //if one of arrays are empty
    while (i < mid) {
        arr[k] = arrOne[i];
        i++;
        k++;
    }
    while (j < mid) {
        arr[k] = arrTwo[j];
        j++;
        k++;
    }
}
int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    mergesort(arr, n);
    for (int j = 0; j < n; j++) {
         std::cout << arr[j] << " ";
     }
    delete[] arr;
    std::cout << "Hello World!\n";
}

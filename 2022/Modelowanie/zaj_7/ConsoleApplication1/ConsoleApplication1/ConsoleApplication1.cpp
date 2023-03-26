#include <iostream>
#include <cstdio>    
#include <cstdlib>    
#include <ctime>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <random>
#include <vector>


//#define PI 3.14;
#define RM (double)RAND_MAX;
double losujRM() {
	return rand() / RM;
}
double losujE() {
	return -log(1 - losujRM());
}
void losuj3_25(std::vector<int> &x2, double d1, double n) {
	double y,x,s;
	for (int i = 0; i < n; i++) {
		x = -1;
		s = 0.0;
		while (s <= d1) {
			y = losujE();
			s += y;
			x += 1;
		}
		x2.push_back(x);
		//std::cout << x << "\n";
	}
}
void losuj3_26(std::vector<int> &x1, double lambda, int n) {
	double q,u,x,s;
	for (int i = 0; i < n; i++) {
		x = -1;
		s = 1;
		q = exp(-lambda);
		while (s > q) {
			u = losujRM();
			s = s * u;
			x++;			
		}
		x1.push_back(x);
		//std::cout << x << "\n";
	}

}
void wysWek(std::vector<int>& a) {
	for (int i : a) {
		std::cout << i << " ";
	}
	std::cout << "\n";
}
double kwadratsumy(std::vector<int> &x1) {
	//std::cout << "\n\n\n\n\n\n";
	double sol = 0;
	for (int i : x1) {
		sol += i * i;
	}
	sol /= x1.size();
	return sol;
}
//
double kwadratsredniej(std::vector<int>& x2) {
	double sol=0;
	for (int i : x2) {
		sol += i;
	}

	sol /= x2.size();

	return sol * sol;
}

std::vector<int> sumaX(std::vector<int>& x1, std::vector<int>& x2) {
	double sol = 0;
	std::vector<int> x3;
	size_t j=0;
	for(int i : x1){
		x3.push_back(i + x2[j]);
		j++;
	}
	return x3;
}

int main() {
	srand(time(NULL));
	std::vector<int> x1;
	std::vector<int> x2;
	losuj3_25(x1, 2.2,2000);
	losuj3_26(x2, 2.2,2000);
	//wysWek(x1);
	//wysWek(x2);
	kwadratsumy(x1);

	//std::cout << newton(4, 4);
	return 0;
}
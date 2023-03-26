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

void losuj2000(double sigma, double mi, int n) {
	double D, j, r;
	double arr[2000];
	int arr2[2000];
	int x;
	int h = 0;
	
	std::fstream file;
	//Odwr�cona Dystrybuanta3
	std::vector <std::pair <double, int>> pairs;
	file.open("odDystr.txt");
	for (int i = 0; i < 2000; i++) {
		D = losujRM();
		if (D >= 0 && D <= 0.2) {
			x = 2;
			file << x << "\n";
			arr[i] = D;
			arr2[i] = x;
		}
		else if (D > 0.2 && D <= 0.3) {
			x = 5;
			arr[i] = D;
			arr2[i] = x;
			file << x << "\n";
		}
		else if (D > 0.3 && D <= 0.8) {
			x = 8;
			arr[i] = D;
			arr2[i] = x;
			file << x << "\n";
		}
		else if (D > 0.8 && D < 1.0) {
			x = 13;
			arr[i] = D;
			arr2[i] = x;
			file << x << "\n";
		}
	}
	//for (int i = 0; i < 2000; i++) {
	//	std::cout << arr[i] << " " << arr2[i] << "\n";
	//}
	file.close();

	////Twierdzenie graniczne
	//file.open("twierdz.txt");
	//double mi_help = 0.5;
	//y = 0;
	//double m = 6;
	//for (int j = 0; j < 2000; j++) {
	//	x = 0;
	//	for (int k = 0; k < m; k++) {
	//		x += losuj_RM();
	//	}
	//	y = ((1 / (double)m * x) - mi_help) / (sqrt(1.0 / 12) / sqrt(m));
	//	double res = y * 1.0 + mi;
	//	file << res << "\n";
	//}
	//file.close();
	////Dystrybuanta i eliminacji
	//file.open("dystryb_elim.txt");
	////random
	//file.close();
	//file.open("biblioteka_random.txt");
	//std::random_device rd;
	//std::mt19937 GEN(rd());
	//std::normal_distribution<double> _x(5., 20);
	//for (int i = 0; i < 2000; i++) {
	//	file << _x(GEN) << "\n";
	//}
}

//

int main() {
	srand(time(NULL));
	losuj2000(7, 5, 2000);

	return 0;
}
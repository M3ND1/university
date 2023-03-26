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

unsigned long long newton(unsigned n, unsigned k) {
	if (n == k || k == 0) {
		return 1; 
	}
	return newton(n - 1, k - 1) * n / k;
}
void losuj2000(double p, double n) {
	double D, pk, r;
	int suk;
	int por = 0;
	std::fstream file;
	//wlasne wartosci n i p
	int k = n*p;
	file.open("rozkladDwumian.txt");
	//pojedyncza proba Bernouliego
	for (int a = 0; a < 1000; a++) {
		suk = 0;
		for (int i = 0; i < n; i++) {
			r = losujRM();
			if (r <= p) {
				//std::cout << 1 << "\n";
				
				suk++;
			}
			else {
				//std::cout << 0 << "\n";
				file << 0 << "\n";
				por++;
			}
			file << suk << "\n";
		}
		//std::cout << newton(suk, k) << std::endl;
		//std::cout << suk << std::endl;
		//std::cout << suk / n*p<< std::endl;

	}
	file.close();
	/*std::cout << newton(suk, k);
	file.open("rozklGeo.txt");
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << " bernouli" << std::endl;
	std::cout << std::endl;
	pk = newton(suk, k) * (pow(suk,k) * pow(por,n-k));
	std::cout << pk << std::endl;*/


	file.close();
	
	

}

//

int main() {
	srand(time(NULL));
	std::cout << "\n MYYYY:LPPPJJ \n\n\n\n";
	losuj2000(0.5, 5);
	//std::cout << newton(4, 4);
	return 0;
}
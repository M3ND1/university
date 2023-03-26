#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <vector>

using namespace std;

const int modulo = 101;
const int asci = 256;

int hashF(string str) {
	int result = 0;
	int n = str.size();
	for (int i = 0; i < n; i++) {
		//cout << endl << "str[" << i << "]: " << str[i] << " ";
		//cout << "str[" << i << "]: " << (int)str[i] << " ";
		result += abs(int(str[i]));
		if (i != str.size() - 1) {
			result *= asci;
		}
		result %= modulo;
		//result += abs(int(str[i]) * (int(pow(256, n-1))) + int(str[i + 1])) % modulo;
		//cout << endl << i << " result: " << result;
	}
	return result;
}
int calcHash(int prevhash, char prevstr, char nxtstr, int power) {
	
	unsigned int result = prevhash;
	result += modulo;
	result -= (unsigned int)(prevstr) * power % modulo;
	result *= asci;
	result += (unsigned int)(nxtstr);
	result %= modulo;

	return result;
}

int main()
{
	int n;
	cin >> n;
	streamoff wsk = cin.tellg();
	cin.seekg(2, ios::cur);
	for (int i = 0; i < n; i++)
	{
		string fname;
		string pat;

		getline(cin, fname);
		getline(cin, pat);

		ifstream f(fname);
		if (f) {
			f.seekg(0, f.end);
			int length = f.tellg();
			f.seekg(0, f.beg); 
			char* fread = new char[length];
			f.read(fread, length);
			f.close();
			int power = 1;
			for (int i = 0; i < pat.length() - 1; i++) {
				power *= asci;
				power %= modulo;
			}


			string text(fread);
			vector<int> str_found;

			const int _pat = hashF(pat);
			string startstr = text.substr(0, pat.length());
			int _startstr = hashF(startstr);
			for (int j = 0; j < length - pat.length() + 1; j++) {
				if (j != 0) {
					_startstr = calcHash(_startstr, text[j - 1], text[j + pat.length() - 1], power);
					startstr = text.substr(j, pat.length());
				}

				if (_pat == _startstr) {
					if (pat == startstr){
						str_found.push_back(j);
					}
				}
			}
			for (int i : str_found) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
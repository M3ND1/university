#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Punkt
{
    long long x = 0;
    long long y = 0;
    bool operator<(const Punkt& kolejny)const {
        if (x > 0 && kolejny.x <= 0) return true;
        else if (x == 0 && kolejny.x < 0) return true;
        else if (x * kolejny.x > 0) {
            if (long double(y) / x < long double(kolejny.y) / kolejny.x) return true;
            else if (long double(y) / x == long double(kolejny.y) / kolejny.x) return x * x + y * y < kolejny.x* kolejny.x + kolejny.y * kolejny.y;
            else return false;
        }
        else if (x == 0 && kolejny.x == 0) return y < kolejny.y;
        return false;
    }
    Punkt& operator=(const Punkt& kolejny) {
        x = kolejny.x;
        y = kolejny.y;
        return *this;
    }

    bool PoLewejLubNaLinii(const Punkt& kolejny)const {
        return 0 <= x * kolejny.y - y * kolejny.x;
    }
};


int main() {
    vector<Punkt> duze_lampiony, male_lampiony;
    duze_lampiony.reserve(10000);
    male_lampiony.reserve(50000);
    int n;
    size_t index = 0;
    cin >> n;
    Punkt tmp;
    cin >> tmp.x >> tmp.y;
    duze_lampiony.push_back(tmp);
    for (int i = 1; i < n; ++i) {
        cin >> tmp.x >> tmp.y;
        duze_lampiony.push_back(tmp);
        if (duze_lampiony[index].y > tmp.y) index = i;
        else if (duze_lampiony[index].y == tmp.y && duze_lampiony[index].x > tmp.x) index = i;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp.x >> tmp.y;
        male_lampiony.push_back(tmp);
    }
    Punkt temp;
    temp = duze_lampiony[index];
    duze_lampiony[index] = duze_lampiony[0];
    duze_lampiony[0] = temp;
    size_t k = 0;
    while (k < max(male_lampiony.size(), duze_lampiony.size())) {
        if (k < male_lampiony.size()) {
            male_lampiony[k].x -= temp.x;
            male_lampiony[k].y -= temp.y;
        }
        if (k < duze_lampiony.size()) {
            duze_lampiony[k].x -= temp.x;
            duze_lampiony[k].y -= temp.y;
        }
        ++k;
    }
    sort(duze_lampiony.begin() + 1, duze_lampiony.end());
    Punkt Wek1, Wek2;
    k = 0;
    while (k < duze_lampiony.size() - 3) {
        Wek1.x = duze_lampiony[k + 3].x - duze_lampiony[k + 1].x;
        Wek1.y = duze_lampiony[k + 3].y - duze_lampiony[k + 1].y;
        Wek2.x = duze_lampiony[k + 2].x - duze_lampiony[k + 1].x;
        Wek2.y = duze_lampiony[k + 2].y - duze_lampiony[k + 1].y;
        if (Wek1.PoLewejLubNaLinii(Wek2)) {
            duze_lampiony.erase(duze_lampiony.begin() + k + 2);
            if (k != 0) k--;
        }
        else k++;
    }
    size_t modulo = duze_lampiony.size();
    k = 0;
    for (size_t i = 0; i < modulo; i++) {
        Wek1.x = duze_lampiony[(i + 1) % modulo].x - duze_lampiony[i].x;
        Wek1.y = duze_lampiony[(i + 1) % modulo].y - duze_lampiony[i].y;
        k = 0;
        while (k < male_lampiony.size()) {
            Wek2.x = male_lampiony[k].x - duze_lampiony[i].x;
            Wek2.y = male_lampiony[k].y - duze_lampiony[i].y;
            if (Wek1.PoLewejLubNaLinii(Wek2)) k++;
            else male_lampiony.erase(male_lampiony.begin() + k);
        }
    }
    cout << male_lampiony.size() << endl;
    return 0;
}
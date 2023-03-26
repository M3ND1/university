#include <iostream>
#include <math.h>

using namespace std;

int closestPowerOfTwo(int teams) { return (pow(2, ceil(log2(teams)))); }
bool isPowerOfTwo(int teams) { return (ceil(log2(teams)) == floor(log2(teams))); }
int groupStageMatches(int g, int t) {
    int gsmatches = 0;
    for (int i = 0; i < t; i++) {
        gsmatches += i;
    }
    return (gsmatches * g);
}
int knockoutStageMatches(int teams) {
    int matchesinfirstround = teams / 2;
    int miks = 0;

    for (int i = matchesinfirstround; i >= 1; i /= 2) {
        miks += i;
    }
    return miks;
}
int main() {
    int g = 0, t = 0, a = 0, d = 0, pom = 0;
    while (g != -1 && t != -1 && a != -1 && d != -1) {
        unsigned int gsmatches = 0, ksmatches = 0, teamsinks = 0, X = 0, Y = 0;
        bool checkPower;
        cin >> g >> t >> a >> d;
        teamsinks = (g * a) + d;
        checkPower = isPowerOfTwo(teamsinks);
        if ((checkPower != true) || (g, t, a, d) >= 0) {
            pom = closestPowerOfTwo(teamsinks);
            gsmatches = groupStageMatches(g, t);
            ksmatches = knockoutStageMatches(pom);

            X = gsmatches + ksmatches;
            Y = pom - teamsinks;
            cout << g << "*" << a << "/" << t << "+" << d << "=" << X << "+" << Y << endl;

        }
        else if (checkPower == true || g, t, a, d >= 0) {
            gsmatches = groupStageMatches(g, t);
            teamsinks = knockoutStageMatches(teamsinks);

            X = gsmatches + teamsinks;
            Y = pom - teamsinks;
            cout << g << "*" << a << "/" << t << "+" << d << "=" << X << "+" << Y << endl;
        }
    }
    return 0;
}
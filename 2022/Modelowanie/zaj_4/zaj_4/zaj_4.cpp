//1. wybieramy nasze 3 ró¿ne kana³y (np. forma zespo³u, pogoda, doœwiadczenie zespo³u)
//2. losujemy je, zliczamy z nich sumê i wyliczamy œredni¹ któr¹ potem
//3. wrzucamy do danej metody np poisson(srednia_z_naszych_kanalow);
//4. Za kolejnym razem wybieramy inn¹ metodê np bernoulli(srednia_z_naszych_kanalow); itd itp.
//5. iterujemy to 5000 razy i z tego wychodzi nam ita faza
//6. wracamy do punktu pierwszego i robimy 5 takich faz
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <random>
#include <map>
#include <iomanip>
#include <string>

////#define PI 3.14;
#define RM (double)RAND_MAX;
//
double losuj_RM();
int uni_int_distr(std::mt19937& gen);
int discret_distr(std::mt19937& gen);
double poisson(double);
double phase_1(int, double, int, std::mt19937& gen);
double phase_2(int, double, int, std::mt19937& gen);
double phase_3(int, double, int, std::mt19937& gen);
double phase_4(int, double, int, std::mt19937& gen);
double phase_5(int, double, int, std::mt19937& gen);
double phase_6(int, double, int, std::mt19937& gen);
double phase_7(int, double, int, double, std::mt19937& gen);

int main() {
    int n;
    std::cin >> n;
    int phases = 5;
    std::random_device rd;
    std::mt19937 gen(rd());
    //losowanie wartosci
    //3 kana³y
    int sol = 0;
    int shots_on_goal = 0; //6
    double team_experience = 0.0; //doswiadczenie zespolu 0.8
    double los;
    int team_form = 0;//forma zawodnikow // 9
    //
    double probability = 0, sum = 2.1;
    bool extra_time = true;
    double pressure = 0.2;
        std::vector<double> v_prob(n, 0);
        for (int i = 0; i < n; i++) {
            //faza grupowa
            v_prob[i] += phase_1(shots_on_goal, team_experience, team_form, gen);
            v_prob[i] += phase_2(shots_on_goal, team_experience, team_form, gen);
            v_prob[i] += phase_3(shots_on_goal, team_experience, team_form, gen);
            ////faza pucharowa
            v_prob[i] += phase_4(shots_on_goal, team_experience, team_form, gen); // dla fazy pucharowej liczone jest prawdp doliczonego
            v_prob[i] += phase_5(shots_on_goal, team_experience, team_form, gen); // czasu gry bernoullim
            v_prob[i] += phase_6(shots_on_goal, team_experience, team_form, gen);
            ////final 
            v_prob[i] += phase_7(shots_on_goal, team_experience, team_form, pressure, gen); // w finale w zaleznosci od doœwiadczenia zespo³u
        }                                                                                   //doliczana jest presja (to przecie¿ gra w finale)
        for (auto& j : v_prob){
            std::cout << j/70.0 << "\n";
        }
}
double losuj_RM() {
    return rand() / RM;
}
int discret_distr(std::mt19937& gen) {
    int sol = 0;

    std::discrete_distribution<int> distr({ 0.06, 0.09, 0.2, 0.5, 0.15 }); //  
    sol = distr(gen);

    return sol;
}
double poisson(double sum) { // kto wygra fina³ mistrzostw
    std::random_device rd;
    std::mt19937 gen(rd());
    double los;

    std::poisson_distribution<> pd(sum);
    los = pd(gen);
    if (los >= 10.0) { // jesli los wyjdzie >= 10.0 forma zespolu jest bardzo dobra wiec to pewne ze wygraj¹
        los = 10.0;
    }
    return los;
}
double bern(double sum) { // kto wygra fina³ mistrzostw
    std::random_device rd;
    std::mt19937 gen(rd());
    double los;

    std::bernoulli_distribution distr(sum);
    los = distr(gen);

    return los;
}
int uni_int_distr(std::mt19937& gen) {
    int form = 0;
    std::uniform_int_distribution<> distr(0, 10);
    form = distr(gen);

    return form;
}
double phase_1(int sog, double te, int tf, std::mt19937& gen) {
    double sol = 0.0;
    double temp = 0.0;
    sog = discret_distr(gen) * 2; //6
    te = losuj_RM(); //doswiadczenie zespolu 0.8
    tf = discret_distr(gen); // 4
    temp += (sog + te + tf);
    sol = poisson(temp);
    return sol;
}
double phase_2(int sog, double te, int tf, std::mt19937& gen) {
    double sol = 0.0;
    double temp = 0.0;
    sog = discret_distr(gen) * 2; //6
    te = losuj_RM(); //doswiadczenie zespolu 0.8
    tf = discret_distr(gen); // 4
    temp += (sog + te + tf);
    sol = poisson(temp);
    return sol;
}
double phase_3(int sog, double te, int tf, std::mt19937& gen) {
    double sol = 0.0;
    double temp = 0.0;
    sog = discret_distr(gen) * 2; //6
    te = losuj_RM(); //doswiadczenie zespolu 0.8
    tf = discret_distr(gen); // 4
    temp += (sog + te + tf);
    sol = poisson(temp);
    return sol;
}
//faza pucharowa
double phase_4(int sog, double te, int tf, std::mt19937& gen) {
    double sol = 0.0;
    double temp = 0.0;
    double e_t = 0.0;
    sog = discret_distr(gen) * 2; //8
    te = losuj_RM(); //doswiadczenie zespolu 0.9
    tf = uni_int_distr(gen); // 4

    temp += (sog + te + tf);
    double t = temp / 20.0;
    if (t > 1.0) {
        t = 0.99;
    } else if (t < 0.0) {
        t = 0.01;
    }
    e_t = bern(t); // 0 1
    if (e_t == 1.0) {
        if (temp >= 10.0 && temp < 12.0) {
            temp -= 3.0;
        }
        else if (temp >= 7.0 && temp < 10.0) {
            temp -= 1.8;
        }
        else if (temp >= 3.0 && temp < 7.0) {
            temp -= 1.0;
        }
        else if (temp > 1.0 && temp < 3.0) {
            temp -= 0.4;
        }
        else if (temp < 1.0) {
            temp += 0.01;
        }
    }
    sol = poisson(temp);
    return sol;
}
double phase_5(int sog, double te, int tf, std::mt19937& gen) {
    double sol = 0.0;
    double temp = 0.0;
    double e_t = 0.0;
    sog = discret_distr(gen) * 2; //8
    te = losuj_RM(); //doswiadczenie zespolu 0.9
    tf = uni_int_distr(gen); // 4

    temp += (sog + te + tf);
    double t = temp / 19.0;
    if (t > 1.0) {
        t = 0.99;
    }
    else if (t < 0.0) {
        t = 0.01;
    }
    e_t = bern(t); // 0 1
    if (e_t == 1.0) {
        if (temp >= 10.0 && temp < 12.0) {
            temp -= 3.0;
        }
        else if (temp >= 7.0 && temp < 10.0) {
            temp -= 1.8;
        }
        else if (temp >= 3.0 && temp < 7.0) {
            temp -= 1.0;
        }
        else if (temp > 1.0 && temp < 3.0) {
            temp -= 0.4;
        }
        else if (temp < 1.0) {
            temp += 0.01;
        }
    }
    sol = poisson(temp);
    return sol;
}
double phase_6(int sog, double te, int tf, std::mt19937& gen) {
    double sol = 0.0;
    double temp = 0.0;
    double e_t = 0.0;
    sog = discret_distr(gen) * 2; //8
    te = losuj_RM(); //doswiadczenie zespolu 0.9
    tf = uni_int_distr(gen); // 4

    temp += (sog + te + tf);
    double t = temp / 20.0;
    if (t > 1.0) {
        t = 0.99;
    }
    else if (t < 0.0) {
        t = 0.01;
    }
    e_t = bern(t); // 0 1
    if (e_t == 1.0) {
        if (temp >= 10.0 && temp < 12.0) {
            temp -= 3.0;
        }
        else if (temp >= 7.0 && temp < 10.0) {
            temp -= 1.8;
        }
        else if (temp >= 3.0 && temp < 7.0) {
            temp -= 1.0;
        }
        else if (temp > 1.0 && temp < 3.0) {
            temp -= 0.4;
        }
        else if (temp < 1.0) {
            temp += 0.01;
        }
    }
    sol = poisson(temp);
    return sol;
}
//fina³
double phase_7(int sog, double te, int tf, double pressure, std::mt19937& gen) {
    double sol = 0.0;
    double temp = 0.0;
    double e_t = 0.0;
    sog = discret_distr(gen) * 2; //8
    te = losuj_RM(); //doswiadczenie zespolu 0.9
    tf = uni_int_distr(gen); // 4

    temp += (sog + te + tf);
    double t = temp / 20.0;
    if (t > 1.0) {
        t = 0.99;
    }
    else if (t < 0.0) {
        t = 0.01;
    }
    e_t = bern(t); // 0 1
    if (e_t == 1.0) {
        if (temp >= 10.0 && temp < 12.0) {
            temp -= 2.0;
            temp -= pressure;
        }
        else if (temp >= 7.0 && temp < 10.0) {
            temp -= 1.2;
            temp -= (pressure * 2);
        }
        else if (temp >= 3.0 && temp < 7.0) {
            temp -= 0.5;
            temp -= (pressure * 3);
        }
        else if (temp > 1.0 && temp < 3.0) {
            temp -= 0.1;
            temp -= pressure;
        }
        else if (temp > 12) {
            temp += 0.05;
            temp -= pressure;
        }
        else if (temp < 1.0) {
            temp += 0.01;
        }
    }
    sol = poisson(temp);
    return sol;
}
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <cmath>
int randomXY(std::vector<std::vector<int>> &demon) {
    return rand() % demon.size();
}
void displayDemon(std::vector<std::vector<int>> &demon) {
    for (std::vector<int> row : demon) {
        for (int j : row) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}
int getEnergy(std::vector<std::vector<int>> &demon){
    int n = demon.size();
    int energy=0;
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<n;j++) {
            energy += -1 * demon[i][j] * (demon[(i + 1) % n][j] + demon[i][(j + 1) % n]);
        }
    }
    return energy;
}
double getMagnetization(std::vector<std::vector<int>>& demon) {
    double avr = 0;
    int n = demon.size(); //square 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            avr += demon[i][j];
        }
    }
    avr /= n*n;
    return avr;
}
int main() {
    srand(time(NULL));
    int x, y, howManySteps, howManySim, k, energyStart, a, b, energy, n, simEnergy, energiesDemon,Sx,Sxx,numberOfX;
    double t,_a=0.0, magnet, avrMag, Sxy, Sy;
    std::cin >> x >> y >> howManySteps >> howManySim;
    std::vector<int> demonEnergy(howManySim);

    for (int i = 0; i < howManySim;i++) {
        std::cin >> k;
        demonEnergy[i]= k;
    }
    avrMag = 0;
    std::vector<double> temperature;
    for (int i = 0; i < howManySim; i++) {
        std::vector<std::vector<int>> demon(x, std::vector<int>(y, 1));
        std::vector<double> magnetization;
        std::vector<int> demonEnergies;
        std::vector<int> systemEnergy;
        std::vector<int> histogram(5,0);

        //counting first energy from demon
        energyStart = getEnergy(demon);
        energiesDemon = demonEnergy[i];
        //demon size
        n = demon.size();        
        magnet = getMagnetization(demon); 
        magnetization.push_back(magnet);
        demonEnergies.push_back(energiesDemon);
        systemEnergy.push_back(energyStart);
        /// ======================================== ////
        for (int j = 0; j < howManySteps; j++) { //n steps of demon's energy
            energy = getEnergy(demon);
            //random indexes
            a = randomXY(demon);
            b = randomXY(demon);
            //demon's energy
            energy = 2 * demon[a][b] 
                * (demon[a][(b + 1 + demon[0].size()) % demon[0].size()] 
                + demon[a][(b - 1 + demon[0].size()) % demon[0].size()] 
                + demon[(a + 1 + demon.size()) % demon.size()][b]
                + demon[(a - 1 + demon.size()) % demon.size()][b]);
            if ((energiesDemon >= energy && energy >= 0) || energy < 0) {
                demon[a][b] = -demon[a][b];
                energiesDemon -= energy;
                energyStart += energy;
                //if (demon[a][b] == 1) {
                //    magnet *= n * n;
                //    magnet += 2;
                //    magnet /= n * n;
                //}
                //else if (demon[a][b] == -1) {
                //    magnet *= n * n;
                //    magnet -= 2;
                //    magnet /= n * n;
                //}
                if (energiesDemon >= 0 && energiesDemon <= 16) {
                    if (energiesDemon == 0) {
                        histogram[0]++;
                    }
                    else if (energiesDemon == 4) {
                        histogram[1]++;
                    }
                    else if (energiesDemon == 8) {
                        histogram[2]++;
                    }
                    else if (energiesDemon == 12) {
                        histogram[3]++;
                    }
                    else if (energiesDemon == 16) {
                        histogram[4]++;
                    }
                }
                
            }
            magnetization.push_back(magnet);
            demonEnergies.push_back(energiesDemon);
            systemEnergy.push_back(energyStart);
        }
        //temperature
        Sxy = 0.0;
        Sy = 0.0;
        Sx = 0;        
        Sxx = 0;
        numberOfX = 0;
        for (int _k = 0; _k < histogram.size(); _k++) {
            if (histogram[_k] == 0) {
                continue;
            }
            numberOfX++;
            Sx  += _k*4;
            Sxy += _k * 4 * log(histogram[_k]);
            Sxx +=  (_k *4)*(_k *4);
            Sy  += log(histogram[_k]);
        }
        _a = (numberOfX * Sxy - Sx * Sy) / (numberOfX * Sxx - Sx * Sx);
        t = 1 / (-_a);
        temperature.push_back(t);
        for (int i = 0; i < magnetization.size(); i++) {
            avrMag += magnetization[i];
        }
        avrMag /= magnetization.size();
        for (int i = 0; i < magnetization.size(); i++) {
            std::cout << magnetization[i] << "\t" << demonEnergies[i] <<"\t" << avrMag << "\n";
        }
        for (auto& hist : histogram) {
            std::cout << hist << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
    for (int i = 0; i < temperature.size(); i++) {
        std::cout << temperature[i] << "\n";
    }
    return 0;
}

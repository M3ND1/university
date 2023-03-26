// Demon.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu. 
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int licz_energie(std::vector < std::vector<int>>& vek);
std::pair<size_t, size_t> losuj_index(std::vector <std::vector<int>>& vek);

int main()
{
    srand(time(0));
    int x, y, liczba_krokow,ilosc_symulacji,energia_tmp,energia_ukl;
    std::cin >> x >> y>> liczba_krokow >> ilosc_symulacji;
    
    std::vector<int> energie_demona(ilosc_symulacji);
    for (auto& i : energie_demona)
    {
        std::cin >> i;
    }

    std::vector<std::vector<int>> val(x,std::vector<int>(y,1));
    energia_ukl = licz_energie(val);
    
    while (liczba_krokow--)
    {
        std::cout << "Energia ukladu: "<<energia_ukl << "\nEnergia demona: "<<energie_demona[0]<<std::endl;
        std::pair<size_t, size_t> indeksy = losuj_index(val);
        energia_tmp = 2 * val[indeksy.first][indeksy.second] 
           * (val[indeksy.first][(indeksy.second + 1 + val[0].size()) % val[0].size()]
            + val[indeksy.first][(indeksy.second - 1 + val[0].size()) % val[0].size()]
            + val[(indeksy.first + 1 + val.size()) % val.size()][indeksy.second]
            + val[(indeksy.first - 1 + val.size()) % val.size()][indeksy.second]);
        if (energie_demona[0]>=energia_tmp && energia_tmp>0 || energia_tmp<=0)
        {
            val[indeksy.first][indeksy.second] = -val[indeksy.first][indeksy.second];
            energie_demona[0] -= energia_tmp;
            energia_ukl += energia_tmp;
        }
    }

    return 0;
}

int licz_energie(std::vector <std::vector<int>>& vek)
{
    int sol = 0;
    for (size_t i = 0; i < vek.size(); ++i)
    {
        for (size_t j = 0; j < vek[i].size(); ++j)
        {
            sol += -1 * vek[i][j] * (vek[(i+1)% vek.size()][j] + vek[i][(j+1)% vek[i].size()]);
        }
    }
    return sol;
}

std::pair<size_t, size_t> losuj_index(std::vector <std::vector<int>>& vek)
{
    std::pair< size_t, size_t> sol;
    sol.first = rand() % vek.size();
    sol.second = rand() % vek[0].size();

    return sol;
}

 
 

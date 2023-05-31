#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Item
{
    char ch;
    double probability;
    string key;
};

void setCodes(std::vector<Item>::iterator it_beg,
    std::vector<Item>::iterator it_end,
    int size, char codeAppend = '*')
{
    if (size == 0)
        return;
    if (size == 1)
    {
        if (codeAppend == '*')
            (*it_beg).key += '0';
        else
            (*it_beg).key += codeAppend;
        return;
    }
    else
    {
        double sumProb{};
        vector<double> probSoFar{};
        for (auto it = it_beg; it != it_end; it++)
        {
            sumProb += (*it).probability;
            probSoFar.push_back(sumProb);
            if (codeAppend != '*')
                (*it).key += codeAppend;
        }
        probSoFar.pop_back();

        int index{};
        double min{ 1.0 };
        int i{};
        for (; i < probSoFar.size(); i++)
        {

            if (abs(probSoFar[i] - (sumProb / 2.0)) < min)
            {
                index = i;
                min = abs(probSoFar[i] - (sumProb / 2.0));
            }
            i++;
        }

        setCodes(it_beg, it_beg + index + 1, index + 1, '0');
        setCodes(it_beg + index + 1, it_end, size - (index + 1), '1');
    }
}

int main()
{

    string input;
    cin >> input;

    map<char, int> frequency;
    int count{};
    for (auto ch : input)
    {
        frequency[ch]++;
        count++;
    }

    vector<Item> items;
    for (auto a : frequency)
        items.push_back({ a.first, static_cast<double>(a.second) / count, "" });

    sort(items.begin(), items.end(),
        [](const auto& a, const auto& b) -> bool
        {
            return a.probability > b.probability;
        });

    setCodes(items.begin(), items.end(), items.size());

    for (auto item : items)
    {
        cout << item.ch << ": probability: " << item.probability << " binary: " << item.key << endl;
    }

    cout << "binary code: ";
    for (auto ch : input)
    {
        auto res = find_if(items.begin(), items.end(),
            [ch](const Item& a)
            {
                return (a.ch == ch);
            });
        if (res != items.end())
            cout << (*res).key;
    }

    return 0;
}
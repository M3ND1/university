#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>

using namespace std;
struct edge {
    int from;
    int to;
    int weight;
};
struct compare {
    bool operator()(const edge& left, const edge& right) {
        return left.weight > right.weight;
    }
};
void DFS(vector<vector<edge>>* mst, stack<edge>* path, int start, int end, int prev_vertex = 0, bool* found = NULL) {
    if (found == NULL) {
        found = new bool(false);
    }
    for (int i = 0; i < (*mst).at(start).size(); i++) {
        int to = (*mst).at(start).at(i).to;
        if (to == prev_vertex) {
            continue;
        }
        path->push((*mst).at(start).at(i));
        if (to == end) {
            *found = true;
            return;
        }
        else {
            DFS(mst, path, to, end, start, found);
            if (*found == true) {
                return;
            }
            else {
                path->pop(); //pop last
            }
        }
    }
}
int main() {
    int cities, _edges, _from, _to, _weight;
    cin >> cities >> _edges;
    vector<vector<edge>> _lista(cities + 1); //x tab w x tab
    //^ 1 2 20  ^ np. tab[i][j][z]
    for (int i = 0; i < _edges; i++) {
        cin >> _from >> _to >> _weight;
        edge e;
        e.from = _from;
        e.to = _to;
        e.weight = (-1) * _weight;
        edge e1;
        e1.from = _to;
        e1.to = _from;
        e1.weight = (-1) * _weight;
        _lista[_from].push_back(e);
        _lista[_to].push_back(e1);
    }
    //mst 
    vector<vector<edge>> mst(cities + 1);
    unordered_set<int> citiesmst;
    priority_queue<edge, vector<edge>, compare> pq;
  
    citiesmst.insert(1); // default vertex
    for (int i = 0; i < _lista[1].size(); i++) {
        pq.push(_lista[1][i]);
    }
    //pushowanie do mst
    while (citiesmst.size() < cities) {
        edge _e = pq.top();
        pq.pop();
        if (citiesmst.count(_e.from) == 1 && citiesmst.count(_e.to) == 1) {
            continue;
        }
        else {
            citiesmst.insert(_e.to); // e.to zawiera sie w mst
            mst[_e.from].push_back(_e);
            edge _e1;
            _e1.from = _e.to;
            _e1.to = _e.from;
            _e1.weight = _e.weight;
            mst[_e1.from].push_back(_e1);
            for (int j = 0; j < _lista[_e.to].size(); j++) {
                pq.push(_lista[_e.to][j]);
            }
        }
    }
    //dfs
    int start, end, passengers;
    cin >> start >> end;
    while (start != 0 && end != 0) {
        cin >> passengers;
        stack<edge> path;
        DFS(&mst, &path, start, end);
        //minstack
        int min_passengers = INT_MAX;
        while (!path.empty()) {
            edge e = path.top();
            path.pop(); // najmniejszy
            if (-e.weight < min_passengers) {
                min_passengers = -e.weight;
            }
        }
        min_passengers -= 1; //driver
        double liczba_kursow = (double)(passengers) / (double)(min_passengers);
        liczba_kursow = ceil(liczba_kursow); //zaokraglenie
        cin >> start >> end;
        cout << liczba_kursow << endl;
    }
    return 0;
}
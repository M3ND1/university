#include <iostream>
#include <string>
using namespace std;

struct HashTable { 
    long key = NULL;
    string x_string=""; 
    bool zajete = false;
};

class Hash_Function {
public:
    HashTable* wsk;
    long t_size=0;
    int n_elements=0;
    Hash_Function();
    ~Hash_Function();
    void size(long n);
    void add(long k, string x);
    void search(int index);
    void swap(int i1,int i2);
    void delete_h(long k);
    long hash(long k); 
    void print();
    HashTable get(long k);
    
};
HashTable Hash_Function::get(long k) {
    HashTable h_null;
    if (n_elements == 0) return h_null;
    long tab_i = hash(k);
    for (int i = 0; i < t_size; i++) {
        if (wsk[hash(k+i)].key == k) {
            return wsk[hash(k + i)];
        }
    }
    return h_null;
} 
Hash_Function::Hash_Function() {

}
Hash_Function::~Hash_Function() {
    delete[] wsk;
}
void Hash_Function::size(long n) { 
    wsk = new HashTable[n];
    t_size = n;
}
long Hash_Function::hash(long k) {
    return (k % t_size);
}
void Hash_Function::add(long k, string x) {
    long tab_i = hash(k);
    if (wsk[tab_i].key == k) {
        wsk[tab_i].x_string = x;
        wsk[tab_i].zajete = true;
        return;
    }else if (n_elements == t_size) {
        return;
    }
    else {
        for (int i = 0; i < t_size; i++) {
            if (wsk[hash(k + i)].key == NULL) {
                wsk[hash(k + i)].key = k;
                wsk[hash(k + i)].x_string = x;
                wsk[hash(k + i)].zajete = true;
                n_elements++;
                return;
            }
        }
    }
}
void Hash_Function::swap(int i1, int i2) {
    HashTable temp = wsk[i1];
    wsk[i1] = wsk[i2];
    wsk[i2] = temp;
}
void Hash_Function::search(int index) {
    int null_i=index;
    HashTable h_null;
    for (int i = 1; i < t_size; i++) {
        HashTable h = wsk[hash(index + i)];
        if (h_null.key == h.key) return;
        else if (h.key % t_size == hash(index + i)) continue;
        else {
            swap(null_i, hash(index + i));
            null_i = hash(index + i);
        }
    }
}
void Hash_Function::delete_h(long k) {
    if (n_elements == 0) return;
    else if (k != get(k).key) {
        return;
    }else {
        HashTable h = get(k);
        for (int i = 0; i < t_size; i++) {
            if (wsk[i].key == get(k).key) {
                wsk[i].key = NULL;
                wsk[i].x_string = "";
                wsk[i].zajete = false;
                n_elements--;
                search(i);
            }
        }
    }
    
    long tab_i = hash(k);
}
void Hash_Function::print() {    
    for (int i = 0; i < t_size; i++) {
        if (wsk[i].zajete != false) {
            cout << i << " " << wsk[i].key << " " << wsk[i].x_string << endl;
        } 
    }
}

int main() {
    Hash_Function x;
    long n, s, key;
    string fun,x_str;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> fun;
        while (fun != "stop") {
            if (fun == "size") {
                cin >> s;
                x.size(s);
            } else if (fun == "add") {
                cin >> key >> x_str;
                x.add(key, x_str);
            } else if (fun == "print") {
                x.print();
            } else if (fun == "delete") {
                cin >> key;
                x.delete_h(key);
            }cin >> fun;
        }
    }
}
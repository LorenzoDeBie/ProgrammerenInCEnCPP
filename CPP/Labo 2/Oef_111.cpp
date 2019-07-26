#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct persoon {
    string naam;
    int leeftijd;
};

ostream& operator<<(ostream&, const persoon &);

template <typename T>
ostream& operator<<(ostream&, const vector<T> &);

template <typename T>
void schrijf(const vector<T> &);

int main() {

    vector<string> v1(6);
    for(int i = 0; i < v1.size(); i++) {
        v1[i] = "testString";
    }

    //structs veld per veld initialiseren!
    vector<persoon> v2(1);
    v2[0].naam = "Lorenzo";
    v2[0].leeftijd = 20;

    vector<vector <int>> v3(2);

    v3[0] = vector<int>(3);
    v3[0][0] = 1;
    v3[0][1] = 2;
    v3[0][2] = 3;

    v3[1] = vector<int>(4);
    v3[1][0] = 1;
    v3[1][1] = 2;
    v3[1][2] = 3;
    v3[1][3] = 4;

    schrijf(v1);

    schrijf(v2);

    schrijf(v3);
    return 0;
}

template <typename T>
void schrijf(const vector<T> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
        cout << endl;
    }
}

ostream& operator<<(ostream& out, const persoon & p){
    out<<p.naam<<" ("<<p.leeftijd<<" j)";
    return out;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T> &v) {
    for(int i = 0; i < v.size(); i++) {
        out << v[i] << " ";
    }
    return out;
}
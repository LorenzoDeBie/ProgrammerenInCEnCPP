//gaat verder op oef 111
#include "headers/containers.h"
using namespace std;

struct persoon {
    string naam;
    int leeftijd;
};

ostream& operator<<(ostream& out, const persoon & p){
    out<<p.naam<<" ("<<p.leeftijd<<" j)";
    return out;
}

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

    cout << v1;

    cout << endl << v2;

    cout << endl << v3;

    //Oef 112

    set<int> s1;
    s1.insert(2);
    s1.insert(5);

    cout << endl << s1;

    stack<int> st1;
    st1.push(2);
    st1.push(5);

    cout << endl << st1;

    map<int, int> m1;

    m1[0] = 2;
    m1[18] = 5;

    cout << endl << m1;

    return 0;
}

#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct persoon {
    string naam;
    int leeftijd;
};

template <typename T>
void schrijf(vector<T> &);

int main() {

    vector<string> v1(6);
    for(int i = 0; i < v1.size(); i++) {
        v1[i] = "testString";
    }

    schrijf(v1);

    return 0;
}

template <typename T>
void schrijf(vector<T> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

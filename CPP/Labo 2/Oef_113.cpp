#include "headers/containers.h"

#define AANTAL 5

int main() {

    stack<string> st1;

    st1.push("een");
    st1.push("twee");
    st1.push("drie");

    cout << st1 << endl;

    vector<string> v1[AANTAL];

    v1[1] = vector<string>(3);

    v1[1][0] = "aap";
    v1[1][1] = "noot";
    v1[1][2] = "mies";

    cout << v1[0] << endl;
    cout << v1[1] << endl;
    cout << v1[2] << endl;

    //why u do dis?
    vector<vector<string>> v3;

    cout << v3 << endl;

    vector<vector<int>> v2(AANTAL);

    for(int i = 0; i < AANTAL; i++) {
        v2[i] = vector<int>(i);
        for(int n = 1; n <= i; n++) {
            v2[i][n] = n * 10;
        }
    }

    cout << v2 << endl;

    return 0;
}
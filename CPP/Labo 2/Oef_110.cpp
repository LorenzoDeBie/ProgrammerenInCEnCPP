#include <iostream>
#include <functional>
#include <string>

using namespace std;

void vul_array(const int[], const int[], int[], int, function<int (int, int)>);
void schrijf(const string &, const int[], int);

int main() {
    const int GROOTTE = 10;
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int b[] = {0,10,20,30,40,50,60,70,80,90};
    int c[GROOTTE];
          
    vul_array(a,b,c,GROOTTE,[](int a, int b){return a+b;});
    schrijf("SOM:      ",c,GROOTTE);
    vul_array(a,b,c,GROOTTE, [](int a, int b){return a*b;});
    schrijf("PRODUCT:  ",c,GROOTTE);
    vul_array(a,b,c,GROOTTE,[](int a, int b){return a-b;});
    schrijf("VERSCHIL: ",c,GROOTTE);
    
    return 0;
}

//VERB: const vergeten!!!
void vul_array(const int a[], const int b[], int c[], int size, function<int (int, int)> func) {
    for(int i = 0; i < size; i++) {
            c[i] = func(a[i], b[i]);
    }
}

//VERB: const vergeten en string doorgeven by reference!
void schrijf(const string &s, const int n[], int size) {
    cout << s;
    for(int i = 0; i < size; i++) {
            cout << " " << n[i];
    }
    cout << endl;
}
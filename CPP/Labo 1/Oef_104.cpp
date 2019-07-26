#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string genereer_string(int);
void vul_array_met_strings(string[], int, int);
void schrijf(const string[], int);
void bepaal_min_en_max(const string[], int, string &, string &);

int main() {
    //deelvraag 1
    srand(time(NULL));
    string s = genereer_string(50);
    cout << s << endl;
    //deelvraag 2
    string arr[4];
    vul_array_met_strings(arr, 4, 50);
    for(int i = 0; i < 4; i++) {
        cout << arr[i] << endl;
    }
    //deelvraag 3
    schrijf(arr, 4);
    //deelvraag 4
    string min = "", max = "";
    bepaal_min_en_max(arr, 4, min, max);
    cout << "min: " << min << endl << "max: " << max << endl;
    return 0;
}

string genereer_string(int n) {
    string result = "";
    for(int i = 0; i < n; i++) {
        result += (char)('a' + rand() % 25);
    }
    return result;
}

void vul_array_met_strings(string tab[], int n, int len) {
    for(int i = 0; i < n; i++) {
        tab[i] = genereer_string(len);
    }
}

void schrijf(const string tab[], int n) {
    for(int i = 0; i < n; i++) {
        cout << tab[i] << endl;
    }
}

void bepaal_min_en_max(const string tab[], int n, string &min, string &max) {
    min = tab[0]; max = min;
    for(int i = 1; i < n; i++) {
        if(tab[i] < min) {
            min = tab[i];
        }
        if(tab[i] > max) {
            max = tab[i];
        }
    }
}
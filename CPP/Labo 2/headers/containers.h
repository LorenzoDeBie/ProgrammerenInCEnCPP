#include <map>
#include <vector>
#include <set>
#include <stack>
#include <iostream>
#include <string>

using namespace std;


//schrijf een map
template <typename T, typename N>
ostream& operator<<(ostream& out, const map<T, N> &m) {
    typename map<T, N>::const_iterator cim = m.begin();
    if(m.empty()) {
        return out;
    }
    out << cim->first << "->" << cim->second;
    cim++;
    while(cim != m.end()) {
        out << endl << cim->first << "->" << cim->second;
        cim++;
    }
    return out;
}

//schrijf een vector
template <typename T>
ostream& operator<<(ostream& out, const vector<T> &v) {
    for(int i = 0; i < v.size(); i++) {
        out << "vector[" << i << "]:" << endl;
        out << v[i] << "; " << endl;
    }
    return out;
}

//schrijf een set
template <typename T>
ostream& operator<<(ostream& out, const set<T> &s) {
    typename set<T>::const_iterator cis = s.begin();
    out << "{" << *cis++;
    while(cis != s.end()) {
        out << ", " << *cis++;
    }
    out << "}";
    return out;
}

//schrijf een stack
template <typename T>
ostream& operator<<(ostream& out, stack<T> &s) {
    while(!s.empty()) {
        out << s.top() << endl;
        s.pop();
    }
    return out;
}
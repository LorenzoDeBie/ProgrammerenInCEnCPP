#include <iostream>
#include "./../../headers/containers.h"

using namespace std;

template<typename T>
class mijn_vector : public vector<T> {
    using vector<T>::vector; //constructor gebruiken 
    
    public:
        void verdubbel(bool=false);
};

template<typename T>
void mijn_vector<T>::verdubbel(bool verdubbel_grootte) {
    if(verdubbel_grootte) { //verdubbelt de grootte v/d vector ipv inhoud
        typename vector<T>::iterator it = (*this).begin();
        while(it != (*this).end()) {
            //cout << *it << endl;
            it =(*this).insert(it, *it);//insert new T before current pos
            it += 2; //move two places (two because inserted one)
        }
    }
    else { //verdubbelt de inhoud
        for(int i = 0; i < (*this).size(); i++) {
            (*this)[i] *= 2;
        }
    }
}


int main(){	
    mijn_vector<int> v{10,20,30}; 
    cout << v;

    v.verdubbel();              
    cout<<endl<<"na verdubbelen zonder parameter: " << v;	
    v.verdubbel(true);          
    cout<<endl<<"na verdubbelen met param true:   " << v;
    
    mijn_vector<int> w(v);      
    cout<<endl<<"een kopie van v: " << w;	

    mijn_vector<double> u(7);   
    cout<<endl<<"een vector met 7 default-elt: " << u;        
    for(int i=0; i<u.size(); i++){
        u[i] = i*1.1;
    }
    cout<<endl<<"na opvullen met getallen: " << u;

    u.verdubbel();              
    cout<<endl<<"na verdubbelen zonder parameter: " << u;  

    u.verdubbel(true);              
    cout<<endl<<"na verdubbelen met parameter: " << u;            
    return 0;
}

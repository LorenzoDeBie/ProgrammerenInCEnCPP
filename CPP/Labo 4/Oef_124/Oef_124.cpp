#include <memory>
#include <vector>
#include <iostream>
using namespace std;

class Langeslang : public vector<unique_ptr<int>>{
    private:		
        void schrijf(ostream&)const;
    public:
        void vul(const vector<int>& v);
        Langeslang& concatenate(Langeslang & c);
		
    friend ostream& operator<<(ostream& out, const Langeslang& l){
        l.schrijf(out);
        return out;	
    }	
};

void Langeslang::vul(const vector<int> &v) {
    int or_size = size();
    resize(size() + v.size());
    for(int i = 0; i < size(); i++) {
        (*this)[or_size + i] = make_unique<int>(v[i]);
    }
}

void Langeslang::schrijf(ostream& out) const {
    if(!(*this).empty()) {
        out << "[ " << *((*this)[0]);
        if((*this).size() > 1) {
            for(int i = 1; i < (*this).size(); i++) {
                out << " - " << *((*this)[i]);        
            }
        }
        out << " ]";
    }
    else {
        out << "empty!";
    }
}

Langeslang& Langeslang::concatenate(Langeslang &c) {
    int or_size = size();
    resize(or_size + c.size());
    if( &c == this) { //concatenating with ourselves --> no moving!
        for(int i = 0; i < c.size(); i++) {
            (*this)[i + or_size] = make_unique<int>(*((*this)[i]));
        }
    }
    else {
        for(int i = 0; i < c.size(); i++) {
            (*this)[i + or_size] = move(c[i]);
        }
        c.resize(0);
    }
    return *this;
}

int main(){
    Langeslang a;
    Langeslang b;
    Langeslang c;
    a.vul({1,2});      // via a vind je de getallen 1 en 2
    b.vul({3,4,5});    // via b vind je de getallen 3, 4 en 5
    c.vul({6,7});      // via c vind je de getallen 6 en 7
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;
    //a.concatenate(a);	
    // via a vind je nu de 4 getallen 1, 2, 1 en 2
		
    //cout<<"na a.concatenate(a)"<<endl;
    //cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;
	
    a.concatenate(b).concatenate(c);
    // via a vind je nu de 9 getallen 1, 2, 1, 2, 3, 4, 5, 6 en 7
    // b is leeg
    // c is leeg
    
    cout<<"na a.concatenate(b).concatenate(c)"<<endl;
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;
    return 0;
}
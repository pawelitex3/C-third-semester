#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

class Ulamek{
    private:
        int licznik, mianownik;

    public:
        Ulamek();
        Ulamek(int l, int m);
        Ulamek(int l);
        void skroc_ulamek();
        friend void sortuj(vector <Ulamek>& ulamki);
        friend bool porownaj(Ulamek u1, Ulamek u2);
        friend istream &operator >> (istream &input, Ulamek &u);
        friend ostream & operator << (ostream & output, Ulamek &u);
};

Ulamek::Ulamek()
{
    this->licznik = 0;
    this->mianownik = 1;
}

Ulamek::Ulamek(int l)
{
    this->licznik = l;
    this->mianownik=1;
}

Ulamek::Ulamek(int l, int m)
{
    this->licznik = l;
    if(m != 0){
        this->mianownik = m;
    }
    else{
        this->mianownik = 1;
    }
}

void Ulamek::skroc_ulamek()
{
    int l, m, p, znakl=1, znakm=1;
    if(this->licznik < 0){
            znakl = -1;
    }
    if(this->mianownik < 0){
            znakm = -1;
    }

    l = znakl * this->licznik;
    m = znakm * this->mianownik;
    if(l<m) swap(l, m);
    while(m!=0){
        p = m;
        m = l%m;
        l = p;
    }
    this->licznik = this->licznik/l;
    this->mianownik = this->mianownik/l;

}

bool porownaj(Ulamek u1, Ulamek u2)
{
    int NWW, licznik1, mianownik1, licznik2, mianownik2, pom;

    mianownik1 = u1.mianownik;
    mianownik2 = u2.mianownik;
    if(mianownik1<mianownik2) swap(mianownik1, mianownik2);
    while(mianownik2!=0){
        pom=mianownik2;
        mianownik2 = mianownik1%mianownik2;
        mianownik1=pom;
    }
    NWW = u1.mianownik*u2.mianownik/mianownik1;

    licznik1 = u1.licznik * NWW/u1.mianownik;
    licznik2 = u2.licznik * NWW/u2.mianownik;

    if(licznik1 > licznik2) return true;
    else return false;

}

istream &operator >> (istream &input, Ulamek &u)
{
    string wejscie, licznik, mianownik;
    int i, kreska_ulamkowa;

    input>>wejscie;

    for(i=0; i<wejscie.size(); i++){
        if(wejscie[i] == '|'){
            kreska_ulamkowa = i;
            break;
        }
    }

    if(i == wejscie.size()){
        u.licznik = strtol(wejscie.c_str(), NULL, 10);
        u.mianownik = 1;
    }

    else{
        licznik = wejscie.substr(0, kreska_ulamkowa);
        mianownik = wejscie.substr(kreska_ulamkowa+1, wejscie.size()-kreska_ulamkowa-1);
        u.licznik = strtol(licznik.c_str(), NULL, 10);
        u.mianownik = strtol(mianownik.c_str(), NULL, 10);
    }

    return input;
}

ostream & operator << (ostream & output, Ulamek &u)
{
    if(u.mianownik != 1){
        output<<u.licznik<<"|"<<u.mianownik;
    }
    else{
        output<<u.licznik;
    }

    return output;
}

void sortuj(vector <Ulamek>&);

int main()
{
    vector <Ulamek> ulamki;
    Ulamek u1;
    int i;
    while(cin>>u1){
        u1.skroc_ulamek();
        ulamki.push_back(u1);
        i--;
    }

    sortuj(ulamki);

    for(i=0; i<ulamki.size(); i++){
        cout<<ulamki[i];
        if(i<ulamki.size()-1){
            cout<<" ";
        }
    }

    return 0;
}

void sortuj(vector <Ulamek> &ulamki)
{
    int i, j;
    for(i=0; i<ulamki.size(); i++){
        for(j=i+1; j<ulamki.size(); j++){
            if(porownaj(ulamki[i], ulamki[j])){
                swap(ulamki[i], ulamki[j]);
            }
        }
    }
}

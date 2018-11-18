#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Litery;
class Porzadek;

class Porzadek
{
    private:
        char poprzednia, kolejna;
        bool spelniony;
    public:
        Porzadek(char p, char k);
        void wypisz();
        friend void sprawdz(Litery l, Porzadek &p);
        friend bool spelnione(vector <Porzadek> & prawidlowy);
        friend void zeruj(vector <Porzadek> & prawidlowy);
};

class Litery
{
    private:
        string slowo;
    public:
        Litery(string s);
        void sortuj();
        void wypisz();
        friend void sprawdz(Litery l, Porzadek &p);
        bool nastepna();
};

Porzadek::Porzadek(char p, char k)
{
    this->poprzednia = p;
    this->kolejna = k;
    this->spelniony = false;
}

Litery::Litery(string s)
{
    this->slowo=s;
}

void Litery::sortuj()
{
    int i;
    string bez_spacji="";
    for(i=0; i<this->slowo.size(); i+=2){
        bez_spacji+=this->slowo[i];
    }
    this->slowo=bez_spacji;
    sort(this->slowo.begin(), this->slowo.end());
}

void Porzadek::wypisz()
{
    cout<<this->poprzednia<<" "<<this->kolejna<<" ";
}

void Litery::wypisz()
{
    cout<<this->slowo;
    cout<<endl;
}

void sprawdz(Litery l, Porzadek &p)
{
    int p1, p2;
    p1 = l.slowo.find(p.poprzednia);
    p2 = l.slowo.find(p.kolejna);
    if(p1<p2) p.spelniony=true;
}

bool Litery::nastepna()
{
    return next_permutation(this->slowo.begin(), this->slowo.end());
}

bool spelnione(vector <Porzadek> & prawidlowy)
{
    int i;
    for(i=0; i<prawidlowy.size(); i++){
        if(prawidlowy[i].spelniony == false) return false;
    }
    return true;
}

void zeruj(vector <Porzadek> & prawidlowy)
{
    int i;
    for(i=0; i<prawidlowy.size(); i++){
        prawidlowy[i].spelniony = false;
    }
}

int main()
{
    string litery, zestawy;
    vector<Porzadek> prawidlowy;
    int i;
    while(getline(cin, litery)){
        Litery l(litery);
        l.sortuj();
        getline(cin, zestawy);
        for(i=0; i<zestawy.size(); i+=4){
            Porzadek p(zestawy[i], zestawy[i+2]);
            prawidlowy.push_back(p);
        }

        do{
            for(i=0; i<prawidlowy.size(); i++){
                sprawdz(l, prawidlowy[i]);
            }
            if(spelnione(prawidlowy)){
                l.wypisz();
            }
            zeruj(prawidlowy);
        }
        while(l.nastepna());

        prawidlowy.clear();

    }


    return 0;
}

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

class Ulamek{
    private:
        int licznik, mianownik;
        vector <int> lancuch;

    public:
        Ulamek();
        Ulamek(int l, int m);
        Ulamek(int l);
        void ulamek_lancuchowy();
        void wypisz_lancuch();
        friend ostream & operator << (ostream & output, Ulamek &u);
        friend istream &operator >> (istream &input, Ulamek &u);

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

void Ulamek::ulamek_lancuchowy()
{
    int licznik, mianownik;
    licznik = this->licznik;
    mianownik = this->mianownik;
    while(mianownik!=1){
        this->lancuch.push_back(licznik/mianownik);
        licznik = licznik - (licznik/mianownik)*mianownik;
        swap(licznik, mianownik);
        if(mianownik == 1){
            this->lancuch.push_back(licznik);
        }
        if(mianownik == 0){
            break;
        }
    }
}

void Ulamek::wypisz_lancuch()
{
    int i;
    cout<<"["<<this->lancuch[0];
    if(this->lancuch.size()>1){
        cout<<";";
        for(i=1; i<this->lancuch.size(); i++){
            cout<<this->lancuch[i];
            if(i != lancuch.size()-1){
                cout<<",";
            }
        }
    }
    cout<<"]";
}

istream &operator >> (istream &input, Ulamek &u)
{
    int licznik, mianownik;

    input>>licznik>>mianownik;

    u.licznik = licznik;
    u.mianownik = mianownik;

    return input;
}

ostream & operator << (ostream & output, Ulamek &u)
{
    u.ulamek_lancuchowy();
    int i;
    output<<"["<<u.lancuch[0];
    if(u.lancuch.size()>1){
        output<<";";
        for(i=1; i<u.lancuch.size(); i++){
            output<<u.lancuch[i];
            if(i != u.lancuch.size()-1){
                output<<",";
            }
        }
    }
    output<<"]";
    u.lancuch.clear();

    return output;
}



int main()
{
    Ulamek u1;
    ofstream wyjscie("plik.txt");

    while(cin>>u1){
        cout<<u1<<endl;
    }



    return 0;
}

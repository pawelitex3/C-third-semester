#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int suma;

class Drzewo
{
    private:
        char litera;
        bool koniec_slowa;
        vector <Drzewo> nastepniki;
    public:
        void dodaj(string slowo, int ktory_znak);
        Drzewo();
        Drzewo(char c);
        friend void szukaj_slow(int licznik, Drzewo d);
        friend void wypisz_drzewo(Drzewo d);
};

void Drzewo::dodaj(string slowo, int ktory_znak)
{
    int i;
    if(ktory_znak<slowo.size()){
        for(i=0; i<this->nastepniki.size(); i++){
            if(slowo[ktory_znak] == this->nastepniki[i].litera){
                if(ktory_znak == slowo.size()-1){
                    this->nastepniki[i].koniec_slowa=true;
                    break;
                }
                else{
                    this->nastepniki[i].dodaj(slowo, ktory_znak+1);
                    break;
                }
            }
        }
        if(i==this->nastepniki.size()){
            Drzewo d(slowo[ktory_znak]);
            if(ktory_znak == slowo.size()-1){
                d.koniec_slowa=true;
                this->nastepniki.push_back(d);
            }
            else{
                this->nastepniki.push_back(d);
                this->nastepniki[i].dodaj(slowo, ktory_znak+1);
            }
        }
    }

}

Drzewo::Drzewo()
{
    this->koniec_slowa=false;
    this->litera=' ';
}

Drzewo::Drzewo(char c)
{
    this->koniec_slowa=false;
    this->litera=c;
}

void szukaj_slow(int licznik, Drzewo d)
{
    int i;
    if(d.koniec_slowa == true){
        suma+=licznik;
    }
    if(d.koniec_slowa == true || d.nastepniki.size()>1){
        if(d.litera!=' '){
            licznik++;
        }
    }
    for(i=0; i<d.nastepniki.size(); i++){
        szukaj_slow(licznik, d.nastepniki[i]);
    }
}

void wypisz_drzewo(Drzewo d)
{
    int i;
    for(i=0; i<d.nastepniki.size(); i++){
        wypisz_drzewo(d.nastepniki[i]);
    }
}

int main()
{
    string slowo;
    int N, i;
    double srednia;

    while(cin>>N){
        Drzewo poczatkowe;
        suma=0;
        for(i=0; i<N; i++){
            cin>>slowo;
            poczatkowe.dodaj(slowo, 0);
        }
        szukaj_slow(1, poczatkowe);
        wypisz_drzewo(poczatkowe);
        srednia = (double)suma / double(N);
        cout<<fixed;
        cout<<setprecision(2)<<srednia<<endl;

    }



    return 0;
}

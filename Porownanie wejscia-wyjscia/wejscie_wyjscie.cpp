#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

int kopiowanie_slow_CPP();

int kopiowanie_slow_C();

int kopiowanie_znakow_CPP();

int kopiowanie_znakow_C();

int kopiowanie_wierszy_CPP();

int kopiowanie_wierszy_C();

int kopiowanie_blokow_CPP();

int kopiowanie_blokow_C();

int main()
{
    #ifdef SLOWA_C
        kopiowanie_slow_C();
    #endif // SLOWA_C


    #ifdef SLOWA_CPP
        kopiowanie_slow_CPP();
    #endif // SLOWA_CPP


    #ifdef ZNAKI_C
        kopiowanie_znakow_C();
    #endif // ZNAKI_C


    #ifdef ZNAKI_CPP
        kopiowanie_znakow_CPP();
    #endif // ZNAKI_CPP


    #ifdef WIERSZE_C
        kopiowanie_wierszy_C();
    #endif // WIERSZE_C


    #ifdef WIERSZE_CPP
        kopiowanie_wierszy_CPP();
    #endif // WIERSZE_CPP


    #ifdef BLOKI_C
        kopiowanie_blokow_C();
    #endif // BLOKI_C


    #ifdef BLOKI_CPP
        kopiowanie_blokow_CPP();
    #endif // BLOKI_CPP

    return 0;
}

int kopiowanie_slow_CPP()
{
    ifstream wejscie("dane.txt");
    ofstream wyjscie("kopia.txt");

    string slowo;

    //ios::sync_with_stdio(false);

    if(!wejscie.good()){
        cout<<"Blad otwarcia pliku\n";
        return 1;
    }

    while(!wejscie.eof()){
        wejscie>>slowo;
        wyjscie<<slowo<<" ";
    }

    wejscie.close();
    wyjscie.close();

    return 0;
}


int kopiowanie_slow_C()
{
    FILE *wejscie = fopen("dane.txt", "r");
    FILE *wyjscie = fopen("kopia2.txt", "w");

    char slowo[100];

    if(wejscie == NULL){
        printf("Blad otwarcia pliku\n");
        return 1;
    }

    if(wyjscie == NULL){
        printf("Blad otwarcia pliku\n");
        return 1;
    }

    while(!feof(wejscie)){
        fscanf(wejscie, "%s", slowo);
        fprintf(wyjscie, "%s ", slowo);
    }

    fclose(wejscie);
    fclose(wyjscie);

    return 0;
}

int kopiowanie_znakow_CPP()
{
    ifstream wejscie("dane.txt");
    ofstream wyjscie("kopia.txt");

    char znak;

    //ios::sync_with_stdio(false);

    if(!wejscie.good()){
        cout<<"Blad otwarcia pliku\n";
        return 1;
    }

    while(!wejscie.eof()){
        wejscie.get(znak);
        wyjscie.put(znak);
    }

    wejscie.close();
    wyjscie.close();

    return 0;
}


int kopiowanie_znakow_C()
{
    FILE *wejscie = fopen("dane.txt", "r");
    FILE *wyjscie = fopen("kopia2.txt", "w");

    char znak;

    if(wejscie == NULL){
        printf("Blad otwarcia pliku\n");
        return 1;
    }

    if(wyjscie == NULL){
        printf("Blad otwarcia pliku\n");
        return 1;
    }

    while(!feof(wejscie)){
        znak = getc(wejscie);
        putc(znak, wyjscie);
    }

    fclose(wejscie);
    fclose(wyjscie);

    return 0;

}

int kopiowanie_wierszy_CPP()
{
    ifstream wejscie("dane.txt");
    ofstream wyjscie("kopia.txt");

    string wiersz;

    //ios::sync_with_stdio(false);

    if(!wejscie.good()){
        cout<<"Blad otwarcia pliku\n";
        return 1;
    }

    while(!wejscie.eof()){
        getline(wejscie, wiersz);
        wyjscie<<wiersz<<"\n";
    }

    wejscie.close();
    wyjscie.close();

    return 0;
}


int kopiowanie_wierszy_C()
{
    FILE *wejscie = fopen("dane.txt", "r");
    FILE *wyjscie = fopen("kopia2.txt", "w");

    char wiersz[100];

    if(wejscie == NULL){
        printf("Blad otwarcia pliku\n");
        return 1;
    }

    if(wyjscie == NULL){
        printf("Blad otwarcia pliku\n");
        return 1;
    }

    while(!feof(wejscie)){
        fgets(wiersz, 100, wejscie);
        fputs(wiersz, wyjscie);
    }

    fclose(wejscie);
    fclose(wyjscie);

    return 0;
}

int kopiowanie_blokow_CPP()
{
    ifstream wejscie("dane.txt");
    ofstream wyjscie("kopia.txt");

    char blok[512];

    //ios::sync_with_stdio(false);

    if(!wejscie.good()){
        cout<<"Blad otwarcia pliku\n";
        return 1;
    }

    while(!wejscie.eof()){
        wejscie.read(blok, 512);
        wyjscie.write(blok, 512);
    }

    wejscie.close();
    wyjscie.close();

    return 0;
}


int kopiowanie_blokow_C()
{
    FILE *wejscie = fopen("dane.txt", "r");
    FILE *wyjscie = fopen("kopia2.txt", "w");

    char blok[512];

    if(wejscie == NULL){
        printf("Blad otwarcia pliku\n");
        return 1;
    }

    if(wyjscie == NULL){
        printf("Blad otwarcia pliku\n");
        return 1;
    }

    while(!feof(wejscie)){
        fread(blok, 1, 512, wejscie);
        fwrite(blok, 1, 512, wyjscie);
    }

    fclose(wejscie);
    fclose(wyjscie);

    return 0;
}

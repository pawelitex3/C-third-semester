#include<iostream>
#include<string>

using namespace std;

int main()
{
    int N, i, j, poziom, dlugosc, najwyzsza, najnizsza, licznik;
    string wejscie;

    char tablica[105][55];
    int granica[105];
    licznik=1;
    cin>>N;
    while(N--){
        cin>>wejscie;

        for(i=0; i<105; i++){
            for(j=0; j<55; j++){
                tablica[i][j]=' ';
                granica[i]=0;
            }
        }

        for(j=0; j<105; j++){
            tablica[j][0]='|';
        }
        poziom=53;
        for(dlugosc=0; dlugosc<wejscie.size(); dlugosc++){
            if(wejscie[dlugosc]=='R'){
                if(tablica[poziom-1][dlugosc+1]=='\\'){
                    poziom--;
                }

                tablica[poziom][dlugosc+2]='/';
                granica[poziom]=dlugosc+2;
                poziom--;

            }
            if(wejscie[dlugosc]=='C'){
                if(tablica[poziom-1][dlugosc+1]=='\\'){
                    poziom--;
                }
                tablica[poziom][dlugosc+2]='_';
                granica[poziom]=dlugosc+2;
            }
            if(wejscie[dlugosc]=='F'){
                if(tablica[poziom+1][dlugosc+1]=='/'){
                    poziom++;
                }
                else if (tablica[poziom][dlugosc+1]=='_'){
                    poziom++;
                }
                tablica[poziom][dlugosc+2]='\\';
                granica[poziom]=dlugosc+2;
                poziom++;

            }
        }
        najnizsza=200;
        najwyzsza=200;
        for(i=0; i<105; i++){
            for(j=2; j<55; j++){
                if(tablica[i][j]!=' '){
                    najwyzsza=i;
                    break;
                }
            }
            if(najwyzsza!=200){
                break;
            }

        }

        for(i=104; i>=0; i--){
            for(j=2; j<55; j++){
                if(tablica[i][j]!=' '){
                    najnizsza=i;
                    break;
                }
            }
            if(najnizsza!=200){
                break;
            }

        }
        cout<<"Case #"<<licznik<<":"<<endl;

        for(i=najwyzsza; i<=najnizsza; i++){
            for(j=0; j<=granica[i]; j++){
                cout<<tablica[i][j];

            }
            cout<<endl;

        }
        cout<<"+";

        for(i=0; i<=wejscie.size()+1; i++){
            cout<<"-";

        }
        cout<<endl<<endl;;

        licznik++;

    }

    return 0;
}

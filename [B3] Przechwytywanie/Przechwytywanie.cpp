#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int aktualny, ilosc, i, j, numer;
    vector <int> wysokosci;
    vector <int> wysokosci_posortowane;


    cin>>aktualny;
    numer=1;
    while(aktualny!=-1){

        while(aktualny!=-1){
            wysokosci.push_back(aktualny);
            cin>>aktualny;

        }

        ilosc = wysokosci.size();
        wysokosci_posortowane=wysokosci;
        sort(wysokosci_posortowane.rbegin(), wysokosci_posortowane.rend());
        int **zestrzelone = new int * [ilosc+1];

        for(i=0; i<=ilosc; i++){
            zestrzelone[i] = new int [ilosc+1];
        }


        for(i=0; i<=ilosc; i++){
            for(j=0; j<=ilosc; j++){
                zestrzelone[i][0]=0;
                zestrzelone[0][i]=0;
            }
        }

        for(i=1; i<=ilosc; i++){

            for(j=1; j<=ilosc; j++){

                if(wysokosci[i-1]==wysokosci_posortowane[j-1]){
                    zestrzelone[i][j]=zestrzelone[i-1][j-1] + 1;
                }
                else{
                    if(zestrzelone[i-1][j]>zestrzelone[i][j-1]){
                        zestrzelone[i][j]=zestrzelone[i-1][j];
                    }
                    else{
                        zestrzelone[i][j]=zestrzelone[i][j-1];
                    }
                }

            }
        }

        cout<<"Test #"<<numer<<":\n";

        cout<<"  maximum possible interceptions: "<<zestrzelone[ilosc][ilosc]<<endl;


        numer++;
        cin>>aktualny;
        wysokosci.clear();
        wysokosci_posortowane.clear();
        if(aktualny!=-1){
            cout<<endl;

        }
    }


    return 0;
}

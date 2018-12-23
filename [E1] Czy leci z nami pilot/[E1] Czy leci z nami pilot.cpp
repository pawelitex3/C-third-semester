#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int i, j, k, N, X, wiatr, poziomy, wiersze;
    vector < vector <int> > wiatry;
    vector <int> p;
    cin>>N;
    for(i=0; i<N; i++){
        cin>>X;
        poziomy=X/100;
        for(k=0; k<10; k++){
            wiatry.push_back(p);
            for(j=0; j<poziomy; j++){
                cin>>wiatr;
                wiatry[k].push_back(wiatr);
            }
        }

        reverse(wiatry.begin(), wiatry.end());

        int tablica[poziomy][10];

        tablica[0][0]=-wiatry[0][0];
        for(j=1; j<10; j++){
            tablica[0][j]=1000;
        }
        for(k=1; k<poziomy; k++){
            for(j=0; j<10; j++){

                if(j>0 && j<9){
                    tablica[k][j] = min(60-wiatry[j][k]+tablica[k-1][j-1], min(30-wiatry[j][k]+tablica[k-1][j], 20-wiatry[j][k]+tablica[k-1][j+1]));
                }
                else if(j==0){
                    tablica[k][j] = min(30-wiatry[j][k]+tablica[k-1][j], 20-wiatry[j][k]+tablica[k-1][j+1]);
                }
                else if(j==9){
                    tablica[k][j] = min(30-wiatry[j][k]+tablica[k-1][j], 60-wiatry[j][k]+tablica[k-1][j-1]);
                }
            }
        }
        tablica[poziomy-1][0]+=30;
        tablica[poziomy-1][1]+=20;

/*
        for(j=0; j<poziomy; j++){
            for(k=0; k<(poziomy+1)/2+3; k++){
                if(j<k-2 || j==0 || k == 0){
                    tablica[j][k]=-1000;
                    tablica2[j][k]=1000;

                }
                else{
                    tablica[j][k]=0;
                    tablica2[j][k]=0;
                }
            }
        }
        for(j=0; j<poziomy; j++){
            for(k=0; k<(poziomy+1)/2+3; k++){
                tablica[poziomy-j-1][k] = tablica[j][k];
                tablica2[poziomy-j-1][k] = tablica2[j][k];
            }
        }

        tablica[0][1]=0;
        tablica[0][2]=0;
        tablica[poziomy-1][1]=0;
        tablica2[poziomy-1][1]=0;
        tablica[poziomy-1][2]=0;
        tablica2[poziomy-1][2]=0;

        tablica2[0][1]=30;

        for(j=0; j<poziomy; j++){
            if(poziomy<16){
                for(k=1; k<(poziomy+1)/2+3; k++){
                    if(tablica[j][k]==0){
                        tablica[j][k]=wiatry[k-1][j];

                    }
                }
            }
            else{
                for(k=1; k<=11; k++){
                    if(tablica[j][k]==0){
                        if(k==11){
                            tablica[j][k]=-1000;
                            tablica2[j][k]=1000;
                        }
                        else tablica[j][k]=wiatry[k-1][j];

                    }
                }
            }
        }

        tablica2[0][1]-=tablica[0][1];


        for(j=1; j<poziomy; j++){
            for(k=1; k<=(poziomy+1)/2+2; k++){
                if(tablica[j][k]!=-1000){
                    tablica2[j][k] = min(60-tablica[j][k]+tablica2[j-1][k-1], min(30-tablica[j][k]+tablica2[j-1][k], 20-tablica[j][k]+tablica2[j-1][k+1]));
                }
            }
        }



        for(k=0; k<10; k++){
            for(j=0; j<poziomy; j++){
                cout<<wiatry[k][j]<<"\t";
            }
            cout<<endl;
        }

        for(k=0; k<10; k++){
            for(j=0; j<poziomy; j++){
                cout<<tablica[j][k]<<"\t";
            }
            cout<<endl;
        }
*/
        cout<<min(tablica[poziomy-1][0], tablica[poziomy-1][1])<<endl;

        wiatry.clear();
    }


    return 0;
}

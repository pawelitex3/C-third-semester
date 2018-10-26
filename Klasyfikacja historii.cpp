#include<iostream>
using namespace std;

void translacja(int *wejscie, int *przetlumaczona, int N)
{
    int i, aktualna;
    for(i=1; i<=N; i++){
        aktualna=wejscie[i];
        przetlumaczona[aktualna] = i;
    }
}


int main()
{

    int N, i, j;

    cin>>N;

    int *wejscie_poprawna = new int[N+1];
    int *poprawna = new int[N+1];
    int *wejscie_sprawdzana = new int[N+1];
    int *sprawdzana = new int[N+1];

    int **podciagi = new int * [N+1];

    for(i=0; i<=N; i++){
        podciagi[i] = new int [N+1];
    }

    for(i=1; i<=N; i++){
        cin>>wejscie_poprawna[i];
    }

    while(cin>>wejscie_sprawdzana[1]){
        for(i=2; i<=N; i++){
            cin>>wejscie_sprawdzana[i];
        }

        for(i=0; i<=N; i++){
            podciagi[i][0]=0;
            podciagi[0][i]=0;
        }

        translacja(wejscie_poprawna, poprawna, N);
        translacja(wejscie_sprawdzana, sprawdzana, N);

        for(i=1; i<=N; i++){
            for(j=1; j<=N; j++){
                if(sprawdzana[i] == poprawna[j]){
                    podciagi[i][j]=podciagi[i-1][j-1]+1;
                }
                else{
                    if(podciagi[i-1][j]>podciagi[i][j-1]){
                        podciagi[i][j]=podciagi[i-1][j];
                    }
                    else{
                        podciagi[i][j]=podciagi[i][j-1];
                    }
                }
            }
        }

        cout<<podciagi[N][N]<<endl;



    }


    for(i=0; i<=N; i++){
        delete [] podciagi[i];
    }

    delete [] podciagi;

    return 0;
}

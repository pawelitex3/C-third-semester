#include<iostream>
#include<vector>

using namespace std;

template <typename T> class Matrix {
    private:
        vector < vector < T > > cell;
    public:
        Matrix(int N){
            vector < T > v;
            int i;
            for(i=0; i<N; i++){
                cell.push_back(v);
            }
        }

        Matrix < T > operator+(Matrix < T > m){
            int i, j;
            for(i=0; i<this->cell.size(); i++){
                for(j=0; j<this->cell[i].size(); j++){
                    m.cell[i][j] = m.cell[i][j] + this->cell[i][j];
                }
            }
        }

        void transpose(){
            int i, j;
            for(i=0; i<this->cell.size(); i++){
                for(j=i; j<this->cell.size(); j++){
                    swap(this->cell[i][j], this->cell[j][i]);
                }

            }
        }

        void wczytaj(){
            char wartosc;
            int i, j;
            for(i=0; i<this->cell.size(); i++){
                for(j=0; j<this->cell.size(); j++){
                    cin>>wartosc;
                    this->cell[i].push_back(wartosc-48);
                }

            }
        }

        void wypisz(){
            int i, j;
            for(i=0; i<this->cell.size(); i++){
                for(j=0; j<this->cell.size(); j++){
                    cout<<this->cell[i][j];
                }
                cout<<endl;
            }
        }

        void inc(){
            int i, j;
            for(i=0; i<this->cell.size(); i++){
                for(j=0; j<this->cell.size(); j++){
                    this->cell[i][j]++;
                    if(this->cell[i][j] == 10){
                        this->cell[i][j] = 0;
                    }
                }

            }
        }

        void dec(){
            int i, j;
            for(i=0; i<this->cell.size(); i++){
                for(j=0; j<this->cell.size(); j++){
                    this->cell[i][j]--;
                    if(this->cell[i][j] == -1){
                        this->cell[i][j] = 9;
                    }
                }

            }
        }

        void row(int a, int b){
            swap(this->cell[a], this->cell[b]);
        }

        void col(int a, int b){
            int i;
            vector < T > p;
            for(i=0; i<this->cell.size(); i++){
                p.push_back(this->cell[i][a]);
            }
            for(i=0; i<this->cell.size(); i++){
                this->cell[i][a] = this->cell[i][b];
                this->cell[i][b] = p[i];
            }
        }
};

int main()
{
    int N, T, M, licznik=1, a, b;
    string operacja;
    cin>>T;
    while(T--){
        cin>>N;
        Matrix <int> macierz(N);
        macierz.wczytaj();
        cin>>M;

        while(M--){
            cin>>operacja;
            if(operacja == "row"){
                cin>>a>>b;
                macierz.row(a-1, b-1);
            }
            else if(operacja == "col"){
                cin>>a>>b;
                macierz.col(a-1, b-1);
            }
            else if(operacja == "inc"){
                macierz.inc();
            }
            else if(operacja == "dec"){
                macierz.dec();
            }
            else if(operacja == "transpose"){
                macierz.transpose();
            }
        }
        cout<<"Case #"<<licznik<<endl;
        macierz.wypisz();
        licznik++;
    }


    return 0;
}

#include<iostream>
#include<vector>

using namespace std;

int nwd(int a, int b){
    if(a<b) swap(a, b);
    if(b==0) return a;
    while(b!=0){
        a=a%b;
        swap(a, b);
    }
    return a;
}

template <typename T> class Matrix {
    protected:
        vector < vector < T > > cell;
    public:
        Matrix(int N){
            vector < T > v(N);
            int i;
            for(i=0; i<N; i++){
                cell.push_back(v);
            }
        }

        Matrix(int N, int M){
            vector < T > v(M);
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
            int wartosc;
            int i, j;
            for(i=0; i<this->cell.size(); i++){
                for(j=0; j<this->cell[i].size(); j++){
                    cin>>wartosc;
                    this->cell[i][j]=wartosc;
                }

            }
        }

        void wypisz(){
            int i, j;
            for(i=0; i<this->cell.size(); i++){
                for(j=0; j<this->cell.size(); j++){
                    cout<<this->cell[i][j]<<" ";
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

template <typename T> class Square:public Matrix <T>
{
    private:
        long long wyznacznik;
    public:
        Square(int n): Matrix<T>::Matrix(n, n) {
            wyznacznik=1;
        };

        long long det(){
            if(this->wyznacznik ==1){
                int i, j, k, z=1, najwiekszy, drugi_najwiekszy;
                for(i=0; i<this->cell.size(); i++){
                    for(j=i; j<this->cell.size(); j++){
                        if(this->cell[j][i]<0){
                            z*=-1;
                            for(k=i; k<this->cell.size(); k++){
                                this->cell[j][k]*=-1;
                            }
                        }
                    }
                    if(i<this->cell.size()-1){
                        do{
                            najwiekszy=i;
                            for(j=i+1; j<this->cell.size(); j++){
                                if(this->cell[j][i] > this->cell[najwiekszy][i]){
                                    najwiekszy=j;

                                }
                            }
                            if(najwiekszy==i){
                                drugi_najwiekszy=i+1;
                            }
                            else{
                                drugi_najwiekszy=i;
                            }
                            for(j=i; j<this->cell.size(); j++){
                                if(this->cell[j][i] > this->cell[drugi_najwiekszy][i] && j!=najwiekszy){
                                    drugi_najwiekszy=j;
                                }
                            }
                            if(this->cell[drugi_najwiekszy][i] != 0){
                                for(j=i; j<this->cell.size(); j++){
                                    this->cell[najwiekszy][j] -= this->cell[drugi_najwiekszy][j];
                                }
                            }
                            if(najwiekszy != i){
                                swap(this->cell[najwiekszy], this->cell[i]);
                                z*=-1;
                            }
                        }
                        while(this->cell[drugi_najwiekszy][i] != 0);
                    }


                }

                for(i=0; i<this->cell.size(); i++){

                    this->wyznacznik*=this->cell[i][i];
                }
                this->wyznacznik*=z;
                return this->wyznacznik;
            }
            else return wyznacznik;
        }

};

int main()
{
    int N;
    cin>>N;
    while(N!=0){
        Square < int > kwadratowa(N);
        kwadratowa.wczytaj();
        cout<<kwadratowa.det()<<endl;
        cin>>N;
    }
    cout<<"*"<<endl;




    return 0;
}

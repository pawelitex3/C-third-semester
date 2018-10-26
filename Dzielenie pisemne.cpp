#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double A, B;
    int i;
    cin>>A>>B;

    cout.width(14);
    cout<<fixed<<setprecision(3)<<A/B<<endl;
    for(i=0; i<10; i++){
        cout<<"-";
    }
    cout<<endl;
    cout.width(10);
    cout<<hex<<(int)A;
    cout<<":"<<oct<<(int)B;

    return 0;
}


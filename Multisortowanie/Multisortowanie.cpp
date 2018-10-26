#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

bool sort_pierwsza(pair < pair < pair < int, int > , pair < int, int > > , int > pierwsza,  pair < pair < pair < int, int > , pair < int, int > > , int > druga)
{
    return pierwsza.first.first.first < druga.first.first.first;
}

bool sort_druga(pair < pair < pair < int, int > , pair < int, int > > , int > pierwsza,  pair < pair < pair < int, int > , pair < int, int > > , int > druga)
{
    return pierwsza.first.first.second < druga.first.first.second;
}

bool sort_trzecia(pair < pair < pair < int, int > , pair < int, int > > , int > pierwsza,  pair < pair < pair < int, int > , pair < int, int > > , int > druga)
{
    return pierwsza.first.second.first < druga.first.second.first;
}

bool sort_czwarta(pair < pair < pair < int, int > , pair < int, int > > , int > pierwsza,  pair < pair < pair < int, int > , pair < int, int > > , int > druga)
{
    return pierwsza.first.second.second < druga.first.second.second;
}



int main()
{
    vector < pair < pair < pair < int, int > , pair < int, int > > , int > > czworki;
    vector < pair < pair < pair < int, int > , pair < int, int > > , int > > do_sortowania;
    pair < pair < pair < int, int > , pair < int, int > > , int > roboczy;
    int i, N, pierwsza, druga, trzecia, czwarta;
    cin>>N;
    for (i=0; i<N; i++){
        cin>>pierwsza>>druga>>trzecia>>czwarta;

        roboczy.first.first.first=pierwsza;
        roboczy.first.first.second=druga;
        roboczy.first.second.first=trzecia;
        roboczy.first.second.second=czwarta;

        roboczy.second=i+1;

        czworki.push_back(roboczy);

    }

    do_sortowania=czworki;

    sort(do_sortowania.begin(), do_sortowania.end(), sort_pierwsza);

    for(i=0; i<N; i++){
        cout<<do_sortowania[i].second;
        if(i!=N-1) cout<<" ";
    }
    cout<<endl;

    do_sortowania=czworki;

    sort(do_sortowania.begin(), do_sortowania.end(), sort_druga);

    for(i=0; i<N; i++){
        cout<<do_sortowania[i].second;
        if(i!=N-1) cout<<" ";
    }
    cout<<endl;

    do_sortowania=czworki;

    sort(do_sortowania.begin(), do_sortowania.end(), sort_trzecia);

    for(i=0; i<N; i++){
        cout<<do_sortowania[i].second;
        if(i!=N-1) cout<<" ";
    }
    cout<<endl;

    do_sortowania=czworki;

    sort(do_sortowania.begin(), do_sortowania.end(), sort_czwarta);

    for(i=0; i<N; i++){
        cout<<do_sortowania[i].second;
        if(i!=N-1) cout<<" ";
    }


    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <unordered_set>
#include <functional>
#include <deque>

using namespace std;

bool zakoncz=0;
vector <int> x;
vector <int> y;
vector<long long> potega;
long long duzaliczba=9223372036807;
int n;



struct skalar{
    int l;
    vector<int> w;
};

struct haszerka{
    
    size_t operator() (const vector<int> &v) const noexcept{

        unsigned long long ziarno = 0;
        
        
        for(int i : v){

            ziarno = (ziarno*587+(long long)i)%duzaliczba;
        }

        return (size_t)ziarno;
    }
};

void wczytaj_dane(){
    
    int a,b;
    cin>>n;

    for(int i=0;i<n;i++){

        cin>>a>>b;

        if(a != 0){
            x.push_back(a);
            y.push_back(b);
        } 
    }
    n=(int)x.size();
}

void warunki_startowe(){
    
    int k=x[0];
    bool zeromin=0;

    for(size_t i=1; i<x.size();i++) if(x[i] != 0) k=__gcd(k,x[i]);

    for(size_t i=0; i<y.size();i++){
        if (y[i]%k != 0) zakoncz=1;
        x[i] = x[i]/k;
        y[i] = y[i]/k;
    }

    for(size_t i=0; i<x.size();i++){
        if(y[i]==x[i] || y[i]==0) zeromin=1;
    }

    if (zeromin==0) zakoncz=1;
}

int bfs(unordered_set <vector<int>, haszerka> &mapa){

    deque <skalar> kolejka;
    skalar poc;
    poc.w=vector<int> (n,0);
    poc.l=0;
    kolejka.push_back(poc);

    while(!kolejka.empty()){


        skalar posredni;
        posredni.w=kolejka.front().w;
        posredni.l=kolejka.front().l;
        kolejka.pop_front();
        
        auto pchaj=[&](){
            if( mapa.count(posredni.w) == 0) {
                kolejka.push_back({posredni.l+1,posredni.w});
            }
        };
   
        if(mapa.count(posredni.w) == 1) continue;

        if(posredni.w == y){
            return posredni.l;
        }

        mapa.insert(posredni.w);

        for(size_t i=0;i<x.size();i++){

            int temp1=posredni.w[i];
            
            if(posredni.w[i]!=0){
                posredni.w[i]=0;
                pchaj();
            }

            if(posredni.w[i]!=x[i]){
                posredni.w[i]=x[i];
                pchaj();
            }
            posredni.w[i]=temp1;

            for(size_t j=i+1;j<x.size();j++){
                
                int tempi=posredni.w[i];
                int tempj=posredni.w[j];

                if(tempi != 0 && tempj != x[j]){

                    posredni.w[i] -= min(tempi,x[j]-tempj);
                    posredni.w[j] += min(tempi,x[j]-tempj);
                    pchaj();

                    posredni.w[i]=tempi;
                    posredni.w[j]=tempj;
                }
                
                if(tempj !=0 && tempi != x[i]){

                    posredni.w[j] -= min(tempj,x[i]-tempi);
                    posredni.w[i] += min(tempj,x[i]-tempi);
                    pchaj();

                    posredni.w[i]=tempi;
                    posredni.w[j]=tempj;
                }

            }
        }
    }
    return -1;
}

int main(){
     
    ios::sync_with_stdio(0);
    cin.tie(0);

    wczytaj_dane();

    if(n == 0){

        cout<<"0"<<endl;
        return 0;
    }


    warunki_startowe();

    if(zakoncz==1) {

        cout<<"-1"<<endl;
        return 0;
    }

    unordered_set <vector<int>, haszerka> mapa;

    cout<<bfs(mapa);

    return 0;
}

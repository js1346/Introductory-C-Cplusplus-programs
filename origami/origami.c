#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
//4 5 P 0 0 2.5 1 Z 1 0.5 0 0.5 1 K 0 1 5 Z 3 0 1 -1 0 1 1.5 0.5 2 1.5 0.5 2 0 0.5 3 4 4 4 4 4

typedef struct { //pair double double
    long double x;
    long double y;
}  pdd;

typedef struct { //zapisujemy prostą jako dwa kolejne ounkty
    pdd p1;
    pdd p2;
}  prosta;


typedef struct { 
    char typ;
    long long zczyfig; //czy zgiecie czy figura zgiecie-indeks brak zgiecia -1
    long double z1;
    long double z2;
    long double z3;
    long double z4;//jesli kolo, to wypelniamy -1; nie ma znaczenia, co tam bedzie;
}fig;

typedef struct {
    long long index;
    pdd pprzeb;
}ask;

long long n;
long long q;
fig *lfig; //lista figur
ask *lprz; //lista zapytan
long long licznik=0;   
long double epsilon=0.000001;


bool row(long double a,long double b){
    if(a-b<epsilon && a-b>-epsilon) return true;
    else return false;
}

void wczytaj_dane(){ 
    if(scanf("%lld", &n) != 1) return; 
    if(scanf("%lld", &q) != 1) return;

    unsigned npom=(unsigned)n;
    unsigned qpom=(unsigned)q;

    lfig=(fig*)malloc(sizeof(fig)*npom);
    lprz=(ask*)malloc(sizeof(ask)*qpom);

    for(int i=0;i<n;i++){

        if(scanf(" %c", &lfig[i].typ) !=1) return;
        
        if(lfig[i].typ=='Z'){
            if(scanf(" %lld", &lfig[i].zczyfig) !=1) return;
            lfig[i].zczyfig--;
        }
        else lfig[i].zczyfig=-1;
        
       if (scanf(" %Lf %Lf %Lf", &lfig[i].z1, &lfig[i].z2, &lfig[i].z3) !=3) return;

        if(lfig[i].typ!='K') {
            if(scanf(" %Lf", &lfig[i].z4) != 1) return;
        }
        else lfig[i].z4=-1;
        
    }
    
    for(int i=0; i<q;i++)
    {
        if(scanf(" %lld %Lf %Lf", &lprz[i].index, & lprz[i].pprzeb.x, &lprz[i].pprzeb.y) !=3) return;
        lprz[i].index--;
    }
}

void zwolnij_pamiec(){ 
    free(lfig);
    free(lprz);
}

pdd przebicie(prosta pro, pdd punkt){

    pdd dozret;

    if(row(pro.p1.x,pro.p2.x)) {

        dozret.y=punkt.y;
        dozret.x=punkt.x+2*(pro.p1.x-punkt.x);
        return dozret;

    }else{

        long double a=(pro.p1.y-pro.p2.y)/(pro.p1.x-pro.p2.x);
        long double b=pro.p1.y-a*pro.p1.x;

        if(row(a,0)){

            dozret.x=punkt.x;
            dozret.y=punkt.y+2*(pro.p1.y-punkt.y);  
            return dozret;

        }else{

            long double apros=-1/a;
            long double bpros=punkt.y-apros*punkt.x;
            long double xprz=(bpros-b)/(a-apros);
            long double yprz=a*xprz+b;

            dozret.x=xprz+xprz-punkt.x;
            dozret.y=yprz+yprz-punkt.y;
            return dozret;
        }
    }
}

void czy_punkt_w_kole(pdd punkt,pdd pu1, long double rr){

    if ((pu1.x-punkt.x)*(pu1.x-punkt.x)+(pu1.y-punkt.y)*(pu1.y-punkt.y) <= rr*rr+epsilon) licznik++;
}

void czy_punkt_w_prostokacie(pdd punkt, pdd pu1,pdd pu2){

    if(punkt.x+epsilon>=pu1.x && punkt.x<=pu2.x+epsilon && punkt.y<=pu2.y+epsilon && punkt.y+epsilon >=pu1.y) licznik++;
}

pdd wektor(pdd a, pdd b) 
{
    pdd dozret;
    dozret.x=b.x-a.x;
    dozret.y=b.y-a.y;
    return dozret;
}

int czy_dobra_strona(prosta pro, pdd punkt){

    long double ord;
    pdd a=wektor(pro.p1,pro.p2);
    pdd b=wektor(pro.p1,punkt);
  
    ord=a.x*b.y-a.y*b.x;

    //det =axby-aybx=absinalfa if axby-aybx>0 sinus mniejszy niz 180, czyli po lewej, gdy axby=aybx =0 czyli na prostej, inaczej po prawej
    if(row(ord,0)) return 1;
    else if(ord > 0) return 2;
    else return 0;
}

void wykonaj_podpunkt(long long index, pdd punkt){

    pdd p1,p2;
    prosta pr;

    long long ind=lfig[index].zczyfig;
    long double r=lfig[index].z3;

    p1.x=lfig[index].z1;
    p1.y=lfig[index].z2;
    p2.x=lfig[index].z3;
    p2.y=lfig[index].z4;

    if(lfig[index].typ == 'K') {
        czy_punkt_w_kole(punkt , p1, r);
        return;
    }
    else if(lfig[index].typ =='P')  {
        czy_punkt_w_prostokacie(punkt, p1, p2); 
        return;
    }
    else{
        pr.p1=p1;
        pr.p2=p2;
        
        if(czy_dobra_strona(pr, punkt)==1)  {
            wykonaj_podpunkt(ind,punkt);
            return;
            }
        else if(czy_dobra_strona(pr, punkt)==0) return;
        else if (czy_dobra_strona(pr, punkt)==2){
            wykonaj_podpunkt(ind,punkt);
            wykonaj_podpunkt(ind, przebicie(pr,punkt));
            return;
        }
    }
}



int main(){
    
    wczytaj_dane();
    //wypisz_dane();
    
    for(int i=0;i<q;i++){
        licznik=0;
        wykonaj_podpunkt(lprz[i].index,lprz[i].pprzeb);
        printf("%lld\n",licznik);
    }

    zwolnij_pamiec();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define dek  (int*)malloc(sizeof(int)*n1)
#define popraw  if(sk==dk)sk++;  if(gk==sk) gk++
#define czyzero if(testwyn=='f') {testwyn='a';printf("0 ");return 0;}
#define sprawdz  int x; if(d==-1||s==-1||g==-1) return 0; else if(siec[d]!=siec[s] && siec[d]!=siec[g] && siec[s]!=siec[g])

int max(int a, int b) {if(a>b) return a; else return b;}
int min(int a, int b) {if(a<b) return a; else return b;}

// 9 1 2 2 6 2 9 1 13 1 13 3 20 1 26 3 27 1 30 

int n;              //rozmiar tablicy
int *siec,*odl,*prev1,*prev2,*next1,*next2;   //tablice oznaczajace nr sieci i jej odleglosc od poczcatku
int dk,sk,gk;        //dolny,środkowy i górny kandydat, dk<sk<gk
char testwyn=0;
int wyn_min=INT_MAX,wyn_max=0;
int tescik=0;


void wczytaj_dane(){
     
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Blad odczytu n\n");
        exit(1);
    }
    unsigned n1=(unsigned int)n;
    siec=dek;
    odl=dek;
    prev1=dek;prev2=dek;next1=dek;next2=dek; 
    
    for(int i=0; i<n;i++)
    {
         if (scanf("%d", &siec[i]) != 1) {
            fprintf(stderr, "Blad odczytu siec[%d]\n", i);
            exit(1);
        }
        if (scanf("%d", &odl[i]) != 1) {
            fprintf(stderr, "Blad odczytu odl[%d]\n", i);
            exit(1);
        }
    }
}

void zwolnij_pamiec(){
    free(siec);
    free(odl);
    free(prev1);
    free(prev2);
    free(next1);
    free(next2);
}



void ustanow_dol()
{
    dk=0;sk=0;
    while(siec[dk]==siec[sk] && testwyn!='f') {
         if (sk==n-2) testwyn='f'; 
        else sk++ ;
    }
    gk=sk;
    while( (siec[gk]==siec[sk]||siec[gk]==siec[dk]) && testwyn!='f') {
        if (gk==n-1) testwyn='f';
        else gk++ ;
    }
}

void ustanow_gora()
{
    dk=n-3;sk=n-2;gk=n-1;
    if(dk<0||sk<0||gk<0) testwyn='f';
    while(siec[gk]==siec[sk] && testwyn!='f') {
         if (sk==1) testwyn='f'; 
        else sk-- ;
    }
    dk=sk;
    while( (siec[dk]==siec[sk]||siec[gk]==siec[dk]) && testwyn!='f') {
        if (dk==0) testwyn='f';
        else dk-- ;
    }
  //  printf("%d %d %d",dk, gk, sk);
}

int sprawdz_min_z_max(int d,int s, int g)
{    
    sprawdz
    {x=max(odl[s]-odl[d],odl[g]-odl[s]);
    wyn_min=min(wyn_min,x);}
    return 0;
}

int sprawdz_max_z_min(int d,int s, int g)
{   sprawdz
    {x=min(odl[s]-odl[d],odl[g]-odl[s]);
    wyn_max=max(wyn_max,x);}
    return 0;
}

void wypelnij_prev_min_z_max()
{
    int i=0,j=0;
    while(i<sk){
        prev1[i]=-1;
        i++;
    }
    prev1[sk]=sk-1;i++;   
    
    for(;i<n;i++){
        if(siec[i]!=siec[i-1]) prev1[i]=i-1;
        else prev1[i]=prev1[i-1];
    }

    while(j<gk){
        prev2[j]=-1;
        j++;
    }    
    prev2[gk]=prev1[gk-1];j++;
    

    for(;j<n;j++){
        if(siec[j]!=siec[j-1]&&siec[j]!=siec[prev1[j-1]]) prev2[j]=prev1[j-1];
        else prev2[j]=prev2[j-1];
    }
}

void wypelnij_next_min_z_max(){
    int i=n-1,j=n-1;
    while(i>sk){
        next1[i]=-1;
        i--;
    }
    next1[sk]=sk+1;i--; 
    
    for(;i>-1;i--){
        if(siec[i]!=siec[i+1]) next1[i]=i+1;
        else next1[i]=next1[i+1];
    }

    while(j>dk){
        next2[j]=-1;
        j--;
    }
    next2[dk]=next1[dk+1];j--;

    for(;j>-1;j--){
        if(siec[j]!=siec[j+1]&&siec[j]!=siec[next1[j+1]]) next2[j]=next1[j+1];
        else next2[j]=next2[j+1];
    }
}

void wypelnij_prev_max_z_min()
{
    //printf("%d %d %d \n",dk,sk,gk);
    int i=sk+1,j=gk;
    prev1[sk]=0;   

    for(;i<n;i++){
        if(siec[i]!=siec[0]) prev1[i]=0;
        else prev1[i]=sk;
    }

    for(;j<n;j++){
        if(siec[j]!=siec[0] && prev1[j]!=0) prev2[j]=0;
        else if(siec[j]!=siec[sk] && prev1[j]!=sk) prev2[j]=sk;
        else prev2[j]=gk;
    }
}

void wypelnij_next_max_z_min(){
    
    next1[sk]=n-1;
    int i=sk-1;int j=dk;

     for(;i>-1;i--){
        if(siec[i]!=siec[n-1]) next1[i]=n-1;
        else next1[i]=sk;
    }

    for(;j>-1;j--){
        if(siec[j]!=siec[n-1] && next1[j]!=n-1) next2[j]=n-1;
        else if (siec[j]!=siec[sk] && next1[j]!=sk) next2[j]=sk;
        else next2[j]=dk;
     }
}

int min_z_max() //czy na przepychaniu nie pomijam niczego?
{   
    ustanow_dol(); 
    czyzero 
    wypelnij_prev_min_z_max();
    ustanow_gora();
    wypelnij_next_min_z_max();

    for(int i=0;i<n;i++){
        sprawdz_min_z_max(prev2[i],i,next1[i]);
        sprawdz_min_z_max(prev2[i],i,next2[i]);
        sprawdz_min_z_max(prev1[i],i,next1[i]);
        sprawdz_min_z_max(prev1[i],i,next2[i]);
    }
    //for(int i=0;i<n;i++) printf("%d %d %d %d %d \n",prev2[i],prev1[i],i, next1[i],next2[i]);
    printf("%d ", wyn_min);
    return 0;
}

int max_z_min()
{
    ustanow_dol(); 
    czyzero 
    //
    wypelnij_prev_max_z_min();
    ustanow_gora();
    wypelnij_next_max_z_min();
    
    for(int i=0;i<n;i++){
        sprawdz_max_z_min(prev2[i],i,next1[i]);
        sprawdz_max_z_min(prev2[i],i,next2[i]);
        sprawdz_max_z_min(prev1[i],i,next1[i]);
        sprawdz_max_z_min(prev1[i],i,next2[i]);
    }
    //for(int i=0;i<n;i++) printf("%d %d %d %d %d \n",prev2[i],prev1[i],i, next1[i],next2[i]);
    printf("%d ", wyn_max);
    return 0;
}

int main()
{
    wczytaj_dane();
    min_z_max();
    max_z_min();
    zwolnij_pamiec();
    return 0;
}

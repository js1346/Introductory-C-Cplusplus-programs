#include "bags.h"
#include <iostream>
using namespace std;

bool czyin=0;
lista przety;
worek biurkowsk;//biurko gdzies istnieje
worek* wskbiurkowsk;//wskaźnik na wskaźnik na biurko
int inw=0; //indeks nowego worka

void create_list(){
    przety = new elem{biurkowsk, nullptr,wskbiurkowsk, nullptr,  nullptr};
}

void push(plecak* aa, rzecz* bb, worek* cc,przedmiot *dd ) {
    lista nowy = new elem{aa, bb, cc, dd , przety};
    przety = nowy;
}

void pop(lista l) {
    przety = l->next;
    if(l->a) delete l->a;
    if(l->b) delete l->b;
    if(l->c) delete l->c;
    if(l->d) delete l->d;
    delete l;
}

void inicjalizuj(){
    czyin = 1;
    biurkowsk = new plecak{0, -1, nullptr};
    wskbiurkowsk = new worek;
    *wskbiurkowsk = biurkowsk;
    create_list();
}

przedmiot *nowy_przedmiot(){
    if (!czyin) inicjalizuj();
    przedmiot dozretwsk = new rzecz{biurkowsk};
    przedmiot* wskdozretwsk = new przedmiot{dozretwsk};
    push(nullptr, dozretwsk, nullptr, wskdozretwsk);
    biurkowsk->licznik++;
    return wskdozretwsk;
}

// Nowy worek na biurku; otrzymuje kolejny numer, począwszy od 0.
worek *nowy_worek(){
    if (!czyin) inicjalizuj();
    worek dozretwsk=  new plecak{0, inw, biurkowsk};
    worek* wskdozretwsk = new worek{dozretwsk};
    push(dozretwsk, nullptr, wskdozretwsk, nullptr);
    inw++;
    return wskdozretwsk;
}

void wloz(przedmiot *co, worek *gdzie){
    (*co)->ojciec = *gdzie;
    (*gdzie)->licznik++;
}

void wloz(worek *co, worek *gdzie){
    (*co)->ojciec = *gdzie;
    (*gdzie)->licznik += (*co)->licznik;
}


void wyjmij(przedmiot *p){
    (*p)->ojciec->licznik--;
    (*p)->ojciec = biurkowsk;
}

void wyjmij(worek *w){
    (*w)->ojciec->licznik -= (*w)->licznik;
    (*w)->ojciec = biurkowsk;
}

int w_ktorym_worku(przedmiot *p){
    return (*p)->ojciec->numer;
}

int w_ktorym_worku(worek *w){
    return (*w)->ojciec->numer;
}

int ile_przedmiotow(worek *w){
    return (*w)->licznik;
}

void na_odwrot(worek *w){
   
    //struktura opisująca biurko zamienia się ze strukturą opisującą worek, potem zamieniamy wartości pod wskaźnikami na biurko i pod wskaźnikami na worek

    int worcpy_licznik=(*w)->licznik; 
    int worcpy_numer=(*w)->numer;
    int biurcpy_licznik=biurkowsk->licznik; 
   
    (*w)->numer=-1;
    (*w)->licznik=biurcpy_licznik;
    (*w)->ojciec=nullptr;

    biurkowsk->licznik=biurcpy_licznik-worcpy_licznik; 
    biurkowsk->numer=worcpy_numer;
    biurkowsk->ojciec=(*w);

    worek pom=biurkowsk;
    biurkowsk=*w;
    *w=pom;

}
// Kończy i zwalnia pamięć
void gotowe(){
    while(przety) pop(przety);
}

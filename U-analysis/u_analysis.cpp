#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

//najpierw liczymy przedziały u maksymalne w nastepujący sposób-tworzymy dwie kolejki
//monotoniczne-jedna z malejącymi maksymami, a druga z rosnącymi minimami 
// każda kolejka przepycha dwie wartości-indeks i wartość
//odpowiednimi warunkami przedłużamy kolejki(tablicy z popfrontem) lub je kończymy i wsadzamy do kolejki z structa:pocz przedziału, koniec przedziału ,jakosc 
//potem za pomocą malejących wartosci(kolejna kolejka) uzyskujemy dla kazdej liczby odpowiedni przedział i zapisujemy dwa z trzech pól (poczatek i koniec.)

struct dan{
    int index;
    int x;
    int y;
};

struct uprzedz{
    int poc;
    int kon;
};

int n, u;

vector <dan> dane;
deque <uprzedz> uprzedzial; 

int porownaj (uprzedz a, uprzedz b){

	__int128_t da=a.kon-a.poc + 1;
	__int128_t db=b.kon-b.poc + 1;
	__int128_t ga=(__int128_t)dane[a.kon].x-dane[a.poc].x;
	__int128_t gb=(__int128_t)dane[b.kon].x-dane[b.poc].x;

	if ( ga *ga *db > gb * gb * da) return 2;
	if ( ga *ga *db == gb * gb * da) return 1;
	else return 0;

}

void wprowadz_dane(){
	
	int a , b;
	cin >> n >> u;
   
    for (int i = 0; i < n; i++){

		cin >> a >> b;
		dane.push_back({i,a,b});

	}

}

void utworz_przedzialy(){

	int lk = 0,pk = 0;
	deque <dan> maxy;
	deque <dan> miny;

	while (pk < n){

		while (!maxy.empty() && dane[pk].y >= maxy.back().y) maxy.pop_back();
		maxy.push_back(dane[pk]);
	    while (!miny.empty() && dane[pk].y <= miny.back().y) miny.pop_back();
		miny.push_back(dane[pk]);

		
		if (abs(maxy.front().y-miny.front().y) <= u){

			if (pk < n-1) pk++;

			else if (pk == n-1){
				pk++;
				uprzedzial.push_back({lk,pk-1});
			}
		}

		else{

			while (abs(maxy.front().y-miny.front().y) > u){

				if(uprzedzial.empty() || uprzedzial.back().kon != pk-1) uprzedzial.push_back({lk,pk-1});
				lk++;

				while (miny.front().index < lk) miny.pop_front();
				while (maxy.front().index < lk) maxy.pop_front();
			}
		}
    }
}

void analizujprzedzialy(){

	deque <uprzedz> kolmax;

	for (int i = 0; i < n; i++){

		while (!uprzedzial.empty() && uprzedzial.front().poc <= i) {

			while(!kolmax.empty() && (porownaj ( uprzedzial.front() , kolmax.back() ) == 2||
			(porownaj ( uprzedzial.front() , kolmax.back() ) == 1 && uprzedzial.front().poc < kolmax.back().poc))){

				kolmax.pop_back();
			}

			kolmax.push_back(uprzedzial.front());

			if (!uprzedzial.empty()) uprzedzial.pop_front();
		}

		while (kolmax.front().kon < i) kolmax.pop_front();

		cout << kolmax.front().poc+1 << " " << kolmax.front().kon+1 << endl;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	wprowadz_dane();
	utworz_przedzialy();
	analizujprzedzialy();

	return 0;
}

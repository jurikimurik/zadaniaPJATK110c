
#include <vector>


#include <iostream>
using namespace std;
//************************************************************************************************************************************************
int main()
{
	//Uruchamiamy generator liczb losowych
	srand(time(NULL));
	cout << "Podaj dolny zakres liczb losowych:";
	int a; cin >> a;

	cout << "Podaj gorny zakres liczb losowych:";
	int b; cin >> b;

	int tabl_rozmiar;
	//Powtarzaj do skutku
	while(true) {
		cout << "Podaj rozmiar tablicy:";
		cin >> tabl_rozmiar;

		//Sprawdzamy wprowadzona liczbe, musi byc z zakresu 0 do 100
				// && - polaczenie dwoch warunkow
		if(tabl_rozmiar > 0 && tabl_rozmiar <= 100)
			// Jezeli sie zgadza, wychodzimy z petli
			break;
		else
			// Jezeli nie - prosimy o wprowadzenie ponownie i informujemy
			cout << "Prosze wprowadzic liczbe z zakresu 0 do 100!" << endl;
	}

	// Tworzymy tablice o dlugosci
	int tabl[tabl_rozmiar];

	//Wypelniamy liczbami losowymi
	for(int i = 0; i < tabl_rozmiar; i++)
	{
		//liczba z zakresu ((b-a), b)
			//(b-a) - oznacza zakres liczb losowych, a - natomiast dolny zakres
			//lepsze tlumaczenie? Spytaj sie u Wujka Google o funkcji "rand() c++"
		tabl[i] = rand() % (b-a) + a;
	}

	//--------------------------------------------------------------------------------------------------


	//Wyliczamy srednia arytmetyczna
		//Definujemy pomocnicza zmienna
		int suma = 0;
	for(int i = 0; i < tabl_rozmiar; i++)
	{
		//Inaczej: suma = suma + tabl[i];
		suma += tabl[i];
	}
		//Teraz trzeba sume liczb podzielic przez ilosc liczb
	int odpowiedz1 = suma / tabl_rozmiar;

	cout << "srednia arytmetyczna elementow tablicy: " << odpowiedz1 << endl;


	//--------------------------------------------------------------------------------------------------

	// Liczba wystapień elementu
	cout << "Prosze podac jaki element interesuje uzytkownika: ";
	int interes_elem; cin >> interes_elem;

	//Przeszukujemy i sprawdzamy ile takich liczb znajdziemy (ilosc powtorzen wpisujemy do zmiennej ponizej)
		// Zakladamy, ze jeszcze nie znalezlismy zadnej
	int ilosc = 0;
	for(int i = 0; i < tabl_rozmiar; i++)
	{
		// Jezeli element z tablicy odpowiada elementowi, ktory nas interesuje
		// po prostu inkrementujemy (dodajemy jeden) do zmiennej ilosc
		if(tabl[i] == interes_elem) {
			ilosc++;
		}

	}

	// Pokazujemy rezultat

	cout << "Liczba wystapień interesujacej liczby: " << ilosc << endl;

	//--------------------------------------------------------------------------------------------------

	// Liczba elementow nieparzystych oraz ich suma
		//Definujemy pomocnicze zmienne i zakladamy ze ich jeszcze nie znalezlismy (0)
	int ilosc_nieparz = 0; int suma_nieparz = 0;

	// Ponownie prezszukujemy tablice na przedmiot interesujacych nas liczb
	for(int i = 0; i < tabl_rozmiar; i++)
	{
		//Jezeli liczba z tablicy podzielona przez dwojke
		//zostawia po sobie reszte 1, to jest to liczba nieparzysta
		if(tabl[i] % 2 == 1) {
			//Inaczej: suma_nieparz = suma_nieparz + tabl[i];
			suma_nieparz += tabl[i];
			ilosc_nieparz++;		// Rowniez inkrementujemy ilosc znalezionych nieparzystych
		}
	}

	//Tak, mozemy pomiedzy << *zmienna* << klikac enter (dodac bialy znak). Dla kompilatora to wciaz
	// bedzie << *zmienna* <<
	cout << "Ilosc znalezionych nieparzystych: " << ilosc_nieparz
			<< ", a ich suma: " << suma_nieparz << endl;

	//--------------------------------------------------------------------------------------------------

	// Element minimalny oraz jego indeks
		//Definujemy pomocnicze zmienne
			//Przy zmiennej minimalny zakladamy, ze pierwsza liczba
			//jest najmniejsza(nawet jesli nie jest, po prostu potrzebujemy liczby z tabeli)
	int minimalny = tabl[0]; int indeks_min = 0;

	//Przeszukujemy tablice
	for(int i = 0; i < tabl_rozmiar; i++)
	{
		//Jezeli liczba z tabeli jest mniejsza od minimalnego, to wtedy ta liczba staje sie minimalna
		if(tabl[i] < minimalny) {
			minimalny = tabl[i];

			//Rowniez zmieniamy indeks, zeby wiedziec ktora z liczb w tabeli jest minimalna
			indeks_min = i;
		}
	}

	cout << "Liczba minimalna: " << minimalny << ", a jej indeks to: " << indeks_min << endl;

	//--------------------------------------------------------------------------------------------------

	//Element maksymalny
		//Definujemy pomocnicze zmienne
		// Sposob podobny, jak przy poszukiwaniu minimalnego elemntu
	int maksymalny = tabl[0]; int indeks_maks = 0;

	//Przeszukujemy tablice
		for(int i = 0; i < tabl_rozmiar; i++)
		{
			//Jezeli liczba z tabeli jest wieksza od maksymalnej, to wtedy ta liczba staje sie maksymalna
			if(tabl[i] > maksymalny) {
				maksymalny = tabl[i];

				//Rowniez zmieniamy indeks, zeby wiedziec ktora z liczb w tabeli jest najwieksza
				indeks_maks = i;
			}
		}

		cout << "Liczba maksymalna: " << maksymalny << ", a jej indeks to: " << indeks_maks << endl;
}

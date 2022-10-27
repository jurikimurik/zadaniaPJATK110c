/*
 * Zadanie20.cpp
 *
 *  Created on: 27 paź 2022
 *      Author: urijmakovskij
 */

#include <string>


#include <iostream>
using namespace std;
//************************************************************************************v
//Pomocnicza tablica z inicjalizowanymi od razu elementami pomaga w sprawdzeniu peselu
//Więcej info: https://www.infor.pl/prawo/gmina/dowod-osobisty/262184,Jak-sprawdzic-czy-masz-poprawny-PESEL.html
int mnoz_do_spr_peselu[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
//************************************************************************************v
int main()
{
	//Etykieta. Dzieki niej z uzyciem goto "ETYKIETA" mozemy przeskakiwac do wlasnie takiej etyiety
	POCZATEK:

	//Prosimy o pesel
	cout << "Podaj numer PESEL: ";
	//Zczytujemy ciąg znakow jako string (dlatego, ze ma funkcje .size() oraz .at()
	//dzieki ktorej bedzie mozna brac pojedyncze specyficzne znaki w stringu
	string pesel; getline(cin, pesel);

	if(pesel.size() != 11)
	{
		//Bledna dlugosc peselu
		cout << "Proszę podac poprawny numer PESEL." << endl;
		//Wracamy do etykiety (POCZATEK)
		goto POCZATEK;
	}
	//Zczytujemy ostatnia liczbe w peselu jako int
		//W tym celu musimy wziasc znak z pozycji 10 (bo numeracja zaczyna sie od 0 a nie od 1) i odjac 48.
		//Czemu 48? Bo .at() zwraca znaczek (char) z kodem z tabeli ASCII wedlug ktorej zakodowane wszystkie znaki
		//I dopiero z pozycji 48 zaczynaja sie znaki numeryczne (od 0 i w gore)
	int ostatnia_liczba = pesel.at(10) - 48;

	//Definujemy pomocnicza zmienna
	int suma_kontrolna = 0;
	//Korzystajac z pomocniczej tabeli, sumujemy wszystkie liczby wedlug wzoru:
		//1*a + 3*b + 7*c + 9*d + 1*e + 3*f + 7*g + 9*h + 1*i + 3*j (po to zdefiniowalismy tabele wczesniej)
	for(int i = 0; i < 10; i++)
	{
							//Zamieniami znaki ASCII do int odejmujac 48 oraz mnozymy to przez odpowiednia liczbe z tabeli pomocniczej
		suma_kontrolna += (pesel.at(i) - 48) * mnoz_do_spr_peselu[i];
	}

	//Zamieniamy suma_kontrolna na string, by stamtad...
	string suma_str = to_string(suma_kontrolna);
								//Pobrac ostatnia cyfre (suma_str.size()-1) i jak wczesniej, odejmujemy 48,
								//by zamienic ja na prawdziwa postac w int
	int ostatnia_liczba_sumy = suma_str.at(suma_str.size()-1) - 48;

	//Wedlug sprawdzenia, nalezy od tej liczby odjac 10. Bedzie ujemna wiec od razu mnozymy przez -1, by uzyskac dodatnia
	ostatnia_liczba_sumy = (ostatnia_liczba_sumy - 10) * -1;

	//Jezeli ta liczba zgadza sie z ostatnia liczba w podanym numerze PESEL - zalatwione!
	if(ostatnia_liczba_sumy == ostatnia_liczba)
		cout << "PESEL poprawny!" << endl;
	else
		cout << "PESEL niepoprawny!" << endl;

	//Pytamy sie, czy ponownie chcemy sprawdzic jakis PESEL
	cout << "Chcesz wprowadzic PESEL ponownie?(y/n) " << endl;
	string odp; getline(cin, odp);
	//Jezeli tak, to wracamy do etykiety POCZATEK
	if(odp == "y" || odp == "Y")
		goto POCZATEK;

}

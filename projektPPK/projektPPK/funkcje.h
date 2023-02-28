/** @file */
#ifndef FUNKCJE_H
#define FUNKCJE_H

#include "struktury.h"
/** Funkcja sprawdzaj¹ca kolejnoœæ wczytywanych plików za pomoc¹ prze³¹czników
* @param graphfile parametr do którego wczytujemy nazwê pliku z grafem 
* @param verticlefile parametr do którego wczytujemy nazwê pliku z wierzcho³kami pocz¹tkowymi
* @param resultfile parametr do którego wczytujemy nazwê pliku z wynikami
* @param argc liczba parametrów wywo³ania funkcji main
* @param argv tablica napisów reprezentuj¹cych parametry
*/
void checkFiles(std::string &graphFile, std::string &verticleFile, std::string &resultFile, int argc,char* argv[]);

/** Funkcja sprawdzaj¹ca czy parametr jest liczb¹ 
* @param s zmienna któr¹ sprawdzamy czy jest liczb¹ 
* @return true kiedy parametr jest liczb¹ lub false kiedy nie jest
*/
bool isNumber(std::string& s);

/** Funkcja wczytujaca zawartosc grafu
* @param name nazwa pliku do wczytania 
* @param edges wektor do ktorego wczytujemy zawartosc grafu
* @param m liczba krawedzi w grafie
* @param max liczba wierzcholkow w grafie
* @param v wektor pomocniczy przechowujacy wszystkie wczytane wierzcholki grafu
* @return 1 w przpadku poprawnych danych lub 0 w przpadku b³êdnych danych
*/
int readEdge(const std::string& name, std::vector<edge>& edges, int& m, int& max, std::vector<int> &v);


/** Funkcja wczytujaca wierzcholki poczatkowe
* @param name nazwa pliku do wczytania
* @param starters wektor do ktorego wczytujemy wierzcholki poczatkowe
* @return 1 w przpadku poprawnych danych lub 0 w przpadku b³êdnych danych
*/
int readStarters(const std::string& name, std::vector<int>& starters);


/** Funkcja znajduj¹ca najkrótsze œcie¿ki miêdzy zadanym wierzcho³kiem grafu a wszystkimi pozosta³ymi wierzcho³kami.
* @param edges wektor z zawartoacia grafu
* @param starters wektor z zawartoscia wierzcholkow poczatkowych 
* @param m liczba krawedzi w grafie
* @param max liczba wierzcholkow w grafie
* @param v wektor pomocniczy przechowujacy wszystkie wczytane wierzcholki grafu
* @param name nazwa pliku do ktorego wczytujemy wynik
*/
void dijkstra(std::vector<edge>& edges, std::vector<int>& starters, int& m, int& max, std::vector<int>& v, std::string& name);


/** Funkcja wczytujaca wyniki do pliku
* @param file zmienna umozliwiajaca dostep do pliku z wynikami 
* @param p tablica poprzednikow wierzcholkow na bierzacej sciezce
* @param d tablica zawierajaca koszty dojscia do bierzacych wierzcholkow z wierzcholkow poczatkowych 
* @param starters wektor z zawartocia wierzcholkow poczatkowych
* @param max liczba wierzcholkow w grafie
* @param i indeks bierzacego wierzcholka poczatkowego 
*/
void LoadGraph(std::fstream& file, int* p, float* d, std::vector<int>& starters, int& max, std::size_t& i);


#endif

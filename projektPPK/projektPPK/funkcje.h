/** @file */
#ifndef FUNKCJE_H
#define FUNKCJE_H

#include "struktury.h"
/** Funkcja sprawdzaj�ca kolejno�� wczytywanych plik�w za pomoc� prze��cznik�w
* @param graphfile parametr do kt�rego wczytujemy nazw� pliku z grafem 
* @param verticlefile parametr do kt�rego wczytujemy nazw� pliku z wierzcho�kami pocz�tkowymi
* @param resultfile parametr do kt�rego wczytujemy nazw� pliku z wynikami
* @param argc liczba parametr�w wywo�ania funkcji main
* @param argv tablica napis�w reprezentuj�cych parametry
*/
void checkFiles(std::string &graphFile, std::string &verticleFile, std::string &resultFile, int argc,char* argv[]);

/** Funkcja sprawdzaj�ca czy parametr jest liczb� 
* @param s zmienna kt�r� sprawdzamy czy jest liczb� 
* @return true kiedy parametr jest liczb� lub false kiedy nie jest
*/
bool isNumber(std::string& s);

/** Funkcja wczytujaca zawartosc grafu
* @param name nazwa pliku do wczytania 
* @param edges wektor do ktorego wczytujemy zawartosc grafu
* @param m liczba krawedzi w grafie
* @param max liczba wierzcholkow w grafie
* @param v wektor pomocniczy przechowujacy wszystkie wczytane wierzcholki grafu
* @return 1 w przpadku poprawnych danych lub 0 w przpadku b��dnych danych
*/
int readEdge(const std::string& name, std::vector<edge>& edges, int& m, int& max, std::vector<int> &v);


/** Funkcja wczytujaca wierzcholki poczatkowe
* @param name nazwa pliku do wczytania
* @param starters wektor do ktorego wczytujemy wierzcholki poczatkowe
* @return 1 w przpadku poprawnych danych lub 0 w przpadku b��dnych danych
*/
int readStarters(const std::string& name, std::vector<int>& starters);


/** Funkcja znajduj�ca najkr�tsze �cie�ki mi�dzy zadanym wierzcho�kiem grafu a wszystkimi pozosta�ymi wierzcho�kami.
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

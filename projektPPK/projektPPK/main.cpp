/** @file */
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include"funkcje.h"
/**
* @param argc liczba parametr�w wywo�ania funkcji main
* @param argv tablica napis�w reprezentuj�cych parametry
*/
int main(int argc, char* argv[])
{
	std::string help = "";
	if (argc == 2)
		help = argv[1];
	if (argc == 7)
	{
		std::string graphFile = "", verticleFile = "", resultFile = "";
		std::vector<edge> edges;
		std::vector<int> starters;
		std::vector<int> v;
		//int start = 3;
		int m, max;

		checkFiles(graphFile, verticleFile, resultFile, argc, argv);
		if (readEdge(graphFile, edges, m, max, v))
		{
			if (readStarters(verticleFile, starters))
				dijkstra(edges, starters, m, max, v, resultFile);
		}
		//readStarters(verticleFile, starters);
	//dijkstra(edges, starters, m, max, v, resultFile);
	}
	else if ((argc == 2 && help == "-h") || (argc == 1))
	{
		std::cout << "Program nale�y uruchomi� w nast�puj�cy spos�b:\nprogram -g graf.txt -w wierzcholki.txt -o wyniki.txt\n";
	}
	else
	{
		std::cout << "Nieprawid�owa lizcba parametr�w" << std::endl;
		std::cout << "Spr�buj program -h" << std::endl;
	}
	/*
	std::vector<edge> edges;
	std::vector<int> starters;
	std::vector<int> v;
	int start = 3;
	int m, max;

	readEdge(argv[1], edges, m, max, v);
	readStarters(argv[2], starters);
	dijkstra(edges, starters, m, max, v, argv[3]);
	*/
	return 0;
}
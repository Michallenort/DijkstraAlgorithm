/** @file */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include"funkcje.h"
#include "struktury.h"

void checkFiles(std::string& graphFile, std::string& verticleFile, std::string& resultFile, int argc, char* argv[])
{
	int i = 1;

	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'g')
			{
				i++;
				graphFile = argv[i];
			}
			else if (argv[i][1] == 'w')
			{
				i++;
				verticleFile = argv[i];
			}
			else if (argv[i][1] == 'o')
			{
				i++;
				resultFile = argv[i];
			}
			else
			{
				std::cout << "Z�y parametr wej�ciowy \n";
			}
			i++;
		}
		else
			std::cout << "Z�y prze��cznik!" << std::endl;
	}
}

bool isNumber(std::string& s)
{
	if (s.length() == 0)
		return false;
	else
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != '.')
				if (isdigit(s[i]) == false)
					return false;
		}
		return true;
	}
}


int readEdge(const std::string& name, std::vector<edge>& edges, int& m, int& max, std::vector<int>& v)
{
	m = 0;
	max = 0;
	std::fstream file;
	file.open(name);
	if (file)
	{
		edge e;
		std::string c;
		std::string line;
		std::string l = "";

		while (!file.eof())
		{
			getline(file, line);

			for (std::size_t i = 0; i < line.length(); i++)
			{
				if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\r')
					l += line[i];
			}

			line = l;
			l.clear();

			if (line.length() > 0)
			{
				std::size_t i = 0;
				if (i < line.length())
				{
					while (line[i] != '-')
					{
						if (line[i] != ' ')
							l += line[i];
						i++;
					}

					if (isNumber(l))
					{
						e.x = std::stoi(l);
						v.push_back(e.x);
					}
					else
					{
						std::cout << "B��dne dane1!!" << std::endl;
						return 0;
					}

					l.clear();
					c = line[i];
					if (line[i + 1] == '>')
					{
						i++;
						c += line[i];
					}

					i++;
					l.clear();

					while (line[i] != ':')
					{
						if (line[i] != ' ')
							l += line[i];
						i++;
					}

					if (isNumber(l))
					{
						e.y = std::stoi(l);
						v.push_back(e.x);
					}
					else
					{
						std::cout << "B��dne dane2!!" << std::endl;
						return 0;
					}
					i++;
					l.clear();

					while (i < line.size())
					{
						if (line[i] != ' ')
							l += line[i];
						i++;
					}

					if (isNumber(l))
					{
						e.w = std::stof(l);
						edges.push_back(e);
					}
					else
					{
						std::cout << "B��dne dane3!!" << std::endl;
						return 0;
					}
					l.clear();


					m++;

					if (c == "-")
					{
						int p;
						p = e.x;
						e.x = e.y;
						e.y = p;
						edges.push_back(e);

						m++;
					}
				}
			}


		}
	}
	else
	{
		std::cout << "Error" << std::endl;
	}

	for (size_t i = 0; i < edges.size(); i++)
	{
		if (edges[i].x > max)
			max = edges[i].x;

		if (edges[i].y > max)
			max = edges[i].y;
	}
	file.close();
	return 1;
}


int readStarters(const std::string& name, std::vector<int>& starters)
{
	std::fstream file;
	file.open(name);
	if (file)
	{
		std::string line, l;
		int x;
		getline(file, line);
		for (std::size_t i = 0; i < line.length(); i++)
		{
			
			if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\r')
			{
				l += line[i];
				if (i == line.length() - 1)
				{
					if (isNumber(l))
					{
						x = std::stoi(l);
						starters.push_back(x);
					}
					else
					{
						std::cout << "B��dne dane!!" << std::endl;
						return 0;
					}
					l.clear();

				}

				 
			}
			else
			{
				 
				if (isNumber(l))
				{
					x = std::stoi(l);
					starters.push_back(x);
				}
				else
				{
					std::cout << "B��dne dane!!" << std::endl;
					return 0;
				}
				l.clear();
			}
		}

	}
	else
		std::cout << "Error!" << std::endl;
	return 1;
}


void LoadGraph(std::fstream& file, int* p, float* d, std::vector<int>& starters, int& max, std::size_t&  i)
{


	int* set, a;

	set = new int[max];
	a = 0;

	file << "Wierzcho�ek startowy: " << starters[i] << std::endl;
	for (int j = 0; j < max; j++)
	{
		if (d[j] != FLT_MAX && d[j] != 0)
		{
			for (int n = j; n > -1; n = p[n])
				set[a++] = n;


			while (a)
			{
				if (set[--a] == starters[i])
					file << set[a];
				else
					file << " -> " << set[a];
			}
			file << " : " << d[j] << std::endl;

		}
	}
	delete[] set;

}

void dijkstra(std::vector<edge>& edges, std::vector<int>& starters, int& m, int& max, std::vector<int>& v, std::string& name)
{
	int* p;
	float* d;
	bool* S;
	int u;
	list** graph;
	list* newElement, * b;
	std::fstream output;
	max++;


	output.open(name, std::ios::app);

	for (std::size_t n = 0; n < starters.size(); n++)
	{
		int a = 0;

		for (std::size_t j = 0; j < v.size(); j++)
		{
			if (starters[n] == v[j])
			{
				a = 1;
				break;
			}
		}
		if (a)
		{
			d = new float[max];
			p = new int[max];
			S = new bool[max];
			graph = new list * [max];

			for (int i = 0; i < max; i++)
			{
				d[i] = FLT_MAX;
				p[i] = -1;
				S[i] = false;
				graph[i] = NULL;
			}

			for (int i = 0; i < m; i++)
			{
				newElement = new  list;
				newElement->y = edges[i].y;
				newElement->w = edges[i].w;
				newElement->next = graph[edges[i].x];
				graph[edges[i].x] = newElement;
			}

			d[starters[n]] = 0;

			for (int i = 0; i < max; i++)
			{
				int j;
				for (j = 0; S[j]; j++);

				u = j++;
				while (j < max)
				{
					if (!S[j] && (d[j] < d[u]))
						u = j;
					j++;
				}
				S[u] = true;


				newElement = graph[u];
				while (newElement)
				{
					if (!S[newElement->y] && (d[newElement->y] > d[u] + newElement->w))
					{
						d[newElement->y] = d[u] + newElement->w;
						p[newElement->y] = u;
					}
					newElement = newElement->next;
				}
			}

			LoadGraph(output, p, d, starters, max, n);

			for (int i = 0; i < max; i++)
			{
				newElement = graph[i];
				while (newElement)
				{
					b = newElement;
					newElement = newElement->next;
					delete b;
				}
			}

			delete[] d;
			delete[] p;
			delete[] S;
			delete[] graph;

		}
		else
		{
			output << "Wierzcho�ek startowy: " << starters[n] << std::endl;
			output << "Brak wierzcho�ka " << starters[n] << " w grafie" << std::endl;
		}
	}
	output.close();


}
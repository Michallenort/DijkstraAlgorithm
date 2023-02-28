#ifndef STRUKTURY_H
#define STRUKTURY_H

/** Krawêd¿ sk³adaj¹ca siê z dwóch wierzcho³ków i wagi krawêdzi*/
struct edge
{
	int x, y;
	float w;
};
/** Lista jednokierunkowa z wierzcho³kiem docelowym, wag¹ i wska¿nikiem na nastêpny element*/
struct list
{
	int y;
	float w;
	list* next;
};

#endif
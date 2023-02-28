#ifndef STRUKTURY_H
#define STRUKTURY_H

/** Kraw�d� sk�adaj�ca si� z dw�ch wierzcho�k�w i wagi kraw�dzi*/
struct edge
{
	int x, y;
	float w;
};
/** Lista jednokierunkowa z wierzcho�kiem docelowym, wag� i wska�nikiem na nast�pny element*/
struct list
{
	int y;
	float w;
	list* next;
};

#endif
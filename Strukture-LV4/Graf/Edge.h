#pragma once
#include<iostream>
using namespace std;
template<class T, class W>
class LinkedNode;
template<class T,class W>
class Edge
{
public:
	LinkedNode<T, W>* dest;
	Edge<T, W>* link;
	W weigth;
	Edge()
	{
		dest = NULL;
		link = NULL;
		weigth = 0;
	}
	Edge(LinkedNode<T, W>* destN, Edge<T, W>* linkN)
	{
		dest = destN;
		link = linkN;
		weigth = 0;
	}
};


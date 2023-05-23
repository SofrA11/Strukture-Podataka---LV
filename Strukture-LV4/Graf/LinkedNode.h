#pragma once
#include<iostream>
using namespace std;
template<class T, class W>
class Edge;
template<class T, class W>
class LinkedNode
{
public:
	T node;
	Edge<T, W>* adj;
	LinkedNode<T, W>* next;
	int status;
	LinkedNode() { adj = NULL; next = NULL; status = 0; }
	LinkedNode(T nodeN)
	{
		node = nodeN;
		adj = NULL;
		next = NULL; 
		status = 0;
	}
	LinkedNode(T nodeN, Edge<T, W>* adjN, LinkedNode<T, W>* nextN, int statusN)
	{
		node = nodeN;
		adj = adjN;
		next = nextN;
		status = statusN;
	}
	void Visit()
	{
		cout << node << endl;
	}
};


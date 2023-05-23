#include "GraphAsList.h"
#include<iostream>
using namespace std;
/*
template <class T, class W>
void GraphAsList<T, W>::print()
{
	LinkedNode<T, W>* ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->node << " -> ";
		Edge<T, W>* pa = ptr->adj;
		while (pa != NULL)
		{
			cout << pa->dest->node << "|";
			pa = pa->link;
		}
		cout << "\r\n";
		ptr = ptr->next;
	}
}
template<class T, class W>
//Ova metoda ima funkciju da prilikom brisanja cvora obrise sve potege u kojima se javlja taj cvor
void GraphAsList<T, W>::deleteEdgeToNode(LinkedNode<T, W>* ptr)
{
	int i = 0;
	LinkedNode<T, W>* pom = start;
	while (pom!=NULL)
	{
		deleteEdge(ptr->node, pom->node);
		pom = pom->next;
	}

	//throw "FUNKCIJA NIJE IMPLEMENTIRANA!";
}
*/
/*
template<class T, class W>
GraphAsList<T, W>::~GraphAsList()
{
	if (start != NULL)
		delete[] start;
	delete start;
}
template <class T, class W>
LinkedNode<T, W>* GraphAsList<T, W>::findNode(T pod)
{
	LinkedNode<T, W>* ptr = start;
	while (ptr != NULL && ptr->node != pod)
	{
		ptr = ptr->next;
	}
	return ptr;
}

template<class T, class W>
LinkedNode<T, W>* GraphAsList<T, W>::findNodeMaxInDeg()
{
	long* mat = new long[nodeNum];
	for (int q = 0; q < nodeNum; q++)
		mat[q] = 0;
	
	for (int i = 0; i < nodeNum; i++)
	{
		while (start[i]->adj != NULL)
		{
			mat[start[i]->adj->dest->node]++;
			start[i]->adj = start[i]->adj->next;
		}
	}
	int max = mat[0];
	int index;
	for (int q = 1; q < nodeNum; q++)
	{
		if (max > mat[q])
		{
			max = mat[0];
			index = q;
		}
	}
	return start[index];
}

template <class T, class W>
Edge<T, W>* GraphAsList<T, W>::findEdge(T a, T b)
{
	LinkedNode<T, W>* pa = findNode(a);
	LinkedNode<T, W>* pb = findNode(b);
	if (pa == NULL || b == NULL)
		return NULL;
	Edge<T, W>* ptr = pa->adj;
	while (ptr != NULL && ptr->dest != pb)
	{
		ptr = ptr->link;
	}
	return ptr;
}
template <class T, class W>
bool GraphAsList<T, W>::insertNode(T pod)
{
	LinkedNode<T, W>* newNode = new LinkedNode<T, W>(pod, NULL, start, 0);
	if (newNode == NULL)
		return false;
	start = newNode;
	nodeNum++;
	return true;
}

template<class T, class W>
bool GraphAsList<T, W>::insertEdge(T a, T b)
{
	LinkedNode<T, W>* pa = findNode(a);
	LinkedNode<T, W>* pb = findNode(b);
	if (pa == NULL || pb == NULL) return false;
	Edge<T, W>* ptr = new Edge<T, W>(pb, pa->adj);
	if (ptr == NULL) return false;
	pa->adj = ptr;
	return true;
}

template <class T, class W>
bool GraphAsList<T, W>::deleteEdge(T a, T b)
{
	Edge<T, W>* pot = findEdge(a, b);
	if (pot == NULL) return false;
	LinkedNode<T, W>* pa = findNode(a);
	if (pot == pa->adj) {
		pa->adj = pot->link;
		delete pot; return true;
	}
	Edge<T, W>* tpot = pa->adj;
	while (tpot->link != pot)
		tpot = tpot->link;
	tpot->link = pot->link;
	delete pot; return true;
}
template <class T, class W>
bool GraphAsList<T, W>::deleteNode(T pod)
{
	LinkedNode<T, W>* ptr;
	if (start == NULL) return false;
	if (start->node == pod) {
		Edge<T, W>* pot = start->adj;
		while (pot != NULL) {
			Edge<T, W>* tpot = pot->link;
			delete pot;
			pot = tpot;
		}
		deleteEdgeToNode(start);
		ptr = start;
		start = start->next;
		delete ptr;
		nodeNum--;
		return true;
	}
	else {
		ptr = start->next;
		LinkedNode<T, W>* par = start;
		while (ptr != NULL && ptr->node != pod) {
			par = ptr;
			ptr = ptr->next;
		}
		if (ptr == NULL) return false;
		par->next = ptr->next;
		Edge<T, W>* pot = ptr->adj;
		while (pot != NULL) {
			Edge<T, W>* tpot = pot->link;
			delete pot; pot = tpot;
		}
		deleteEdgeToNode(ptr);
		delete ptr;
		nodeNum--;
		return true;
	}
}
*/
/*
template <class T, class W>
long GraphAsList<T, W>::breadthTrav(T a)
{
	long retVal = 0;
	LinkedNode<T, W>* ptr = start;
	QueueAsArray<LinkedNode<T, W> que(nodeNum);
	while (ptr != NULL) {
		ptr->status = 1;
		ptr = ptr->next;
	}
	ptr = findNode(a);
	if (ptr == NULL) return 0;
	que.enqueue(ptr);
	ptr->status = 2;
	while (!que.isEmpty()) {
		ptr = que.dequeue();
		ptr->status = 3;
		ptr->Visit();
		retVal += 1;
		Edge<T, W>* pot = ptr->adj;
		while (pot != NULL) {
			if (pot->dest->status == 1) {
				pot->dest->status = 2;
				que.enqueue(pot->dest);
			}
			pot = pot->link;
		}
	}
	return retVal;
}

template<class T, class W>
long GraphAsList<T, W>::depthTrav(T a)
{
	
	return 0;
}
*/
/*
template <class T, class W>
long GraphAsList<T, W>::topologicalOrderTrav()
{
	int retVal = 0; //broj obidjenih cvorova
	// Odredjivanje ulaznog stepena za svaki cvor
	LinkedNode<T, W>* ptr;
	ptr = start;
	while (ptr != NULL) {
		ptr->status = 0;
		ptr = ptr->next;
	}
	ptr = start;
	while (ptr != NULL) {
		Edge<T, W>* pot = ptr->adj;
		while (pot != NULL) {
			pot->dest->status += 1;
			pot = pot->link;
		}
		ptr = ptr->next;
	}
	// Sve izvorne potege smestiti u red
	QueueAsArray<LinkedNode<T, W>*> que(nodeNum);
	ptr = start;
	while (ptr != NULL) {
		if (ptr->status == 0) que.enqueue(ptr);
		ptr = ptr->next;
	}
	while (!que.isEmpty()) {
		ptr = que.dequeue();
		ptr->Visit(); retVal += 1;
		Edge<T, W>* pot = ptr->adj;
		while (pot != NULL) {
			pot->dest->status -= 1;
			if (pot->dest->status == 0)
				que.enqueue(pot->dest);
			pot = pot->link;
		}
	}
	return retVal;
}
*/
#pragma once
#include"LinkedNode.h";
#include"Edge.h";
template<class T,class W>
class GraphAsList
{
protected:
	LinkedNode<T, W>* start;
	long nodeNum;
	void deleteEdgeToNode(LinkedNode<T, W>* ptr)
	{
		int i = 0;
		LinkedNode<T, W>* pom = start;
		while (pom != NULL)
		{
			deleteEdge(ptr->node, pom->node);
			pom = pom->next;
		}
	}
public:
	inline GraphAsList() { start = NULL; nodeNum = 0; }
	~GraphAsList()
	{
		if (start != NULL)
			delete[] start;
		delete start;
	}
	LinkedNode<T, W>* findNode(T pod)
	{
		LinkedNode<T, W>* ptr = start;
		while (ptr != NULL && ptr->node != pod)
		{
			ptr = ptr->next;
		}
		return ptr;
	}
	LinkedNode<T, W>* findNodeMaxInDeg()
	{
		T** mat = new T * [nodeNum];
		LinkedNode<T, W>* ptr = start;
		int q = 0;
		//Kreira matricu, u cijoj je 1. vrsti ulazni stepen inicijalizovan na 0, dok je 2. vrsta ime cvora
		while (ptr != NULL)
		{
			mat[q] = new T[2];
			mat[q][0] = 0;
			mat[q][1] = ptr->node;
			ptr = ptr->next;
			q++;
		}
		ptr = start;
		//obilazak svakog cvora
		while (ptr != NULL)
		{
			int i = 0;
			//obilazi svaki poteg odabranog cvora
			while (ptr->adj != NULL)
			{
				int k = 0;
				//prolazak kroz matricu i trazenje cvora na koji ukazuje dati poteg
				while (ptr->adj->dest->node != mat[k][1])
				{
					k++;
				}
				mat[k][0]++;//uvecava ulazni stepen za 1
				ptr->adj = ptr->adj->link;
			}
			i++;
			ptr = ptr->next;
		}

		int max = mat[0][0];
		int index = 0;
		T node=0;
		//trazenje najveceg ulaznog stepena
		for (int q = 1; q < nodeNum; q++)
		{
			if (max < mat[q][0])
			{
				node = mat[q][1];
				max = mat[q][0];
				index = q;
			}
		}
		LinkedNode<T, W>* ptr2 = start;
		while (ptr2 != NULL)
		{
			if (ptr2->node == node)
			{
				break;
			}
			ptr2 = ptr2->next;
		}
		ptr2->Visit();
		return ptr2;
	}
	LinkedNode<T, W>* findNodeMaxOutDeg()
	{
		LinkedNode<T, W>* ptr = start;
		LinkedNode<T, W>* cvor = new LinkedNode<T, W>[1];
		int max = 0;
		//obilazak svakog cvora
		while (ptr != NULL)
		{
			int count = 0;
			//obilazak svakog potega i brojenje
			while (ptr->adj != NULL)
			{
				count++;
				ptr->adj = ptr->adj->link;
			}
			//odredjivanje koji cvor ima najveci broj potega
			if (max < count)
			{
				cvor = ptr;
				max = count;
			}
			ptr = ptr->next;
		}
		cvor->Visit();
		return cvor;
	}
	LinkedNode<T, W>* findNodeNullInDeg()//pronalazenje cvorova koji imaju ulazni stepen 0
	{
		T** mat = new T * [nodeNum];
		LinkedNode<T, W>* ptr = start;
		int q = 0;
		//obilazi svaki cvor i 1.kolonu matrice inicijalizuje na 0 u 2. kolonu matrice upisuje naziv cvora
		while (ptr != NULL)
		{
			mat[q] = new T[2];
			mat[q][0] = 0;
			mat[q][1] = ptr->node;
			ptr = ptr->next;
			q++;
		}

		ptr = start;
		//obilazi svaki cvor
		while (ptr != NULL)
		{
			int i = 0;
			//obilazi svaki poteg zadatog cvora
			while (ptr->adj != NULL)
			{
				int k = 0;
				//obilazi svaku vrstu matrice i trazi onu u kojoj je smesten cvor na koji poteg ukazuje
				while (ptr->adj->dest->node != mat[k][1])
				{
					k++;
				}
				mat[k][0]++;
				ptr->adj = ptr->adj->link;
			}
			i++;
			ptr = ptr->next;
		}

		int br = 0;
		int index = 0;
		LinkedNode<T, W>* vr = NULL;
		for (int q = 1; q < nodeNum; q++)
		{
			if (mat[q][0] == 0)
			{
				LinkedNode<T, W>* node = new LinkedNode<T, W>(mat[q][1], NULL, NULL, 0);
				if (vr == NULL)//inicijalizuje se lista elemenata za ulaznim stepenom 0
				{
					vr = node;
				}
				if (index != 0)//svaki sledeci element(osim 1.), koji ima ulazni stepen 0 se dodaje na sledeci nacin
				{
					LinkedNode<T, W>* newNode = new LinkedNode<T, W>(node->node, NULL, vr, 0);
					if (newNode != NULL)
					{
						vr = newNode;
					}
				}
				index = 1;
			}
		}
		LinkedNode<T, W>* stampa = vr;
		while (stampa != NULL)//stampa cvorove koji imaju ulazni stepen 0
		{
			stampa->Visit();
			stampa = stampa->next;
		}
		return vr;
	}
	LinkedNode<T, W>* findNodeNullOutDeg()
	{
		LinkedNode<T, W>* ptr = start;
		LinkedNode<T, W>* vr = NULL;
		int i = 0;
		int n = 0;
		while (ptr != NULL)//Obilazi svaki cvor grafa
		{
			if (ptr->adj == 0)//Ispituje da li cvor ima potege
			{
				LinkedNode<T, W>* node = new LinkedNode<T, W>(ptr->node, NULL, NULL, 0);
				if (vr == NULL)//Prvi cvor koji ima izlazni stepen 0
				{
					vr = node;
				}
				if (i != 0)//Svaki sledeci cvor koji ima izlazni stepen 0 se dodaje na sledeci nacin u listu cvorova
				{
					LinkedNode<T, W>* newNode = new LinkedNode<T, W>(node->node, NULL, vr, 0);
					if (newNode != NULL)
					{
						vr = newNode;
						n++;
					}
				}
			}
			i = 1;
			ptr = ptr->next;
		}
		LinkedNode<T, W>* stampa = vr;
		while (stampa != NULL)//prikaz cvoroca ciji je izlazni stepen 0
		{
			stampa->Visit();
			stampa = stampa->next;
		}
		return vr;
	}
	Edge<T, W>* findEdge(T a, T b)
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
	bool insertNode(T pod)
	{
		LinkedNode<T, W>* newNode = new LinkedNode<T, W>(pod, NULL, start, 0);//new LinkedNode<T, W>(NodeName, Edge, NextNode, status)
		if (newNode == NULL)
			return false;
		start = newNode;
		nodeNum++;
		return true;
	}
	bool deleteNode(T pod)
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
	bool insertEdge(T a, T b)
	{
		LinkedNode<T, W>* pa = start;
		while (pa != NULL&& pa->node!=a)//nalazenje cvora A
		{
			pa = pa->next;
		}
		LinkedNode<T, W>* pb = start;
		while (pb!=NULL&&pb->node!=b)//nalazenje cvora B
		{
			pb = pb->next;
		}

		if (pa == NULL || pb == NULL) return false;
		Edge<T, W>* ptr = new Edge<T, W>(pb, pa->adj);
		if (ptr == NULL) return false;
		pa->adj = ptr;
		return true;
	}
	bool deleteEdge(T a, T b)
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
	T** MatricaSuseda()
	{
		LinkedNode<T, W>* ptr = start;
		int n = nodeNum + 1;
		T** mat = new T * [n];
		for (int i = 0; i < n; i++)
		{
			mat[i] = new T[n]();
		}

		int i = 1;
		while (ptr != NULL)
		{
			mat[0][i] = ptr->node;
			mat[i][0] = ptr->node;
			i++;
			ptr = ptr->next;
		}
		ptr = start;
		i = 1;
		while (ptr != NULL)//obilazi cvorove
		{
			Edge<T, W>* adj = ptr->adj;
			while (adj != NULL)//ukoliko cvor ima poteg, trazi odredisni cvor tog potega i smesta se u listu
			{
				for (int j = 1; j < n; j++)//obilazi 1. vrstu matrice i trazi cvor koji odgovara cvoru na koji pokazuje dati poteg
				{
					if (mat[0][j] == adj->dest->node)
					{
						mat[i][j] = 1;
						break;
					}
				}
				adj = adj->link;
			}
			i++;
			ptr = ptr->next;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << mat[i][j] << " ";
			cout << endl;
		}
		return mat;
	}
	long findPath(T prvi,
		T drugi, T* arPath/*=NULL*/, T* lPath/*=NULL*/)
	{

		LinkedNode<T, W>* ptr = findNode(prvi);
		LinkedNode<T, W>* pEnd=findNode(drugi);
		if (ptr->node == pEnd->node) {
			if (arPath != NULL)
				arPath[*lPath++] = ptr->node;
			return 1;
		}
		int retVal = 0;
		if (ptr->status != 1) {
			ptr->status = 1;
			Edge<T, W>* pot = ptr->adj;
			while (retVal == 0 && pot != NULL) {
				retVal = findPath(pot->dest->node, pEnd->node, arPath, lPath);
				pot = pot->link;
			}
			if (retVal != 0 && arPath != NULL)
				arPath[*lPath++] = ptr->node;
		}
		return retVal;
	}
	/*
	long breadthTrav(T a)
	{
		long retVal = 0;
		LinkedNode<T, W>* ptr = start;
		QueueAsArray < LinkedNode<T, W> que(nodeNum);
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
	*/
	long depthTrav(T a)//FALI
	{
		throw "FUNKCIJA NIJE IMPLEMENTIRANA!";
	}
	/*
	long topologicalOrderTrav()
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
	void print()
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

};

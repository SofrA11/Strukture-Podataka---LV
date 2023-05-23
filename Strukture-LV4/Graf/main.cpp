#include"GraphAsList.h";
#include"LinkedNode.h";
#include"Edge.h";
#include<iostream>
#include<exception>
using namespace std;

void main()
{
	
	try {
		/*		GraphAsList<int,double>* graf=new GraphAsList<int, double>();
		for (int i = 1; i < 5; i++)
			graf->insertNode(i);

		graf->insertEdge(1, 2);
		graf->insertEdge(1, 3);
		graf->insertEdge(1, 4);
		graf->insertEdge(2, 1);
		graf->insertEdge(3, 1);
		graf->insertEdge(4, 1);
		graf->insertEdge(4, 2);
		*/

		GraphAsList<char, double>* graf = new GraphAsList<char, double>();
		for (int i = 'A'; i <='E'; i++)
		{
			char c = i;
			graf->insertNode(c);
		}
		char a = 'A';
		char b = 'B';
		char c = 'C';
		char d = 'D';
		char e = 'E';
		graf->insertEdge(a,b);
		graf->insertEdge(a,d);
		graf->insertEdge(b,b);
		graf->insertEdge(b,d);
		graf->insertEdge(c,a);
		graf->insertEdge(c,d);
		graf->insertEdge(c,e);
		graf->insertEdge(d,e);
		LinkedNode<char,double>* L;
		graf->print();
		cout << "----------- " << endl;
		graf->findNodeMaxInDeg();
		//graf->findNodeMaxOutDeg();
		//graf->findNodeNullOutDeg();
		//graf->findNodeNullInDeg();
		//graf->MatricaSuseda();		
		//cout<< graf->findPath(a, e, NULL, NULL);
	}
	catch (exception ex)
	{
		cerr << ex.what();
	}
	catch (...)
	{

	}
}
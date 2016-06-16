#ifndef EDGE
#define EDGE
#include <iostream>
#include "Nodo.h"
using namespace std;
template<class G>
class Edge
{
public:
	typedef typename G::Nodo Nodo;
	typedef typename G::E E;
	Edge(E, Nodo*, Nodo*, bool);
	E m_peso;
	Nodo* m_nodos_place[2];
	bool m_dir; // 0 <-> ; 1 0-->1

};

template<class G>
Edge<G>::Edge(E peso, Nodo*a, Nodo*b, bool dir)
{
	m_peso = peso;
	m_dir = dir;
	m_nodos_place[0] = a;
	m_nodos_place[1] = b;
}
#endif // EDGE


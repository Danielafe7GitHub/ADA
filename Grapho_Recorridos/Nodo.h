#ifndef NODO
#define NODO

#include <iostream>
#include <vector>
#include "Edge.h"
using namespace std;

template<class G>
class Nodo
{
public:
	typedef typename G::N N;
	typedef typename G::Edge Edge;	
	Nodo(N);
	N m_dato;
	vector<Edge*>m_edges; /*Arista que llegan o salen del Nodo*/

	char m_color ;
	int m_distancia ;
	int m_distancia_i;
	int m_distancia_f;


};

template<class G>
Nodo<G>::Nodo(N dato)
{
	m_dato = dato;
	m_color = 'B';
	m_distancia = 10000;
	m_distancia_i = 0;
	m_distancia_f = 0;

}



#endif // NODO


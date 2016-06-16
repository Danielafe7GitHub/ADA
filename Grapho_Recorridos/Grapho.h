#ifndef GRAPHO
#define GRAPHO

#include "Nodo.h"
#include "Edge.h"
#include<iostream>
#include <vector>
#include <queue>          

using namespace std;

template<class N, class E>
class Grapho
{
public:
	typedef typename Grapho  <N, E> self;
	typedef typename Nodo    <self> Nodo;
	typedef typename Edge    <self> Edge;
	typedef typename N N;
	typedef typename E E;

	Grapho(){};
	vector<Nodo*> m_nodos;
	bool Insert_Nodo(N) ;
	bool Insert_Edge(Nodo*, Nodo*, E, bool) ;//De dónde, hacia a dónde,peso arista,dirección
	void recorrido_anchura(int);
	void recorrido_profundidad();
	void recorrido_profundidad_visita(Nodo*);
	void Imprimir();
	int time;
};

template<class N,class E>
bool Grapho<N, E>::Insert_Nodo(N dato)
{
	if (!m_nodos.empty())
	{
		for (int i = 0; i < m_nodos.size(); i++)
		{
			if (dato == (m_nodos[i])->m_dato)
				return 0;

		}
	}
	
	Nodo* nodo = new Nodo(dato);
	m_nodos.push_back(nodo);
	return 1;
}

template<class N,class E>
bool Grapho<N, E>::Insert_Edge(Nodo*a, Nodo*b, E e, bool dir)
{
	Edge* edge = new Edge(e, a, b, dir);
	a->m_edges.push_back(edge);
	b->m_edges.push_back(edge);
	return 1;
}


template<class N,class E>
void Grapho<N, E>::Imprimir()
{
	
	for (int i = 0; i <m_nodos.size(); i++)
	{
		cout << "Nodo " << (m_nodos[i])->m_dato << " Con Aristas de Peso:"  << endl;
		int j = 0;
		for (vector<Edge*>::iterator it = ((m_nodos[i])->m_edges).begin(); it != ((m_nodos[i])->m_edges).end(); ++it)
		{
						
			cout << "Arista [" << j << "]" << "Color: " << (*it)->m_nodos_place[1]->m_color << " Distancia: " << (*it)->m_nodos_place[1]->m_distancia << endl;
			//cout << "Nodo " << (m_nodos[i])->m_dato << " ->" << << endl;
			//cout << "Arista [" << j << "]" << "Color: " << (*it)->m_nodos_place[1]->m_color << " Distancia_Inicial: " << (*it)->m_nodos_place[1]->m_distancia_i << " Distancia_Final: " << (*it)->m_nodos_place[1]->m_distancia_f << endl;
			j++;
			
		}

	}

}

template<class N, class E>
void Grapho<N, E>::recorrido_anchura(int nodo_partida)
{
	(m_nodos[nodo_partida])->m_color = 'G';
	(m_nodos[nodo_partida])->m_distancia = 0;
	/*for (int i = 0; i < m_nodos.size(); i++)
		cout << "Color: " << (m_nodos[i])->m_color << " Distancia: " << (m_nodos[i])->m_distancia << endl;*/
		
	
	
	queue<Nodo*> queue_nodo;
	queue_nodo.push(m_nodos[nodo_partida]);
	while (!queue_nodo.empty())
	{
		Nodo* u = (queue_nodo.front());
		queue_nodo.pop();
		//cout << "Color: " << u->m_dato<<endl;
		
		for (vector<Edge*>::iterator it = ((u)->m_edges).begin(); it != ((u)->m_edges).end(); ++it)
		{
			if ((*it)->m_nodos_place[1]->m_color == 'B')
			{
				(*it)->m_nodos_place[1]->m_color = 'G';
				(*it)->m_nodos_place[1]->m_distancia = u->m_distancia + 1;
				queue_nodo.push((*it)->m_nodos_place[1]);
			}
			//cout << "Dato Adyacentes " << (*it)->m_nodos_place[1]->m_dato << endl;
			

		}
		u->m_color = 'N';
		
	}
}




template<class N, class E>
void Grapho<N, E>::recorrido_profundidad_visita(Nodo*u)
{
	time = time + 1;
	u->m_distancia_i = time;
	u->m_color = 'G';
	

	for (vector<Edge*>::iterator it = ((u)->m_edges).begin(); it != ((u)->m_edges).end(); ++it)
	{
		if ((*it)->m_nodos_place[1]->m_color == 'B')
		{
			recorrido_profundidad_visita((*it)->m_nodos_place[1]);
			
		}
		


	}
		u->m_color = 'N';
		time = time + 1;
		u->m_distancia_f = time;

	}


template<class N, class E>
void Grapho<N, E>::recorrido_profundidad()
{
	for (int i = 0; i < m_nodos.size(); i++)
	{
		(m_nodos[i])->m_color = 'W';

	}
	time = 0;
	for (int i = 0; i < m_nodos.size(); i++)
	{
		if ((m_nodos[i])->m_color == 'W')
		{
			recorrido_profundidad_visita((m_nodos[i]));
		}
		

	}

	

	

}
#endif // GRAPHO


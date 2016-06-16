#include <iostream>
#include "grapho.h"
using namespace std;

int main()
{
	Grapho<char,int> G;
	G.Insert_Nodo('A');
	G.Insert_Nodo('B');
	G.Insert_Nodo('C');
	G.Insert_Nodo('D');
	G.Insert_Edge(G.m_nodos[0], G.m_nodos[1], 2, 1);
	G.Insert_Edge(G.m_nodos[0], G.m_nodos[2], 3, 1);
	G.Insert_Edge(G.m_nodos[1], G.m_nodos[3], 4, 1);
	G.Insert_Edge(G.m_nodos[2], G.m_nodos[1], 7, 1);
	G.Insert_Edge(G.m_nodos[2], G.m_nodos[3], 1, 0);
	G.Insert_Edge(G.m_nodos[3], G.m_nodos[2], 1, 0);
	G.recorrido_anchura(0);
	//G.recorrido_profundidad();
	G.Imprimir();

	
	getchar();


	return 0;
}

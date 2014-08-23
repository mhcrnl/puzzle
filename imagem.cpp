#include "imagem.h"
using namespace std;

Node * Node::montaNo (Dado _D) {


    for(x=0;x<5;x++)
    {
        for(y=0;y<5;y++)
        {
        matriz[x][y]=num;
        num++;
        }

    }
	return P;
}

Dado* Node::desmontaNo (Node * _P) {
	Dado *D =new Dado;
 	*D=_P -> d;
	delete _P;
	return D;
}

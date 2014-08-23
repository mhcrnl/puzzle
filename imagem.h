#ifndef _IMAGEM_H_
#define _IMAGEM_H_


using namespace std;

class Imagem {
private:

public:
	Node * Next;
	Dado d;
	Imagem(int matriz[5][5]);
	~Imagem() {};


	static Node * montaNo (Dado _D);
	static Dado* desmontaNo (Node * _P);
	Dado getDado();




};
#endif

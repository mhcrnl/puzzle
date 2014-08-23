#include <iostream>
#include <algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int matriz[5][5];

bool repetido(int num,int vet[25])
{
int ind;
    for(ind=0;ind<25;ind++)
            {
                if(vet[ind]==num)
                {
                    return true;
                }

            }
return false;
}

void printcelula(int cel)
{
    cout<<"[";
                if (cel<10)
                {
                 cout<<" "<<cel;
                }
                else
                {
                 cout<<cel;
                }
    cout<<"]";
}


int preenchevet(int vet[25]){
srand (time(NULL));
    int ind,num;
    ind=0;
    while(ind<26)
    {
        num = rand() % 25 + 1;
        if(!repetido(num,vet))
        {
            vet[ind]=num;
            ind++;
            if(ind==25)
            {
                ind++;
            }
        }

    }

    return *vet;

}


void printmatriz(int m[5][5])
{
int ind1,ind2;

    for(ind1=0;ind1<5;ind1++)
    {
        for(ind2=0;ind2<5;ind2++)
        {
            if(ind2==4)
            {
              printcelula(matriz[ind1][ind2]);
              cout<<endl;

            }
            else
            {
                printcelula(matriz[ind1][ind2]);

            }

        }

    }

}

int jogo(){

cout<<"Pressione WASD para mover a peça desejada para o espaço vazio,  pressione M para abandonar o jogo."<<endl;
char comando,comando2;
int zerox,zeroy;
comando='q';
zerox=4;//indice do 0
zeroy=4;//indice do 0
printmatriz(matriz);
    while(comando != 'M'){
        cin>>comando;

        switch (comando)
            {

                case 'D':

                    if(zerox==0||zerox==4){

                        cout<<"Movimento invalido";
                        break;
                        }
                    swap(matriz[zeroy][zerox],matriz[zeroy][zerox-1]);
                    zerox=zerox-1;

                break;

                case 'A':
                        if(zerox==0||zerox==4){

                        cout<<"Movimento invalido";
                        break;
                        }

                    swap(matriz[zeroy][zerox],matriz[zeroy][zerox+1]);
                    zerox=zerox+1;

                break;

                case 'W':

                    if(zeroy==0||zeroy==4){

                        cout<<"Movimento invalido";
                        break;
                        }
                    swap(matriz[zeroy][zerox],matriz[zeroy+1][zerox]);
                    zeroy=zeroy+1;

                break;

                case 'S':

                    if(zeroy==0||zeroy==4){

                        cout<<"Movimento invalido";
                        break;
                        }
                    swap(matriz[zeroy][zerox],matriz[zeroy-1][zerox]);
                    zeroy=zeroy-1;

                break;


                case 'M':

                    cout<<"Deseja mesmo sair desse jogo magnifico? S para sim e N para nao.";
                    cin>>comando2;
                        if(comando2=='S'||comando2=='s')
                        {
                            return 0;
                        }
                        else{
                        comando='T';
                        }

                break;

            }

        printmatriz(matriz);

        }

}
int main()
{

 int num,x,y,vet[25];
cout<<"  Imagem Inteira"<<endl;
///Preencho a matriz ordenadamente
 num=1;
 for(x=0;x<5;x++)
 {
    for(y=0;y<5;y++)
    {
        matriz[x][y]=num;
        num++;
    }

 }
///////////////////////////////////////////////////////////////////////////////
printmatriz(matriz);
cout<<"  Imagem Baguncada com 0 sendo o espaco vazio"<<endl;
preenchevet(vet);//preencho o vetor aleatoriamente, com numeros de 1 a 25

///daqui ate o proximo comentario, eu pego o vet[] e insiro na matriz
///alem de colocar um 0 no matriz[4][4], para representar o vazio.
int ind=0;
int ind2,ind3;

for(ind3=0;ind3<5;ind3++)
{
    for(ind2=0;ind2<5;ind2++){

        matriz[ind2][ind3]=vet[ind];
        ind++;
    }
}


//////////////////////////////////////////////////////////////////////////////

printmatriz(matriz);

///jogo preparado, agora jogamos!

jogo();



return 0;

}



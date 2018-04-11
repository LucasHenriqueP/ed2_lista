#include "Lista.h"
#include <iostream>

using namespace std;
Lista::Lista(void)
{
    iSize=0;//ctor
}

Lista::~Lista()
{
    //dtor
}

// retorna o n�mero de objetos da lista
int Lista::getSize(void) const{
    return iSize;
}

//Retorna o objeto existente em uma determinada posi��o da lista
//Caso a posi��o seja inv�lida, retorna diferente de zero
int Lista::getData(int pos, T& elem) const
{
    if (pos < 0 || pos >= iSize)
    {
        cerr << "Posi��o inv�lida!!!" << endl;
    return 1;
    }
    elem = listData[pos];
    return 0;
}

//Altera o conteudo da lista em uma determinada posi��o
int Lista::setData(int pos, T& data)
{
    if (pos < 0 || pos >= iSize)
    {
        cerr << "Posi��o inv�lida!!!" << endl;
        return 1;
    }
    listData[pos] = data;
    return 0;
}

// Insere um objeto no final da lista
int Lista::insert(const T& item)
{
    //Caso o n�mero de posi��es m�ximo tenha sido atingindo retorna
    if (iSize >= iMaxListSize){
        cerr << "O tamanho m�ximo da lista foi atingido!" << endl;
        return 1;
    }
    // Insere um objeto no final da lista
    listData[ iSize] = item;
    // Incrementa o n�mero de objetos
    iSize++;
    return 0;
}
// Procura por um item na lista e remove a primeira ocorr�ncia
int Lista::remove(const T& item)
{
    //Inicializa vari�vel ii que ser� utilizada para percorrer a lista
    int ii(0);
    // Procura por um objeto
    while (ii < iSize && !(item == listData[ii] ))
        ii++;
    //Caso ii seja igual ou maior que iSize, ent�o n�o foi encontrado
    if (ii == iSize)
        return 1;
    //Decrementa o tamanho da lista
    iSize--;
    // move os objetos seguintes da lista para esquerda uma posi��o,
    //ou seja o objeto da posi��o ii+1 ser� colocado na posi��o ii
    while (ii < iSize)
    {
        listData[ ii] = listData[ ii+1] ;
        ii++;
    }
    return 0;
}


// Remove todos os objetos da lista
void Lista::removeAll(void){
iSize = 0;
}
// Remove o primeiro objeto da lista e retorna o valor removido
//Caso a posi��o seja inv�lida, o programa return diferente de zero
int Lista::removeFirst(T& item)
{
    // Caso a Lista esteja Vazia, finaliza o programa
    if (isEmpty())
    {
        cerr << "Erro! Lista vazia..." << endl;
        return 1;
    }
    //Recupera o primeiro objeto
    item = listData[0] ;
    //Remove o primeiro objeto
    remove(item);
    // retorna 0 - remo��o bem sucedida
    return 0;
}

// Verifica se a lista est� vazia
bool Lista::isEmpty(void) const
{
    return iSize==0;
}

//Este m�todo ir� percorrer a lista a fim de encontrar o objeto
//Caso o mesmo n�o seja encontrado retorna false
bool Lista::find(T& item) const
{
    int ii(0);
    //Caso a lista seja vazia retorna false
    if (isEmpty())
        return false;
    //Procura pelo objeto na lista
    while (ii < iSize && !(item == listData[ ii] ))
        ii++;
    //Caso ii seja igual ao tamanho da lista, indica que o item
    //nao foi encontrado
    if (ii == iSize)
        return false;
    return true;
}
//Imprime o conte�do da lista
void Lista::print()const
{
    int ii(0);
    //Caso a lista seja vazia retorna
    if (isEmpty()){
        cout << "Lista Vazia!" << endl;
        return;
    }
    cout << "[";
    while (ii < iSize)
    {
        cout << listData[ ii] <<" ";
        ii++;
    }
    cout << "]"<<endl;
}

void Lista::troca(int i, int j){
    T aux;
    aux = listData[i];
    listData[i] = listData[j];
    listData[j] = aux;
}

int Lista::binarySearch(T elem){
  return binarySearchAux(elem, 0, iSize-1);
}

int Lista::binarySearchAux(T elem, int ini, int fim){
  if(fim<ini){
    return -1;
  }

  int calc = ini + (fim-ini)/2;

  if(listData[calc] == elem)
    return calc;
  if(listData[calc] > elem){
    return binarySearchAux(elem, ini, calc-1);
  }
  else{
    return binarySearchAux(elem, calc+1, fim);
  }
}

void Lista::bubbleSort(void)
{
    int i, j, aux;
    for( i = 0; i < iSize; i++ )
    {
        for( j = i + 1; j < iSize; j++ ) // sempre 1 elemento � frente
        {
        // se o (x > (x+1)) ent�o o x passa pra frente (ordem crescente)
            if ( listData[i] > listData[j] )
            {
                aux = listData[i];
                listData[i] = listData[j];
                listData[j] = aux;
            }
        }
    } // fim da ordena��o
    return;
}

void Lista::bubbleSortOtm(void)
{
    int i, j, aux, t;
    for( i = 0; i < iSize; i++ )
    {
        t = 0;
        for( j = i + 1; j < iSize; j++ ) // sempre 1 elemento � frente
        {
        // se o (x > (x+1)) ent�o o x passa pra frente (ordem crescente)
            if ( listData[i] > listData[j] )
            {
                aux = listData[i];
                listData[i] = listData[j];
                listData[j] = aux;
                t++;
            }
        }
        if(t==0)
            return;
    } // fim da ordena��o
    return;
}

void Lista::shakerSort(void){

	int i, j, k;
	for(i = 0; i < iSize-1;)
	{

		for(j = i+1; j < iSize-1; j++)
		{
			if(listData[j] < listData[j-1])
				troca(j, j-1);
		}
		
	
 

		for(k = iSize-2; k > i; k--)
		{
			if(listData[k] < listData[k-1])
				troca(k, k-1);
		}
		
		i++;
	}
}

void Lista::selectionSort(void){
  int i, j, maior, aux;
  for(i = iSize-1; i>=1; i--){
    maior = 0;
    for(j = 0; j<= i; j++){
      if(listData[j] > listData[maior]){
        maior = j;
      }
    }
    aux = listData[maior];
    listData[maior] = listData[i];
    listData[i] = aux;
  }
  return;
}

void Lista::shellSort(void){
  int i, j, elem, q, ju;
  int k [7] = {1, 2, 3, 5, 7, 11, 13};
  for(i = 0; i <7; i++){
    if (k[i] >= iSize){
      q = i - 1;
    }
  }
  while(q >= 0){
    ju = k[q];
    for(i=ju; i< iSize-1; i++){
      elem = listData[i];
      j = i - ju;
      while(elem < listData[j] && j>=0){
          listData[j+ju] = listData[j];
          j = j - ju;
        }
        listData[j+ju] = elem;
    }
    q--;
  }

}


void Lista::insertionSort(void){
  int i, j, elem;
  for(i = 1; i < iSize-1; i++){
    elem = listData[i];
    j = i-1;
    while(elem < listData[j] && j>=0){
      listData[j+1] = listData[j];
      j--;
    }
    listData[j+1] = elem;
  }
}

void Lista::insertionSortBin(void){
    int i, j, elem, pos;

    for(i = 1; i < iSize-1; i++){
    elem = listData[i];
    j = i-1;
    pos = binarySearchAux(elem, 0, j);
    while(j >= pos){
      listData[j+1] = listData[j];
      j--;
    }
    listData[j+1] = elem;
  }
}

void Lista::mergeSort(void){

}

 int main(int argc, char const *argv[]) {
   Lista l1;
   l1.insert(10);
   l1.insert(3);
   l1.insert(-50);
   l1.insert(1);
   l1.insert(66);
   l1.insert(5);
   l1.insert(653);

   l1.print();
   //l1.selectionSort();
   //l1.insertionSort();
   //l1.shellSort();
   //l1.insertionSortBin();
   l1.shakerSort();
   l1.print();
   int a = l1.binarySearch(100);
   std::cout << a << '\n';
  return 0;
}

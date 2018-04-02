#ifndef LISTA_H
#define LISTA_H

# include <iostream>
# define iMaxListSize 32

typedef int T;


class Lista
{
    public:
        Lista(void);
        virtual ~Lista();
        // Metodos Acessores
        //Recupera o n�mero de objetos da lista
        int getSize(void) const;
        //Recupera a informa��o contida em uma determinada posi��o
        T getData(int, T&) const;

        //M�todos Modificadores
        //Altera o conteudo da lista em uma determinada posi��o
        int setData(int, T&);
        //Insere um objeto no final da lista
        int insert(const T&);
        //Remove a primeira ocorr�ncia de um objeto da lista
        int remove(const T&);
        //Remove o primeiro objeto da lista
        int removeFirst(T&);
        //Remove todos os objetos da lista
        void removeAll(void);
        //Outros m�todos
        //Retorna um valor booleano caso a lista n�o seja vazia
        bool isEmpty(void) const;
        //Encontra a primeira ocorr�ncia de um objeto da lista
        bool find(T&) const ;
        // imprime o conteudo da lista
        void print() const;

        //ordenacao pelo m�todo bubbleSort
        void bubbleSort();
        // ordenacao pelo metodo selectionSort
        void selectionSort();
        // Ordenacao pelo metodo InsertionSort
        void insertionSort();
        // Ordenacao pelo metodo shellSort
        void shellSort();

    protected:

    private:
        //Vetor que ir� conter os objetos da lista
        int listData[ iMaxListSize];
        //N�mero de objetos da lista
        int iSize;

};

#endif // LISTA_H

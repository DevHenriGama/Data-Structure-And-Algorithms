#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no *prox;
};

int count = 1; // Inicia no 1 pq está sendo inciado no main

struct no Inicio = {0, NULL};

void Adicionar(int valor)
{
    struct no *Novo = malloc(sizeof(struct no));
    Novo->valor = valor;
    Novo->prox = NULL;

    if (Inicio.prox == NULL)
    {
        Inicio.prox = Novo;
    }
    else
    {
        // O Iterador Serve para navegar entre a lista
        struct no *Iterador;
        Iterador = Inicio.prox;

        while (Iterador->prox != NULL)
        {
            Iterador = Iterador->prox;
        }

        Iterador->prox = Novo;
    }

    count++;
    printf("Adicionado \n");
}

void ImprimirLista(struct no *ptr)
{
    while (ptr != NULL)
    {
        printf("%d \n", ptr->valor);
        ptr = ptr->prox;
    }
}

void ImprimirCount()
{
    printf("Quant. itens na lista -> %d \n", count);
}

int RemoverUltimo(struct no *LInicio)
{
    if (LInicio->prox == NULL)
    {
        printf("A lista está vazia.");
        return -1;
    }

    struct no *Anterior = LInicio;
    struct no *Atual = LInicio->prox;

    if (Atual->prox == NULL)
    {
        int elemento = Atual->valor;
        free(Atual);
        LInicio->prox = NULL;
        count --;
        return elemento;
    }

    while (Atual->prox != NULL)
    {
        Anterior = Atual;
        Atual = Atual->prox;
    }

    int elemento = Atual->valor;
    free(Atual);
    Anterior->prox = NULL;
    count --;

    return elemento;
    
}

int main()
{
    Inicio.valor = 15;
    ImprimirCount();
    ImprimirLista(&Inicio);

    Adicionar(10);
    ImprimirCount();
    ImprimirLista(&Inicio);

    Adicionar(40);
    ImprimirCount();
    ImprimirLista(&Inicio);

    printf("O ultimo elemento e %d , e foi removido \n", RemoverUltimo(&Inicio));
    ImprimirCount();
    ImprimirLista(&Inicio);

    return 0;
}

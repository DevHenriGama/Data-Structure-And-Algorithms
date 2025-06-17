#include <stdio.h>
#include <stdlib.h>

// Cria a estrutura
struct Leaf {
  int value;
  struct Leaf *Left;
  struct Leaf *Right;
};

// Função que retorna uma nova Leaf
struct Leaf *createLeaf(int Value) {

  struct Leaf *Temp = (struct Leaf *)malloc(sizeof(struct Leaf));
  Temp->value = Value;
  Temp->Right = Temp->Left = NULL;

  return Temp;
}

struct Leaf *InsertLeaf(struct Leaf *Root, int value) {

  // Cria a Leaf que será inserida na Arvore
  struct Leaf *Temp = createLeaf(value);

  if (Root == NULL) {
    return Temp;
  }

//Cria as variaveis parent e curr para buscar a leaf onde sera 
//inseria. A curr e usada como index de navegação.
  struct Leaf *parent = NULL, *curr = Root;

  while (curr != NULL) {
    //Passa curr para parent para que quando
    //encontrar a leaf que será inserida a nova leaf
    //guarde a referencia para ser usada posteriormente.
    parent = curr;

    //A logica está apontando para o Nó já inserido
    if (curr->value > value) {
      curr = curr->Left;
    } else if (curr->value < value) {
      curr = curr->Right;
    } else {
      return Root;
    }
  }

//Aqui faz a inserção
  if (parent->value > value) {
    parent->Left = Temp;
  } else {
    parent->Right = Temp;
  }

  return Root;
}

void inorder(struct Leaf *Root) {
    //Usa recursividade para listar a árvore
  if (Root != NULL) {
    inorder(Root->Left);
    printf("%d - > ", Root->value);
    inorder(Root->Right);
  }
}

int main() {
  //Cria e inicializa a árvore
  struct Leaf *root = createLeaf(20);
  root = InsertLeaf(root, 15);
  root = InsertLeaf(root, 2);
  root = InsertLeaf(root, 500);
  root = InsertLeaf(root, 150);

  inorder(root);

  return 0;
}

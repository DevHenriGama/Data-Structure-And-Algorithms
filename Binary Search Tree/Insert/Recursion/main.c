#include <stdio.h>
#include <stdlib.h>

typedef struct TreeLeaf {
  int Value;
  Leaf *Left;
  Leaf *Right;
} Leaf;

Leaf *createLeaf(int value) {
  Leaf *Temp = (Leaf *)malloc(sizeof(Leaf));
  Temp->Value = value;
  Temp->Left = Temp->Right = NULL;
  return Temp;
}

Leaf * InsertLeaf(Leaf* Tree, int value){
    
}

int main() { return 0; }
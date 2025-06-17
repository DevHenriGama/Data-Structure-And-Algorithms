#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* Left;
    struct Node* Right;
};

struct Node* createNode(int Value)
{

    struct Node* Temp = (struct Node*)malloc(sizeof(struct Node));
    Temp->value = Value;
    Temp->Right = Temp->Left = NULL;

    return Temp;
}

struct Node* InsertNode(struct Node* Root, int value)
{

    struct Node* Temp = createNode(value);
    if (Root == NULL)
    {
        return Temp;
    }

    struct Node* parent = NULL, * curr = Root;

    while (curr != NULL)
    {
        parent = curr;
        if (curr->value > value)
        {
            curr = curr->Left;
        }
        else if (curr->value < value)
        {
            curr = curr->Right;
        }
        else
        {
            return Root;
        }
    }

    if (parent->value > value)
    {
        parent->Left = Temp;
    }
    else
    {
        parent->Right = Temp;
    }

    return Root;
}

void inorder(struct Node* Root)
{
    if (Root != NULL)
    {
        inorder(Root->Left);
        printf("%d - > ", Root->value);
        inorder(Root->Right);
    }
}

int main()
{
    struct Node* root = createNode(20);
    root = InsertNode(root, 15);
    root = InsertNode(root, 2);
    root = InsertNode(root, 500);
    root = InsertNode(root, 150);

    inorder(root);


    return 0;
}

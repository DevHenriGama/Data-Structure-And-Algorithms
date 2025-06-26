#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

void addEdge(struct Node *adj[], int i, int j) {
  struct Node *newNode = createNode(j);
  newNode->next = adj[i];
  adj[i] = newNode;

  newNode = createNode(i);
  newNode->next = adj[j];
  adj[j] = newNode;
}

void displayAdjList(struct Node *adj[], int V) {

  for (int i = 0; i < V; i++) {
    printf("%d: ", i);
    struct Node *temp = adj[i];

    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  int v = 4;
  struct Node *adj[v];

  for (int i = 0; i < v; i++) {
    adj[i] = NULL;
  }

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);

  printf("Adjacency List Representation:\n");
  displayAdjList(adj, v);

  return 0;
}

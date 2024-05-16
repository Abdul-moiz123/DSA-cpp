#include <iostream>
using namespace std;

// STACK FOR DFS
struct Record {
  int data;
  Record* next;
};

void insert(Record*& top, int data) {
  Record* ptr = new Record();
  ptr->data = data;
  ptr->next = top;
  top = ptr;
}

int pop(Record*& top) {
  if (top == nullptr) {
    cout << "The stack is empty" << endl;
    return -1;
  }
  Record* temp = top;
  int data = temp->data;
  top = temp->next;
  delete temp;
  return data;
}

// QUEUE FOR BFS
struct node {
  int data;
  node* next;
};

void enqueue(node*& rear, node*& front, int data) {
  node* new_node = new node();
  new_node->data = data;
  new_node->next = NULL;

  if (rear == NULL && front == NULL) {
    rear = new_node;
    front = new_node;
  } else {
    rear->next = new_node;
    rear = new_node;
  }
}

int dequeue(node*& rear, node*& front) {
  if (front == NULL) {
    cout << "Queue is empty." << endl;
    return -1;
  }

  node* current = front;
  int data = current->data;
  front = current->next;
  if (front == NULL) {
    rear = NULL;
  }
  delete current;
  return data;
}

// INSERT VERTEX AND EDGES
struct edge {
  int data;
  edge* next;
};

struct vertex {
  int data;
  vertex* next;
  edge* edgeList;
  bool visited;
  int parent; // For keeping track of parent vertex
};

void insertVertex(vertex*& head_refer, int data){
  vertex* new_node = new vertex();
  new_node->data = data;
  new_node->next = NULL;
  new_node->edgeList = NULL;
  new_node->visited = false;
  new_node->parent = -1; // Initialize parent to -1
  if (head_refer == NULL) {
    head_refer = new_node;
  } else {
    vertex* current = head_refer;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

void insertEdge(vertex*& head_refer, int vertexData, int data) {
  edge* new_node = new edge();
  new_node->data = data;
  new_node->next = NULL;
  vertex* current = head_refer;
  while (current != NULL) {
    if (current->data == vertexData) {
      if (current->edgeList == NULL) {
        current->edgeList = new_node;
      } else {
        edge* temp = current->edgeList;
        while (temp->next != NULL) {
          temp = temp->next;
        }
        temp->next = new_node;
      }
      return;
    } else {
      current = current->next;
    }
  }
}

// BFS FOR GRAPH TRAVERSAL
void BFS(vertex*& start, node*& rear, node*& front) {
  if (start == nullptr) return;
  start->visited = true;
  enqueue(rear, front, start->data);
  while (rear != NULL && front != NULL) {
    int currentVertexData = dequeue(rear, front);
    vertex* currentVertex = start;
    while (currentVertex != nullptr && currentVertex->data != currentVertexData) {
      currentVertex = currentVertex->next;
    }
    edge* currentEdge = currentVertex->edgeList;
    while (currentEdge != nullptr) {
      vertex* adjacentVertex = start;
      while (adjacentVertex != nullptr && adjacentVertex->data != currentEdge->data) {
        adjacentVertex = adjacentVertex->next;
      }
      if (adjacentVertex != nullptr && !adjacentVertex->visited) {
        adjacentVertex->visited = true;
        adjacentVertex->parent = currentVertexData; // Set parent field
        enqueue(rear, front, adjacentVertex->data);
      }
      currentEdge = currentEdge->next;
    }
  }
}

// Function to get the path from start vertex to end vertex
void getPath(vertex* start, vertex* end, int path[], int& pathLength) {
    int currentVertex = end->data;
    while (currentVertex != -1) {
        path[pathLength++] = currentVertex;
        vertex* current = start;
        while (current != nullptr && current->data != currentVertex) {
            current = current ->next;
        }
        currentVertex = current->parent;
    }
}

// MAIN FUNCTION
int main() {
    Record* top = NULL;
    vertex* head = NULL;
    node* rear = nullptr;
    node* front = nullptr;

    // Adding vertices
    insertVertex(head, 0);
    insertVertex(head, 1);
    insertVertex(head, 2);
    insertVertex(head, 3);
    insertVertex(head, 4);

    // Adding edges
    insertEdge(head, 0, 1);
    insertEdge(head, 0, 2);
    insertEdge(head, 1, 2);
    insertEdge(head, 2, 0);
    insertEdge(head, 2, 3);
    insertEdge(head, 3, 3);
    insertEdge(head, 3, 4);

    cout << "BFS Traversal: ";
    BFS(head , rear , front);
    cout << endl;

    // Find the path from vertex 0 to vertex 4
    int path[100];
    int pathLength = 0;
    vertex* start = head;
    vertex* end = head;
    while (start != nullptr && start->data != 0) {
        start = start->next;
    }
    while (end != nullptr && end->data != 4) {
        end = end->next;
    }
    getPath(head, end, path, pathLength);
    
    // Output the path
    cout << "Path from 0 to 4: ";
    for (int i = pathLength - 1; i >= 0; --i) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}

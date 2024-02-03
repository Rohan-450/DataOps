#include <iostream>
using namespace std;

int min(int a, int b) { return a > b ? b : a; }
int max(int a, int b) { return a > b ? a : b; }

class Node {
public:
  int data;
  Node *lptr;
  Node *rptr;

  Node() {
    data = 0;
    lptr = NULL;
    rptr = NULL;
  }

  Node(int data) {
    this->data = data;
    lptr = NULL;
    rptr = NULL;
  }
};

void _treverseInOrder(Node *root) {
  if (!root)
    return;

  _treverseInOrder(root->lptr);
  cout << root->data << " ";
  _treverseInOrder(root->rptr);
}

void _treversePreOrder(Node *root) {
  if (!root)
    return;

  cout << root->data << " ";
  _treversePreOrder(root->lptr);
  _treversePreOrder(root->rptr);
}

void _treversePostOrder(Node *root) {
  if (!root)
    return;

  _treversePreOrder(root->lptr);
  _treversePreOrder(root->rptr);
  cout << root->data << " ";
}

Node *removeNode(Node *root, int data) {
  if (root == NULL) {
    return root;
  }

  if (data > root->data) {
    root->rptr = removeNode(root->rptr, data);
    return root;
  }

  if (data < root->data) {
    root->lptr = removeNode(root->lptr, data);
    return root;
  }

  Node *temp = root;

  if (root->rptr == NULL) {
    temp = root->lptr;
    free(root);
    return temp;
  }

  if (root->lptr == NULL) {
    temp = root->rptr;
    free(root);
    return temp;
  }

  Node *succ = root->rptr;
  while (succ->lptr)
    succ = succ->lptr;
  succ->lptr = root->lptr;

  temp = root->rptr;
  free(root);
  return temp;
}

int _height(Node *root) {
  if (root == NULL)
    return 0;
  return 1 + max(_height(root->lptr), _height(root->rptr));
}

int _totalNodes(Node *root) {
  if (root == NULL)
    return 0;
  return 1 + _totalNodes(root->lptr) + _totalNodes(root->rptr);
}

int _totalExternal(Node *root){
  if(root == NULL) return 0;
  if(root->lptr || root->rptr)
    return _totalExternal(root->lptr) + _totalExternal(root->rptr);
  return 1;
}

class BST {
  Node *root;

public:
  BST() { root = NULL; }

  void insert(int data) {
    Node *nn = new Node(data);
    if (root == NULL) {
      root = nn;
      return;
    }
    Node *temp = root;
    while (true) {
      if (temp->data == data)
        return;

      if (data < temp->data) {
        if (temp->lptr == NULL) {
          temp->lptr = nn;
          return;
        }
        temp = temp->lptr;
        continue;
      }
      if (temp->rptr == NULL) {
        temp->rptr = nn;
        return;
      }
      temp = temp->rptr;
    }
  }

  int height() { return _height(root); }
  int totalNodes() { return _totalNodes(root); }
  int totalExternal(){return _totalExternal(root);}

  void remove(int data) { removeNode(root, data); }
  void displayInOrder() {
    _treverseInOrder(root);
    cout << endl;
  }
  void displayPreOrder() {
    _treversePreOrder(root);
    cout << endl;
  }
  void displayPostOrder() {
    _treversePostOrder(root);
    cout << endl;
  }
};

int main() {
  BST bst;
  int c, d;

  do {
    cout << "1. Display In Order" << endl
         << "2. Display Pre Order" << endl
         << "3. Display Post Order" << endl
         << "4. Insert" << endl
         << "5. Remove" << endl
         << "6. Height" << endl
         << "7. Total Nodes" << endl
         << "8. Total External" << endl
         << "0. Exit" << endl
         << "Enter your choice:: ";
    cin >> c;

    switch (c) {
    case 1:
      bst.displayInOrder();
      break;
    case 2:
      bst.displayPreOrder();
      break;
    case 3:
      bst.displayPostOrder();
      break;
    case 4:
      cout << "Enter your value:: ";
      cin >> d;
      bst.insert(d);
      break;
    case 5:
      cout << "Enter your value:: ";
      cin >> d;
      bst.remove(d);
      break;
    case 6:
      cout << "Height is " << bst.height() << endl;
      break;
    case 7:
      cout << "Total Nodes :: " << bst.totalNodes() << endl;
      break;
    case 8:
      cout << "Total External Nodes :: " << bst.totalExternal() << endl;
      break;
    case 0:
      break;
    default:
      cout << "Invalid choice" << endl;
    }

  } while (c != 0);

  return 0;
}

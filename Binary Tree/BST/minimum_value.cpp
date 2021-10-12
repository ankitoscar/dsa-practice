// Program to find minimum element of bst
#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
      data = x;
      left = right = NULL;
    }
};

void inorder(Node* node){
  if(node == NULL)
    return;

  inorder(node->left);
  cout<<node->data<<' ';
  inorder(node->right);
}

bool search(Node* node, int value){
  if(node == NULL)
    return false;

  if(node->data == value)
    return true;

  if(value < node->data)
    return search(node->left, value);

  if(value > node->data)
    return search(node->right, value);

  return false;
}

Node* insert(Node* node, int value){
  if(node == NULL){
    node = new Node(value);
    return node;
  }

  if(search(node, value))
    return node;

  if(value < node->data)
    node->left =  insert(node->left, value);

  else
    node->right =  insert(node->right, value);

  return node;
}
/*
The idea is to find the leftmost element of the BST,
which can be done by going to the leftmost node by
inorder traversal.
*/
int minimum(Node* node){
  if(node == NULL)
    return -1;

  if(node-> left == NULL && node->right == NULL)
    return node->data;

  return minimum(node->left);
}

int maximum(Node* node){
  if(node == NULL)
    return -1;

  if(node->left == NULL && node->right == NULL)
    return node->data;

  return maximum(node->right);
}

int main(){
  Node* root = NULL;

  int x, y;
  while(x != 0){
    cin>>x;
    root = insert(root,x);
    inorder(root);
    cout<<'\n';
  }
  cin>>y;
  if(search(root, y))
    cout<<"YES\n";
  else
    cout<<"NO\n";
  cout<<minimum(root)<<'\n'<<maximum(root);
  return 0;
}

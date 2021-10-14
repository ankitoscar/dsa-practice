// Program to delete node from binary search tree
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

bool search(Node* node, int value){
  if(node == NULL)
    return false;

  if(node->data == value)
    return true;

  if(value < node->data)
    return search(node->left, value);
  else
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
    node->left = insert(node->left, value);
  else
    node->right = insert(node->right, value);

  return node;
}

Node* minValueNode(Node* node){
  if(node == NULL)
    return node;

  Node* curr = node;
  while(curr != NULL && curr->left != NULL)
    curr = curr->left;

  return curr;
}

Node* deleteNode(Node* node, int value){
  if(node == NULL)
    return node;

  if(value < node->data)
    node->left = deleteNode(node->left, value);
  else if(value > node->data)
    node->right = deleteNode(node->right, value);

  else{
    if(node->left == NULL && node->right == NULL)
      return NULL;
    else if(node->left == NULL){
      Node* temp = node->right;
      free(node);
      return temp;
    }
    else if(node->right == NULL){
      Node* temp = node->left;
      free(node);
      return temp;
    }

  Node* temp = minValueNode(node->right);
  node->data = temp->data;
  node->right = deleteNode(node->right, temp->data);
  }
  return node;
}

void inorder(Node* node){
  if(node == NULL)
    return;

  inorder(node->left);
  cout<<node->data<<' ';
  inorder(node->right);
}

int main(){
  Node* root = NULL;

  int x, y;
  while(x != 0){
    cin>>x;
    if(x == 0)
      break;
    root = insert(root,x);
    inorder(root);
    cout<<'\n';
  }
  cin>>y;
  if(search(root, y))
    cout<<"YES\n";
  else
    cout<<"NO\n";
  int z;
  cin>>z;
  root = deleteNode(root, z);
  inorder(root);
  return 0;
}

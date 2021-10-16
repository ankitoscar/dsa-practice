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

bool search(Node* root, int value){
  if(root == NULL)
    return false;

  if(root->data == value)
    return true;

  if(value < root->data)
    return search(root->left, value);

  if(value > root->data)
    return search(root->right, value);

  return false;
}

Node* insert(Node* root, int value){
  if(root == NULL){
    root = new Node(value);
    return root;
  }

  if(search(root, value))
    return root;

  if(value < root->data)
    root->left = insert(root->left, value);

  if(value > root->data)
    root->right = insert(root->right, value);

  return root;
}

int floor(Node* root, int key){
  if(root == NULL)
    return INT_MAX;

  if(root->data == key)
    return root->data;

  if(root->data > key)
    return floor(root->left, key);

  int f = floor(root->right, key);

  return (f <= key)? f : root->data;
}

int ceil(Node* root, int key){
  if(root == NULL)
    return -1;

  if(root->data == key)
    return root->data;

  if(root->data < key)
    return ceil(root->right, key);

  int c = ceil(root->left, key);

  return (c >= key)? c : root->data;
}

void inorder(Node* root){
  if(root == NULL)
    return;

  inorder(root->left);
  cout<<root->data<<' ';
  inorder(root->right);
}

int main(){
  Node* root = NULL;

  int x, y;
  while(x != 0){
    cin>>x;
    if(x == 0)
      break;
    root = insert(root, x);
    inorder(root);
    cout<<'\n';
  }

  int p;
  cin>>p;
  while(p--){
    cout<<'('<<p<<','<<floor(root, p)<<','<<ceil(root, p)<<")\n";
  }
  return 0;
}

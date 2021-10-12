#include<bits/stdc++.h>
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

bool check_bst(Node* root, Node* l = NULL, Node* r = NULL){
  if(root == NULL)
    return true;

  if(l != NULL && root->data <= l->data)
    return false;

  if(r != NULL && root->data >= r->data)
    return false;

  return check_bst(root->left, l, root) && check_bst(root->right, root, r);
}

void inorder(Node* root){
  if(root == NULL)
    return;

  inorder(root->left);
  cout<<root->data<<' ';
  inorder(root->right);
}

int main(){
  Node* root = new Node(8);
  root->left = new Node(6);
  root->right = new Node(9);
  root->left->left = new Node(5);
  root->left->right = new Node(7);

  inorder(root);
  cout<<'\n';

  if(check_bst(root))
    cout<<"True\n";
  else
    cout<<"False\n";

  return 0;
}

/*
Program to insert in a binary tree
*/

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

/*
To insert a node, we will do BFS of the tree and insert
data into to leftmost empty spot in the tree and insert
the node there.
*/
void insertNode(Node* node, int value){
  if(node == NULL)
    return;
  if(node->left == NULL && node->right == NULL){
    node->left->data = value;
    return;
  }
  queue<Node* > q;
  q.push(node);
  while(!q.empty()){
    Node* curr = q.front();
    q.pop();
    if(curr->left == NULL){
      curr->left = new Node(value);
      return;
    }
    else
      q.push(curr->left);
    if(curr->right == NULL){
      curr->right = new Node(value);
      return;
    }
    else
      q.push(curr->right);
  }
}

void inorder(Node* node){
  if(node == NULL)
    return;

  inorder(node->left);
  cout<<node->data<<' ';
  inorder(node->right);
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->right->left = new Node(6);

  inorder(root);
  cout<<'\n';
  insertNode(root, 8);
  inorder(root);
  cout<<'\n';

  return 0;
}

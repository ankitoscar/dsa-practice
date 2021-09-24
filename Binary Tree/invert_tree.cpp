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

void inorder(Node* node){
  if(node == NULL)
    return;

  inorder(node->left);
  cout<<node->data<<' ';
  inorder(node->right);
}

void inverttree(Node* node){
  if(node == NULL)
    return;

  queue<Node* > q;
  q.push(node);
  while(!q.empty()){
    Node* curr = q.front();
    q.pop();

    swap(curr->left, curr->right);

    if(curr->left != NULL)
      q.push(curr->left);
    if(curr->right != NULL)
      q.push(curr->right);
  }
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  inorder(root);
  cout<<'\n';
  inverttree(root);
  inorder(root);
  cout<<'\n';

  return 0;
}

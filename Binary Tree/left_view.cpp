/*
Program to print left view of a binary tree
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
The idea is to do BFS of tree and loop three each level
and print the first node.
*/
void leftView(Node* root){
  if(root == NULL)
    return;

  queue<Node* > q;
  q.push(root);

  while(!q.empty()){
    int n = q.size();

    for(int i=1; i<=n; i++){
      Node* temp = q.front();
      q.pop();

      if(i == 1)
        cout<<temp->data<<' ';

      if(temp->left)
        q.push(temp->left);

      if(temp->right)
        q.push(temp->right);
    }
  }
}

int main(){
  Node* root = new Node(10);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(7);
  root->left->right = new Node(8);
  root->right->right = new Node(15);
  root->right->left = new Node(12);
  root->right->right->left = new Node(14);

  leftView(root);
  return 0;
}

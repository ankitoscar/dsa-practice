// Program to show right view of a binary tree
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
In order to print the right view, we will do BFS of the tree,
then we will store the number of nodes at each level and
iterate from 1 to n, if i == n, then that node will be printed.
*/

void rightView(Node* root){
  if(root == NULL)
    return;

  queue<Node* > q;
  q.push(root);

  while(!q.empty()){
    int n = q.size();

    for(int i=1; i<=n; i++){
      Node* temp = q.front();
      q.pop();

      if(i == n)
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

  rightView(root);
  return 0;
}

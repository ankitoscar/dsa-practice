// Program to perform iterative inorder traversal
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
To perfrom iterative inorder traversal, we can use a stack to insert
the left nodes and push them till the left node becomes null. Take the
top of stack and print its data and then push it's right child.
*/
void inorder(Node* root){
  stack<Node* > s;
  Node* curr = root;

  while(curr != NULL || s.empty() == false){
    while(curr != NULL){
      s.push(curr);
      curr = curr->left;
    }

    curr = s.top();
    s.pop();

    cout<<curr->data<<' ';
    curr = curr->right;
  }
}

int main(){
  Node* root = new Node(11);
  root->left = new Node(12);
  root->right = new Node(9);
  root->left->left = new Node(7);
  root->left->right = new Node(8);

  inorder(root);
  return 0;
}

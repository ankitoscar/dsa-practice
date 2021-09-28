// Program to print ancestors of a node in a binary tree
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
The idea here is to recursive find the node with the target
data and print all its ancestors after target is found
*/

bool printAncestors(Node* node, int target){
  if(node == NULL)
    return false;
  if(node->data == target)
    return true;
  if(printAncestors(node->left, target) || printAncestors(node->right, target)){
    cout<<node->data<<' ';
    return true;
  }
  return false;
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  printAncestors(root, 5);
  return 0;
}

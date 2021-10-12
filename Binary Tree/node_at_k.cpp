// Program to find nodes at k distance from a node
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
The idea here is to recursive do DFS inorder and
decrease the distance by one till it becomes zero.
Then print that particular node.
*/

void kdistancenodes(Node* node, int k){
  if(node == NULL || k < 0)
    return;
  if(k == 0){
    cout<<node->data<<' ';
    return;
  }
  kdistancenodes(node->left, k-1);
  kdistancenodes(node->right, k-1);
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  kdistancenodes(root, 2);
  return 0;
}

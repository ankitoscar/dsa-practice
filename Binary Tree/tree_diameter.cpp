// Program to find diameter of a binary tree
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
The idea here is to recursively find the height and depth
of the left and right subtree, and then take the maximum
of the sums of heights and depths as the diameter.
*/
int diameter(Node* node, int* height){

  int lh = 0, rh = 0;
  int ld = 0, rd = 0;

  if(node == NULL){
    *height = 0;
    return 0;
  }

  ld = diameter(node->left, &lh);
  rd = diameter(node->right, &rh);

  *height = max(lh, rh) + 1;

  return max(lh + rh + 1, max(ld, rd));
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->left->left = new Node(6);

  int height = 0;

  cout<<diameter(root, &height)<<' '<<height<<'\n';
  return 0;
}

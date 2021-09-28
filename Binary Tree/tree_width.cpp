// Program to find width of a binary tree
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
The idea here is to store the maximum number of nodes in
a level of tree while doing BFS.
*/
int getWidth(Node* node){
  if(node == NULL)
    return 0;

  int result = 0;
  queue<Node *> q;
  q.push(node);
  while(!q.empty()){
    int count = q.size();

    result = max(count, result);

    while(count--){
      Node* temp = q.front();
      q.pop();

      if(temp->left != NULL)
        q.push(temp->left);
      if(temp->right != NULL)
        q.push(temp->right);
    }
  }
  return result;
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  cout<<getWidth(root)<<'\n';
  return 0;
}

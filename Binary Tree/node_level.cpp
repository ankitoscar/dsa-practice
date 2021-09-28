// Program to print level of each node
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
The idea is to do BFS of the tree in a queue storing a pair ouf
node and its level and display each node.
*/

void levels(Node* root){
  if(root == NULL)
    return;

  queue<pair<Node*, int >> q;
  q.push({root, 0});
  while(!q.empty()){
    auto temp = q.front();
    q.pop();

    cout<<temp.first->data<<"->"<<temp.second<<'\n';

    if(temp.first->left != NULL)
      q.push({temp.first->left, temp.second + 1});
    if(temp.first->right != NULL)
      q.push({temp.first->right, temp.second + 1});

  }

  return;
}

int main(){
  Node* root = new Node(0);
  root->left = new Node(2);
  root->left->left = new Node(5);
  root->left->right = new Node(6);
  root->right = new Node(1);
  root->right->left = new Node(3);
  root->right->right = new Node(4);

  levels(root);
  return 0;
}

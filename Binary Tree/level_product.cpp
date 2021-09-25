/*
Program to print product of sums of nodes at a level
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
The idea is to store the sum of each level by doing BFS in
an array, indexed by their level. Then their product will be calculated
and returned.
*/
int levelProduct(Node* root){
  int arr[1000] = {0};
  queue<pair<Node*, int>> q;
  q.push(make_pair(root, 0));

  while(q.empty() != true){
    auto s = q.front();
    q.pop();

    if(s.first->left)
      q.push(make_pair(s.first->left, s.second+1));
    if(s.first->right)
      q.push(make_pair(s.first->right, s.second+1));

    if(s.first->left == NULL && s.first->right == NULL)
      arr[s.second] += s.first->data;
  }

  int p = 1;
  for(int i=0; i<1000; i++){
    if(arr[i] != 0)
      p *= arr[i];
  }

  return p;
}

void printInorder(Node* root){
  if(root == NULL)
    return;

  printInorder(root->left);
  cout<<root->data<<' ';
  printInorder(root->right);
}

int main(){
  Node* root = new Node(2);
  root->left = new Node(7);
  root->right = new Node(5);
  root->left->right = new Node(6);
  root->left->left = new Node(8);
  root->left->right->left = new Node(1);
  root->left->right->right = new Node(11);
  root->right->right = new Node(9);
  root->right->right->left = new Node(4);
  root->right->right->right = new Node(10);

  printInorder(root);
  cout<<"\nProduct of sum of leaves at every level :\n"<<levelProduct(root);
  return 0;
}

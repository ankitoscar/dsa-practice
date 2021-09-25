/*
Program to print average of each level
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

void levelOrder(Node* root){
  if(root == NULL)
    return;

  queue<Node *> q;
  q.push(root);

  while(q.empty() == false){
    Node* temp = q.front();
    q.pop();

    cout<<temp->data<<' ';
    if(temp->left)
      q.push(temp->left);
    if(temp->right)
      q.push(temp->right);
  }
}

/*
The idea is to do BFS of the tree and create a map which will store
the level number pointing to its sum, and the number of elements in that
level. After sum of every level is stored, average of each level is displayed.
*/
void levelAverage(Node* root){
  queue<pair<Node *, int>> q;
  map<int, pair<int, int>> m;

  q.push(make_pair(root, 1));

  while(q.empty() == false){
    pair<Node* , int> temp = q.front();
    q.pop();

    if(m.find(temp.second)==m.end())
      m[temp.second] = make_pair((temp.first)->data, 1);
    else{
      m[temp.second].first += (temp.first)->data;
      m[temp.second].second++;
    }

    if((temp.first)->left)
      q.push(make_pair((temp.first)->left, temp.second + 1));
    if((temp.first)->right)
      q.push(make_pair((temp.first)->right, temp.second + 1));
  }

  for(auto itr=m.begin(); itr!=m.end(); itr++){
    cout<<(float)(*itr).second.first/(float)(*itr).second.second<<' ';
  }
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->left->left = new Node(6);

  levelOrder(root);
  cout<<'\n';
  levelAverage(root);
  return 0;
}

#include<iostream>
using namespace std;

class DLL{
  public:
    int data;
    DLL* left;
    DLL* right;

    DLL(int x){
      data = x;
      left = right = NULL;
    }
};

int size(DLL* head, DLL* end){
  if(head == NULL)
    return 0;

  DLL* temp = head;
  int s = 0;
  while(temp != end){
    temp = temp->right;
    s++;
  }

  return s;
}

DLL* middle(DLL* head, int size){
  if(head == NULL || size <= 0)
    return NULL;

  DLL* temp = head;
  int mid = size/2;
  while(mid--)
    temp = temp->right;

  return temp;
}

DLL* toBST(DLL* head, DLL* end){
  if(head == NULL || head == end)
    return NULL;

  int n = size(head, end);
  DLL* root = middle(head, n);

  root->left = toBST(head, root->left);

  root->right = toBST(root->right, end);

  return root;
}

void printDLL(DLL* head){
  if(head == NULL)
    return;

  DLL* temp = head;
  while(temp != NULL){
    cout<<temp->data<<' ';
    temp = temp->right;
  }
  cout<<'\n';
}

void printInorder(DLL* root){
  if(root == NULL)
    return;

  printInorder(root->left);
  cout<<root->data<<' ';
  printInorder(root->right);

  cout<<'\n';
}

int main(){
  DLL* head = new DLL(2);
  head->right = new DLL(3);
  head->right->left = head;
  head->right->right = new DLL(4);
  head->right->right->left = head->right;
  head->right->right->right = new DLL(5);
  head->right->right->right->left = head->right->right;

  printDLL(head);

  DLL* root = toBST(head, NULL);

  printInorder(root);
  return 0;
}

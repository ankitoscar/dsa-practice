#include<iostream>
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

void merge(int arr[], int l, int m, int r){
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];
  for(int i=0; i<n1; i++)
    L[i] = arr[l + i];
  for(int j=0; j<n2; j++)
    R[j] = arr[m+j+1];

  int i = 0, j = 0, k = l;
  while(i < n1 && j < n2){
    if(L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    }
    else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while(i < n1){
    arr[k] = L[i];
    i++; k++;
  }
  while(j < n2){
    arr[k] = R[j];
    j++; k++;
  }
}

void mergeSort(int arr[], int start, int end){
  if(start >= end)
    return;

  int mid = start + (end-start)/2;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid+1, end);
  merge(arr, start, mid, end);
}

void storeInorder(Node* root, int inorder[], int *index){
  if(root == NULL)
    return;

  storeInorder(root->left, inorder, index);
  inorder[*index] = root->data;
  (*index)++;
  storeInorder(root->right, inorder, index);
}

void sortedArrToBST(int arr[], Node* root, int* index){
  if(root == NULL)
    return;

  sortedArrToBST(arr, root->left, index);

  root->data = arr[*index];
  (*index)++;

  sortedArrToBST(arr, root->right, index);
}

int countNodes(Node* root){
  if(root == NULL)
    return 0;

  return countNodes(root->left) + countNodes(root->right) + 1;
}

void convertToBST(Node* root){
  int n = countNodes(root);
  int* arr = new int[n];
  int i = 0;

  storeInorder(root, arr, &i);
  mergeSort(arr, 0, n-1);

  i = 0;
  sortedArrToBST(arr, root, &i);

  delete[] arr;
}

void printInorder(Node* root){
  if(root == NULL)
    return;

  printInorder(root->left);
  cout<<root->data<<' ';
  printInorder(root->right);
}

int main(){
  Node* root = new Node(10);
  root->left = new Node(30);
  root->right = new Node(15);
  root->left->left = new Node(20);
  root->left->right = new Node(5);

  printInorder(root);
  cout<<'\n';

  convertToBST(root);
  printInorder(root);
  return 0;
}

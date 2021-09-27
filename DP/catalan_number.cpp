#include<bits/stdc++.h>
using namespace std;

unsigned long int catalan(unsigned long int n){
  unsigned long int cat[n];
  cat[0] = 1;
  cat[1] = 1;

  for(int i=2; i<=n; i++){
    cat[i] = 0;
    for(int j=0; j<i; j++)
      cat[i] += cat[j]*cat[i-j-1];
  }

  return cat[n];
}

int main(){
  unsigned long int n;
  cin>>n;

  cout<<catalan(n);
  return 0;
}

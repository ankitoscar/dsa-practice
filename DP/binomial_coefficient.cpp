// Program to find coefficient of kth term in (1+x)^n
#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

/*
The idea is to find factorial of n using bottum up approach
and access the factorials of n, n-k and k, then use them to
obtain coefficient of kth term.
*/
unsigned long long fact[MAX] = {0};

void factorial(int n){
  fact[0] = 1;
  for(int i=1; i<=n; i++)
    fact[i] = i * fact[i-1];
}

unsigned long long coefficient(unsigned long long n, unsigned long long k){
  factorial(n);

  return fact[n]/(fact[n-k] * fact[k]);
}

int main(){
  unsigned long long n, k;
  cin>>n>>k;

  cout<<coefficient(n, k);
  return 0;
}

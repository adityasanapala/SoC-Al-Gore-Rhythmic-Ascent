#include<bits/stdc++.h>
using namespace std;
#include"sort.h"

//To analyse time complexity lets calculate the number of steps T(n) required to sort an array of size n 

void mergesort(int A[], int l, int u, int G[]){
    if(l >= u) return;
    int mid = (l+u)/2; // T(n) += 1
    mergesort(A,l,mid,G); // T(n) += T(n)/2
    mergesort(A,mid+1,u,G); // T(n) += T(n/2)
    int lt=l; // T(n) += 1
    int rt=mid+1; // T(n) += 1
    for(int i=l;i<u+1;i++){
        if(lt > mid){G[i] = A[rt++];}
        else if(rt > u || A[lt] <= A[rt]){G[i] = A[lt++];}
        else {G[i] = A[rt++];}
    } // due to this whole for loop T(n) += k1*n+k2 [some iterations will check for all 3 conditions while some might only check for one hence total steps will be between 2n and 4n]
    for(int i=l;i<u+1;i++) A[i] = G[i]; // T(n) +=n

// finally T(n) = c1*n + c2 + 2*T(n/2)
//              = 2c1*n + (1+2)c2 + 4*T(n/4)
// let n = 2^k; then we will have
// T(n) = kc1*n + (1+2+...+2^(k-1))c2 + 2^k*T(1)
// we know that T(1) = 1 hence->
// T(n) = c1*n*log(n) + n*(some constant) + another constant
// hence T(n) = O(nlog(n))

}

/*
void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
   ios::sync_with_stdio(0);
cin.tie(0);
int A[] = {2,6,4,32,4,67,89,78,56,10,25,49};
int n=sizeof(A)/sizeof(int);
int G[n];
printarr(A,n);
mergesort(A,0,n-1,G);
printarr(A,n); 
}

*/
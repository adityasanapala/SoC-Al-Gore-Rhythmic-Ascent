#include<bits/stdc++.h>
using namespace std;
#include"sort.h"

void printarr(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

int maximum_bit(int A[], int n){
    int max = A[0];
    for(int i=1;i<n;i++){
        if(A[i] > max) max = A[i];
    }
    int i=0;
    while(max != 0){
        i++;
        max = max/2;
    }
    return i;
}

int radixpartition(int* A,int l,int u,int b){
    int i=l;
    int j=u;
    int b1 = 1 << b;

    while(true){
        while(i<u+1 && (b1 & A[i]) == 0) {i++;}
        while(j>l && (b1 & A[j]) != 0) {j--;}
        if(j > i) swap(A[j],A[i]);
        else return j;
    }

}

void radixsort(int* A,int l,int u,int b){
    if(l>=u) return;
    int p = radixpartition(A,l,u,b);
    radixsort(A,l,p,b-1);
    radixsort(A,p+1,u,b-1);
}

/*

int main()
{

int A[] = {2,6,4,32,4,67,89,78,56,10,25,49};
int n=sizeof(A)/sizeof(int);
int b=maximum_bit(A,n);
cout << b <<"\n";
printarr(A,n);
radixsort(A,0,n-1,b);
printarr(A,n);
}

*/
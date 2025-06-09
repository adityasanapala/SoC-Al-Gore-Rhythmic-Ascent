#include<bits/stdc++.h>
using namespace std;
#include"sort.h"

int maximum(int A[], int n){
    int max = A[0];
    for(int i=1;i<n;i++){
        if(A[i] > max) max = A[i];
    }
    return max;
}
int minimum(int A[], int n){
    int min = A[0];
    for(int i=0;i<n;i++){
        if(A[i] < min) min = A[i];
    }
    return min;
}

void countsort(int A[], int n){
    int mx = maximum(A,n);
    int mn = minimum(A,n);
    int B[mx-mn+1];
    for(int i=0;i<mx-mn+1;i++){B[i]=0;}
    for(int i = 0;i<n;i++){
        B[A[i]-mn]++;
    }

    for(int j=0,i=0;j<mx-mn+1;j++){
        while(B[j] != 0){
            A[i] =j+mn;
            i++;
            B[j]--;
        }
    }
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

int A[] = {2,6,4,32,4,67,89,78,56,10,25,49, -2, -1, -7,66,69,36};
int n=sizeof(A)/sizeof(int);
printarr(A,n);
countsort(A,n);
printarr(A,n);
}

*/
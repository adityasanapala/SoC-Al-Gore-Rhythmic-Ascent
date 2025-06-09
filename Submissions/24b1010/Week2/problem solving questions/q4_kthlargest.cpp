#include<bits/stdc++.h>
using namespace std;
int partition(int* A,int l, int h){
    int q=A[l];
    int i=l+1;
    int j=h;
    while (true){
        while(i<h+1 && q>A[i]) {i++;}
        while(j>l && q<=A[j]) {j--;}
        if(j>i){swap(A[i],A[j]);}
        else break;
    }
    swap(A[l],A[j]);
    return j;
}

int find_kth_largest(int* A, int l,int h, int k){
    int i = partition(A,l,h);
    if(i==h+1-k) return A[i];
    else if( i>h-k+1) return find_kth_largest(A,l,i-1,i-1+k-h);
    else return find_kth_largest(A,i+1,h,k);
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int arr[] = {3,5,7,2,8,9,1,4,6};
cout << find_kth_largest(arr,0,8,4) << "\n";
}
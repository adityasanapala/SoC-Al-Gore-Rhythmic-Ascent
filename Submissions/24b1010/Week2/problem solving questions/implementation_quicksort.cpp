#include<bits/stdc++.h>
using namespace std;
#include"sort.h"

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

void quicksort(int* A, int l, int h){
    if(l>=h) return;
    int p = partition(A,l,h);
    quicksort(A,l,p-1);
    quicksort(A,p+1,h);
}

/*

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int p[9] = {7,8,1,2,3,6,5,9,4};
quicksort(p,0,8);

for(int i = 0; i < 9;i++){
    cout << p[i] << " ";
} cout << "\n";
}

*/
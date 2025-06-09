#include<bits/stdc++.h>
#include<chrono>
#include"sort.h"
using namespace std;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int p1[] = {7,8,1,2,3,6,5,9,4};
int p2[] = {7,8,1,2,3,6,5,9,4};
int p3[] = {7,8,1,2,3,6,5,9,4};
int p4[] = {7,8,1,2,3,6,5,9,4};
int n=9;
int p5[n];
printarr(p1,n);
auto start = std::chrono::high_resolution_clock::now();
countsort(p1,n);
auto end = std::chrono::high_resolution_clock::now();
printarr(p1,n);
std::chrono::duration<double, std::milli> duration = end - start;
std::cout << "Time taken by Countsort: " << duration.count() << " ms\n";

printarr(p2,n);
start = std::chrono::high_resolution_clock::now();
mergesort(p2,0,n-1,p5);
end = std::chrono::high_resolution_clock::now();
printarr(p2,n);
duration = end - start;
std::cout << "Time taken by Mergesort: " << duration.count() << " ms\n";

printarr(p3,n);
start = std::chrono::high_resolution_clock::now();
quicksort(p3,0,n-1);
end = std::chrono::high_resolution_clock::now();
printarr(p3,n);
duration = end - start;
std::cout << "Time taken by Quicksort: " << duration.count() << " ms\n";

printarr(p4,n);
start = std::chrono::high_resolution_clock::now();
int b=maximum_bit(p4,n);
radixsort(p4,0,n-1,b);
end = std::chrono::high_resolution_clock::now();
printarr(p4,n);
duration = end - start;
std::cout << "Time taken by Radixsort: " << duration.count() << " ms\n";
}
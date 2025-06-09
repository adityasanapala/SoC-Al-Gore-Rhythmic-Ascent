#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<vector<int>> v;
        for(int i=0; i<nums.size();i++){
            if(m[target-nums[i]] != 0){
                v.push_back({nums[i],nums[m[target-nums[i]]-1]});
            }
            m[nums[i]] = i+1;
        }
    return v;
}

void printvec(vector<int> v){
    for(int i=0,n=v.size();i<n;i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

vector<int> v = {1,5,6,3,8,13,16,45,89,12,33};
int target = 11;
printvec(v);
vector<vector<int>> a = twoSum(v,target);
for(int i=0,n=a.size();i<n;i++){
    printvec(a[i]);
}   
}
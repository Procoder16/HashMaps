#include<bits/stdc++.h>
using namespace std;

int longestSubarrayK(int arr[], int n, int k){

    int prefixSum = 0;
    int maxLen = INT_MIN;
    map<int,int> m;

    for(int i = 0; i < n; i++){
        prefixSum+=arr[i];
        if(prefixSum == k){
            maxLen = max(maxLen,i+1);
        }
        if(m.find(prefixSum - k) != m.end()){
            maxLen = max(maxLen, i - m[prefixSum-k]);
        }
        else{
            m[prefixSum] = i;
        }
    }
    return maxLen;
}    

int main(){

    int n;
    cout<<"ENTER THE LENGTH OF THE ARRAY:";
    cin>>n;

    int arr[n];
    cout<<"ENTER THE ELEMENTS OF THE ARRAY:";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int k;
    cout<<"ENTER THE VALUE OF K:";
    cin>>k;

    cout<<"LENGTH OF THE LONGEST SUBARRAY WITH SUM K IS:"<<longestSubarrayK(arr, n, k);

    return 0;
}
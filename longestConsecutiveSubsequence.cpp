#include<bits/stdc++.h>
using namespace std;

int longestConsecutiveSubsequence(int arr[], int n){
    unordered_map<int, int> m; //number, its current streak length

    for(int i = 0; i < n; i++){
        int num = arr[i];
        if(m.count(num - 1) == 0 && m.count(num + 1) == 0){
            m[num] = 1;
        }

        else if(m.count(num - 1) && m.count(num + 1)){
            int leftLen = m[num - 1];
            int rightLen = m[num + 1];

            int newLen = leftLen + 1 + rightLen;
            m[num - leftLen] = newLen;
            m[num + rightLen] = newLen;
            m[num] = newLen;
        }

        else if(m.count(num - 1) && m.count(num + 1) == 0){
            int strkLen = m[num - 1];
            m[num - strkLen] = strkLen + 1;
            m[num] = strkLen + 1;            
        }

        else if(m.count(num - 1) == 0 && m.count(num + 1)){
            int strkLen = m[num + 1];
            m[num + strkLen] = strkLen + 1;
            m[num] = strkLen + 1;            
        }
    }

    int largest = 0;
    for(auto p : m){
        largest = max(largest, p.second);
    }

    return largest;
}

int main(){

    int arr[] = {14,5,1,2,6,8,9,4,3,10,0};

    int n = sizeof(arr)/sizeof(int);

    cout<<"LENGTH OF THE LONGEST CONSECUTIVE SUBSEQUENCE:"<<longestConsecutiveSubsequence(arr, n);    

    return 0;
}

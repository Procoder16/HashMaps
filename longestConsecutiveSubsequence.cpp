#include<bits/stdc++.h>
using namespace std;

/*
    -> The naive or the brute force approach would be just sorting the array and then find the consecutive numbers and then form a subsequence.
       In this approach we would also have to manage the edge case of duplicate values as we only want unique elements in the subsequence.

    -> The second approach is using a hash map(unordered_map) for this where we will map the number with the length of the current streak it belongs to.
       The idea is that we would be traversing the array and for each element:
            >> We would chech whether it has a streak starting from n + 1 or ending at n - 1.

            Now there can be 4 cases:
                -> It has no such streaks on either side. In that case just make a new pair with key as the number and value as 1
                -> It has both these streaks:
                    > Calculate the length of the left and the right streak respectively and then the new streak length would be a sum of the both + 1.
                    > Then change the streak length of the left end and the right end
                -> It has one streak only on any one side:
                    > Calculate the streak length on that side.
                    > Give the current number the value of streak length + 1
                    > Change the end value to streak plus one also.                                              
*/

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

int longestConsecutiveSubsequenceSet(int arr[], int n){

    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(arr[i]);
    }

    int maxLen = INT_MIN;

    for(int i = 0; i < n; i++){
        int num = arr[i];
        if(s.count(num - 1) == 0){
            int strkLen = 1;
            while(s.count(num + 1)){
                strkLen++;
                num++;
            }
            maxLen = max(maxLen, strkLen);
        } 
    }
    return maxLen;
}

int main(){

    int arr[] = {14,5,1,2,6,8,9,4,3,10,0};

    int n = sizeof(arr)/sizeof(int);

    cout<<"LENGTH OF THE LONGEST CONSECUTIVE SUBSEQUENCE USING HASH MAP APPROACH:"<<longestConsecutiveSubsequence(arr, n)<<endl;
    cout<<"LENGTH OF THE LONGEST CONSECUTIVE SUBSEQUENCE USING SET APPROACH:"<<longestConsecutiveSubsequenceSet(arr, n);    

    return 0;
}

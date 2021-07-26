#include<bits/stdc++.h>
using namespace std;

/*
    The idea almost follows the same as the question "Check whether Subarray with sum 0 is present or not".
    The only difference is that we would be using unordered map or map instead of set to store the idex of the last occurence.
    ***And one edge case to keep in mind is that, if the prefix sum at amy position is zero, then that should be the longest subarray with sum 0 till
    that position.
*/    

int main(){

    int n;
    cout<<"ENTER THE LENGTH OF THE ARRAY:";
    cin>>n;

    int maxLen = INT_MIN;

    int arr[n];
    cout<<"ENTER THE ELEMENTS OF THE ARRAY:";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // making the prefix sum

    int prefixSum = arr[0];
    for(int i = 1; i < n; i++){
        prefixSum += arr[i];
        arr[i] = prefixSum;        
    }

    //printing the prefix sum
    cout<<"PREFIX SUM ARRAY:"<<endl;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    map<int, int> m;

    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            maxLen = max(maxLen, i+1);
        }
        if(m.count(arr[i]) > 0){
            int diff = i - m[arr[i]];
            maxLen = max(maxLen, diff);
        }
        else{
            m.insert(make_pair(arr[i], i));
        }
    }

    cout<<endl;
    
    cout<<"LONGEST SUBARRAY WITH SUM 0: "<<maxLen;

    return 0;
}
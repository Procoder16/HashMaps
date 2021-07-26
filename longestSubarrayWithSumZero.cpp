#include<bits/stdc++.h>
using namespace std;

/*
         
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
        if(m.count(arr[i]) > 0){
            int diff = i - m[arr[i]];
            maxLen = max(maxLen, diff);
        }
        else{
            m.insert(make_pair(arr[i], i));
        }
    }

    cout<<endl;
    
    cout<<maxLen;

    return 0;
}
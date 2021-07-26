#include<bits/stdc++.h>
using namespace std;

/*
    There can be three ways of solving this problem and I'll be writing the approach for all of them but the code for the optimized approach only
        1. The first approach is the brute force which takes O(n^3) time complexity where there is an outer loop with i and an inner loop with j
            which basically gives you the subarrays with O(n^2) complxity and then another loop that runs from i to j calculating the sum with O(n)

        2. Second approach would be just maintaining a prefix sum or making a prefix sum. Then again two loops i and j denoting the subarrays with 
            cumulative sum. This time we would just calculate the difference of the cumulative sum at position j and at position i. So the 
            maintaining of the cumulative sum would take a complexity of O(n) and then the two loops would require O(n^2) complexity and the 
            calculation of the difference just takes a constant time. So the overall time complexity would be O(n) + O(n^2) which can be further 
            written as O(n^2).

        3. The third approach is just an optimised solution using the prefix sum itself where you maintain a prefix sum and then you take the help of 
            a hash map or an unordered set to check whether there comes same cumulative sum in the prefix sum array.     
*/    

int main(){

    int n;
    cout<<"ENTER THE LENGTH OF THE ARRAY:";
    cin>>n;

    bool isPresent = false;

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

    unordered_set<int> s;

    for(int i = 0; i < n; i++){
        if(s.count(arr[i]) > 0){
            isPresent = true;
            break;
        }
        else{
            s.insert(arr[i]);
        }
    }

    cout<<endl;
    
    if(isPresent){
        cout<<"THERE IS A SUBARRAY PRESENT WITH SUM 0";
    }
    else{
        cout<<"A SUBARRAY WITH SUM 0 IS NOT FOUND";
    }

    return 0;
}
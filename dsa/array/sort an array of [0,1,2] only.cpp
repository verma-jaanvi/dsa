#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//brute approach is to use any sorting algorithm to sort the array
//the best one is the merge sort with the time complexity O(nlogn)

//better approach is to count the number of 0's , 1's and 2's and then store it 
vector<int> better(vector<int> arr, int n){
    int a[3]= {0};
    for(int i=0;i<n;i++){
        a[arr[i]]++;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<a[i];j++){
            arr.push_back(i);
        }
    }
}

//optimal approach 
//using the dutch national flag algorithm 
vector<int> optimal(vector<int> arr, int n){
    int low = 0, mid = 0, high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return arr;
}
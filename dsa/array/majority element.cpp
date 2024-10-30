//an element in the array that appears greater than n/2 times in the array 
//if the arr=[1,1,2,3,1,1] and n=6 so the ans should be 1 as it appears more than n/2=6/2=3times in the array 
#include<iostream>
#include<vector>
#include<unordered_map>

//brute force approach
int brute(std::vector<int> arr, int n) {
    int a= int(n/2);
    for(int i=0;i<arr.size();i++){
        int count=0;
        for(int j=0;j<arr.size();j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>a){
            return arr[i];
        }
    }
    return -1;
}

//better solution
//O(2n)
int better(std::vector<int> arr, int n) {
    std::unordered_map<int,int> a;
    for(int i=0;i<arr.size();i++){
        a[arr[i]]++;
    }
    for(auto it: a){
        if(it.second>n/2)
            return it.first;
    }
    return -1;
}

//optimal solution
//Moore's Voting Algorithm
int optimal(std::vector<int> arr, int n) {
    int num = arr[0];
    int count=1;
    for(int i=1;i<arr.size();i++){
        if(arr[i]==num)
            count++;
        else if(count==0){
            num=arr[i];
            count=1;
        }
        else 
            count--;
    }
    for(int i=0;i<arr.size();i++){
        if(arr[i]==num) count++;
    }
    if(count > n/2) return num;
    return -1;
}
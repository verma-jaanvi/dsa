#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


//return the index at which the two values whose sum = target is present
//for arr[]=[2,6,5,8,11] target=14
vector<int> brute(vector<int> arr, int target){

    for(int i=0;i<arr.size();i++){
        for (int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==target)
                return {i,j};
        }    
    }
    return {};
}

//better approach 
//hashing   
//O(nlogn)
vector<int> better(vector<int> arr, int n, int target){
    //map <element, index>
    map<int, int> map;

    for(int i=0;i<arr.size();i++){
        int a = arr[i];
        int next = target - a;
        if(map.find(next)!=map.end())
            return {map[next], i};
        map[a] = i;
    }
    return {};
}

//without map 
vector<int> optimal(vector<int> arr, int n, int target){
    int left = 0, right = n-1;
    sort(arr.begin(),arr.end());
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target)
            return {left, right};
        else if(sum < target) 
            left++;
        else
            right--;
    }
    return {};
}
//longest subarray whose sum is k
// arr[]=[1,2,3,1,1,1,4,2,3]
// k=3
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
//brute
int brute(std::vector<int> arr, int k){
    int ans=0;
    //traversing the whole array using two pointer approach 
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            int s=0;
            //calculates the sum
            for(int l=i;l<=j;l++){
                s+=arr[l];
            }
            if(s==k) 
                ans=std::max(ans,j-i+1);
        }
    }
    return ans;
}

//brute two 
//as the next sum is the result of revious sum + next number so we can reduce the k loop

int brute2(std::vector<int> arr, int k){
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        int s = 0;
        for (int j = i; j < arr.size(); j++) {
            s += arr[j]; 
            if (s == k) {
                ans = std::max(ans, j - i + 1); 
            }
        }
    }
    
    return ans;
}

//note* unoredered_map: O(n*1) but in the worst case O(n^2)
//ordered_map: O(nlogn)

//better
//using hashing, we check if the the sum of subarray is k then the previously the sum of the other is x-k
int better(std::vector<int> a, long long k){
    int ans = 0;
    // we store the key value pair to check the reverse indexing
    std::map<long long, int> preSumMap;
    long long sum =0;
    int maxLen = 0;
    //traversing the array
    for(int i=0;i<a.size();i++){
        sum+= a[i]; //updating the sum each time
        if(sum == k){
            maxLen = std::max(maxLen, i+1);
        }
        //to check if the sum exists in the middle of the array by total sum - target is present or not 
        long long rem = sum - k;
        if(preSumMap.find(rem)!= preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = std::max(maxLen, len);
        }
        //if the sum is previously not their then adds the sum to the map
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum]=i;
        }
    }
    return maxLen;
}
// the above solution works only for positives i.e. won't work if there is 0


//optimal solution 
//two pointer approach arr[]= [1,2,3,1,1,1,1,3,3] k=6
int optimal(std::vector<int> a, long long k){
    //we move the i when the sum goes beyond k on moving j
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();
    // as the size should not exceed the max index
    while(right < n){
        //sum should not exceed the k
        while(left <= right && sum > k){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            maxLen = std::max(maxLen, right-left+1);
        }
        right++;
        if(right < n) sum += a[right];
    }
    return maxLen;
}
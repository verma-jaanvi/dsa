#include<iostream>
#include<vector>
using namespace std;
//kadane's algorithm
//contigious sum in the array with maximum sum
//brute
int brute(vector<int> arr, int n) {
    int sum =0, maxsum=0;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++) {
            sum = 0;
            for(int k=i;k<=j;k++) {
                sum += arr[k];
            }
            if(sum > maxsum) {
                maxsum = sum;
            }
        }
    return maxsum;
}


//better
int better(vector<int> arr, int n) {
    int sum =0, maxsum=0;
    for(int i=0;i<n;i++) {
        sum=0;
        for(int j=i;j<n;j++) {
            sum += arr[j];
            if(sum > maxsum) {
                maxsum = sum;
            }
        }
    }
    return maxsum;
}
//kadane's algorithm
//optimal
long long optimal(vector<int> arr, int n) {
    long long sum=0, maxi = LONG_MIN;
    for(int i=0;i<n;i++) {
        sum += arr[i];
        if(sum > maxi) {
            maxi = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    if(maxi<0){
        maxi=0;
    }
    return maxi;
}

//if we are asked to print the subarray with maximum sum
//note more than one subarray exists that gives us the maximun sum
//a little changes are needed
//sum is always 0 when we start to form a new subarray 
long long optimal(vector<int> arr, int n) {
    long long sum=0, maxi = LONG_MIN;
    int start=-1,end=-1;
    for(int i=0;i<n;i++) {
        if(sum==0) start = i; // tracks back the ans subarray 
        sum += arr[i];
        if(sum > maxi) {
            maxi = sum;
            start = start,end=i; //extends the subarray
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    if(maxi<0){
        maxi=0;
    }
    return maxi;
}
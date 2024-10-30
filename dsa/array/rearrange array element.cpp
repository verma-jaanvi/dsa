//rearrange array element by sign such as [ + , - , + , - , + , - ]
// values having equal positive and negative elements value
#include <iostream>
#include <vector>
using namespace std;

//brute
vector<int> brute(vector<int> arr, int n) {
    vector<int> posi;
    vector<int> nega;
    for(int i=0;i<n;i++) {
        if(arr[i] < 0) 
            nega.push_back(arr[i]);
        else    
            posi.push_back(arr[i]);
    }
    for(int i=0;i<n/2;i++){
        arr[2*i]=posi[i];
        arr[2*i+1]=nega[i];
    }
    return arr;
}

//optimized
vector<int> optimized(vector<int> arr, int n) {
    int posi=0, negi=1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            swap(arr[i],arr[negi]);
            negi+=2;
        }
        else{
            swap(arr[i],arr[posi]);
            posi+=2;
        }
    }
    return arr;
}

//when the number of positive and negative elements are not equal
//brute
vector<int> brute(vector<int> arr, int n) {
    vector<int> posi;
    vector<int> negi;
    for(int i=0;i<n;i++) {
        if(arr[i] < 0)
            negi.push_back(arr[i]);
        else
            posi.push_back(arr[i]);
    }
    int mini = min(posi.size(),negi.size());
    for(int i=0; i<mini; i++) {
        arr[2*i]=posi[i];
        arr[2*i+1]=negi[i];
    }
    int index=mini*2;
    while(posi.size()>=mini||negi.size()>=mini){
        if(posi.size()>=mini)
            arr[index]=(posi[mini]);
        else if(negi.size()>=mini)
            arr[index]=(negi[mini]);
        mini++;
        index++;
    }
    return arr;
}
#include<iostream>
#include<algorithm>
using namespace std;
bool isPossible(long long distance,int* arr,int stalls,int cows){
    cows--;
    long long last_pos=arr[0];
    for(int i=1;i<stalls;i++){
        if(arr[i]-last_pos >=distance){
           last_pos=arr[i];
           cows--; 
        }
        if(cows==0){
            return true;
        }
    }
    return false;
}

int main() {
	// Write your code here
    int t;
    cin>>t;
    while(t--){
        int stalls;
        cin>>stalls;
        int cows;
        cin>>cows;
        int* positions= new int[stalls];
        for(long long i=0;i<stalls;i++){
           cin>>positions[i]; 
        }
        sort(positions,positions+stalls);
        long long min=0;
        long long max=positions[stalls-1]-positions[0];
        int ans=-1;
        while(min<=max){
           long long distance=min+(max-min)/2;
           if(isPossible(distance,positions,stalls,cows)){
              ans = distance; 
              min = distance+1;
           }
           else{
              max = distance-1; 
           } 
        }
        cout<<ans<<endl;
    }
}
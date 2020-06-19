#include<iostream>
#define MAXN 100005
using namespace std;
int merged(int ar[],int st,int mid,int en){
    int i=st;
    int j=mid; 
    int* temp= new int[(en-st)+1];
    int count=0;
    int k=0;
    while(i<mid || j<=en){
      if(i>=mid){
        for(int p=j;p<=en;p++){
           temp[k]=ar[p];
           k++; 
        }
        break;  
      }
      if(j>en){
        for(int p=i;p<mid;p++){
           temp[k]=ar[p];
           k++; 
        }
        break;  
      }
      if(ar[i] <= ar[j]){ 
          temp[k]=ar[i]; 
          i++;
      }
      else{
         temp[k]=ar[j];
         count=count+(mid-i);
         j++; 
      }
      k++;    
    }
    //put it back to original array
    k=0;
    for(int i=st;i<=en;i++){
       ar[i]=temp[k];
       k++; 
    }
    delete[] temp;
    return count;
}


long long getInversions(int ar[],int st,int en){
   if(st>=en){
     return 0;
   }
   int mid=(st+en)/2;
   long long left  = getInversions(ar,st,mid); 
   long long right = getInversions(ar,mid+1,en);
   long long merge = merged(ar,st,mid+1,en); 
   return left+right+merge;
}

long long solve(int A[], int n){
	// Write your code here
    return getInversions(A,0,n-1);
}


int main(){
  int n,A[MAXN];
  cin>>n;
  for(int i = 0; i < n ; i++){
    cin>>A[i];
  }
  cout<<solve(A,n)<<endl;
} 
#include<bits/stdc++.h>
using namespace std;
void headAdjust(int A[],int index,int n){
    while((index+1)*2<=n){
        int temp = A[index];
        int i=(index+1)*2;
        if(i+1<=n&&A[i-1]<A[i]) i++;
        if(A[index] > A[i-1]) break;
        else{
            A[index] = A[i-1];
            A[i-1] = temp;
            index = i-1;
        }
    }
}
void buildMaxHeap(int A[],int n){
    for(int i=n-1;i>=0;i--){
        headAdjust(A,i,n);
    }
}
void pileSort(int A[],int n){
    buildMaxHeap(A,n);
    for(int i=n-1;i>0;i--){
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        headAdjust(A,0,i);
    }
}
int main(){
    int n=10;
    int A[10]={9,8,7,6,5,4,3,2,1,0};
    pileSort(A,n);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}

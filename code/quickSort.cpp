#include<bits/stdc++.h>
using namespace std;
int sort(int A[],int start,int e){
    int temp = A[start];
    while(start<e){
        while(start<e&&temp<A[e]){
            e--;
        }
        A[start] = A[e];
        while(start<e&&temp>A[start]){
            start++;
        }
        A[e] = A[start];
    }

    A[start] = temp;
    return start;
}
void quickSort(int A[],int start,int e){
    if(start<e){
        int mid = sort(A,start,e);
        quickSort(A,start,mid-1);
        quickSort(A,mid+1,e);
    }
}
int main(){
    int A[10]={25,4,6,7,49,1,3,2,59};
    for(int i=0;i<9;i++){
        A[i] = i;
        cout<<A[i]<<" ";
    }
    cout<<endl;
    quickSort(A,0,8);
    for(int i=0;i<9;i++){
        cout<<A[i]<<" ";
    }
}

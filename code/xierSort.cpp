#include<bits/stdc++.h>
using namespace std;
void xierSort(int A[],int n){
    int d = n/2;
    while(d>0){
        for(int i=d;i<n;i++){
/*            int j=i;
            int t=A[i];
            for(j=i;j>=d&&t<A[j-d];j-=d){
                A[j] = A[j-d];
            }
            A[j] = t;*/
            for(int j=i;j>=d;j-=d){
                if(A[j]<A[j-d]){
                    int t = A[j];
                    A[j] = A[j-d];
                    A[j-d] = t;
                }
            }
        }
        d/=2;
    }

}
int main(){
    int A[10]={25,4,6,7,49,1,3,2,59};
    for(int i=0;i<9;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    xierSort(A,9);
    for(int i=0;i<9;i++){
        cout<<A[i]<<" ";
    }
}

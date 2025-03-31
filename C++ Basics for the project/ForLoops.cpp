#include <iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    for(int x: arr){
        cout<<x<< " ";
    }
    cout<<"\nTraversing the array whith foreach using auto keyword   :";
    for(auto y: arr){
        cout<<y <<" ";
    }
    return 0;
}
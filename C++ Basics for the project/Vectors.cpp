#include <iostream>
#include <vector>


using namespace std;
vector<int> v = {1,2,3,4,5,6,7,8};

int main(){
    for(auto x : v){
        cout<<x<<endl;
    }
    return 0;
}
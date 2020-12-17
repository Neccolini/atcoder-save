#include<iostream>
#include<vector>
using namespace std;

/*
left は「常に」条件を満たさない
right は「常に」条件を満たす
right - left = 1 になるまで範囲を狭める (最後は right が条件を満たす最小)
*/
vector<int> a={1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
bool isOK(int index, int key){
    if(a[index]>=key)return true;
    else return false;
}
int binary_search(int key){
    int left=-1;
    int right=(int)a.size();

    while(right-left>1){
        int mid=left+(right-left)/2;
        
        if(isOK(mid,key))right=mid;
        else left=mid;
    }
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator> //prev
using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
//lower_bound -> key以上の要素の一番左側のイテレータを返す
    auto it = lower_bound(v.begin(), v.end(), 4);
// upper_bound -> keyより大きい要素で一番左側のイテレータを返す
    auto it2=upper_bound(v.begin(), v.end(),4);
//indexを取得するには, v.begin()を引く
    int index_l = it - v.begin();
    int index_u = it2-v.begin();
//key以下で最大の要素
    cout<<*prev(upper_bound(v.begin(),v.end(),4))<<endl;
    cout<<index_u-1<<endl;
//keyより小さい最大の要素
    cout<<*prev(lower_bound(v.begin(),v.end(),4))<<endl;
    cout<<index_l-1<<endl;
}
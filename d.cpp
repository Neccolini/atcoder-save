/* 
与えられたビットストリームデータに含まれるunsigned exp-golomb符号を全てデコードしてください。
なお、unsigned exp-golomb符号とは、動画CODECなどで用いられる符号化方式です。
0～10までの値に対応する符号の表を以下に示します。

  符号のBit string | 符号の値 | デコード値
   (2進数)         | (10進数) | (10進数)    
 ------------------+----------+------------
 1                 |        1 |          0
 010               |        2 |          1
 011               |        3 |          2
 00100             |        4 |          3
 00101             |        5 |          4
 00110             |        6 |          5
 00111             |        7 |          6
 0001000           |        8 |          7
 0001001           |        9 |          8
 0001010           |       10 |          9
 0001011           |       11 |         10
 ↓                 |        ↓ |          ↓
 ------------------+----------+------------
符号の長さは連続する0の数×2+1bitであり、符号が示す値-1がデコード値となります。
符号化コードは左詰めで格納されているものとします。
例としてビットストリームが 0x230de722の場合、下記の符号が含まれることになります。
00100, 011, 000011011, 1, 1, 00111, 00100, 010
したがって、ビットストリーム0x230de722に含まれるunsigned exp-Golomb符号のデコード値は
先頭から順に3,2,26,0,0,6,3,1となります。
streamで与えられる32bitのストリームに含まれるunsigned Golomb符号をデコードした結果を
先頭から順にprintfを使って表示するプログラムを記述してください。
*/

#include <stdio.h>
#include <iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

string sto2(int x){
    string res ="";
    while(x){
       res+=(char)(x%2+'0');
       x/=2;
}
    int r=res.size();
    for(int i=0;i<4-r;i++)res+='0';
    reverse(res.begin(), res.end());
    return res;
}

int ston(string s){
int ans=0;
    for(int i=s.size()-1;i>=0;i--){
        ans+=(s[i]-'0')*pow(2,i);
    }
    return ans;
}

int main(int argc, char **argv) 
{
  // exp-Golomb符号のbit string表現
  unsigned int stream = 0x230de722; 
  {
    unsigned int buf = stream;
    vector<int> s;
    while(buf){
        s.emplace_back(buf%16);
        buf/=16;
}
    reverse(s.begin(), s.end());

    string ans="";
    for(auto v:s)ans+=sto2(v);

    vector<string> Gol;
    int j=0;
    for(int i=0;i<ans.size();i++){
        while(ans[j]=='0' && j<ans.size())j++;
        int n=(j-i)*2+1;
        Gol.emplace_back(ans.substr(i, n));

    }
    for(int i=0;i<ans.size();i++)printf("%d,", ston(Gol[i]));
  }
  return 0;
}



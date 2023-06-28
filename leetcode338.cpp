//
// Created by 26236 on 2023/6/28.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    if (n == 0){
        return {0};
    }
    vector<int> base_res = countBits(n-1);
    int one_count = 0;
    int tmp = n;
    while (tmp != 0){
        one_count += tmp % 2;
        tmp = tmp/2;
    }
    base_res.push_back(one_count);
    return base_res;
}

void print_vec(vector<int> v){
    for (int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> res = countBits(5);
    print_vec(res);
    return 0;
}
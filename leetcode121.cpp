//
// Created by 26236 on 2023/10/11.
//

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    if (n==1) return 0;
    int left=0, right=1;
    int max_profit=0;
    for (right=1;right<n;right++){
        if (prices[right]-prices[left]<0){
            left=right;
            continue; // means that right++ already
        }
        else if (prices[right]-prices[left]>max_profit){
            // update the profit
            max_profit=prices[right]-prices[left];
        }
    }
    return max_profit;
}

int main(){
    vector<int> vec1 = {7,1,5,3,6,4};
    vector<int> vec2 = {7,6,4,3,1};
    int k1 = maxProfit(vec1);
    int k2 = maxProfit(vec2);
    cout<<k1<<" "<<k2<<endl;
}
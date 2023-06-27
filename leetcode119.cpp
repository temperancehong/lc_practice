//
// Created by 26236 on 2023/6/27.
//

#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> my_vec){
    for (int i = 0; i < my_vec.size(); i++){
        cout<<my_vec[i]<<" ";
    }
    cout<<endl;
}

vector<vector<int>> generate(int numRows) {
    if (numRows == 1){
        vector<vector<int>> res;
        vector<int> res0 = {1};
        res.push_back(res0);
        return res;
    }
    else if (numRows ==2){
        vector<vector<int>> res;
        vector<int> res0 = {1};
        res.push_back(res0);
        res0.push_back(1);
        res.push_back(res0);
        return res;
    }
    else{
        vector<vector<int>> res_last = generate(numRows-1);
        vector<int> res_last_last = res_last[res_last.size()-1];
        vector<int> res_new;
        res_new.push_back(1);
        for (int i = 1; i < numRows-1; i++){
            res_new.push_back(res_last_last[i-1]+res_last_last[i]);
        }
        res_new.push_back(1);
        res_last.push_back(res_new);
        return res_last;
    }

}

vector<int> getRow(int rowIndex){
    vector<vector<int>> res = generate(rowIndex+1);
    return res[res.size()-1];
}

int main(){
//    vector<vector<int>> res = generate(5);
    vector<int> last_line = getRow(5);
    print_vector(last_line);
}

//
// Created by 26236 on 2023/10/23.
//

#include <bits/stdc++.h>
using namespace std;

void printIntVector(const std::vector<int>& intVector, int k) {
    for (int i = 0; i < k; i++){
        cout<<intVector[i]<<" ";
    }
    std::cout << std::endl;
}

void printCharMap(const std::map<char, std::vector<int>>& charMap) {
    for (const auto& pair : charMap) {
        std::cout << "Character: " << pair.first << " Positions: ";
        for (int position : pair.second) {
            std::cout << position << ' ';
        }
        std::cout << std::endl;
    }
}


bool isIsomorphic(string s, string t) {
    map<char, vector<int>> s_map, t_map; // the char and the corresponding positions
    int n=t.length();
    int i=0;
//    map<char, vector<int>>::iterator it_s, it_t;
    while (i<n){
        if (s_map.find(s[i])==s_map.end() && t_map.find(t[i])==t_map.end()){
            // new letter in the map
            s_map[s[i]]={i};
            t_map[t[i]]={i};
        }
        else if (s_map.find(s[i])==s_map.end() || t_map.find(t[i])==t_map.end()){
//            cout<<"second reached"<<endl;
            return false;
        }
        else{
            s_map[s[i]].push_back(i);
            t_map[t[i]].push_back(i);
            if (s_map[s[i]] != t_map[t[i]]){
//                cout<<"third reached"<<endl;
                return false;
            }
        }
        printCharMap(s_map);
        printCharMap(t_map);
        i++;
    }
    return true;
}

int main(){
    string str1 = "12";
    string str2 = "\u0067\u0067";
    string str3 = "paper";
    string str4 = "title";
    bool res = isIsomorphic(str1, str2);
    cout<<res<<endl;
    return 0;
}
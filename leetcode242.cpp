//
// Created by 26236 on 2023/10/25.
//

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()){return false;}

    unordered_map<char, int> s_map, t_map;
    for (auto char_s:s){
        if (s_map.find(char_s) == s_map.end()){
            s_map[char_s] = 1;
        }
        else{
            s_map[char_s]++;
        }
    }

    for (auto char_t: t){
        if (s_map.find(char_t) == s_map.end()){
            return false; // no corresponding letter
        }
        else{
            s_map[char_t]--;
            if (s_map[char_t] < 0){
                return false;
            }
        }
    }
    return true;
}

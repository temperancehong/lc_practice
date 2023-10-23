//
// Created by 26236 on 2023/10/23.
//

#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    // establishing a hashmap for magazine and get a count-down for ransomNote
    unordered_map<char, int> magazine_map;
    for (auto c : magazine){
        if (magazine_map.find(c)==magazine_map.end()){
            // new key, add it
            magazine_map[c] = 1;
        }
        else{
            magazine_map[c]++;
        }
    }
    // hashmap established
    for (auto k:ransomNote){
        if (magazine_map.find(k)==magazine_map.end()){
            // is not a key
            return false;
        }
        else{
            magazine_map[k]--;
            if (magazine_map[k]<0){
                return false;
            }
        }
    }
    return true;
}
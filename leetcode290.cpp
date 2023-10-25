//
// Created by 26236 on 2023/10/24.
//

#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) {
    map<char, vector<int>> pattern_map;
    map<string, vector<int>> s_map;
    int n = pattern.length();

    // put the sentence into words
    std::istringstream iss(s);
    // Create a vector to store the words
    std::vector<std::string> words;
    // Tokenize the string and store the words in the vector
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }

    if (n != words.size()){return false;}

    int i=0;
    while (i < n){
        if (pattern_map.find(pattern[i]) == pattern_map.end() && s_map.find(words[i])==s_map.end()){
            pattern_map[pattern[i]] = {i};
            s_map[words[i]] = {i};
        }
        else if (pattern_map.find(pattern[i]) == pattern_map.end() || s_map.find(words[i])==s_map.end()){
            return false;
        }

        else{
            pattern_map[pattern[i]].push_back(i);
            s_map[words[i]].push_back(i);
            if (pattern_map[pattern[i]] != s_map[words[i]]){
                return false;
            }
        }
        i++;
    }
    return true;
}

int main(){
    string pattern = "abba";
    string s = "dog cat cat fish";
    bool res = wordPattern(pattern, s);
    cout<<res<<endl;
    return 0;
}

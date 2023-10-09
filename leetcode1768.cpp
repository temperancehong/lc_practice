//
// Created by 26236 on 2023/8/10.
//

#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) {
    int len1, len2;
    len1 = word1.size();
    len2 = word2.size();
    string output;
    if (len1 <= len2){
        string::iterator it1;
        string::iterator it2 = word2.begin();
        for (it1 = word1.begin(); it1 != word1.end(); it1++){
            output.push_back(*it1);
            output.push_back(*it2);
            it2++;
        }
        while (it2 != word2.end()){
            output.push_back(*it2);
        }
    }
    else{ // len1 > len2
        string::iterator it1;
        string::iterator it2 = word2.begin();
        for (it1 = word1.begin(); it1 != word1.end(); it1++){
            output.push_back(*it1);
            output.push_back(*it2);
            it2++;
        }
        while (it2 != word2.end()){
            output.push_back(*it2);
        }
    }
}

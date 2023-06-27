<<<<<<< HEAD
//
// Created by 26236 on 2023/5/5.
//

#include <bits/stdc++.h>
using namespace std;
int maxVowels(string s, int k);

int main(){
    string main_str = "abciiidef";
    string main_str1 = "aeiou";
    string main_str2 = "leetcode";
    int k = 3, k1 = 2, k2 = 3;
    printf("main_str: %d, main_str1: %d, main_str2: %d\n", maxVowels(main_str,k),maxVowels(main_str1,k1),maxVowels(main_str2,k2));

}


int maxVowels(string s, int k){
    // the sliding windows shouldn't start counting newly each time, but updating the increment and decrement at two ends
    int count=0, res = 0; // init all the values
    unordered_set<char> vowels{'a','e','i','o','u'};
    for (int i = 0; i < k; i++){
        count += vowels.count(s[i]);
    }
    res = count;
//    int tmp_res;
    for (int i = k; i < s.size(); i++){
        count = count + vowels.count(s[i]) - vowels.count(s[i-k]);
//        tmp_res = res + vowels.count(s[i]) - vowels.count(s[i-k]);
        res = max(res, count);
    }
    return res;
}

/*
int maxVowels(string s, int k){ // this answer exceeds the running time
    set<char> vowels;
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
    int max_res = 0;
    // using the sliding windows to solve the problem
    for (int i = 0; i <= s.size() - k; i++){
        int tmp_res = 0;
        string sub_str = s.substr(i, k);
        for (auto c : sub_str){
            if (vowels.find(c) != vowels.end()){
                tmp_res++;
            }
        }
        if (tmp_res > max_res){
            max_res = tmp_res;
        }
    }
    return max_res;
}
=======
//
// Created by 26236 on 2023/5/5.
//

#include <bits/stdc++.h>
using namespace std;
int maxVowels(string s, int k);

int main(){
    string main_str = "abciiidef";
    string main_str1 = "aeiou";
    string main_str2 = "leetcode";
    int k = 3, k1 = 2, k2 = 3;
    printf("main_str: %d, main_str1: %d, main_str2: %d\n", maxVowels(main_str,k),maxVowels(main_str1,k1),maxVowels(main_str2,k2));

}


int maxVowels(string s, int k){
    // the sliding windows shouldn't start counting newly each time, but updating the increment and decrement at two ends
    int count=0, res = 0; // init all the values
    unordered_set<char> vowels{'a','e','i','o','u'};
    for (int i = 0; i < k; i++){
        count += vowels.count(s[i]);
    }
    res = count;
//    int tmp_res;
    for (int i = k; i < s.size(); i++){
        count = count + vowels.count(s[i]) - vowels.count(s[i-k]);
//        tmp_res = res + vowels.count(s[i]) - vowels.count(s[i-k]);
        res = max(res, count);
    }
    return res;
}

/*
int maxVowels(string s, int k){ // this answer exceeds the running time
    set<char> vowels;
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
    int max_res = 0;
    // using the sliding windows to solve the problem
    for (int i = 0; i <= s.size() - k; i++){
        int tmp_res = 0;
        string sub_str = s.substr(i, k);
        for (auto c : sub_str){
            if (vowels.find(c) != vowels.end()){
                tmp_res++;
            }
        }
        if (tmp_res > max_res){
            max_res = tmp_res;
        }
    }
    return max_res;
}
>>>>>>> 0f624ce6372e51a14920d90879008100a776bbc5
*/
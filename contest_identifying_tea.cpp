<<<<<<< HEAD
//
// Created by 26236 on 2023/6/18.
// for internal contest, prob A identifying tea
// input line 1: int T, the correct tea number
// input line 2: vector of answers provided
// output: number of contestants getting the right answer
//
#include <bits/stdc++.h>
using namespace std;

//int id_tea(int T, vector<int>& ans);

int main(){
    // test case 1
    while(1){
        int T_main;
        int a;
        int correct = 0;

        int ret = scanf("%d", &T_main);
        if (ret != 1){
            break;
        }
        for (int i = 0; i <5; i++){
            scanf("%d", &a);
            if (a == T_main){
                correct++;
            }
        }
        cout<<correct<<endl;
    }
    return 0;
}

//int id_tea(int T, vector<int>& ans){
//    int correct = 0;
//    for (auto i = ans.begin(); i != ans.end(); i++){
//        if (*i == T){
//            correct++;
//        }
//    }
//    return correct;
//}
=======
//
// Created by 26236 on 2023/6/18.
// for internal contest, prob A identifying tea
// input line 1: int T, the correct tea number
// input line 2: vector of answers provided
// output: number of contestants getting the right answer
//
#include <bits/stdc++.h>
using namespace std;

//int id_tea(int T, vector<int>& ans);

int main(){
    // test case 1
    while(1){
        int T_main;
        int a;
        int correct = 0;

        int ret = scanf("%d", &T_main);
        if (ret != 1){
            break;
        }
        for (int i = 0; i <5; i++){
            scanf("%d", &a);
            if (a == T_main){
                correct++;
            }
        }
        cout<<correct<<endl;
    }
    return 0;
}

//int id_tea(int T, vector<int>& ans){
//    int correct = 0;
//    for (auto i = ans.begin(); i != ans.end(); i++){
//        if (*i == T){
//            correct++;
//        }
//    }
//    return correct;
//}
>>>>>>> 0f624ce6372e51a14920d90879008100a776bbc5

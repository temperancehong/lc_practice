//
// Created by 26236 on 2023/6/27.
//

#include <bits/stdc++.h>
using namespace std;

int start5(int n){
    return 1;
}

int start4(int n){
    if (n == 1){
        return 1;
    }
    else{
        return start4(n-1) + start5(n-1);
    }
}

int start3(int n){
    if (n == 1){
        return 1;
    }
    else{
        return start3(n-1) + start4(n-1) +start5(n-1);
    }
}

int start2(int n){
    if (n == 1){
        return 1;
    }
    else{
        return start2(n-1) + start3(n-1) + start4(n-1) +start5(n-1);
    }
}

int start1(int n){
    if (n == 1){
        return 1;
    }
    else{
        return start1(n-1) + start2(n-1)+ start3(n-1) + start4(n-1) +start5(n-1);
    }
}


int countVowelStrings(int n) {
    return start1(n)+start2(n)+start3(n)+start4(n)+start5(n);
}

int main(){
    int res = countVowelStrings(2);
    cout<<res<<endl;

}
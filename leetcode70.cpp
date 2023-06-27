<<<<<<< HEAD
//
// Created by 26236 on 2023/6/18.
//

#include <bits/stdc++.h>
using namespace std;

int climbing_stairs(int n);


int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    int res = climbing_stairs(n);
    cout<<res<<endl;

    return 0;
}

int climbing_stairs(int n){
    int prev1 = 0;
    int prev2 = 1;
    int prev3 = 2;
    int curr;

    if (n==0){
        return prev1;
    }
    else if (n==1){
        return prev2;
    }
    else if (n==2){
        return prev3;
    }

    for (int i = 3; i <= n; i++){
        curr = prev2 + prev3;
        prev1 = prev2;
        prev2 = prev3;
        prev3 = curr;
    }
    return curr;
}


=======
//
// Created by 26236 on 2023/6/18.
//

#include <bits/stdc++.h>
using namespace std;

int climbing_stairs(int n);


int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    int res = climbing_stairs(n);
    cout<<res<<endl;

    return 0;
}

int climbing_stairs(int n){
    int prev1 = 0;
    int prev2 = 1;
    int prev3 = 2;
    int curr;

    if (n==0){
        return prev1;
    }
    else if (n==1){
        return prev2;
    }
    else if (n==2){
        return prev3;
    }

    for (int i = 3; i <= n; i++){
        curr = prev2 + prev3;
        prev1 = prev2;
        prev2 = prev3;
        prev3 = curr;
    }
    return curr;
}


>>>>>>> 0f624ce6372e51a14920d90879008100a776bbc5

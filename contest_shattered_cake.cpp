//
// Created by 26236 on 2023/6/18.
// input first line: the width of the cake
// input second line: number of pieces damaged
// input lines: width and lines of the pieces
// output line: length of the cake
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    while (1){
        int W;
        int N;
        int surface = 0;
        int retW;
        int l, w;
        retW = scanf("%d", &W);
//        printf("W: %d\n", W);
        if (retW != 1){ // end of test cases
            break;
        }
        scanf("%d",&N);
//        printf("N: %d\n", N);

        for (int i = 0; i < N; i++){
            scanf("%d %d", &l, &w);
            surface += l * w;
//            printf("surface: %d\n", surface);
        }
        int L;
        L = surface / W;
        cout << L <<endl;
    }

    return 0;
}

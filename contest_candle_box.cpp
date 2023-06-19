//
// Created by 26236 on 2023/6/19.
// first input line: age difference
// second input line: candle in Rita
// third input line: canlde in Theo

#include <bits/stdc++.h>
using namespace std;

int main(){
    while (1){
        int D, R, T;
        int retD = scanf("%d",&D);
        if (retD != 1){// end of testing loop
            break;
        }
        scanf("%d", &R);
        scanf("%d", &T);
//        printf("%d-%d-%d\n",D, R, T);
        int ageR, ageT;


        for (int i=4; i <= 1000; i++){
            int sumR = 0;
            int sumT = 0;
            for (int j = 4; j<= i; j++){
                sumR += j;
            }
            for (int k = 3; k <= i-D; k++){
                sumT += k;
            }
            int total;
            total = sumR + sumT;
//            printf("Total candles: %d\n", %total);
            if (total == R + T){
                ageR = i;
                ageT = ageR - D;
//                printf("age of Rita: %d, age of Theo: %d\n", ageR, ageT);
                int res;
                res = R - sumR;
//                printf("Should put back %d candles\n", res);
                cout<<res<<endl;
                break;

            }
        }


//        ageR = D + 2 + sqrt(-D*D -6*D + 40 + 4*R+4*T);
//        printf("age of Rita: %d, age of Theo: %d\n", ageR, ageT);
    }
    return 0;

}



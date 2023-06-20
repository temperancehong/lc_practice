//
// Created by 26236 on 2023/6/20.
//

#include <bits/stdc++.h>
using namespace std;

int change_state(int old_state){
    if (old_state == 0){
        return 1;
    }
    else
        return 0;
}

int main(){
    while (1){
        int N;
        long B;
        int retNB = scanf("%d %ld", &N, &B);

        if (retNB!=2){
            break; //end of test
        }
        vector<int> v_states;
        int curr_state;
        for (int i = 0; i < N; i++){
            scanf("%d",&curr_state);
            v_states.push_back(curr_state);
        }
        vector<int> v_states_old = v_states;
        for (long t = 0; t < B; t++){
            for (int i = 0; i < N; i++){
                if (i==0){// the first element depends on the last
                    if (v_states_old[N-1] == 1){
                        v_states[0] = change_state(v_states_old[0]);
                    }
                }
                else
                    if (v_states_old[i-1] == 1){
                        v_states[i] = change_state(v_states_old[i]);
                    }
            }
            v_states_old = v_states;
        }
        cout<<"\n"<<endl;
        for (int i = 0; i < N; i++){
            cout<<v_states[i]<<endl;
        }

    }

    return 0;
}

//
// Created by 26236 on 2023/5/4.
//
#include <bits/stdc++.h>
using namespace std;
string predictPartyVictory(string senate);

int main(){
    string main_senate = "RDD";
    string res = predictPartyVictory(main_senate);
    printf("%s\n", res.c_str());
}

string predictPartyVictory(string senate){
    // the greedy method is to ban the next opposing senate in line
    // when banning a member from opposing senate, we delete it from the string
    // we keep count of the index of the current senate that we're looking at

    // keep count of the number of senate that each party has
    int rCount = count(senate.begin(), senate.end(), 'R');
    int dCount = senate.size() - rCount;

    auto ban = [&](char toBan, int startAt){
        bool loopAround = false; // set the bool value to whether keep the current index or advance
        int currSenate = startAt;
        while (true){
            if (currSenate == 0){
                loopAround = true; // meaning it started over again returning to 0
            }
            if (senate[currSenate] == toBan){
                senate.erase(senate.begin() + currSenate);
                break; // break out of the while loop that is searching for the element
            }
            currSenate = (currSenate + 1) % senate.size(); // so that it doesn't exceed the string
        }
        return loopAround;
    };
    int tour = 0; // keep in track of the current senator
    while (rCount > 0 && dCount >0){
        // while there is still no winner
        if (senate[tour] == 'R'){
            // it's R's turn to ban senators
            bool loopedAround = ban('D', (tour + 1) % senate.size());
            dCount--;
            if (loopedAround){
                tour--;
            }
        }
        else{
            bool loopedAround = ban('R', (tour + 1) % senate.size());
            rCount--;
            if (loopedAround){
                tour--;
            }
        }
        tour = (tour + 1) % senate.size();
    }
    return dCount == 0 ? "Radiant" : "Dire";

}

/* my methode that passed 74/83 cases
string predictPartyVictory(string senate) {
    if (senate == "RD" || senate == "R"){
        return "Radiant";
    }
    else if (senate == "DR" || senate == "D"){
        return "Dire";
    }
    else{
        int numD = 0;
        int numR = 0;
        for (int i = 0; i < senate.size(); i++){
            if (senate[i] == 'R'){
                numR++;
            }
            else if (senate[i] == 'D'){
                numD++;
            }
        }
        if (senate.size() == 3){
            if (numD > numR){
                return "Dire";
            }
            else{
                return "Radiant";
            }
        }
        else if (senate[0] == 'R'){
            if (numR >= numD -1){
                return "Radiant";
            }
            else return "Dire";
        }
        else{
            if (numD >= numR -1){
                return "Dire";
            }
            else return "Radiant";
        }
    }
}

 */
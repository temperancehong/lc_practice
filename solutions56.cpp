//
// Created by 26236 on 2023/3/2.
//
#include "solutions56.h"

/*
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 */

vector<vector<int>> merge(vector<vector<int>>& intervals){
    // first sort according to the first element of the interval
    //try insertion sort first
    vector<int> tmpV;
    for (int i = 1; i < intervals.size(); i++){
        for (int j = i; (j > 0) && (intervals[j][0] < intervals[j-1][0]); j--){
            //swap
            tmpV = intervals[j];
            intervals[j] = intervals[j-1];
            intervals[j-1] = tmpV;
        }
    } // end of sorting


    /* Working backwards */
    vector<int> tmpV2;
    vector<vector<int>> intervals2; // the second chunk of the vector
    for (int i = intervals.size()-1; i > 0; i--){
        // check if the first element of the next interval is smaller or equal to the second element of this interval
        if(intervals[i][0] <= intervals[i-1][1]){ //overlapping case
            // find the larger second element
            if (intervals[i-1][1] >= intervals[i][1]){ // the former one completely includes the second one
                tmpV2 = {intervals[i-1][0], intervals[i-1][1]};
            }
            else{// overlapping but not including case
                tmpV2 = {intervals[i-1][0], intervals[i][1]};
            }
            intervals.pop_back();
            intervals.pop_back(); // pop the two out
            intervals.push_back(tmpV2); // push the processed result in
            // the process of i-- will happen and move to the next procedure naturally
        }
        else{ // non overlapping case
            tmpV = intervals[i]; // save the last one
            intervals.pop_back();
            intervals2.push_back(tmpV); // push the saved interval into the second part of the vector(a new vector)
        }
    }// now all arranged in ideal situation, but scattered in two separate intervals vector: intervals & intervals2
    while (!intervals2.empty()){ // while the second half is not exhausted
        // need to pop and push into the first one
        int n = intervals2.size();
        tmpV = intervals2[n-1];
        intervals2.pop_back();
        intervals.push_back(tmpV);
    }

    /* Working forwards */
    vector<int> tmpV3;
    int startPos = 0; // the start position of the interval first chunk of the vector intervals
    for (int i = 0; i < intervals.size() -1 ; i++){ //  we need n-1 cuz we check the NEXT interval
        // check if the next interval's first element is smaller than or equal the second element of this one
        if (intervals[i+1][0] <= intervals[i][1]){ // overlapping case
            // find the larger second element
            if (intervals[i][1] >= intervals[i+1][1]){ // including case
                tmpV3 = {intervals[i][0], intervals[i][1]};
            }
            else{ // overlapping but not including case
                tmpV3 = {intervals[i][0], intervals[i+1][1]};
            }
            intervals[i+1] = tmpV3;
            startPos++; // move the start position to the new place
        }
    }
    vector<vector<int>> res(intervals.begin()+startPos, intervals.end());

    return res;

}

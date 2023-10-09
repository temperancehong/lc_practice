//
// Created by 26236 on 2023/7/19.
//

#include <bits/stdc++.h>
using namespace std;


// outside solution class, or static bool
bool compareEndInterval(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals){
    int res = 0;
    int k = INT_MIN;
    // sort the vectors according to the second/ending element
    sort(intervals.begin(), intervals.end(), compareEndInterval);
    for (int i = 0; i < intervals.size(); i++){
        if (intervals[i][0] >= k){
            k = intervals[i][1];
        }
        else{
            res++;
        }
    }

    return res;
}

// /* false response */
//int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//    vector<int> length;
//    for (auto interval: intervals){
//        length.push_back(interval[1]-interval[0]);
//    }
//
//
//    vector<int> start, end;
//    int erase_count = 0;
//    for (auto interval : intervals){
//        int overlap_flag = 0;
//        if (start.size() == 0){
//            start.push_back(interval[0]);
//            end.push_back(interval[1]);
//            continue;
//        }
//        for (int i = 0; i < start.size(); i++){
//            if ((interval[0] >= start[i] && interval[0] < end[i])||(interval[1] > start[i] && interval[1] <= end[i])){
//                erase_count++; // overlapped
//                overlap_flag = 1;
//                break; // break from iterating the existing intervals
//            }
//        }
//        if (overlap_flag == 0){
//            start.push_back(interval[0]);
//            end.push_back(interval[1]);
//        }
//    }
//    return erase_count;
//}

int main(){
    vector<vector<int>> test1 = {{1,2},{2,3}};
    vector<vector<int>> test2 = {{1,2},{2,3},{3,4},{1,3}};
    vector<vector<int>> test3 = {{1,2},{1,2},{1,2}};
    vector<vector<int>> test4 = {{1,2},{3,4},{4,6},{7,8},{1,3}};
    vector<vector<int>> test5 = {{1,100},{11,22},{1,11},{2,12}};
    int res1 = eraseOverlapIntervals(test1), res2 = eraseOverlapIntervals(test2),res3 = eraseOverlapIntervals(test3),res4 = eraseOverlapIntervals(test4),res5 = eraseOverlapIntervals(test5);
    printf("res1: %d, expected: 0\n", res1);
    printf("res2: %d, expected: 1\n", res2);
    printf("res3: %d, expected: 2\n", res3);
    printf("res4: %d, expected: 1\n", res4);
    printf("res5: %d, expected: 2\n", res5);
    return 0;
}
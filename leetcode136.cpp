#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int len = nums.size();
    int double_flag = 0;
    for (int i = 0; i < len; i++){
        if (i == len - 1){
//            printf("The single number is %d", nums[i]);
            return nums[i];
        }
        double_flag = 0;
        for (int j = i + 1; j < len; j++){
            if (nums[i] == nums[j]){
//                printf("%d appears for the second time\n",nums[i]);
                swap(nums[j], nums[i+1]);
                i++;
                double_flag = 1;
            }
            if (j == len-1 && double_flag == 0){
                return nums[i];
            }
            if (double_flag == 1){break;}
        }
    }
    return 0;
}

int main() {

//    vector<int> nums = {1,2,1,2,3,3,4,6,5,5,6};
    vector<int> nums = {1,1,2,3,4,5,4,5,3,-1,2};
    int single = singleNumber(nums);
    printf("The number is : %d\n",single);
    return 0;
}

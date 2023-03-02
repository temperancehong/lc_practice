#include <iostream>
#include "solutions75.h"
#include <vector>
using namespace std;

int main() {
//    std::cout << "Hello, World!" << std::endl;
    vector<int> main_nums = {2,0,2,1,1,0};
    sortColors(main_nums);
    for (int i = 0; i < main_nums.size(); i++){
        printf("%d ", main_nums[i]);
    }
    printf("\n");


    return 0;
}

# Readme
Hello to my place for coding practice. I'm a beginner trying to code better.


# Notes
Notes taken from each problem, classified by the theme of the problems.

## Dynamic Programming
### Leetcode 198 - house robbers

The following code, which takes every two houses to rob, does not pass because we can have `[2,1,1,2]`
, we cannot say one after the other is the best in this case.
```c++
int rob(vector<int>& nums) {
    int n = nums.size();
    int sum1=0, sum2=0;
    for (int i=0; i<n;i+=2){
        sum1+=nums[i];
    }
    for (int i=1; i<n;i+=2){
        sum2+=nums[i];
    }
    if (sum1 >= sum2){
        return sum1;
    }
    else return sum2;
}
```

The subproblem or the recursive problem can be written as following:
```text
rob=max(arr[0]+rob[2:n], rob[1:n])
```
Either we rob the first one and starting from the one skipping the middle,
either we don't rob the first one but we start from the second one.

Using dynamic programming, we can see that the subproblem can be 
that with an array `[1 2 3 1]`, we either choose robbing `1+rob([3,1])`, or we choose `rob([2 3 1])`
. We take the maximum of this.

We initialize this problem two variables storing the two choice values. and the answer is
```c++
int rob(vector<int>& nums) {
    int n = nums.size();
    //[rob1, rob2, nums[i]]
    int rob1=0, rob2=0;
    for (int i=0; i < n; i++){
        int tmp = max(nums[i]+rob1, rob2);
        rob1=rob2;
        rob2=tmp;
    }
    return rob2;
}
```
With the help of video by Neetcode.


## Two pointers
### Leetcode121 - Best time to buy and sell stocks

Time moves in one direction. We do it with the technic of two pointers.
Initialize the Left pointer and Right pointer from the first and second element in the array.
When it is a lost, we move both the left and right to the right for 1 element.

When it's buying low and selling high, we can move just the right pointer.

Mind the case `[2,1,2,1,0,1,2]`. That once we met a negative profit, 
we need to update the left pointer to the position of the right pointer instead of just +1.

The following code passes. With the help of Neetcode.
```c++
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    if (n==1) return 0;
    int left=0, right=1;
    int max_profit=0;
    for (right=1;right<n;right++){
        if (prices[right]-prices[left]<0){
            left=right;
            continue; // means that right++ already
        }
        else if (prices[right]-prices[left]>max_profit){
            // update the profit
            max_profit=prices[right]-prices[left];
        }
    }
    return max_profit;
}
```
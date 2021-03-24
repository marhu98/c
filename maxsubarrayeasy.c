#define false 0
#define true 1

int max(int a, int b){
    return a>b ? a : b;
}

int maxSubArray(int* nums, int numsSize){

    int maxSum = nums[0], candSum = 0;
    
    for (int i = 0; i<numsSize; i++){
        if (candSum < 0 ){
            candSum = 0;
        }
        candSum +=nums[i];
        maxSum = max(candSum,maxSum);
    }
    
    
    return maxSum;

}

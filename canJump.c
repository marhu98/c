bool canJump(int* nums, int numsSize){
    int good[numsSize];
    
    good[numsSize-1]=1;
    
    for (int i = numsSize-2; i>=0;i--){
        good[i]=0;
        for (int j=1; j<=nums[i];j++){
            if (i+j<numsSize && good[i+j]){
                    good[i]=1;
                    break;
                }
        }
    }
    
    return good[0];

}

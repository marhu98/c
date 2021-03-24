int jump(int* nums, int numsSize){
    int dist[numsSize];
    
    dist[0]=0;
    int k = 0;
    int max1 = nums[0];
    

    for (int j = 1; j<numsSize; j++){

        while(j-k>max1){
            max1 = nums[++k];
        }
        
        dist[j]=1+dist[k];
        
    }
    
    return dist[numsSize-1];
}

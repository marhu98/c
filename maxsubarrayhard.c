#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0


typedef struct node {
    int val;
    struct node * next;
} node_t;


void printList(node_t * head){
    printf("\n\n");
    node_t * current = head;
    int i = 0;
    do {
        printf("IterationPrint %d %d\n",i++, current->val);
        current = current -> next;
    } while (current != NULL);
    
}

int maxSubArray(int* nums, int numsSize){
    printf("New call\n\n\n");
    int findPos = 0;
    
    
    if (numsSize == 0){
        return 0;
    } else if (numsSize == 1){
        return nums[0];
    }
    
    node_t * head = NULL;
    node_t * current = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head->next = NULL;
    current = head;
    current -> val = nums[0];
    
    for (int i = 0; i<numsSize; i++){
        //printf("%d %d\n",nums[i],current->val);
        // printf("%d",i); 
        if (!findPos && nums[i]>=0){
            findPos = true;
            current -> val = nums[i];
            // printList(head);

            //printf("Sum %d\n",sum);
            continue;
        }
        if (!findPos && nums[i]>current -> val){
            current -> val = nums[i];
        }
        
        if (findPos){
            int val = current->val;
            if (nums[i]<0){
                //printf("There %d\n",current -> val);
		//printf("Here");                
                current->next = (node_t *) malloc(sizeof(node_t));
                current = current->next;
                current->next = NULL;
                current -> val = val+nums[i];
            }  
            
            if (val+nums[i]>=0){
                current -> val =val+ nums[i];
            } else{
                //printf("Here %d\n",current -> val);
                current -> val = 0;
            }
                      
        }
        
        //printList(head);
        //printf("Sum %d\n",sum);
        
    }
    
    if (!findPos){
        return current -> val;
    }
    
    current = head;
    int max = current->val;
    int i = 0;
    //printf("%d",current->next == NULL);
    do {
        if (current->val>max){
            max = current->val;
        }
        current = current->next;
    } while (current != NULL);
    
    
    free(head);
    
    return max;

}


int main(){
	int test1[] = {-2,1,-3,4,-1,2,1,-5,4};
	int test2[] = {8,-19,5,-4,20};
	
	if (maxSubArray(test1,9)!=6){
		printf("Test 1 failed");
		return false;
	} else if (maxSubArray(test2,5)!=21){
		printf("Test 2 failed, output was: %d",maxSubArray(test2,5));
		return false;
	}

	printf("Everything alright");
	return true;
}

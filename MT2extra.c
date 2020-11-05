int ReverseArray(int array[], int arraySize){
    int start = 0;
    int right = arraySize - 1;
    if (start <= right){
        return 0;
    }
    int tmp = array[start];
    array[start] = array[right];
    array[right] = tmp;
    return ReverseArray(array+1, arraySize-2); //similar to prac 1 and dunno why is -2
}

int dotProduct(int vectorA[], int vectorB[], int vectorLength){
    int dotprosum = 0;
    for (int i = 0; i< vectorLength; i++){
        int tmp = vectorA[i]*vecotrB[i];
        dotprosum += tmp;
    }
    return dotprosum;
}

int largestSubarray(int *A, int start, int end){
    //returns the size of the largest subarray
    //if no such subarray, returns 0
    if (start == end){
        return 0;
    }
    int i;
    int c1, c0;
    c1 = 0;
    c0 = c1;
    for(i=start; i<=end; i++){
        if (A[i] == 0){
            c0 += 1;
        }
        else{
            c1 += 1;
        }
    }
    if (c1 == c0){
        return (end-start+1);
    }
    int a = largestSubarray(A, start+1, end);
    int b = largestSubarray(A, start, end-1);
    if (a>=b){
        return a;
    }
    return b;
}

int findpair(int array[], int start, int end){
    if (start == end){
        return 0;
    }
    int i;
    int comp = array[start];
    if(comp>0){
        for (i = start+1; i<=end;i++){
            if (array[i] == comp){
                array[i] = -1;
                array[start] = -1;
                return findpair(array, start+1,end)+1;
            }
        }
    }
    return findpair(array, start+1, end);
}

int main()
{
    int array[7] = {11,5,7,9,11,3,5};
    printf("%d\n", findpair(array,0,6));
    for (int i = 0; i<7; i++){
        printf("%d ",array[i]);
    }
}

//runtime stack
xBCD1   d
xBCD2   c
xBCD3   frame pointer
xBCD4   return address
xBCD5   return value
//part B
xBCD6   x           ;R6 points here
xBCD7   n 
//part A
xBCD8   x[0] = 1    ;R6 points here
xBCD9   x[1] = 3
xBCDA   x[2] = 5
xBCDB   n = 3       ;R5 points here 

//callee setup
ADD R6, R6, #-5     ;allocating space for bookkeeping + local var
STR R5, R6, #3      ;stores frame pointer
STR R7, R6, #4      ;stores return address
ADD R5, R6, #1      ;R5 goes to the bottom of local variable

//function logic
AND R0, R0, #0      ;represents variable d
STR R0, R6, #1      ;initializes c to 0
STR R0, R6, #0      ;initializes d to 0
AND R2, R2, #0      ;represents variable c
LDR R1, R6, #6      ; 
NOT R1, R1
ADD R1, R1, #1      ;R1 stores the negative of b
ADD R3, R0, R1      ;checking while loop condition
BRzp    BREAK       ;d>=b
ADD R4, R6, #9      ;loads R4 with the first element of the ReverseArray
ADD R4, R4, R2      ;accessing the desire index      
LDR R4, R4, #0      ;
ADD R2, R4, R2      ;
ADD R0, R0, #1      ;incrementing 'd'

BREAK 
//callee teardown
STR R2, R6, #4      ;pushing return value into the stack
LDR R5, R6, #2      ;restoring frame pointer
LDR R7, R6, #3      ;restoring return address
ADD R6, R6, #5      ;clearing the stack
RET

int ReverseArray(int array[], int arraySize){
    int start = 0;
    int right = arraySize - 1;
    if (start <= right){
        return 0;
    }
    int tmp = array[start];
    array[start] = array[right];
    array[right] = tmp;
    return ReverseArray(array+1, arraySize-1);
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
    int count = 0;
    int boo = 1;
    while(boo){
        int a = array[start];
        int b = array[end];
        if (a == b){
            array[start] = -1;
            array[end] = array[start]-1;
            count += 1;
            break;
        }
    }
    int x = findpair(array, start+1,end)+count;
    int y = findpair(array, start, end-1)+count;
    if (x>=y){
        return x;
    }
    return y;
}

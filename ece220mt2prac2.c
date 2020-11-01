//P1 Find max profit
//function finds the maximum profit of buying a stock on a certain day a
//and selling it later

//inputs: array of prices of stock corresponding to day
#include<stdio.h>
int maxProfit(int *prices, int n){
    int i,j,buy,sell,profit,tmp;
    for (i = 0; i<n; i++){
        buy = prices[i];
        for(j=i; j<n; j++){
            sell = prices[j];
            tmp = sell - buy;
            if (tmp>profit)profit = tmp;
        }
    }
    return profit;
}

int main(){
    int prices[6] = {2,7,3,1,2,8};
    int n = 6;
    printf("%d", maxProfit(prices, n));
}

//P3 Permutation using swap function
void swap(char* a, char* b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void permutation(char *s, int left, int right){
    int i;
    if(left == right){
        printf("%s\n",s);
    }
    else{
        for (i = left, i<right, i++){
            swap(s[i],s[0]);
            permutation(s, left+1, right);
            swap(s[i],s[0]);
        }
    }
}

//P3 partC
DEF
DFE
EDF 
EFD 
FDE 
FED

//P4 concepts
//PartA
Problem happens at line12
printf("%p\n",arr2[i]);

//partB
int binarySearch(int arr[], int start, int end, int item){
    if (end>=start){
        int mid = (end+start)/2;
        if (arr[mid]==item)return mid;
        if(arr[mid]>item)return binarySearch(arr[],mid+1,end,item);
        return binarySearch(arr[], start,mid, item);
    }
    return -1;
}

//PartC
A 2D array is stored in memory in the form of double pointers int** 2darray.
The first pointer points to an array of pointers, which points to the 1D arrays
The second pointer points to the elements in the 1D array.

//PartD
The code compiler will crashes and gives the exception, exceeds recursion depth.
This means that it steps into an infinite loop and runs out of memory.
#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    float result[n];
    int profits[n];
    int weights[n];

    // Taking inputs

    for(int i = 0; i < n; i++){
        scanf("%d",&profits[i]);
    }

    for(int i = 0; i < n; i++){
        scanf("%d",&weights[i]);
    }

    // Profit / weight ratio

    for(int i = 0; i < n; i++){
        result[i] = ((float)profits[i] / (float)weights[i]);
    }

    // Sorting the datas in ascending order

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            int temp;
            temp = result[j];
            result[j] = result[j + 1];
            result[j + 1] = temp;

            int temp1;
            temp1 = profits[j];
            profits[j] = profits[j + 1];
            profits[j + 1] = temp1;

            int temp2;
            temp2 = weights[j];
            weights[j] = weights[j + 1];
            weights[j + 1] = temp2;
        }
    }

    // Display

    for(int i = 0; i < n ; i++){
        printf("%d\n",result[i]);
        printf("%d\n",profits[i]);
        printf("%d\n",weights[i]);
    }

    // Enter knapsack capacity

    int capacity;
    printf("Enter knapsack capacity\n");
    scanf("%d",&capacity);

    int currentWeight = 0;
    float maxProfit = 0.0;
    float remainingCapacity;

    // Calculating maximum profit
    for(int i = 0; i < n; i++){
        if(currentWeight + weights[i] <= capacity){
            currentWeight = currentWeight + weights[i];
            maxProfit = maxProfit + profits[i];
        }else{
            remainingCapacity = capacity - currentWeight;
            maxProfit += (remainingCapacity / weights[i]) * profits[i];
            break;
        }
    }

    printf("Max profit from the knapsack is\n");
    printf("%f ", maxProfit);
    return 0;
}

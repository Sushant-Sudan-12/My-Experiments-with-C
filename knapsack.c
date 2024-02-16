#include<stdio.h>

int max(int a , int b){
    if(a>b){
        return a;
    }else {
        return b;
    }
}

int knapSack(int W,int wt[],int profit[],int n){
    int knap[n+1][W+1];
    int i,w;
    for (i = 0 ; i <= n;i++){
        for (w = 0 ; w <= W;w++){
            if(i==0||w==0)
                knap[i][w]=0;
            else if((wt[i-1]-w)<=0)
                knap[i][w] = max(profit[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
            else
                knap[i][w]=knap[i-1][w];
        }
    }
    return knap[n][W];
}




int main(){
    int wt[] = {15,45,10,7,18,36,28,21,16};
    int profit[] = {80,23,8,12,18,5,20,40,14};
    int load = 150;
    int n = sizeof(wt)/sizeof(wt[0]);
    printf("The solution is : %d",knapSack(load,wt,profit,n));
    return 0;
}



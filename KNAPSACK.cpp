#include <iostream>
#include<bits/algorithmfwd.h>
#include<bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }
/*int k1(int val[], int wt[], int n, int W)
{
    // matrix to store final result
    int mat[2][W+1];
    memset(mat, 0, sizeof(mat));

    // iterate through all items
    int i = 0;
    while (i < n) // one by one traverse each element
    {
        int j = 0; // traverse all wieghts j <= W

        // if i is odd that mean till now we have odd
        // number of elements so we store result in 1th
        // indexed row
        if (i%2!=0)
        {
            while (++j <= W) // check for each value
            {
                if (wt[i] <= j) // include element
                    mat[1][j] = max(val[i] + mat[0][j-wt[i]],
                                    mat[0][j] );
                else           // exclude element
                    mat[1][j] = mat[0][j];
            }

        }

        // if i is even that mean till now we have even number
        // of elements so we store result in 0th indexed row
        else
        {
            while(++j <= W)
            {
                if (wt[i] <= j)
                    mat[0][j] = max(val[i] + mat[1][j-wt[i]],
                                     mat[1][j]);
                else
                    mat[0][j] = mat[1][j];
            }
        }
        i++;
    }

    // Return mat[0][W] if n is odd, else mat[1][W]
    return (n%2 != 0)? mat[0][W] : mat[1][W];
}
int knapsack(int* weights, int* values, int n, int max){



return k1(values,weights,n,max);
}

//int kelp(int* weights, int* values, int n, int wm,)
*/
int knapsack(int* w, int* values, int n, int wm){

    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[wm+1];
    }

    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }

    for(int i=0;i<=wm;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;i<=wm;j++){
            dp[i][j]=dp[i-1][j];
            if(w[i-1]<=wm){
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i-1]]+values[i-1]);
            }
        }
    }
    int ret=dp[n][wm];
    for(int i=0;i<=n;i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ret;

}
int main()
{

    int n;
    cin>>n;
    int *w=new int[n];
    int *prof=new int[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>prof[i];
    }
    int wm;
    cin>>wm;
    cout<<knapsack(w,prof,n,wm);
    return 0;
}

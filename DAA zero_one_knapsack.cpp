#include<iostream>

using namespace std;

int main(){
    int capacity, items;
    
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    
    cout << "Enter the number of items: ";
    cin >> items;

    int price[items + 1], wt[items + 1];
    price[0] = 0;
    wt[0] = 0;

    cout << "Enter the price and weight of each item:\n";
    for(int i = 1; i <= items; i++){
        cout << "Item " << i << " - Price: ";
        cin >> price[i];
        cout << "Item " << i << " - Weight: ";
        cin >> wt[i];
    }

    int dp[items + 1][capacity + 1];

    for(int i = 0; i <= items; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(wt[i] <= j){
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";
    return 0;
}
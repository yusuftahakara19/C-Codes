#include <stdio.h>

/*

You are given the daily values of a company's stock traded on the stock market in an integer array. You want to maximize your profit by choosing a single day to buy a stock and a different day in the future to sell it. You cannot sell before buying, and you are limited to only one buy and one sell transaction.

Create an algorithm that finds the maximum profit achievable, and prints the day/value of the purchase, the day/value of the sale, and the profit. If no profit can be obtained, print the value 0.

Example:
Input:
n = 6, Prices = [7, 1, 5, 3, 6, 4]
Output:
Buy: Day 2, Value 1
Sell: Day 5, Value 6
Profit: 5

Note:
In the above example, buying on Day 2 and selling on Day 1 is not allowed, and a profit of 7 - 1 = 6 cannot be achieved.

Input:
n = 5, Prices = [7, 6, 4, 3, 1]
Output:
Profit: 0"

*/
void findMaxProfit(int prices[], int n) {
    if (n <= 1) {
        printf("Profit: 0\n");
        return;
    }

    int buy_day = 0, sell_day = 0;
    int max_profit = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int profit = prices[j] - prices[i];
            if (profit > max_profit) {
                max_profit = profit;
                buy_day = i + 1;
                sell_day = j + 1;
            }
        }
    }

    if (max_profit > 0) {
        printf("Buy: Day %d, Value %d\n", buy_day, prices[buy_day - 1]);
        printf("Sell: Day %d, Value %d\n", sell_day, prices[sell_day - 1]);
        printf("Profit: %d\n", max_profit);
    } else {
        printf("Profit: 0\n");
    }
}

int main() {
    int n;
    printf("Enter the number of days: ");
    scanf("%d", &n);

    int prices[n];
    printf("Enter the prices: ");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    findMaxProfit(prices, n);

    return 0;
}


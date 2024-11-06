#!/usr/bin/python3
"""
Change comes from within
Dynamic programming
Time Complexity O(n * m)
Space complexity O(total)
"""


def makeChange(coins: list, total: int) -> int:
    """
    Given a pile of coins of different values, determine the fewest
    number of coins needed to meet a given amount total.

    Args:
        coins (list): Is a list of the values of the coins in
                      your possession
        total (int):  Total number to reach

    Returns:
        int: Fewest number of coins needed to meet total
    """
    if total <= 0:
        return 0
    dp = [float('inf')] * (total + 1)
    dp[0] = 0
    for coin in coins:
        for i in range(coin, total + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)
    return dp[total] if dp[total] != float('inf') else -1


if __name__ == "__main__":
    coins = [507, 500, 300, 200, 6, 5, 4, 3]
    total = 1413
    print(makeChange(coins, total))

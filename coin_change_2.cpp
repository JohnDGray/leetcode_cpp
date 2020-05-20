/* Coin Change 2 */

/* You are given coins of different denominations and a total amount of */
/* money. Write a function to compute the number of combinations that */
/* make up that amount. You may assume that you have infinite number of */
/* each kind of coin. */
/* Note: */
/* You can assume that */
/* 0 <= amount <= 5000 */
/* 1 <= coin <= 5000 */
/* the number of coins is less than 500 */
/* the answer is guaranteed to fit into signed 32-bit integer */
/* Example 1: */
/* Input: amount = 5, coins = [1, 2, 5]Output: 4 */
/* Explanation: there are four ways to make up the amount: */
/* 5=5 */
/* 5=2+2+1 */
/* 5=2+1+1+1 */
/* 5=1+1+1+1+1 */
/* Example 2: */
/* Input: amount = 3, coins = [2] */
/* Output: 0 */
/* Explanation: the amount of 3 cannot be made up just with coins of 2. */
/* Example 3: */
/* Input: amount = 10, coins = [10] */
/* Output: 1 */

#include <iostream>
#include <vector>

int coin_change2(int amount, std::vector<int> coins, int current){
  if (current >= coins.size()) {
    return 0;
  }
  if (amount == 0) {
      return 1;
  }
  if (amount < 0) {
    return 0;
  }
  int r1 = coin_change2(amount - coins[current], coins, current);
  int r2 = coin_change2(amount, coins, current + 1);
  return r1 + r2;
}

int coin_change(int amount, std::vector<int> coins){
  if (coins.size() == 0) {
    exit(1);
  }
  return coin_change2(amount, coins, 0);
}

void helper(int amount, std::vector<int> coins, int trial_num){
  int result = coin_change(amount, coins);
  std::cout << "Result " << trial_num << ":\n";
  std::cout << result;
  std::cout << std::endl;
}

int main(int argc, char *argv[])
{
  helper(5, {1, 2, 5}, 1); 
  helper(3, {2}, 2); 
  helper(10, {10}, 3); 
  return 0;
}

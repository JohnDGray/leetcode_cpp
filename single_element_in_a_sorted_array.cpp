/* Single Element in a Sorted Array */

/* Given a sorted array consisting of only integers where every element */
/* appears twice except for one element which appears once. Find this */
/* single element that appears only once. */
/* Example 1: */
/* Input: [1,1,2,3,3,4,4,8,8] */
/* Output: 2 */
/* Example 2: */
/* Input: [3,3,7,7,10,11,11] */
/* Output: 10 */
/* Note: */
/* Your solution should run in O(log n) time and O(1) space. */

#include <iostream>
#include <vector>

int single_el(std::vector<int> input){
  std::vector<int>::const_iterator beg = input.begin(), en = input.end();
  int first, second;
  while(beg != en){
    first = *beg++;
    if(beg == en){
      return first;
    }
    second = *beg++;
    if(first != second){
      return first;
    }
  }
  exit(1);
}

void helper(std::vector<int> input, int trial_num){
  int result = single_el(input);
  std::cout << "Result " << trial_num << ":\n";
  std::cout << result;
  std::cout << std::endl;
}

int main(int argc, char *argv[])
{
  std::vector<int> test_input = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  helper(test_input, 1);
  test_input = {3, 3, 7, 7, 10, 11, 11};
  helper(test_input, 2);

  return 0;
}

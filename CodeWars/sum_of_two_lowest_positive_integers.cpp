#include <vector>


long sumTwoSmallestNumbers(std::vector<int> numbers)
{
  sort(numbers.begin(),numbers.end());
  return numbers[0] + numbers[1];
}

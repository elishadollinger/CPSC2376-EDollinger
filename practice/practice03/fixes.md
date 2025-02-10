# CPSC2376-EDollinger
Bug #1 - Off by one error in "sumRange"
- What went wrong: The code was not including the "end" value. Instead of i<end, the for loop should have used "i <= end"
- Fix: I replaced the "i<end" in the for loop with "i<=end"

Bug #2 - Out of bounds error in "containsNegative"
- What went wrong: The for loop in "containsNegative" states for (size_t i = 0; i <= numbers.size(); i++). This causes an out of bounds exception that crashes the code, as the final number in a vector is one less than the actual size of the vector.
- How I fixed it: I changed this for loop to (size_t i = 0; i < numbers.size(); i++)

Bug #3 - Invalid check
- What went wrong: The for loop is only supposed to return true if there is a negative. However, the "if" statement states  "if (numbers[i] > 0)" instead of if "(numbers[i] < 0)"
- How I fixed it: I changed the if statement to "if(numbers[i]<0)"

Bug #4: Out of bounds exception in "findMax"
- What went wrong: The for loop in "findMax" starts at 1 and ends at the size of the vector. Instead, it should start at 0 and end at numbers.size()-1
- How I fixed it: I changed the for loop from for (size_t i = 1; i <= numbers.size(); i++) to for (size_t i = 0; i < numbers.size(); i++)

Bug #5: Returning "0" instead of "INT_MIN" for empty vectors in "findMax"
- What went wrong: The code returns 0 when there is an empty array. While this is not completely incorrect, it would not be effecient for vectors that actually had a max value of 0.
- How I fixed it: I fixed this bug by returning "INT_MIN" instead of 0 for empty arrays.

Bug #6: The condition "if (numbers[i] >= maxVal)" in "findMax"
- What went wrong: This states that if the is the same as the maxVal, then it is the maxVal. Instead, all we need is "if(numbers[i] > maxVal)"
- How I fixed it: I replaced "if (numbers[i] >= maxVal)" with if "(numbers[i] > maxVal)"

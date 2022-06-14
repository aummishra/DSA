Why LCS is not applicable?
Check Example 2,
word1 = "intention"
word2 = "exectution"
​
LCS = " e t i o n"
so according to lcs approach our answer should be LengthOf(word2) - LengthOfLCS
i.e, = 4
but answer is 5. because in our lcs approach we take the common subsequence and count all the other characters that are different and need to be deleted but in this we are asked to
find out number of characters to delete, insert or replace so that means if you are deleting something you need to add its replacement/insertion too somewhere else in our second string.
so it makes that total 2 operations and thus it is different than that.
​
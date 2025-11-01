# 📘 CSES Problem Set Notes

These are my notes for [CSES Problem Set](https://cses.fi/problemset/).  
Reading material on which the problemset is based: [**Competitive Programmer’s Handbook**](https://cses.fi/book/book.pdf).

---

## Introductory Problems:

1. **Weird Algo:** simply simulate the process  

2. **Missing Number:** make a set with all 1 to n, remove the inputs, one number left  

3. **Repetitions:** check at every letter it's occurences  

4. **Increasing Array:** at every index make the number >= previous  

5. **Permutations:** n=1 is always good, n=2 or 3 can never give solution, in all other cases just print all even numbers (last even would be >=4), then all odd numbers starting with 1 (diff b/w 1 and last even def. >1)  

6. **Number Spiral:** see that in extending a grid from x*x to (x+1)*(x+1) dimensions, we will be adding numbers in the range (x*x)+1 to (x+1)*(x+1), after this observation it's easy to see that the "controlling" number is the larger out of row and column given in question, using this info we can find the target in O(1) time.  

7. **Two Knights:** at any position, a knight can "disable" 2, 3, 4, 6, 8 squares depending on it's position, so we just need to substract these specific disabled configurations from total configurations, so total configurations possible are x*(x-1) where x is the number of squares on board, a knight on corners blocks 2 squares, knight in absolute center (of a large board) blocks 8, specific number of blockages can be calculated in O(1). Answer is divided by 2 to discount duplicates.  

8. **Two Sets:** sum of n natural numbers has to be divisible by 2 to have a "YES" case: in this case greedily pick the numbers to make up half the sum, remaining numbers form the second set.  

9. **Bit Strings:** Binary exponentiation  

10. **Trailing Zeros:** 0 is created by multiplication of 2 and 5, multiples of 2 will be much higher than that of 5, so number of 5's control the answer, therefore in prime factorization of factorial we need to find the number of 5s - which is our answer.  

11. **Coin Piles:** In every turn 3 coins are reduces in total, so the total number of coins has to be divisible by 3 if we want to empty them together, also, we need to see that difference in number of coins is not too large: you keep removing 1 coin from smaller lot and 2 coins from bigger and still you exhaust the smaller lot then the answer is not possible.  

12. **Palindrome Reorder:** Easy to see that no solution exists if multiple characters have odd frequency. If <=1 characters have odd frequency just keep them in middle and others can be half to the left - half to the right.  

13. **Gray Code:** answer for n=1 is {"0", "1"}, for n=2 and ahead what we can do is - we know that answer for previous n is correct, so in constructing answer for n, just copy in reverse order the answer for n-1 (since we have copied in reversed, we have in second half maintained the "correctness" of previous solution, also let's say X was the last string in n-1's answer, and we copied in reverse order so X is again followed by X - no difference here), so for n=2, till now we have: {"0", "1", "1", "0"} in the first half of this list there is already a difference of 1 digit so we have to paste the same digit in front to not have >=2 difference, now we have {"00", "01", "1", "0"}, in second half also we see that difference between each string is of one character, so we paste the same character now, list becomes: {"00", "01", "11", "10"} at the half junction the strings were same so we could add different character at the beginning.  

14. **Tower of Hanoi:** if there is just one disk, we can simply move it from "left" to "right" tower and problem is solved, if there are n disks, then let's say we somehow managed to move n-1 disks from left to the middle tower - we just have to move one disk from left to right (which is just one step, simple), for the n-1 disks that are now in "middle" - we can treat it as a fresh problem where n-1 disks are to be moved from middle to right using left.  

15. **Creating Strings:** Iterate through all permutations, use set to keep unique ones  

16. **Apple Division:** Try all possible divisions and output the min possible difference.  

17. **Chessboard and Queens:** try safely placing a queen in each row (try all possible columns, wherever you can place, pursue that solution further), if you are able to place a queen safely then you have reached a valid configuration and answer count increases by 1.  

18. **Raab Game 1:** An outright "NO" case is if sum of number of wins of both players is > number of moves. Now in every move three outcomes are "Draw"/"A wins"/"B wins" - we can tackle these one by one, if at any point we don't find a possible move - we know answer is not possible. Appropriate move can be selected greedily: we have canceled first Q numbers to satisfy the number of draws, now we want A moves where player 1 wins so let's get A biggest numbers from player 1 and A smallest numbers (out of those that are left after draws) from player 2, vice-versa we do for B moves where player 2 is supposed to win.  

19. **Mex Grid Construction:** Just traverse through each cell in n*n dimensions and check the previous numbers of same row and column, pick the smallest number that's not found in same row and column yet.  

20. **Knight Moves Grid:** do a BFS starting from (0, 0)  

21. **Grid Coloring 1:** A solution is always possible because there are 4 options per index so for any "central" index we can find a letter such that it doesn't match it's adjacent four indices. So just try 4 options at every index - whichever letter is possible try to put it and construct the solution further.  

22. **Digit Queries:** We can traverse in "blocks" and then our "query" can be transformed to a number and it's digit in that block. Block here is numbers with particular number of digits.  

23. **String Reorder:** when we start constructing our answer string, at every index we have two choices: place lexicographically smallest character (because this will help in creating lexicographic small string) OR a character with maximum frequency (assume a case where if I don't place character with max frequency, then in further indices I won't be able to ensure "no two adjacent characters are same" property), so at every index we just need to see if placing maximum frequency character is absolutely necessary or not - if it's absolutely necessary then place it, otherwise place the smallest character. No solution case occurs when we are unable to maintain the "no two adjacent..." property with any character selection for an index.  

24. **Grid Path Description:** We can do backtracking with pruning, so the optimisations that we can do are:  
    a. If you reach the target without visiting all cells, the path is not valid so no need to pursue it  
    b. At any position if the path given in question doesn't have '?' then just try the direction given there and not all directions  
    c. at any point if you can't move up and down but you can move either left or right, then see that whatever side we move to the other side will remain unvisited. Same thing happens when you can't move left and right but you can move up or down.  

    **Note 1:** CSES has extremely tight constraints, so even with the correct approach you can get TLE, in the committed solution see that I have commented some code at bottom - which has exact same logic but gets TLE, so had to do micro optimizations (what data type to use, global variables, etc...)  

    **Note 2:** The pruning idea is very well explained in the CP Handbook (chapter 5 - Complete Search), I have implemented the grid problem from book in `OtherProblemsFromBook/CompleteSearch_GridPathCount.cpp`

---

## Sorting and Searching:

1. **Distinct Numbers:** Use a set to keep count of distinct numbers.

2. **Apartments:** Greedy approach works best here, we can sort the desired size and actual sizes, now at every desired size we can skip the actual apartments that are small than current constraint (since thae arrays are sorted, if constraint for current index is not satisfied - no way it satisfies constraints for any thing later), if appropriate apartment found then assign it to the applicant and move forward.

3. **Ferris Wheel:** Greedy approach works here, we can sort the weights, start picking the highest weight and see if we can fit another weight.

4. **Concert Tickets:** Greedy approach works here, for every visitor try to assign them the highest priced ticket possible.
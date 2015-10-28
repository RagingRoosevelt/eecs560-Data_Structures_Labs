([lab index](https://github.com/RagingRoosevelt/eecs560-Data_Structures_Labs))

# Lab 7 - Min 5-heap

## Task overview

Construct a class for a Min 5-heap.  Build the initial tree using the bottom up method.  All 
multiple occurrences of values.  Include support for insert, delete min, delete max, remove.  
Whenever a specific value is removed, remove all instances of that value.

[Detailed description][pdf]
[pdf]: https://github.com/RagingRoosevelt/EECS_560-Data_Structures/blob/master/Lab07/Lab07_Assignment.pdf

## Discussion

I think I could have handled the level order printing more graciously.  I think there's probably a 
more efficient way to determine if an integer is, for some `n`, equal to `sum_{k=1}^n (r^k)` (which 
is the condition to determine if we should insert `\n` before printing the next value).

If I found the closed form `sum_{k=1}^n (5^k) = r^(n+1) / (r-1) - r / (r-1)`, set it equal to the 
current index and solved to get `n = Log_r (x * (r-1) + r) - 1` and checked if it had a decimal part 
or was an integer, I could have used that to determine if a line break were needed.

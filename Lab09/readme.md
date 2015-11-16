([lab index](https://github.com/RagingRoosevelt/eecs560-Data_Structures_Labs))

# Lab 9 - Skew heap, leftist heap, and performance testing for both

## Task overview

Construct classes for a leftist heap and a skew heap.  Both should support delete min, insert, 
pre-order printing, in-order printing, and level-order printing.  Each should have a nice cli menu
interface for each of those features and should populate the heap with values from `data.txt`.
Also, conduct a performance analysis test for `n` in {50000, 100000, 200000, 400000}, use a total of 
`n` values randomly chosen from the interval [1, 4n] to populate both heaps.  Time the insertion of 
these numbers starting from before the data is generated to once it has all been inserted.  Use five 
different seeds for the random number generator but use the same seed for both heaps.


[Detailed description][pdf]

[pdf]: https://github.com/RagingRoosevelt/EECS_560-Data_Structures/blob/master/Lab09/Lab09_Assignment.pdf

## Discussion

I think both heaps are without any bugs.  The when performing the level-order printing, I think 
there are probably more efficient ways to decide if a new line should be started due to descending 
a level in the tree.  The method I'm using is simple, though, and I didn't see a reason to implement
something more complicated.
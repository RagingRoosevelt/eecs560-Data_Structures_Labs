([lab index](https://github.com/RagingRoosevelt/eecs560-Data_Structures_Labs))

# Lab 2 - Binary tree

## Task overview

Implement a binary tree.  Read from a file assuming that the tree isn't full or complete.

[Detailed description][pdf]
[pdf]: https://github.com/RagingRoosevelt/EECS_560-Data_Structures/blob/master/Lab02/Lab02_Assignment.pdf

## Discussion

It seems I didn't test as many edge cases as needed.  This segfaults when there is just 1 element 
in the file (just a root).  This should be an easy fix in which you just be more careful when 
checking the child pointers when inserting.

Although it works, I'm not happy with how I read the tree in.  What I do is for each level, I start 
at the root and descend until I find the current level, then read in from the file and insert that 
element.  What I *should* do is just use an insert function that inserts an entire line at a time.
If the data file stored the tree as a full tree, then it would be easy since I could split the line,
pass to the children, split, pass, until there's just a single element at which point it would be 
time to insert the value.



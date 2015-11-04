([lab index](https://github.com/RagingRoosevelt/eecs560-Data_Structures_Labs))

# Lab 8 - Binary MinMax Heap

## Task overview

Construct a class for a binary minmax heap.  Include support for insert, deletemin, deletemax, 
and levelorder.  Read data from a hardcoded file.

[Detailed description][pdf]

[pdf]: https://github.com/RagingRoosevelt/EECS_560-Data_Structures/blob/master/Lab08/Lab08_Assignment.pdf

## Discussion

I added a remove function that removes all occurrences a specified value.  Code for bubbleup and 
trickledown were adapted from pseudocode in ["Min-Max Heaps and Generalized Priority Queues"][paper] 
(Atkinson, et al).

[paper]: http://dl.acm.org/citation.cfm?id=6621
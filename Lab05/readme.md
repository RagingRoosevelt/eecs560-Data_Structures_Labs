# Lab 5 - Binary search tree

## Task overview

Implement a binary search tree.  Read data from a file.

[Detailed description][pdf]
[pdf]: https://github.com/RagingRoosevelt/EECS_560-Data_Structures/blob/master/Lab05/Lab05_Assignment.pdf

## Discussion

I approached this with the goal of only handling nodes, not node values (especially in the removal 
function).  I came close to that goal but ended up using values in the deleteMin and deleteMax 
functions for the sake of convenience.

I'm not happy with the node removal function.  I think I might be able to simplify some of the 
checks I have to do (esp checking if I'm looking at the root or not) but I'm not going to bother 
with that now.
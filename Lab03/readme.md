# Lab 3 - Hash table with open hashing

## Task overview

Implement a hash table with open addressing.

[Detailed description][pdf]
[pdf]: https://github.com/RagingRoosevelt/EECS_560-Data_Structures/blob/master/Lab03/Lab03_Assignment.pdf

## Discussion

The one thing I wish I did differently was to handle rehasing within the data structure rather than 
letting whatever uses the data structure handle it.  I think that it varries by application which 
way makes more sense but in this case, it would have been better for the data structure to be more 
self-contained.

I seemed to have missed an edge case that comes from 1) inserting a value, 2) inserting a different 
value that has a hash collision and is then inserted via probing, 3) removing the first value that 
got inserted 4) inserting the second value again.  In this case, the insert function should notice 
the "deleted" flag and keep hunting for the value rather than seeing that the location is empty and 
then inserting the duplicate value.
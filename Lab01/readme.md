## Task overview

Implement a linked list.  Read the values in from a file.

[Detailed description](https://github.com/RagingRoosevelt/EECS_560-Data_Structures/blob/master/Lab01/Lab01_Assignment.pdf)

## Discussion

The way I read the file isn't very clean.  I probably should have just done (in `main.cpp`) is

    while (dataFile >> value)
    {
        list.insert(value);
    }
    
and that would have been a lot cleaner.
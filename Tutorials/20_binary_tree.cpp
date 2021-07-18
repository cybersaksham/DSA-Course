/*
Degree of each node must be less than or equal to 2
*/

/*
Types of Binary Tree:

1. Full / Strict Tree:
    All nodes have degree = 0 or 2 (not 1)

2. Perfect Binary tree:
    Internal nodes have 2 children & all leaf nodes must be at same level.

3. Complete Binary Tree:
    All level are completely filled except possibly the last level & last level must have its keys as left as possible.

4. Degenerate Tree:
    All parent nodes have exactly one child.

5. Skewed Tree:
    All nodes are left aligned (left-skewed) or right aligned (right-skewed)
*/

/*
Representation of Binary Tree:

1. Array Representation:
                    7
            11<-----|----->2
        7<--|              |-->9
    arr = [7, 11, 2, 7, NULL, NULL, 9]

2. Linked Representation:
                    7
            11<-----|----->2
        7<--|              |-->9
-------------------------------------------------------------
|                        l,7,r                              |
|               l,11,r<--|   |-->l,2,r                      |
|       l,7,r<--|    |           |   |-->l,9,r              |
|                   NULL        NULL                        |
|  All left & right pointers of leaf nodes point to NULL    |
-------------------------------------------------------------
*/
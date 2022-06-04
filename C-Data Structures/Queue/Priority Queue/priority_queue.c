/*

Queue in which elements are arranged according to the priority i.e ascending or descending
--->Each element has a priority
--->The element with highest priority will get deleted first
--->If two elements have same priority then FIFO principle will decide
--->Methods on Priority Queue 1. POLL() removes the highest priority element
                          2. ADD() inserts the element
--->Implementation of Priority Queue is done with the help of heap 1.Max 2.Min
--->The following are the applications of the priority queue:

1 It is used in the Dijkstra's shortest path algorithm.
2 It is used in prim's algorithm
3 It is used in data compression techniques like Huffman code.
4 It is used in heap sort.
5 It is also used in operating system like priority scheduling,
load balancing and interrupt handling.

In the above program, we have created the following functions:

>>int parent(int i): This function returns the index of the parent node of a child node, i.e., i.
>>int left_child(int i): This function returns the index of the left child of a given index, i.e., i.
>>int right_child(int i): This function returns the index of the right child of a given index, i.e., i.
>>void moveUp(int i): This function will keep moving the node up the tree until the heap property is restored.
>>void moveDown(int i): This function will keep moving the node down the tree until the heap property is restored.
>>void removeMax(): This function removes the element which is having the highest priority.
>>void insert(int p): It inserts the element in a priority queue which is passed as an argument in a function.
>>void delete(int i): It deletes the element from a priority queue at a given index.
>>int get_Max(): It returns the element which is having the highest priority, and we know that in max heap,
the root node contains the element which has the largest value, and highest priority.
>>int get_Min(): It returns the element which is having the minimum priority, and we know that in max heap,
the last node contains the element which has the smallest value, and lowest priority.


*/
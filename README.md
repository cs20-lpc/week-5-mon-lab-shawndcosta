# Week 5 Mon Lab

## Directions

You will be finishing the implementation of the DoublyList ADT as a linked list. The `DoublyList` abstract class is already given to you, along with the header file for the `DoublyList` class, and a skeleton of its implementation file. Many of the operations are already done for you. Your task is to complete the remaining three methods marked TO DO.

## Do not edit the driver.cpp file

You are also in charge of writing your own driver program to test your `DoublyList` class more extensively and submit the output to canvas. Be thorough with your testing by checking all the operations in different scenarios and with various data types. You can call your driver file any name (except don't use driver.cpp)

## Notes

- If you notice you are writing the same code (for example, get a node at a particular position in several methods then create a new method getNode to use everywhere. You need to edit the .hpp file  to include prototype and .tpp file for implementation. 
  
```C++
// return the node at the given position (argument)
Node* getNode(int) const;
```
- The `<<` stream insertion operator has been overloaded for the `DoublyList` class, meaning you can use `cout` on your `DoublyList` object to print out the nodes inside

# Linked list
This code is contains the C implementation of a simple linked list.

## Questions :

1. I implemented the bubble sort algorithm to sort the list as it's simple and quickly coded.
2. The sorting operation has a complexity of $O(n^{2})$ in the worst case and $O(n)$ in the best case.
3. The insert operation has a complexity of $O(n)$.

## Choices and motivation

At first glance, I did not exactly know how to implement the library. This is certainly because I am more familiar with C++ and thus did not see directly how a pointer to an instance of the list was requested in almost every function member. Then, after a little time of search, I came accross this [pattern](https://stackoverflow.com/a/1403926).

It became clear this was the way to go, with a structure containing the data members and the function members implemented as simple functions but with the first parameter containing a pointer to an instance of the structure.

I implemented some functions on top of what was requested :
* ```List_create_element``` to create a list element from only the only 3 key parameters (pointer to previous element, pointer to next element and pointer to item).
* A crawler function : ```List_crawl```; as crawling the list was requested in different functions.
* A display function : ```List_display``` for debugging and printing.
* A function to switch two elements within the list : ```List_switch```. This function is used by the sorting function.

## Encountered difficulties

It's the first time I created a makefile description file.

## Funny joke

Belgian summer 2023 was sunny.
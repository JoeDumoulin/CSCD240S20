# Assignment 4
In this assignment, you will create some programs using what you know about basic pointers and all the previous study you have done.  

You will need to successfully complete both problems for an A grade.  Completing one problem successfully is sufficient for a B grade.

### Problem 1 - String Length

Look at the ```stringlength``` function from Lecture 3.  Rewrite this function to use a pointer to find the length of a string instead of an array iterator. 

 Make sure you write a ```main``` function that tests your ```stringlength``` function.  Think carefully about what can go wrong with ```stringlength``` and how it should respond in each case.  For example, 

- What happens when the string is empty?  what should ```stringlength```return?
- What should happen if the string contains unprintable characters, should it return the length normally?  What if the string contains ```'\0'```?

Be creative.  Try to think of your own tests, and how the function should respond.  Be liberal with documenting what you are doing in the test function (this can be ```main``` or a separate test function called by ```main```).

### Problem 2 - 

Starting with the ```better_copy.c``` program, modify the program to use a dynamically allocated buffer for copying.  The dynamically allocated buffer should replace the statically allocated buffer defined on line 17.

Use ```malloc``` to allocate the buffer.  Look at the example of malloc from Lecture 5 and any of the text material for an understanding of usage.

You will need to include a new module at the top of the source file.  The new module is ```string.h``` and contains the defnitions for the functions ```malloc``` and ```free```.

Remember to include a call to ```free``` after the buffer is no longer needed.

Think about the issues with this approach.  free should be called as soon as possible after the buffer is no longer needed.  What happens in the case of an error?  What is the ideal result?

Remember that when the program exits the memory is freed anyway.  Why might we need to call free as a matter of discipline?  Under what circumstances is it necessary to call free?  We will talk about these questions in following lectures.


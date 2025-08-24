# ProduceList_Project
Final Project for my C++ class.


This project was created to solve the issue of unorganized produce lists, and grocery lists. I feel that I performed this task expertly and efficiently.
The code uses industry standard best practices, using a class and header file, using inline comments explaining the variables and functions; as well as using
input validation to make sure that an error is thrown if the user doesnt type in a number between 1 and 4, and to make sure that the user types in a product
from the list. I could improve my code by adding a constructor and more input validation with a try and catch statement with the input to throw an actual error.
I found the most challenging piece of code to write was to create the list using a C++ map. I figured out that if you call the emplace function while looping
through each of the items in the list, it creates a full list of each product that has shown up one time. Then if you set every map key value to 0 on initialization,
you can iterate over the list again and add 1 every time a particular item shows up in the list. This creates a perfect list of how many times the products
show up on the list everytime. I think the main take away from this project, and the other 2 that we did was to practice for industry standard best practices
and make sure we implemented them correctly. I made it readable by using in line comments, switch case statements, and proper variable camelcase naming protocols.
I make the project more maintainable and adaptable by creating a modular system that can accept any list of words or "products", and organize them into a list.


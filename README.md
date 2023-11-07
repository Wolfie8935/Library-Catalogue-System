# Library-Catalogue-System
A basic library management system for managing books and all using c and data structures


# Problem Definition

The problem is to create a library catalog system in C that efficiently manages a collection of books. 
The system allows users to add books to the catalog, search for books by their ISBN, display the 
catalog, and exit the program. It employs a binary search tree to organize books based on ISBN for 
quick retrieval and an ISBN-based hash table for indexing. Users can interact with the system 
through a simple menu, facilitating the addition and retrieval of book information. This solution 
addresses the need for an organized and accessible library catalog system, benefiting both librarians 
and library patrons in managing and finding books efficiently.
Problem Explanation
It allows users to add books to the catalog, search for books by ISBN, and display the catalog. The 
key data structures used in this system are:
Structures:
struct Book: Represents book information, including title, author, and ISBN.
struct Node: Represents a node in a linked list for storing books in a hash table.
struct HashTable: A hash table for storing books by their ISBN.
Binary Search Tree (BST): A binary search tree is used to maintain the catalog of books, primarily 
based on their ISBN. This tree allows for efficient searching and insertion of books.
Arrays: An array of struct Book named books is used to store all books added to the catalog. The 
bookCount variable keeps track of the number of books.

# Diagram

+----------------------------------+
 | Library Catalog System (C) |
 +----------------------------------+
 | |
 | Binary Search Tree |
 | (Catalog) |
 | / \ |
 | Book 1 - ISBN 12345 Book 2 - ISBN 67890
 | / \ / \
 | ... ... ... ...
 | |
 | +--------------------+ |
 | | Hash Table | |
 | | (ISBN-based) | |
 | +--------------------+ |
 | / | |
 | 12345 67890 ... |
 | | | | |
 | | | | |
 | v v v |
 | Book 1 Book 2 ... |
 | |
 +----------------------------------+
 | |
 | +--------------------------+ |
 | | Main Menu | |
 | | | |
 | | 1. Add a Book to Catalog | |
 | | 2. Search by ISBN | |
 | | 3. Display Catalog | |
 | | 4. Exit | |
 | +--------------------------+ |
 | |
 +----------------------------------+
 
# Example

Suppose you add several books to the catalog, and then you use the menu options:
## Add a Book to the Catalog:
You can input book information such as title, author, and ISBN. The 
book is added to the BST and the ISBN-based hash table.
Search for a Book by ISBN: You can enter an ISBN to search for a book. If the book is found, its 
details are displayed.
Display Catalog: This option displays all books in the catalog, allowing you to see the entire 
collection.
## Exit:
You can exit the program when you're done.
This code provides a simple but functional library catalog system that uses a BST for efficient search 
and an ISBN-based hash table for fast indexing and retrieval.
Data Structures Used
A library catalog system typically utilizes various data structures to efficiently manage and organize 
its collection of books and related information. Some of the common data structures used in a library 
catalog system include:
Array: Arrays are used to store books and patron data in a structured manner, allowing for direct 
access to elements based on their index or position.
## Linked List:
Linked lists can be employed to manage a list of books, patrons, or loan transactions. 
They allow for easy insertion and removal of items from the list. 
Binary Search Tree (BST): A binary search tree is often used to organize the catalog of books based 
on attributes like ISBN (International Standard Book Number) or title. This data structure allows for 
efficient searching and retrieval of books.
## Hash Table:
Hash tables are used to index and store books based on attributes such as ISBN or other 
unique identifiers. They provide fast access to specific books and are especially useful for quick 
lookups.


# Colaborators:

<img src="https://github.com/RishaanYadav.png" width="50" height="50" /> [Rishaan Yadav](https://github.com/RishaanYadav)
<br>
<img src="https://github.com/Wolfie8935.png" width="50" height="50" /> [Aman Goel](https://github.com/Wolfie8935)

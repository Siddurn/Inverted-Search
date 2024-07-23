# Inverted-Search
Inverted Search Using Hashing in C 
***********************************************************************************************************
Project Overview
The Inverted Search project aims to optimize search query performance by creating an efficient indexing system. Instead of scanning every document in the corpus, the search engine utilizes an index, significantly reducing search time and computational overhead. This project leverages hashing techniques and single linked lists to build a robust and scalable search system.
***********************************************************************************************************
Project Structure
create_database.c: Functions for creating and initializing the database.
display_database.c: Functions to display the contents of the database.
insert.c: Implements the insertion of documents into the database.
save_database.c: Saves the current state of the database.
update_database.c: Functions for updating existing entries in the database.
save.c: Utility functions related to saving data.
main.c: The main driver file that uses Command Line Arguments (CLA) to read file names and manage the overall process.
***********************************************************************************************************

Key Features
Optimized Search: Achieves faster search times by indexing documents with hashing.
Efficient Data Management: Manages collisions using single linked lists for quick lookups.
Scalability: Designed to handle large datasets with minimal performance degradation.
Prerequisites
Hashing: Fundamental knowledge of hashing techniques and their applications.
Single Linked List: Understanding of single linked list data structures for collision management.

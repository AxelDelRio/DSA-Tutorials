# HASH TABLES

A Hash Table is a collection of <key, value> pairs, each pair is called an "entry"

EX: if we have a key as an int and String as the value, this is what it would look like:

432, "Banana"
654, "Strawberry"
765, "Mango"

Now to put this entry in our table, we need to hash our key then module it by the capacy of our table, Here is a diagram of that process:

![HashTable1](/DiagramNotes/HashTableImages/HashTable1.drawio.png)

## Collisions

There are situations where two hashes are calculated to be the same value, these are called "collision"

Here is the same example from above but with a collision:

![HashTable2](/DiagramNotes/HashTableImages/HashTables2.drawio.png)

**Notice:**There are two entries going into index 2

We avoid the collision by implementing a linked list into each index in our Hash Tables, think of it as each slot as a bucket holding out entries

Here is the visual of our updated Hash Table with the linked list:


## ARRAYS

An Array is a list of data with indexes, these indexes count the place in which the data is in the list

EX:

Let's just say our array is filled with random numbers

![Diagram 1](/DiagramNotes/ArraysImages/Arrays1.drawio.png)

Now lets include our indexes:

![Diagram 2](/DiagramNotes/ArraysImages/Arrays2.drawio.png)

**Notice** that we start counting the number with the number 0, then we "increment" the number by one

Now, instead of using random data (Like numbers) we can use different data types, like a String value

EX:

["Banana", "Strawberry", "Blueberry"]
    0           1             2

In the example above, instead of using numbers, we use String values!

* In our implentation, for our data, we just use a template T variable so that the user can make an array of any type of data!

The template T variable lets the user input any type of data they want!

Exampe of template T syntax:

template <typename T>

Now the user can implement our array in any way:

Array<int> myArray;

    OR

Array<String> myArray;






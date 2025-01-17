#include <iostream>
#include <string>

template <typename T>
class MyVector{

    public:

    //Default Capacity
    static constexpr size_t DEF_CAPACITY = 64;

    //Minimum Capcity
    static constexpr size_t MIN_CAPACITY = 8;

    //Default Constructor
    MyVector(size_t capacity = MyVector::DEF_CAPACITY) {

        //Checks if the user inputs a capacity under the Minimum Capacity, it will automatically set the user's capacity to the Minimum Capacity
        if (capacity < MIN_CAPACITY) {
            capacity = MIN_CAPACITY
        }

        //Sets private variables to the default values
        this->capacity_ = capacity;
        this->size_ = 0;
        this->elements_ = new T[capacity]; // Creating an empty array with default capacity

    }
    

    //Copy Constructor
    MyVector(const MyVector& other) {

        //Copying private variables from "other" vector to our vector(this*)
        this->size_ = other.size_;
        this->capacity_ = other.capacity_;
        this->elements_ = new T[other.capacity_];

        //scanning through "other" vector and copying it's elements to our vector(this*)
        for (size_t index = 0; index < this->size_; index++) {
            this->elements_[index] = other.elements_[index];
        }

        //Copy Constructor is Linear Time Complexity
    }


    //Destructor
    ~MyVector() {

        /*
        - the if statement is for Safeguarding, checks if the elements in our array are nullptr(nothing), then we don't
          delete those elements (wouldn't make sense to delete nothing!)

        - We basically use the destructor for clean-up, useful for memory leaks

        - in this case, we delete the array with the elements and set the elements to nullptr
        */
        
        if (this->elements_ != nullptr) {
            delete[] this->elements_;
            this->elements_ = nullptr;
        }
    }


    //operator= function
    MyVector& operator= (const MyVector& rhs) {

        //Checks for self assignment, if our array is already equal to rhs vector, then we return our array/vector! (make sure to dereference "*")
        if (this == &rhs) {
            return *this;
        }
        //We delete here since we don't want to copy the rhs vector contents into an existing array that already has elements
        delete[] this->elements_;

        //Similiar to the copy constructor, we copy the contents of rhs, you can also try to call the copy constructor to do all the work for you!
        this->size_ = rhs.size_;
        this->capacity_ = rhs.capacity_;
        this->elements_ = new T[this->capacity_];
        for (size_t index = 0; index < this->size_; index++) {
            this->elements_[index] = rhs.elements_[index];
        }

        //we return our array/vector (*this)
        return *this;

        /*
        - this operator function is a linear time complexity

        Example of using an operator= in main:

        MyVector<int> v1;
        MyVector<int> v2;

        v1 = v2;
        
        */
    }


    //operator[] function -- similiar to the at() function! (Overload)
    T& operator[](size_t index) const {

        //checking for exceptions in our vector, the user can't access an element that doesn't exist in the array, so we throw an error to the user!
        if (index >= this->size_) {
            throw std::range_error("ERROR: Can't access an index that is out of bounds");
        }

        //we return the element at the index the user inputted
        return this->elements_[index];
    }


    //Return the size of the array/vector
    size_t size() const {
        return this->size_;
    }


    //Return the capacity of the array/vector
    size_t capacity() const {
        return this->capacity_;
    }


    //empty function that returns true if we have zero elements in our array, we can ignore the capacity!
    //else we return false!
    bool empty() const {

        //if the size of our array is zero, we return true
        if (this->size_ == 0) {
            return true;
        }

        //else return false
        return false;
    }


    //at function which returns an element at a specific index the user inputs
    T& at(size_t index) const {

        //if the index is not within the size of the array/vector, then we throw an error to the user
        if (index >= this->size_) {
            throw std::range_error("ERROR: Can't access an index that is out of bounds");
        }

        //we return the element at that specific index
        return this->elements_[index]
    }


    /*
    the push_back function basically adds an element to the back of our vector

    * We will incorporate doubling-capacity logic within our function

    - Whenever the new element that the user wants to insert doesn't fit 
      in our array/vector due to no more capacity, we double our capacity
      automatically so that the element can fit in our array/vector

      hint: this is what our helper function (changeCapacity) was for!
    
    */
    T& push_back(cont T& element) {
        
        /*
        this is our doubling logic!

        we check if our size is equal to our capacity, to see
        if our new element fits in the back of our array

        then we call the helper function to double our capacity automatically!

        now our element fits in our array/vector!
        */
        if (this->size_ == this->capacity_) {
            this->changeCapacity(this->capacity_ * 2);
        }

        //adding the element to the back of our array!
        this->elements_[this->size_] = element;

        //We increment the size of our array!
        this->size_++;

        //We return a copy of the new inserted element!
        return this->elements_[this->size_ - 1];

        //This push_back function is Linear Time since our changeCapacity helper function scans through our array/vector
    }


    /*
    The pop_back function basically removes an element from the back of our array

    * We will incorporate a shrinking knowledge within our function!

    - Whenever we pop from the vector and the size is 1/3 of our capacity
      then we automatically shrink our capacity by 1/2

      hint: We also use our changeCapacity helper function for this function
    
    */
    T pop_back() {

        //checks if the user is trying to pop from an empty vector, which isn't allowed
        if (this->empty()) {
            throw std::range_error("ERROR: erasing last number in an empty vector is not allowed!");
        }

        //store the last element into a T variable to we can return the element that we will remove!
        T lastElement = this->elements_[this->size_ - 1];

        //decrement the size since we removed an element in our array!
        this->size--;

        /*
        This is our shrinking logic!

        in our while loop, we check when our capacity is greater than our Minimum capacity
        value and our size is less than 1/3 of our capacity, we shrink the capacity by 1/2
        then store it into a size_t variable

        we then check if our shrinked capacity is less than our Minimum capacity, and if it is
        then we set it equal to our Minimum capacity, then we call the changeCapacity and input
        the shrinked capacity into it

        the reason we use a while loop is because we want to keep shrinking if our size is still
        1/3 of our capacity, until we get the optimal capacity
        
        */
        while (this->capacity_ > MIN_CAPACITY && this->size_ < this->capacity_ / 3) {
            size_t shrinkedCapacity = this->capacity_ / 2;
            if (shrinkedCapacity < MIN_CAPACITY) {
                shrinkedCapacity = MIN_CAPACITY;
            }

            this->changeCapacity(shrinkedCapacity);
        }

        //we return the element we deleted
        return lastElement;

        //this function is linear time since our changeCapacity function scans our array/vector
    }

    /*
        Our insert function handles wanting to input a element at a specific index in our array/vector

        EX: 
        Inserting a 2 at index 3

        Before: [1,2,3,4,5]
        After: [1,2,3,4,2,5]

        We also add the doubling logic from push_back!

        then we return a reference to the inserted element
    */
    T& insert(size_t index, const T& element) {
        //check to see if the index is out of bounds
        if (this->size_ < index) {
            throw std::range_error("ERROR: You are inserting at an invalid index");
        }

        //installing doubling logic here!
        if (this->capacity_ == this->size_) {
            this->changeCapacity(this->capacity_ * 2);
        }
        //We move the elements to the right!
        for (size_t i = this->size_; i > index; i--) {
            this->elements_[i] = this->elements_[i - 1];
        }
        //placing the element at the index
        this->elements_[index] = element;
        //increment size for recently added element
        this->size_++;
        //return a reference to the added element
        return this->elements_[index];

        //this function is Linear time complexity!
    }

    /*
        Erase an element at a specific index!

        EX:

        Erase index 4
        Before: [1,2,3,4,5,6]
        After: [1,2,3,4,6]

        we add the shrinking logic from pop_back

        return a reference of the erased element!
    
    */
    T erase(size_t index) {
        //check for index that it out of bounds
        if (this->size_ <= index) {
            throw std::range_error("ERROR: invalid index");
        }
        //create a copy of the index which we are erasing
        T copyElement = this->elements_[index];

        //move the elements to the left to replace the erased element -- this automatically erases the element
        for (size_t i = index; i < this->size_ - 1; i++) {
            this->elements_[i] = this->elements_[i + 1];
        }
        //decrement the size since we erased an element
        this->size_--;

        //add shrinking logic
        while (this->capacity_ > MIN_CAPACITY && this->size_ < this->capacity_ / 3) {
            size_t currentCapacity = this->capacity_ / 2;
            if (currentCapacity < MIN_CAPACITY) {
                currentCapacity = MIN_CAPACITY;
            }
            this->changeCapacity(currentCapacity);
        }
        // return a copy of the erased element
        return copyElement;
    }


    //clear function removes all the elements in the array/vector
    void clear() {
        //delete the array
        delete[] this->elements_;

        //default all the private variables
        this->size_ = 0;
        this->capacity_ = DEF_CAPACITY;
        this->elements_ = new T[DEF_CAPACITY];
    }


    //erase function which deletes an element at a specific index
    T erase(size_t index) {

        //checks if the index is out of bounds
        if (this->size_ <= index) {
            throw std::range_error("ERROR: you are trying to erase an element at an index that does not exist");
        }

        //create a copy of the index that is going to be erased
        T copyElement = this->elements__[index];

        //move everything to the left to replace the erased element, this automatically deletes the element
        for (size_t s = index; s < this->size_ - 1; s++) {
            this->elements_[s] = this->elements_[s + 1];
        }

        //decrement the size since we erased the element
        this->size--;

        //apply shrinking logic from push_back
        while (this->capacity_ > MIN_CAPACITY && this->size_ < this->capacity_ / 3) {
            size_t shrinkedCapacity = this->capacity_ / 2;
            if (shrinkedCapacity < MIN_CAPACITY) {
                shrinkedCapacity = MIN_CAPACITY;
            }

            this->changeCapacity(shrinkedCapacity);
        }

        //return the copy that we erased
        return copyElement;
    }


    //insert function which adds an element at a specific index
    T& insert(size_t index, const T& element) {
        //checks if the index is out of bounds
        if (this->size_ < index) {
            throw std::range_error("ERROR: You are trying to insert at an invalid index");
        }

        //we apply the doubling logic
        if (this->capacity_ == this->size_) {
			this->changeCapacity(this->capacity_ * 2);
        }

        //we move the elements to the right
        for (size_t s = this->size_; s > index; s--) {
            this->elements_[s] = this->elements_[s - 1]
        }

        //we add the element at the specific index!
        this->elements_[index] = element;

        //we increment the size since we just added an element to our array/vector
        this->size_++;

        //we return a reference at the added element
        return this->elements_[index];
    }

    private:

    size_t size_ = 0; //size to keep track of size of Array
    size_t capacity_ = 0;//capacity to keep track of capacity of Array
    T* elements_ = nullptr; //the data we keep track in our Array, we will initalize 


    // This is our helper function which changes the capacity of our Array, 
    void changeCapacity(size_t c) {

        //checks if the user tries to change the capacity and results in it being less than our size!
        if (c < this->size_) {
            throw std::range_error("ERROR: You are trying to change the capacity which is smaller than the vector's size");   
        }

        //create a new array with the capacity being passed in the parameter
        T* currentArray = new T[c];

        //copy the contents of our array/vector into the newly created array (currentArray)
        for (size_t index = 0; index < this->size_; index++) {
            currentArray[index] = this->elements_[index];
        }

        //delete our old array, to clear any memory leaks
        delete[] this->elements_;

        //change the pointer of elements from our old array to the new array
        this->elements_ = currentArray;
        //update the capacity
        this->capacity_ = c;

        //Linear Time for changeCapacity, since we scan through the array once
    }
};
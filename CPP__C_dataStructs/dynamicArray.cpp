#include <iostream>


class DynamicArray{
    public:
    int size;
    int capacity;
    int* static_array;

    DynamicArray (int l_capacity){
        size = 0;
        capacity = l_capacity;
        static_array = new int[l_capacity];
    };

    DynamicArray* duplicateCapacity(){
        if(this -> capacity <= this -> size){
            this -> capacity = 2* this -> capacity;
        }
        return this;
    }

    void addIntIndexZero(DynamicArray* DA_p, int toAdd){
        //
        if(DA_p -> capacity < DA_p -> size){
            (*DA_p).duplicateCapacity();
        }
        DA_p -> static_array[0] = toAdd;
    }
};

int main()
{
    
    DynamicArray myArray(5);
    DynamicArray* myArray_p = &myArray;
    myArray.addIntIndexZero(myArray_p,5);


    std::cout << myArray_p -> static_array[0] << std::endl;

}
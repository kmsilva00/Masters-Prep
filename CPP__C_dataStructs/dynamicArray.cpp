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

    void duplicateCapacity(){
        if(this -> capacity <= this -> size){
            this -> capacity = 2* this -> capacity;
        }
    }    
    
    void addIntAtEnd(int toAdd){

        if (this->size + 1 > this->capacity){
           (*this).duplicateCapacity();
        }

        this->static_array[this->size] = toAdd;
    
        // NOW increment the size, because we've successfully added an element.
        this->size += 1;
    }

    void addIntAtBeggining(int toAdd){

        if (this->size + 1 > this->capacity){
           (*this).duplicateCapacity();
        }
        this->size += 1;

        for(int i = this->size; i>=0;i--){
            this->static_array[i] = this->static_array[i-1];
        }
        this->static_array[0] = toAdd;
        
    }

    void addIntAtIndex(int index, int toAdd){
        if (this->size + 1 > this->capacity){
           (*this).duplicateCapacity();
        }
        this->size += 1;

        for( int i = this->size-1; i>index ; i-- ){
            this -> static_array[i] = this -> static_array[i-1];
        }
        this->static_array[index] = toAdd;

    }
    

    void printDynamicArray(){
        std::cout << "[";

        for(int i = 0; i < this -> size;i++){
            std::cout << this -> static_array[i] << ","; 
        }
        std::cout << "]";
    }
};

int main()
{
    
    DynamicArray myArray(6);
    DynamicArray* myArray_p = &myArray;

    myArray.addIntAtEnd(5);
    myArray.addIntAtEnd(12);
    myArray.addIntAtEnd(8);
    myArray.addIntAtEnd(4);
    myArray.addIntAtBeggining(3);
    myArray.addIntAtIndex(2,25);
    myArray.printDynamicArray();

}
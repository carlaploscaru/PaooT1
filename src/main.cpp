#include <iostream>
#include "class.hpp"

//using namespace std;

Booking::Booking(int apartment_id, const std::string& owner_name)//the initialization part of a constructor occurs in the constructor's initializer list.
    : apartment_id(apartment_id), owner_name(owner_name) {
    std::cout << "created\n";
}

Booking::~Booking(){
    std::cout<<"distrus\n";
    delete[] this->client;
}

Booking::Booking(const Booking& a)
    : apartment_id(a.apartment_id),owner_name(a.owner_name){
    std::cout<<"copy constructor called"<<std::endl;
}

void Booking::afisareInfo() const{
    std::cout<<"apartment_id :"<< apartment_id<<"\n";
    std::cout<<"owner_name :"<< owner_name<<"\n";
    std::cout<<"nr_apartments :"<< nr_apartments<<"\n";
}

Booking& Booking::operator=(const Booking& other) {
    if (this != &other) { 
        apartment_id = other.apartment_id;
        owner_name = other.owner_name;
        nr_apartments = other.nr_apartments;
        nr_pers_per_ap = other.nr_pers_per_ap;
        nr_days = other.nr_days;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this; // Return a reference to the modified object
}


//allocate memory on the heap using the new operator for single objects or arrays and deallocate it using the delete operator.

int main(){
    std::string name="ion"; //daca nu am const in constructor
    Booking owner1(24,name);//object is created as a local variable on the stack

    Booking* owner2 = new Booking(25, "ariel"); // Allocate a single Booking object on the heap
    Booking* owner3 = new Booking[5]{
    {1, "Alice"},
    {2, "Bob"},
    {3, "Charlie"},
    {4, "David"},
    {5, "Eve"}
}; // Allocate an array of 5 Booking objects on the heap
    
    owner1.afisareInfo();
    owner2->afisareInfo();
    for(int i = 0; i < 5; ++i){
        owner3[i].afisareInfo();
    }
  

    delete owner2;//Call the destructor explicitly and deallocate memory
    delete[] owner3;

    Booking owner15(24, "John");
    Booking owner4(NULL,NULL);//pt copy constructor
    owner4 = owner15;//Use the copy assignment operator to assign owner1 to owner4
    owner4.afisareInfo();

    std::cout<<"Hello agica";
    return 0;
}


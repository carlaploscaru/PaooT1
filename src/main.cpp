#include <iostream>
#include "class.hpp"
#include <vector>
#include <cstring>

//using namespace std;

Booking::Booking(int h_id, const std::string& o_name,const char* hotel)
    : hotel_id(h_id), owner_name(o_name) {
    this->hotel = new char[strlen(hotel) + 1];
    strcpy(this->hotel, hotel);
    std::cout << "created\n";
}

Booking::~Booking(){
    std::cout<<"distrus\n";
    delete[] hotel;
}

Booking::Booking(const Booking& next)
    : hotel_id(next.hotel_id),owner_name(next.owner_name){
    std::cout<<"copy constructor apelat"<<std::endl;
}

void Booking::afisareInfoBooking() const{
    std::cout<<"hotel_id :"<< hotel_id<<"\n";
    std::cout<<"owner_name :"<< owner_name<<"\n";
    std::cout<<"nr_apartments :"<< nr_apartments<<"\n";
}

Booking& Booking::operator=(const Booking& next) { 
    if (this != &next) { 
        hotel_id = next.hotel_id;// se face copierea
        owner_name = next.owner_name;
        nr_apartments = next.nr_apartments;
        nr_pers_per_ap = next.nr_pers_per_ap;
        nr_days = next.nr_days;
    }
    std::cout << "assignment operator apelat" << std::endl;
    return *this; // returneaza o referinta la obiectul modificat
}









Client::Client(int a_id, const Booking& book,const std::string & c_name)
    : apartment_id(a_id), booking(book),client_name(c_name){
}

void Client::displayClientInfo() const {
    std::cout << "apartment_id: " << apartment_id << std::endl;
    std::cout << "client_name: " << client_name << std::endl;
    std::cout << "Booking Info:" << std::endl;
    booking.afisareInfoBooking(); // Call the Booking's display function
}

Client::~Client(){
    std::cout<<"distrus\n";
    delete[] client;
}






int main(){
    //std::string name="ion"; 
    Booking apartment1(24,"ion","name1");//obj creat ca var locala pe stack 

    Booking* apartment2 = new Booking(25, "ariel","name1"); 
    Booking* apartment3 = new Booking[3]{
    {1, "Alice","name1"},
    {2, "Bob","name1"},
    {3, "Charlie","name1"}
    };
    
    apartment1.afisareInfoBooking();
    /*apartment2->afisareInfoBooking();
    for(int i = 0; i < 5; ++i){
        apartment3[i].afisareInfoBooking();
    }*/


    Booking apartment23(253, "Alice","name1"); 
    std::string client_name = "pop andrei";
    Client client1(25, apartment23, client_name);
    std::cout << "Client Info:" << std::endl;
    client1.displayClientInfo();
    

    delete apartment2;
    delete[] apartment3;

    Booking apartment15(24, "John","name1");
    Booking* apartment4 = new Booking(0, "","");
    *apartment4 = apartment15;
    apartment4->afisareInfoBooking();
   
    delete apartment4;

   Booking a(1, "aaaaa","name1");
   Booking b(2, "bbbbbb","name1");
   a.afisareInfoBooking();
   b.afisareInfoBooking();
   b = a;
   Booking c=b;
   c.afisareInfoBooking();


return 0;
}


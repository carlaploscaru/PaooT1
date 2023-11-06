#include <iostream>
#include "class.hpp"
#include <vector>
#include <cstring>


//using namespace std;

Booking::Booking(int h_id, const std::string& o_name,const char* hotel)
    : hotel_id(h_id), owner_name(o_name) {
    if (hotel) {
        this->hotel = new char[strlen(hotel) + 1];
        strcpy(this->hotel, hotel);
    }
    std::cout << "created\n";
}

Booking::~Booking(){
    std::cout<<"distrus\n";
    delete[] hotel;
}

Booking::Booking(const Booking& next)
    : hotel_id(next.hotel_id),owner_name(next.owner_name){
    if (next.hotel) {
        this->hotel = new char[strlen(next.hotel) + 1];
        strcpy(this->hotel, next.hotel);
    } else {
        this->hotel = nullptr;
    }
    std::cout<<"copy constructor apelat"<<std::endl;
}

void Booking::afisareInfoBooking() const{
    std::cout<<"hotel_id :"<< hotel_id<<"\n";
    std::cout<<"owner_name :"<< owner_name<<"\n";
    std::cout<<"nr_apartments :"<< nr_apartments<<"\n";
}

//supraincarcarea operatorului =
Booking& Booking::operator=(const Booking& next) { 
    if (this != &next) { 
        hotel_id = next.hotel_id;
        owner_name = next.owner_name;

        delete[] hotel;

        hotel = new char[strlen(next.hotel) + 1];
        strcpy(hotel, next.hotel);
    }
    std::cout << "assignment operator apelat" << std::endl;
    return *this; 
}

Booking::Booking(Booking&& other) noexcept
    : hotel_id(other.hotel_id), owner_name(std::move(other.owner_name)), hotel(other.hotel) {
    other.hotel_id = 0;
    other.owner_name.clear();
    other.hotel = nullptr;
}







Client::Client(int a_id, const Booking& book,const std::string & c_name)
    : apartment_id(a_id), booking(book),client_name(c_name){
}

Client::Client(int a_id, Booking&& book, std::string&& c_name)
     : apartment_id(a_id), booking(std::move(book)), client_name(std::move(c_name)) {
}

void Client::displayClientInfo() const {
    std::cout << "apartment_id: " << apartment_id << std::endl;
    std::cout << "client_name: " << client_name << std::endl;
    std::cout << "Booking Info:" << std::endl;
    booking.afisareInfoBooking();
}



int Client::sumClienti( const std::vector<InterfaceClient*>& clienti, int hotel_id) {
            int sum = 0;
            for (const InterfaceClient* c: clienti) {
                if (c->getHotelId() == hotel_id) {
                    sum++;
                }
            }
            return sum;
        }






namespace Guest {
    GuestClient::GuestClient(int apartment_id, const Booking& booking, const std::string& client_name)
        : Client(apartment_id, booking, client_name) {}

    void GuestClient::displayInfo() {
        std::cout << "Guest Client Information:" << std::endl;
        displayClientInfo();
    }
}


namespace Tourists {
    TouristClient::TouristClient(int apartment_id, const Booking& booking, const std::string& client_name)
        : Client(apartment_id, booking, client_name) {}

        void TouristClient::displayInfo() {
            std::cout << "Tourist Client Information:" << std::endl;
            displayClientInfo();
        }

        
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

    //booking+client info
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


    //sum
    Booking apartment8(24, "ion", "name1");

    Tourists::TouristClient client3(25, apartment1, "Client1");
    Tourists::TouristClient client4(26, apartment23, "Client2");
    Tourists::TouristClient client5(27, apartment15, "Client3");
    Tourists::TouristClient client6(28, apartment8, "Client4");

   
    std::vector< InterfaceClient*> clients;

    clients.push_back(&client3);
    clients.push_back(&client4);
    clients.push_back(&client5);
    clients.push_back(&client6);
    Client client(0, Booking(0, "",""),""); 
    int totalClients = client.sumClienti(clients, 24);

    std::cout << "\n\n\n\n\nTotal clients: "<< totalClients << std::endl;
    for (const InterfaceClient* client : clients) {
         client->displayClientInfo(); 
         std::cout << "\n"<< std::endl;
    }


    Guest::GuestClient guest(101, apartment1, "Alice (Guest)");
    Tourists::TouristClient tourist(102, apartment23, "Eve (Tourist)");
    guest.displayInfo();
    tourist.displayInfo();

//move constr
    std::cout << "\n\n\n\n\n " << std::endl;
    Booking apartment11(24, "ina", "name1");
    Booking another(std::move(apartment11)); 

   
    std::cout << "apartment11: " << std::endl;
    apartment11.afisareInfoBooking() ;
    std::cout << "another: " << std::endl;
    another.afisareInfoBooking();

    Client client11(25, std::move(another), "client11");

    std::cout << "client11: " << std::endl;
    client11.displayClientInfo();

return 0;
}
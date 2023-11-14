
#include <iostream>
#include "class.hpp"
#include <vector>
#include <cstring>
#include <iomanip>


//using namespace std;


Booking::Booking() : hotel_id(0), owner_name(""), nr_apartments(0), price(0), nr_days(0), hotel(nullptr) {
    // Additional initialization if needed
    std::cout << "Default constructor called\n";
}

// Booking::Booking(int h_id, const std::string& o_name,const char* hotel)
//     : hotel_id(h_id), owner_name(o_name) {
//     if (hotel) {
//         this->hotel = new char[strlen(hotel) + 1];
//         strcpy(this->hotel, hotel);
//     }
//     std::cout << "created\n";
// }
Booking::Booking(int h_id, const std::string& o_name, const char* hotel, int pri)
    : hotel_id(h_id), owner_name(o_name), price(pri) {
    if (hotel) {
        this->hotel = std::make_unique<char[]>(strlen(hotel) + 1);
        strcpy(this->hotel.get(), hotel);
    }
    std::cout << "created\n";
}
Booking::Booking(int h_id, const char* o_name, const char* hotel, int pri)
    : hotel_id(h_id), owner_name(o_name), price(pri) {
    if (hotel) {
        this->hotel = std::make_unique<char[]>(strlen(hotel) + 1);
        strcpy(this->hotel.get(), hotel);
    }
    std::cout << "created\n";
}





Booking::~Booking(){
    std::cout<<"distrus\n";
    //delete[] hotel;
}

// Booking::Booking(const Booking& next)
//     : hotel_id(next.hotel_id),owner_name(next.owner_name){
//     if (next.hotel) {
//         this->hotel = new char[strlen(next.hotel) + 1];
//         strcpy(this->hotel, next.hotel);
//     } else {
//         this->hotel = nullptr;
//     }
//     std::cout<<"copy constructor apelat"<<std::endl;
// }
Booking::Booking(const Booking& next)
    : hotel_id(next.hotel_id), owner_name(next.owner_name),price(next.price) {
    if (next.hotel) {
        this->hotel = std::make_unique<char[]>(strlen(next.hotel.get()) + 1);
        strcpy(this->hotel.get(), next.hotel.get());
    } else {
        this->hotel = nullptr;
    }
    std::cout << "copy constructor apelat" << std::endl;
}

void Booking::afisareInfoBooking() const{
    std::cout<<"hotel_id :"<< hotel_id<<"\n";
    std::cout<<"owner_name :"<< owner_name<<"\n";
    std::cout<<"price :"<< price<<"\n";
}

//supraincarcarea operatorului =
// Booking& Booking::operator=(const Booking& next) { 
//     if (this != &next) { 
//         hotel_id = next.hotel_id;
//         owner_name = next.owner_name;

//         delete[] hotel;

//         hotel = new char[strlen(next.hotel) + 1];
//         strcpy(hotel, next.hotel);
//     }
//     std::cout << "assignment operator apelat" << std::endl;
//     return *this; 
// }
Booking& Booking::operator=(const Booking& next) {
    if (this != &next) {
        hotel_id = next.hotel_id;
        owner_name = next.owner_name;
        price = next.price;

        hotel = std::make_unique<char[]>(strlen(next.hotel.get()) + 1);
        strcpy(hotel.get(), next.hotel.get());
    }
    std::cout << "assignment operator apelat" << std::endl;
    return *this;
}

// Booking::Booking(Booking&& other) noexcept
//     : hotel_id(other.hotel_id), owner_name(std::move(other.owner_name)), hotel(other.hotel) {
//     other.hotel_id = 0;
//     other.owner_name.clear();
//     other.hotel = nullptr;
// }
Booking::Booking(Booking&& other) noexcept
    : hotel_id(other.hotel_id), owner_name(std::move(other.owner_name)),hotel(std::move(other.hotel)),price(other.price) {
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
/*//nu e alocat dinamic=>nu ne trebe
Client::~Client(){
    std::cout<<"distrus\n";
    delete[] client;
}
*/

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

template <typename T>
float TotalPrice(const std::vector<T*>& items) {
    float total = 0.0;
    for (const T* item : items) {
        total += item->getPrice();
    }
    return total;
}



int main(){

    
//     //std::string name="ion"; 
    Booking apartment1(24,"ion","name1",100);//obj creat ca var locala pe stack 

//     Booking* apartment2 = new Booking(25, "ariel","name1"); 
//     Booking* apartment3 = new Booking[3]{
//     {1, "Alice","name1"},
//     {2, "Bob","name1"},
//     {3, "Charlie","name1"}
//     };
    
//     apartment1.afisareInfoBooking();
//     /*apartment2->afisareInfoBooking();
//     for(int i = 0; i < 5; ++i){
//         apartment3[i].afisareInfoBooking();
//     }*/


    Booking apartment23(253, "Alice","name1",200.9); 
//     std::string client_name = "pop andrei";
//     Client client1(25, apartment23, client_name);
//     std::cout << "Client Info:" << std::endl;
//     client1.displayClientInfo();
    

//     delete apartment2;
//     delete[] apartment3;

    Booking apartment15(24, "John","name1",100);
//     Booking* apartment4 = new Booking(0, "","");
//     *apartment4 = apartment15;
//     apartment4->afisareInfoBooking();
   
//     delete apartment4;

//    Booking a(1, "aaaaa","name1");
//    Booking b(2, "bbbbbb","name1");
//    a.afisareInfoBooking();
//    b.afisareInfoBooking();
//    b = a;
//    Booking c=b;
//    c.afisareInfoBooking();


   // sum
    Booking apartment8(24, "ion", "name1",50);

    Tourists::TouristClient client3(25, apartment1, "Client1");
    Tourists::TouristClient client4(26, apartment23, "Client2");
    Tourists::TouristClient client5(27, apartment15, "Client3");
    Tourists::TouristClient client6(28, apartment8, "Client4");

   
    std::vector< InterfaceClient*> clients;

    clients.push_back(&client4);
    clients.push_back(&client5);
    clients.push_back(&client6);
    Client client(0, Booking(0, "","",0),""); 

    int totalClients = client.sumClienti(clients, 24);
    std::cout << "\n\n\n\n\nTotal clients: "<< totalClients << std::endl;

    float total = TotalPrice(clients);
    std::cout << "Total clients price: " << std::fixed << std::setprecision(2) << total << std::endl;



    for (const InterfaceClient* client : clients) {
         client->displayClientInfo(); 
         std::cout << "\n"<< std::endl;
    
    }

std::vector< Client*> h;
h.push_back(&client4);
    h.push_back(&client5);
    h.push_back(&client6);
float total2 = TotalPrice(h);
    std::cout << "Total clients price: " << std::fixed << std::setprecision(2) << total2 << std::endl;

    // Guest::GuestClient guest(101, apartment1, "Alice (Guest)");
    // Tourists::TouristClient tourist(102, apartment23, "Eve (Tourist)");
    // guest.displayInfo();
    // tourist.displayInfo();


    std::cout << "\n\n\n\n\n " << std::endl;
    // Booking apartment11(24, "ion", "name1");
    // Booking another(std::move(apartment11)); 

    // std::cout << "apartment11: " << std::endl;
    // apartment11.afisareInfoBooking() ;
    // std::cout << "another: "   << std::endl;
    // another.afisareInfoBooking();

    // Client client11(25, std::move(another), "client1");
    // std::cout << "client11: " << std::endl;
    // client11.displayClientInfo();





//uniq pointer
    std::unique_ptr<Booking> apartment22 = std::make_unique<Booking>(1, "ana", "name1",100);
    std::unique_ptr<Booking[]> apartment33 = std::make_unique<Booking[]>(3);
    apartment33[0] = Booking(2, "ana2", "name1",100);
    apartment33[1] = Booking(3, "ana3", "name1",50);
    apartment33[2] = Booking(4, "ana4", "name1",90);
    if (apartment22) {
        apartment22->afisareInfoBooking();
    }
    for (int i = 0; i < 3; ++i) {
        if (apartment33) {
             apartment33[i].afisareInfoBooking();
              std::cout << "\n" << std::endl;
        }
    }

    std::unique_ptr<Client> client1 = std::make_unique<Client>(1, *apartment22, "John Doe");
    if (client1) {
        client1->displayClientInfo();
    }
   std::cout << "\n\n\n\n\n " << std::endl;



//share pointer
    std::shared_ptr<Booking> Shared1 = std::make_shared<Booking>(1, "share1", "name1",200);
    std::cout << "Use count: " << Shared1.use_count() << std::endl;
    Shared1->afisareInfoBooking();

    std::shared_ptr<Booking> Shared2 = Shared1;
    std::cout << "Use count after creating another shared pointer: " << Shared1.use_count() << std::endl;
    std::cout << "\nUsing the second shared pointer:\n";
    Shared2->afisareInfoBooking();
   
    std::cout << "\nOutside the scope of the second shared pointer:\n";
    
    Shared1->afisareInfoBooking();
    


   
    Shared1.reset(new Booking(30, "john", "name1",80));
    std::cout << "Use count after resetting: " << Shared1.use_count() << std::endl;
    Shared1->afisareInfoBooking();

return 0;
}



#include <iostream>
#include <string>
#include <vector>

class Booking{
   private: 
        int hotel_id;
        std::string owner_name;
        int nr_apartments;
        int nr_pers_per_ap;
        int nr_days;
        char* hotel;
   
    public:
         Booking(); 
         Booking(int hotel_id, const std::string & owner_name,const char* hotel);
         ~Booking();
         Booking(const Booking & next);
         void afisareInfoBooking() const;
         Booking& operator=(const Booking& next);
         int getHotelId() const{ return hotel_id; };
};


class Client{
private: 
        int apartment_id;
        std::string client_name;
        std::string email;
        std::string password;
        Booking booking;
        char* client;
   
    public:
         Client(int apartment_id,const Booking& booking,const std::string & client_name);
         ~Client();
         void afisareInfo() const;
         void displayClientInfo() const;
         int getHotelId() const { return booking.getHotelId(); }
         int sumClienti(const std::vector<Client>& clienti, int hotel_id);
};



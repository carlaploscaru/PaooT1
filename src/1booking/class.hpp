
#include <iostream>
#include <string>
#include <vector>//?????????????
#include <memory>


class Booking{
   private: 
        int hotel_id;
        std::string owner_name;
        int nr_apartments;
        int nr_pers_per_ap;
        int nr_days;
        std::unique_ptr<char[]> hotel;//char* hotel;

   
   
    public:
         Booking(); 
         Booking(int hotel_id, const std::string & owner_name,const char* hotel);
         ~Booking();
         Booking(const Booking & next);//????????????????
         void afisareInfoBooking() const;
         Booking& operator=(const Booking& next);//??????????????
         int getHotelId() const{ return hotel_id; };
         Booking(Booking&& other) noexcept;
      
};


class InterfaceClient {
public:
    virtual int getHotelId() const= 0;
    virtual void displayClientInfo() const = 0;
    virtual ~InterfaceClient() {} //??????????????????????????
};

class Client: public InterfaceClient {
     private: 
        int apartment_id;
        std::string client_name;
        std::string email;
        std::string password;
        Booking booking;
        std::unique_ptr<char[]> client;//char* client;
   
    public:
         Client(int apartment_id,const Booking& booking,const std::string & client_name);
         Client(int apartment_id, Booking&& booking, std::string&& client_name);
         //~Client();
         void displayClientInfo()  const override;
         int getHotelId() const override{ return booking.getHotelId(); }
         int sumClienti(const std::vector<InterfaceClient*>& clienti, int hotel_id);
};



namespace Guest {
    class GuestClient : public Client  {
    public:
        GuestClient(int apartment_id, const Booking& booking, const std::string& client_name);
        void displayInfo();
    };
};

namespace Tourists {
    class TouristClient : public Client  {
    public:
        TouristClient(int apartment_id, const Booking& booking, const std::string& client_name);
        void displayInfo();
    };
};




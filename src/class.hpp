#ifndef BOOKING_HPP // Add include guards//are used to prevent a header file from being included multiple times in a translation unit (source file)
#define BOOKING_HPP


#include <iostream>
#include <string>



class Booking{
   private: //by defsult e privst si dscs nu pun private
        int apartment_id;
        std::string owner_name;//std for string
        int nr_apartments;
        int nr_pers_per_ap;
        int nr_days;
        char* client;
   
    public:
         Booking(int apartment_id, const std::string & owner_name);//"const" ne arata ca parametrul "owner_name" e o referinta constnta la un obiect std::string, daca nu pun &=> transmit prin valore numele nu prin referinta
         ~Booking();
         Booking(const Booking & ceva);//& indica ca "ceva" e referinta la obiectul Booking 
         void afisareInfo() const;
         Booking& operator=(const Booking& other);

};

#endif
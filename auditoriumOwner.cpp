#include "auditoriumOwner.h" 
#include <iostream>
#include <vector>

AuditoriumOwner::AuditoriumOwner(int id,const string &firstName, const string &lastName, const string &username, const string &password)
: Person(id, firstName, lastName, username, password){
}

AuditoriumOwner::AuditoriumOwner(){}


#define CALCULATE_TOTAL_PROFIT(reservations, reservationCount)   \
   do                                                            \
   {                                                             \
      int totalProfitMacro = 0;                                  \
      for (int i = 0; i < reservationCount; i++)                 \
      {                                                          \
         totalProfitMacro += reservations[i].price;              \
      }                                                          \
      std::cout << "Total Profit : " << totalProfitMacro << '\n'; \
   } while (0)




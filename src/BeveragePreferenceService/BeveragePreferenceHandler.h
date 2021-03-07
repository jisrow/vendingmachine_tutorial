#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceHandler();
  ~BeveragePreferenceServiceHandler() override=default;

  void GetBeverage(std::string& _return, const BeverageType::type b) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {
  std::string beverages[2][3] = {{"cappuccino", "latte", "espresso"},{"lemonade", "ice tea", "soda"}};
}

// Remote Procedure "PlaceOrder"

void BeveragePreferenceServiceHandler::GetBeverage(std::string& _return, const BeverageType::type b) {
     // Your implementation goes here
     printf("GetBeverage\n");

     if(b == BeverageType::type::HOT) {
       _return = beverages[0][rand()%3];
     } else {
       _return = beverages[1][rand()%3];
     }
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H


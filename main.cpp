#include "./sources/magicfunction.h"
#include <string_view>


int main(int, char**){

  bool boolVar = true;
  int intVar = 997;
  std::string_view strviewVar = "I'm a string_view!";

  magicFunction(boolVar, intVar, strviewVar);
  magicFunction(boolVar, strviewVar, intVar);
  magicFunction(intVar, strviewVar, boolVar);
  magicFunction(intVar, boolVar, strviewVar);
  magicFunction(strviewVar, boolVar, intVar);
  magicFunction(strviewVar, intVar, boolVar);

	return 0;
}


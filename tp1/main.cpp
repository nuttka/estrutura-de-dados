#include "list.hpp"
#include <string>

void inputTreatment(FlaskList &myFlasks, FlaskList &requestedVolumes){
  int volume;
  char function;
  while(!std::cin.eof()){
    std::cin >> volume;
    std::cin >> function;
    // std::cout << volume << " " << function << std::endl;

    std::cin.ignore();
    fflush(stdin);
  }
}

int main(){
  FlaskList myFlasks;
  FlaskList requestedVolumes;
  inputTreatment(myFlasks, requestedVolumes);
}
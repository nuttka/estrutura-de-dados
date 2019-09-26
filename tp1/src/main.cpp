#include "list.hpp"
#include <string>

void inputTreatment(FlaskList &myFlasks, FlaskList &requestedVolumes){
  int volume;
  char function;

  while(std::cin >> volume >> function){
    if(function == 'i'){
      myFlasks.insertFlask(volume, 1);
      // std::cout << "insere " << volume << std::endl;
    }else if(function == 'r'){
      myFlasks.removeFlask(volume);
      // std::cout << "remove " << volume << std::endl;
    }else if(function == 'p'){
      myFlasks.haveFlask(volume);
      myFlasks.printList();
      // myFlasks.flaskMeasurement(volume);
    }

    std::cin.ignore();
    fflush(stdin);
  }
}

int main(){
  FlaskList myFlasks;
  FlaskList requestedVolumes;
  inputTreatment(myFlasks, requestedVolumes);
}
#include "list.hpp"
#include <string>

void inputTreatment(FlaskList &myFlasks, FlaskList &requestedVolumes){
  int volume;
  char function;

  while(std::cin >> volume >> function){
    if(function == 'i'){
      myFlasks.insertFlask(volume);
      std::cout << "insere " << volume << std::endl;
    }else if(function == 'r'){
      myFlasks.removeFlask(volume);
      std::cout << "remove " << volume << std::endl;
    }else if(function == 'p'){
      myFlasks.printList();
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
#include "list.hpp"
#include <string>

void FlaskMeasurement(int volume, FlaskList &myFlasks, FlaskList &auxFlasks){
  if(volume == 0){
    std::cout << volume << std::endl;
    return;
  }
  int i;
  Flask *aux;
  Flask *aux2;
  aux2 = myFlasks.getHead();
  for(i=0; i<myFlasks.getNumberOfFlasks(); i++){
    if(aux2->volume == volume){
      std::cout << aux2->operations << std::endl;
      return;
    }
    auxFlasks.insertFlask(aux2->volume, aux2->operations);
    aux2 = aux2->next;
  }
  aux = auxFlasks.getHead();
  aux2 = myFlasks.getHead();
  int amount = auxFlasks.getNumberOfFlasks();
  int amount2 = 0;

  while(true){
    aux = auxFlasks.getHead();
    if(aux2->next == nullptr){
      aux2 = myFlasks.getHead();
      amount2 = auxFlasks.getNumberOfFlasks() - amount;
      amount = auxFlasks.getNumberOfFlasks();
    }else{
      aux2 = aux2->next;
    }
    for(i=amount2; i<amount; i++){
      if(aux->volume + aux2->volume == volume){
        std::cout << aux->operations + aux2->operations << std::endl;
        // auxFlasks.printList();
        return;
      }else if(!auxFlasks.haveFlask(aux->volume + aux2->volume)){
        auxFlasks.insertFlask(aux->volume + aux2->volume, aux->operations + aux2->operations);
      }
      if(aux->volume - aux2->volume == volume){
        std::cout << aux->operations+aux2->operations << std::endl;
        // auxFlasks.printList();
        return;
      }else if(aux->volume > aux2->volume && !auxFlasks.haveFlask(aux->volume - aux2->volume)){
        auxFlasks.insertFlask(aux->volume - aux2->volume, aux->operations + aux2->operations);
      }
      aux = aux->next;
    }
  }
}

void inputTreatment(FlaskList &myFlasks, FlaskList &auxFlasks){
  int volume;
  char function;

  while(std::cin >> volume >> function){
    if(function == 'i'){
      myFlasks.insertFlask(volume, 1);
    }else if(function == 'r'){
      myFlasks.removeFlask(volume);
    }else if(function == 'p'){
      auxFlasks.clearList();
      FlaskMeasurement(volume, myFlasks, auxFlasks);
    }

    std::cin.ignore();
    fflush(stdin);
  }
}

int main(){
  FlaskList myFlasks;
  FlaskList auxFlasks;
  inputTreatment(myFlasks, auxFlasks);
}
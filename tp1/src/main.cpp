#include "list.hpp"
#include <string>

void FlaskMeasurement(int volume, FlaskList &myFlasks, FlaskList &auxFlasks){
  if(volume == 0){
    std::cout << volume << std::endl;
    return;
  }
  Flask *aux;
  Flask *aux2;
  aux2 = myFlasks.getHead();
  for(int i=0; i<myFlasks.getNumberOfFlasks(); i++){
    if(aux2->volume == volume){
      std::cout << aux2->operations << std::endl;
      return;
    }
    auxFlasks.insertFlask(aux2->volume, aux2->operations);
    aux2 = aux2->next;
  }
  aux = auxFlasks.getHead();

  while(true){
    aux2 = myFlasks.getHead();
    for(int i=0; i<myFlasks.getNumberOfFlasks(); i++){
      if(aux->volume + aux2->volume == volume){
        std::cout << aux->operations + aux2->operations << std::endl;
        return;
      }else if(!auxFlasks.haveFlask(aux->volume + aux2->volume)){
        auxFlasks.insertFlask(aux->volume + aux2->volume, aux->operations + aux2->operations);
      }
      if(aux->volume - aux2->volume == volume){
        std::cout << aux->operations + aux2->operations << std::endl;
        return;
      }else if(aux->volume > aux2->volume && !auxFlasks.haveFlask(aux->volume - aux2->volume)){
        auxFlasks.insertFlask(aux->volume - aux2->volume, aux->operations + aux2->operations);
      }
      aux2 = aux2->next;
    }
    aux = aux->next;
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
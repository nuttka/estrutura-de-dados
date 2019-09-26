#include "list.hpp"

FlaskList::FlaskList(){
  this->head = nullptr;
  this->tail = nullptr;
  this->numberOfFlasks = 0;
}

FlaskList::~FlaskList(){

}

void FlaskList::insertFlask(int volume, int operations){
  Flask *newFlask = new Flask;
  newFlask->volume = volume;
  newFlask->operations = operations;

  if(this->numberOfFlasks == 0){
    this->head = newFlask;
    this->tail = newFlask;
  }else{
    this->tail->next = newFlask;
    this->tail = newFlask;
  }
  newFlask->next = nullptr;
  this->numberOfFlasks++;
}

void FlaskList::removeFlask(int volume){
  Flask *aux = this->head;
  // primeiro termo e unico da lista
  if(this->numberOfFlasks == 1){
    delete aux;
    this->head = nullptr;
    this->tail = nullptr;
    this->numberOfFlasks--;
    std::cout << "Volume deletado." << std::endl;
  } // primeiro termo mas n o unico
  else if(aux->volume == volume){
    this->head = aux->next;
    delete aux;
    this->numberOfFlasks--;
  }else{
    // termo do meio
    while(aux->next->next != nullptr){
      if(aux->next->volume == volume){
        Flask *auxNext = aux->next;
        aux->next = auxNext->next;
        std::cout << "Volume deletado." << std::endl;
        delete auxNext;
        this->numberOfFlasks--;
        return;
      }
      aux = aux->next;
    }
    // ultimo termo
    if(aux->next->volume == volume){
      Flask *auxNext = aux->next;
      delete auxNext;
      this->tail = aux;
      aux->next = nullptr;
      std::cout << "Volume deletado." << std::endl;
      this->numberOfFlasks--;
    }
  }
}

bool FlaskList::haveFlask(int volume){
  Flask *aux = this->head;
  int i;
  bool exist = false;
  for(i=0; i<this->numberOfFlasks; i++){
    if(aux->volume == volume){
      exist = true;
    }
    aux = aux->next;
  }
  delete aux;
  return exist;
}

void FlaskList::printList(){
  if(this->numberOfFlasks == 0){
    std::cout << "Lista vazia." << std::endl;
  }

  Flask *aux = this->head;
  int i;
  for(i=0; i<this->numberOfFlasks; i++){
    std::cout << aux->volume << " ml" << std::endl;  
    aux = aux->next;
  }
  delete aux;
}

void flaskMeasurement(int volume){
  FlaskList auxFlasks;
  auxFlasks.insertFlask(0, 0);
  int i;
  Flask *aux;
  aux = this->head;
  for(i=0; i<this->numberOfFlasks; i++){
    auxFlasks.insertFlask(aux->volume, aux->operations);
    aux = aux->next;
  }
  aux = auxFlasks.head->next;
  while(auxFlasks.haveFlask(volume)){
    
  }
}

#include "list.hpp"

FlaskList::FlaskList(){
  this->head = nullptr;
  this->tail = nullptr;
  this->numberOfFlasks = 0;
}

FlaskList::~FlaskList(){
  Flask* temp;
  while(this->head != nullptr){
    temp = this->head->next;
    delete this->head;
    this->head = temp;
  }
}

void FlaskList::clearList(){
  Flask* temp;
  while(this->head != nullptr){
    temp = this->head->next;
    delete this->head;
    this->head = temp;
  }
  this->head = nullptr;
  this->tail = nullptr;
  this->numberOfFlasks = 0;
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
      this->numberOfFlasks--;
    }
  }
}

bool FlaskList::haveFlask(int volume){
  Flask *aux = this->head;
  int i;
  for(i=0; i<this->numberOfFlasks; i++){
    if(aux->volume == volume){
      return true;
    }
    aux = aux->next;
  }
  return false;
}

void FlaskList::printList(){
  if(this->numberOfFlasks == 0){
    std::cout << "Lista vazia." << std::endl;
  }

  Flask *aux = this->head;
  int i;
  for(i=0; i<this->numberOfFlasks; i++){
    std::cout << "operations: " << aux->operations << " " << aux->volume << " ml" << std::endl;  
    aux = aux->next;
  }
  delete aux;
}

Flask* FlaskList::getHead(){
  return this->head;
}

int FlaskList::getNumberOfFlasks(){
  return this->numberOfFlasks;
}

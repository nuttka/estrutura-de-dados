#ifndef LIST_H
#define LIST_H

struct Flask{
  int volume;
  Flask *next;
}

class FlaskList{
  private:
    Flask *head;
    Flask *tail;
    int numberOfFlasks;
  public:
    FlaskList();
    ~FlaskList();
    void insertFlask(int volume);
    void removeFlask(int volume);
    bool haveFlask(int volume);
    void printList();
}
#endif
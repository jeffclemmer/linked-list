#include <iostream>
using namespace std;

// define a struct to hold each list node
struct node {
  int data;
  node *next = nullptr;
};

// a class that handles all the linked operations
class list {
private:
  node *start = nullptr;
  node *head = nullptr;
  int _length = 0;
public:

  // delete all nodes on class destruction
  ~list() {
    
    int deleted = 0;
    while (start != nullptr) {
      node *next = start->next;
      delete start;
      deleted++;
      if (next != nullptr)
        start = next;
      else
        break;
    }
    
    cout << "deleted " << deleted << " nodes" << endl;
    
  }
  
  
  int length() {
    return _length;
  };
  
  
  // push a node on to the back of the list 
  void push(const int &data) {
    cout << "pushing " << data << endl;
    node *newNode = new node;
    newNode->data = data;
    
    if (start == nullptr) {
      start = newNode;
      head = start;
    } else {
      head->next = newNode;
      head = head->next;
    }
    
    _length++;
    
  };
  
  
  // shift a node from the front of the list and delete the entry
  int shift() {
    if (start != nullptr) {
      int ret = start->data;
      
      node * next = start->next;
      delete start;
      
      start = next;
      
      _length--;
      
      return ret;
    }
    
    return 0;
  };

};


// do some quick testing in our main function
int main(int argc, char **argv) {
  
  // create a list
  list list;
  
  list.push(123);
  list.push(678);
  
  cout << "list length: " << list.length() << endl;
  
  cout << "shifted: " << list.shift() << endl;
  cout << "shifted: " << list.shift() << endl;
  
  cout << "list length: " << list.length() << endl;
  
  return 0;
}

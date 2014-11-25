//Sources consulted:
//Random: http://www.cplusplus.com/reference/cstdlib/rand/
//Arrays: http://www.tutorialspoint.com/cplusplus/cpp_arrays.htm
//Collaborator: Elias



#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Ship {

  private:
    int x;
    int y;
    bool status;

  public:
    //Constructor
    Ship(){
      status = true;
      y = rand() % 6 + 1;
      x = rand() % 6 + 1;

      cout<<"Calling constructor\n";

    }

    //Destructor
    ~Ship(){
      cout<<"Calling destructor\n";

    }

    //Get/set for locationX
    void setX(int n){
      x = n;
    }

    int getX(){
      return x;
    }

    //Get/set for locationY
    void setY(int n){
      y = n;
    }

    int getY(){
      return y;
    }


    //Get/set for isSunk

    bool isSunk(){
      return status;
    }

    void setStatus(bool n){
      status = n;

    }

}; //end of class



int main(){
  //create 5 ships

  Ship battleships[5];

  for (int i=1; i < 6; i++){
    // battleships[i].setLocation();
      cout << "Ship " << i << " @ " << battleships[i].getX() << ", " << battleships[i].getY() << ". Status: " << battleships[i].isSunk() << endl;

  }

} //end of main






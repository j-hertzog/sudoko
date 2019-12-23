#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//prototypes
bool checkTable(string n);

int main(int argc, char* argv[])
{
  //correct input
  if(argc != 2)
  {
    cout << "Error: Please enter the name of the text file you want to validate" << endl;
    return 1;
  }
  if(!checkTable(argv[1]))
  {
    cout << "Error: Incorrect grid format, please enter a 9x9 Sudoku grid" << endl;
    return 1;
  }



  return 0;
}

//checks if user submitted a 9x9 grid
bool checkTable(string n)
{
  ifstream ifile(n);

  //invalid file name
  if(ifile.fail())
    return false;
  
  int rows = 0;
  while(!ifile.fail())
  {
    string temp;
    getline(ifile,temp);

    if(ifile.fail())
      break;
    else
    { 
      //number of columns != 9 
      if(temp.size() != 9)
        return false;
    }
    rows++;
  }
  if(rows != 9)
    return false;
  else
    return true;
}







#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

//prototypes
bool checkTable(string n);

int main(int argc, char* argv[])
{
  //verify correct input
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


  //we have a valid 9x9 grid, check for unique characters in rows and columns
  ifstream mfile(argv[1]);
  int row = 0;
  int table[9][9];

  while(!mfile.fail())
  {
    unordered_set<int> s;
    string line;

    getline(mfile, line);

    //prevent bad input
    if(mfile.fail())
    {
      break;
    }

    for(int i = 0; i < 9; i++)
    {
      if(line[i] == ' ')
      {
        cout << "Error: Incomplete list, please fill in any empty spaces." << endl;
        return 1;
      }
      else
      {
        //use a hashset to make sure #'s are unique by rows 
        if(s.find(line[i]) == s.end())
        {
          //insert unique items into the hashset and a 2-d array to check by rows
          s.insert(line[i]);
          table[row][i] =line[i] - 48; // -48 for correct ascii to int conversion
          cout << line[i] << " ";
        }
        else
        {
          cout << "Table not correct: duplicate items in row " << row + 1 << endl;
          return 0;
        }
      }
    }
    cout << endl;
    row++;
  }
  
  //use the 2-d array we populated to check for unique columns
  

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



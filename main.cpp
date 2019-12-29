#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

//prototypes
bool checkTable(string n);
bool checkRC(string n);
bool sumNonets(string n, int sum);

int main(int argc, char* argv[])
{
  //verify correct input
  if(argc != 2)
  {
    cout << "Error: Please enter the name of the text file you want to validate" << endl;
    return 1;
  }
  else if(!checkTable(argv[1]))
  {
    cout << "Error: Incorrect grid format, please enter a 9x9 Sudoku grid" << endl;
    return 1;
  }
  
  //check for duplicates or spaces in rows and columns
  checkRC(argv[1]);

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

//verifies unique values in rows/columns
bool checkRC(string n)
{
  ifstream mfile(n);
  if(mfile.fail())
    return false;

  int row = 0;
  int table[9][9];

  while(!mfile.fail())
  {
    string line;
    getline(mfile, line);

    //prevent bad input
    if(mfile.fail())
      break;

    for(int i = 0; i < 9; i++)
    {
      //checks for spaces while populating 2d array
      if(line[i] == ' ')
      {
        cout << "Error: Incomplete list, please fill in any empty spaces." << endl;
        return false;
      }
      else
      {
          table[row][i] = line[i] - 48; // -48 for correct ascii to int conversion
          cout << line[i] << " ";
      }
    }
    cout << endl;
    row++;
  }
  for(int i = 0; i < 9; i++)
  {
    unordered_set<int> r;
    unordered_set<int> c;
      
    for(int j = 0; j < 9; j++)
    {
      //checking for unique values using 2 unordered sets
      //one for each orientation (row-wise) and (column-wise)
      if(r.find(table[i][j]) == r.end() && c.find(table[j][i]) == c.end())
      {
        r.insert(table[i][j]);
        c.insert(table[j][i]);
      }
      else
      {
        cout << "Sudoku table incorrect: duplicate items in the same row or column" << endl;
        return false;
      }
    }
  }
  return true;
}

bool sumNonets(string n, int sum)
{
  ifstream nfile(n);
  
  if(nfile.fail())
    return false;

  int count = 0;
  int sum1 = 0;
  int sum2 = 0;
  int sum3 = 0;

  while(!nfile.fail())
  {
    string line;
    getline(nfile, line);

    if(nfile.fail())
      break;
    
   if(count != 0 && count%3 ==0)
   {
     sum1 = 0;
     sum2 = 0;
     sum3 = 0;
   }
  }






}

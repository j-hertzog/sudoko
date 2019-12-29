#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

//prototypes
bool checkTable(string n);
bool checkRCN(string n);
bool sumNonets(string n, int sum);

int main(int argc, char* argv[])
{
  //verify correct inputs
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
  //check if the #'s in row, columns, and nonets are correct
  if(checkRCN(argv[1]))
  {
    cout << "Success, this sudoku table is correct!" << endl; 
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

//checks for unique items in each row/column and verifies that the sum of each nonet is 45
bool checkRCN(string n)
{
  ifstream mfile(n);
  if(mfile.fail())
    return false;

  int row = 0;
  int table[9][9];
  
  //pipes file input into 2d array and checks for unfilled spaces
  while(!mfile.fail())
  {
    string line;
    getline(mfile, line);

    //prevents bad input
    if(mfile.fail())
      break;

    for(int i = 0; i < 9; i++)
    {
      //check for spaces 
      if(line[i] == ' ')
      {
        cout << "Error: Incomplete list, please fill in any empty spaces." << endl;
        return false;
      }
      else
      {
        table[row][i] = line[i] - 48; // -48 for correct ascii to int conversion
      }
    }
    row++;
  }
 
  //for checking the sum of each horizontal nonet(3x3 grid)
  int sum1 = 0, sum2 = 0, sum3 = 0; 

  for(int i = 0; i < 9; i++)
  {
    unordered_set<int> r;
    unordered_set<int> c;
      
    for(int j = 0; j < 9; j++)
    {
      //checking for unique values using 2 unordered sets (row-wise) and (column-wise)
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

      //finding the sum of each # in a nonet
      if(j < 3)
        sum1 += table[i][j];
      else if(j < 6)
        sum2 += table[i][j];
      else
        sum3 += table[i][j];
    }
    //after we reach rows 3, 6, and 9 check and clear the sums 
    if((i+1)%3 == 0)
    {
      //check and clear sums
      if(sum1 != 45 || sum2 != 45 || sum3 != 45)
      {
        cout << "Sudoku table incorrect: the sum a 3x3 grid is not 45" << endl;
        return false;
      }
      else
      {
        //reset the sums for next three nonets
        sum1 = 0;
        sum2 =0;
        sum3 = 0;
      }
    }
  }
  return true;
}


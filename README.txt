Welcome to Sudoko, a lightweight Sudoku puzzle verifier.
  -parses and verifies a textfile with a "completed" sudoku table.
  -splits 9x9 table into 3, 3x3 tables to check if #'s are unique.

  To run this program: 
    -execute main with the text file of your choice

    ./main example_1.txt

  Example List:
    example_1.txt
      -complete and correct sudoku table 

    example_2.txt
      -incomplete sudoku table(empty spaces)

    example_3.txt
      -incorrect sudoku table(duplicate items)(rows)
        
    example_4.txt
      -incorrect sudoku table(duplicate items)(columns)
    
    example_5.txt
      -incorrect sudoku table(nonet sum is not 45) 
      -0 still counts as a unique #, but makes the sum < 45

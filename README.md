## Welcome to Sudoko, a lightweight Sudoku puzzle verifier
  -parses and verifies if a textfile contains a "completed" sudoku table.  
  -checks if each row and column contain unique #'s.  
  -checks if each nonet (one of the 9 3x3 tables) contain unique #'s.
    
![rules](https://raw.githubusercontent.com/j-hertzog/sudoko/master/img/sudoku_rules.jpg)


  To run this program: 
    -execute main with the text file of your choice

    ./main example_1.txt

##  Included Examples:
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

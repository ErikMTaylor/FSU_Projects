#================================================================
# PROGRAM -- Simple DNA Seuquences
# 
# AUTHOR: Erik Taylor
# FSU ID: emt20bd 
# RECITATION SECTION NUMBER: 1
# RECITATION INSTRUCTOR NAME:  Maitry Chauhan
# CGS 3465 - Fall 2022
# PROJECT NUMBER: 5
# DUE DATE: 11/10/2022
# 
# SUMMARY: 
# 
#  This progarm takes input from data file and processes multiple different options that
#   can be chosen by the user. 
# 
# INPUT: 
# 
#   User inputs the data file they want to work with, and also choses options from the menu.
#   
# BAD DATA CHECKING: 
#   
#   This program does not force upper case letters when searching for a substrand.
#   It does not check to make sure that the file includes only a DNA strand.
# 
# OUTPUT:
# 
#   The program outputs a menu of choices and it also prints out the conversion of each choice
#    in parralell with the original strand.
# 
# DATA STRUCTURES:  
# 
# Mix of strings and lists
# 
# ASSUMPTIONS:  
#
# Data files are not empty, only contain one DNA sequence, and do not contain data errors.
#  
#===============================================================
import random           #For psuedo random numbers
QUIT = 4                      #Constant for menu loop in  main

#Main Function---------------------------------------------------------------------------------------------------
def main():
    valid = False           #Holds a boolean to end the loop controlling valid file input.
    choice = 0               #Holds the value of users choice

    #While loop that ends when a valid file is entered.
    while not valid:
        #Try/Except statement that prevents an invalid file entry
        try:
            fileName = str(input("Enter the name of the file:"))    #Takes input for file name
            insert_file = open(fileName, 'r')                                     #Opens the file into variable
            original = str(insert_file.readline())                                #copies the file string into variable
            original = original.rstrip("\n")                                         #Strips the newline character
            valid = True
        except FileNotFoundError:
            print("File was not found")                                              #Prints if exception  occurs

    #Menu Loop
    while choice != QUIT:
        menu()                                                                  #Displays menu
        choice = int(input("Enter Your Choice:  "))       #Takes in userschoice
        print("-=-=-=-=-=-=-=-=-=-=-=-=-=-")

        if choice == 1:
            compliment = findCompliment(original)       #Gets compliment through function
            print("Original      :   ", original)                         #Displays original strand
            print("Complimet :   ", compliment)                  #Displays compliment strand
        elif choice == 2:
            mutant = makeMutant(original)                       #Gets mutated strand through function
            print("Original :   ", original)                               #Displays original
            print("Mutant  :   ", mutant)                               #Displays the mutation
        elif choice == 3:
            print("Original:    ", original)                                #Displays the original
            index = findStrand(original)                                #Gets the index from search function
            if index != -1:
                print("The strand was found at index ", index)      #Prints the index if found
            else:
                print("That strand was not found.")                         #Prints not found
        elif choice == 4:
            print("Quitting the program...")                                    #Prints closing statement
        else:
            print("That was not a vaild choice.")                             #Choice Validation
    
    return
#End of Main---------------------------------------------------------------------------------------------------

#Menu fucntion that displays the menu options. Gets called in main loop.-----------------------------
def menu():
    print("-=-=-=-=-=-=-=-=-=-=-=-=-=-")
    print("1.    Find the complement strand")
    print("2.    Make a mutation")
    print("3.    Find a substrand")
    print("4.    Quit")
    return
#End of Menu function---------------------------------------------------------------------------------------

#Function that gets called when 1 is chosen. Makes a compliment strand  and returns it.-------------
def findCompliment(original):
    compliment = ""                             #Initializes the compliment string as blank

    #For loop that iterates through each character in the original
    for character in original:
        #If statement that concatenates the reverse of each character to compliment strand
        if character == "G":
            compliment +=  "C"
        elif character == "C":
            compliment += "G"
        elif character == "T":
            compliment += "A"
        elif character == "A":
            compliment += "T"
        else:
            print("There is an invalid character.")         #Tests to make sure there is no weird characters
    
    return compliment                                                #Returns the compliment string
#End of Compliment Function-----------------------------------------------------------------------------

#Function that randomly picks four indexes to mutate when  2 is chosen. Returns the mutant string.
#----------------------------------------------------------------------------------------------------------------
def makeMutant(original):
    copy = list(original)           #Turns the original into a list of characters
    change = 0                          #Initializes the number of mutations that have occured
    mutant = ""                         #Initializes the mutant string to nothing

    #While loops that loops until there is 5 mutations
    while change < 5:
        #Gets a randomly generated number in the range of the string length
        #Stores it into index variable
        index = random.randrange(len(original))
        copy[index] = "M"                                                           #Changes the character at index to M
        change += 1                                                                     #Increments the number of changes

#For loop that iterates through all characters in the copy list
    for character in copy:
        mutant += character                 #Concotenates the letter to mutant string
        
    return mutant                                 #Returns the mutant string
#End of mutant function-------------------------------------------------------------------------------------

#Function that searches for a sunstrand when 3 is called. Takes in a substrand as input and returns
# the index of the strands location.-------------------------------------------------------------------------
def findStrand(original):
    strand = str(input("Enter in the strand you want to find:"))        #User enters substrand to find
    index = original.find(strand)                                                           #Searches for index and returns it
    return index                                                                                       #Returns the index
#End of findStrand function--------------------------------------------------------------------------------

main()      #Calls the main function to start

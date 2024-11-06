#================================================================
# PROGRAM -- Conversion Calculating Software
# 
# AUTHOR: Erik Taylor
# FSU ID: emt20bd 
# RECITATION SECTION NUMBER: 1
# RECITATION INSTRUCTOR NAME:  Maitry Chauhan
# CGS 3465 - Fall 2022
# PROJECT NUMBER: 3
# DUE DATE: 10/6/2022
# 
# SUMMARY: 
# 
# The program displays a menu and takes in a choice. The program then converts the entered
# American units to English units like meters or kilometers. The program only ends when the
# user choses to end it.
# 
# INPUT: 
# 
# The user inputs their choice of conversion, and then they enter the wanted units for that conversion.
#   
# BAD DATA CHECKING: 
#   
#   N/A
# 
# OUTPUT:
# 
# It displays a menu repeatedly until 'quit' is chosen. It also displays the calculated conversion
# for the chosen measurment.
# 
# DATA STRUCTURES:  
# 
# N/A
# 
# ASSUMPTIONS:  
# 
#  No letters are entered for the choice or the units.
#===============================================================

#Constants for Conversion
CENTIMETER = 2.54
METER = 0.3048
KILOMETER = 1.6094
KILOGRAM = 0.4536
LITER = 3.7853

#This is the main function that calls all the other functions. ===========================
def main():
    choice = 0   #To make sure the while loop starts.

    #Prints the welcom messages.
    print("Welcome to the Conversion Program!")
    print("Please choose an option below, or enter '6' to quit.")

    #While loop that iterates until the user choses to quit by entering 6.
    while( choice != 6 ):
        displayMenu()                      #Displays the menu of choices by calling the function.
        choice = getValidChoice()   #Calls the function that returns only valid choices.
        
        if(choice == 1):
            #Prints a message for the choice.
            print("Please enter the length in inches: ",  end = ' ')
            units = getValidUnits()                      #Calls function to store valid input into units.
            calculated = units * CENTIMETER    #Calculates the new measurement.
            #Prints the conversion with the input.
            print(f'{units: .3f} inches is equivalent to{calculated: .3f} centimeters.')
            
        elif(choice == 2):
            print("Please enter the length in feet: ", end = ' ')
            units = getValidUnits()
            calculated = units * METER
            print(f'{units: .3f} feet is equivalent to{calculated: .3f} meters.')
            
        elif(choice == 3):
            print("Please enter the length in miles: ", end = ' ')
            units = getValidUnits()
            calculated = units * KILOMETER
            print(f'{units: .3f} miles is equivalent to{calculated: .3f} kilometers.')
            
        elif(choice == 4):
            print("Please enter the weight in pounds: ", end = ' ')
            units = getValidUnits()
            calculated = units * KILOGRAM
            print(f'{units: .3f} pounds is equivalent to{calculated: .3f} kilograms.')
            
        elif(choice == 5):
            print("Please enter the volume in gallons: ", end = ' ')
            units = getValidUnits()
            calculated = units * LITER
            print(f'{units: .3f} gallons is equivalent to{calculated: .3f} liters.')
            
    #Prints the exit message.
    print("----Closing the Program.----")
    return    #Returns nothing.
#==============================================================

#This function is called in main, and it prints all the menu choices.======================
def displayMenu():
    print("1.  Inches to Centimeters")
    print("2.  Feet to Meters")
    print("3.  Miles to Kilometers")
    print("4.  Pounds to kilograms")
    print("5.  Gallons to Liters")
    print("6.  Quit the Program")

#This function is called in main, every time the loop iterates.
def getValidChoice():
    valid = False   #Holds the variable that keeps the loop iterating.

    #Loop iterates until a valid choice is entered.
    while( valid == False ):  
        choice = int(input("Please enter your choice."))               #Takes input and stores into choice.

        #If statement that tests to make sure input is valid.
        if( choice < 1 or choice > 6 ):
            print("That was not a valid choice. Please try again.")   #Prints if input is not valid.
        else:
            valid = True   #Ends the loop when input is valid.
    return choice         #Returns the valid input.
#==============================================================

#Function called inside each choice in main.===================================
def getValidUnits():
    valid = False

    #While loop that continues until a number is entered > 0.
    while( valid == False ):
        units = float(input())    #Takes input and stores it into the variable units.

        #If statement that tests to see if the input is valid.
        if( units <= 0 ):
            print("That was not valid input. It must be > 0.")
        else:
            valid = True   #Ends the loop.
    return units           #Returns the valid input.
#=============================================================

main() #Calls the main function.

#================================================================
# PROGRAM -- Sales Calculator Software
# 
# AUTHOR: Erik Taylor
# FSU ID: emt20bd 
# AUTHOR:  Erik Taylor
# FSU MAIL NAME:  EMT20BD
# RECITATION SECTION NUMBER: 1
# RECITATION INSTRUCTOR NAME:  Maitry Chauhan
# CGS 3465 - Fall 2022
# PROJECT NUMBER: 2
# DUE DATE: 9/22/2022
# 
# SUMMARY: 
# 
# The program takes in an amount of sales and then
#  calculates the price per unit and the total.
# 
# INPUT: 
# 
# The input is interactive and comes from the user.
#The program only runs if the input is correct.
#   
# BAD DATA CHECKING: 
#   
#   The program makes sure that the amount of sales is a whole integer above 0.
#   If it is not above zero, the program ends.
# 
# OUTPUT:
# 
# The program only outputs a welcome message, and the data in calculates.
# The calculated data is formated to two decimal points because it is money related.
# 
# DATA STRUCTURES:  
# 
# N/A
# 
# ASSUMPTIONS:  
# 
#  N/A
#===============================================================

#Variabel that holds the cost of a single unit.
 packagePrice = 99.00

#Welcome Message
print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-")
print("Welcome to the Software Sales Calculator")
print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-")

#Takes in the input of units sold into a variable.
soldUnits = float(input("How many units were sold? "))
#Validates input to make sure the program can run properly.
if(soldUnits < 1):
    print("Units sold must be greater than zero. Ending Program.")
    exit()

#Nested if statements that determine the discount cost.    
if(soldUnits < 10):
    print("There were not enough units to have a discount.")
    discount = 1
elif(soldUnits <20):
    discount = 0.20
elif(soldUnits < 50):
    discount = 0.30
elif(soldUnits < 100):
    discount = 0.40
else:
    discount = 0.50

#These are the calculations of the cost of each unit after discount
#and the new total cost after discount.
costPerUnit = packagePrice * discount
total = costPerUnit * soldUnits

#Prints out the calculations.
print(f'Your effective cost per unit is ${costPerUnit: .2f}')
print(f'The total cost of the purchase is ${total: .2f}')

#Exit Message
print("Execution Terminated Normally.")

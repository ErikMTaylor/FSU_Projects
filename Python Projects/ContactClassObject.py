#================================================================
# PROGRAM -- Contacts Class Objects List
# 
# AUTHOR: Erik Taylor
# FSU ID: emt20bd 
# RECITATION SECTION NUMBER: 1
# RECITATION INSTRUCTOR NAME:  Maitry Chauhan
# CGS 3465 - Fall 2022
# PROJECT NUMBER: 6
# DUE DATE: 11/29/2022
# 
# SUMMARY: 
# 
# 
# 
# INPUT: 
# 
#   
#   
# BAD DATA CHECKING: 
#   
#   
# 
# OUTPUT:
# 
#   
# DATA STRUCTURES:  
# 
# 
# 
# ASSUMPTIONS:  
#
# 
#  
#===============================================================

class Contact:
    def __init__(self):
        self.name = "unavailable"
        self.address = "unavailable"
        self.phone = "unavailable"
        self.age = int(0)
        self.type = "NONE"

    def getName(self):
        return self.name
    
    def getAddress(self):
        return self.address

    def getPhone(self):
        return self.phone

    def getAge(self):
        return self.age

    def getType(self):
        return self.type
    
    def setName(self, givenPerson):
        self.name = givenPerson

    def setAddress(self, givenAddress):
        self.address = givenAddress

    def setPhone(self, givenNumber):
        self.phone = givenNumber

    def setAge(self, givenAge):
        self.age = givenAge

    def setType(self, givenType):
        self.type = givenType


def main():
    print("Welcome to the Contacts Application!")
    try:
        open_file = open("contacts.txt", 'r')
    except:
        print("Wrong file name... Closing the program.")
        return

    contactList = list(range(5))
    for item in contactList:
        contactList[item] = Contact()
        
    numberContacts = int(open_file.readline())

    for index in range(numberContacts):
        contactList[index].setName(str(open_file.readline().rstrip("\n")))
        contactList[index].setAddress(str(open_file.readline().rstrip("\n")))
        contactList[index].setAge(int(open_file.readline()))
        contactList[index].setPhone(str(open_file.readline()))
        contactList[index].setType(str(open_file.readline().rstrip("\n")))

    for item in contactList:
        print("Name: ", item.getName())
        print("Age: ", item.getAge())
        print("Type: ", item.getType())
        print("Address: ", item.getAddress())
        print()
    

    return


main()


        

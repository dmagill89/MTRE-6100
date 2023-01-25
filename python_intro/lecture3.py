#!/usr/bin/env python3
#


print('hello world')
print("hello world")
#JSON format
print('{"message": "JSON Format"}')
print("{\"message\": \"JSON Format\"}")

variable = 10
# sum = variable + variable
# print(sum)
variable_2 = [10, 25, 5, -3]
print(sum(variable_2))

condition_variable = 1

# different ways to check conditionals
# if condition_variable == 1:
#     print('is one')
# if condition_variable == True:
#     print('test')

condition_variable = 0
if condition_variable:
    print('True')

condition_2 = 1

if condition_2 == 2:
    print('condition is:', condition_2)
elif condition_2 == 3:                      #else if in python is elif
    print('condition is:', condition_2)
else:
    print('condition is neither 2 or 3')

#------------------------------------------------------------------------#
# Python types Data Structures #
integer_type = 5
float_type = 5.0
string_type = str(5)
#plus additional data structures types including lists, dictionaries, tuples,
# sets, etc.

print(type(integer_type))
print(type(float_type))
print(type(string_type))

if type(integer_type) == type(int()):
    print('It is an integer')

#lists() - a collection of objects. It does not have to be the same type.
list_variable = [1, 3, 4, 10]
print(type(list_variable))

list_variable = [1, "string", 5.0, 4]
print('list_variable:', list_variable)

print(list_variable[1])
print(2 * list_variable[1])
print(2 * list_variable)

# different ways to define lists
list_variable = []
list_variable = list()
# you can add values in the list
list_variable = [1, 4, 7]
value_pop = list_variable.pop()

print(value_pop)
print(list_variable)

#--------------------------------------------------------------#
# tuples

#defining a tuple
tuple_variable = (2, 3)

#tuples can be converted from lists and backwards
tuple_variable = tuple([3, 4])

print(tuple_variable)
print(type(tuple_variable))

# unpacking tuples
variable_one, variable_two = tuple_variable

print('variable_one:', variable_one)
print('variable_two:', variable_two)

#--------------------------------------------------------------#
#dictionaries

dictionary_variable = dict()
dictionary_variable = {}
dictionary_variable = {"key_1": "value_1"}

print(dictionary_variable)
print(dictionary_variable.values())
print(dictionary_variable.keys())

#-------------------------------------------------------------#
# python sets - cannot have duplicate sets

set_variable = set()

#-------------------------------------------------------------#
# loops

print(range(6))
print(range(1, 6))
list_variable = [1, 2, 3, 4, 5, 10]

#using range for the for loop
for index in range(len(list_variable)):
    print(index, list_variable[index])

for item in list_variable:
    print(item)

# enumerate - returns the range count in the item
for index, item in enumerate(list_variable):
    print(index, item)

for index in range(1, 6):
    print(index)

for even in range(0,6,2):
    print(even)

while_conidtion = 0
while while_conidtion < 6:
    while_conidtion += 1
    print(while_conidtion)
else:
    print('do something when the initial condition is not met.')

#--------------------------------------------------------------#
# logic operators

variable_one = 4
variable_two = 8
if variable_one > 3 and variable_two < 9:
    print('both conditions met')
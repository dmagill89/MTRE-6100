#!/usr/bin/env python3

#dunder or magic methods double underscore __name__, __init__

def method():
    # pass allows you to skip this line of code
    pass
    # continue allos you to skip an iterator in a loop

def method2(param1):
    print(param1)

def method_2(param1 = None):
    print(param1)

def binary_hex():
    string = 'a'
    #ord = pythons method for converting char to int
    int_value = ord(string[0])
    print('int_value', int_value)
    encoded_variable = str.encode(string)
    print(encoded_variable)
    print(encoded_variable[0])
    print(encoded_variable.decode())
    print(chr(97))
    print(hex(int_value))
    print(bin(int_value))
    print(int(string[0], 16))
    print(hex(int(string[0], 16)))

def main():
    print('this is our main program')
    method()
    method2('this is a string')
    method_2()

global_variable = 20
def global_values():
    #reassignment makes the variable a local variable and no longer references it
    global_variable = 30

def lambda_funtions():
    doubler = lambda param1: param1 * param1
    print(doubler(2))

if __name__ == "__main__":
    main()
    binary_hex()
    print(global_variable)
    lambda_funtions()

class Base():

    # Class Constructor
    def __init__(self): #self similar to this keyword in c++
        print('Class Constructor')
        # self allow defining object to use within the class
        self.place_holder = None
        # without self, the object only exists as a local object
        second_item = None
    
    # Class Destructure
    def __del__(self):
        print('Class Destructor')

    def __add__(self, RHS):
        # check the type of the RHS and provide soutions for any type
        # type(RHS) == type(int())
        # type(RHS) == type(self)
        print('add was called')
        print(f'Our RHS is: {RHS}')
        print(f'The type is: {type(RHS)}')

        if type(RHS) == type(int()):
            print('We can do something with the integer')
            self.place_holder = 7


    def calc_avg(items = None):
        if items is None:
            return
        
    def print_information():
        print('This is the base class')

class Derived(Base):
    def __init__(self):
        print('Derived Class Constructor')

def main():
    base_object = Base()
    base_object2 = Base()
    base_object + base_object2
    base_object + 7

    derived = Derived()

if __name__ == '__main__':
    main()
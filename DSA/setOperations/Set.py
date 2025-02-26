class Sets:

    def __init__(self):                #constructor
        self.data = set()

    def __str__(self):                 #ensures that the set is printed for print() function
        return str(self.data)

    def create(self):                  # Creates a set
        n = int(input("Enter the number of Elements: "))
        for i in range(n):
            element = int(input("Enter an element: "))
            self.data.add(element)

    def add(self, element):            #Add an element to Set
        self.data.add(element)

    def remove(self, element):         #Removes an element from the set
        if element in self.data:
            self.data.remove(element)
        else:
            print("Element not found in set.")

    def contain(self, element):        #Checks whether the element is present or not in set
        if element in self.data:
            return True
        return False
    
    def size(self):                   # Returns the size of set
        return len(self.data)
    
    def intersection(self, otherSet): # Returns a set as a result containing  
                                      # common elements bet two sets
        result = Sets()

        for i in self.data:
            if i in otherSet.data:
                result.data.add(i)
        return result

    def union(self, otherSet):        # Returns all unique element 
                                      # of two sets
        result = Sets()

        for i in self.data:
            result.data.add(i)

        for i in otherSet.data:
            if i not in result.data:
                result.data.add(i)

        return result

    def difference(self, otherSet):   # Returns a set containing 
                                      # element which ar not in seond one
        result = Sets()

        for i in self.data:
            if i not in otherSet.data:
                result.data.add(i)

        return result

    def issubset(self, otherSet):     # Returns True if one set is subset of another one
        for i in self.data:
            if i not in otherSet.data:  
                return False  
        return True  

        
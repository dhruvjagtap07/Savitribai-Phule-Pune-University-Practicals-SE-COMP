from Set import Sets

a = Sets()
b = Sets()

while(True):                                          # MENU 
    print("============== < MENU > ================")
    print("1. Create SET.")
    print("2. Add an element.")
    print("3. Remove an element.")
    print("4. Contain (element present or not)")
    print("5. Size of the SET")
    print("6. Intersection of two sets.")
    print("7. Union. ")
    print("8. Differnece.")
    print("9. Subset.")
    print("10. EXIT.")
    print("======================================")
    choice = int(input("Enter choice: "))

    if choice == 1:                                # choice 1 : create set
        print("For SET 'A': ")
        a.create()
        print("SET A: ", a)

        print("For SET 'B': ")
        b.create()
        print("SET B: ", b)

    elif choice == 2:   
        print("Add Element: ")                     # choice 2 : add element 
        ele = int(input("Enter element to add: "))
        set_choice = input("Add to SET 'A' or 'B'? (A/B): ").strip().upper()
        if set_choice == "A" or set_choice == "a" or set_choice == "1":
            a.add(ele)
            print("Element added.")
        elif set_choice == "B" or set_choice == "b" or set_choice == "2":
            b.add(ele)
            print("Element added.")
        else:
            print("Invalid choice!")



    elif choice == 3:   
        print("Remove Element: ")                   # choice 3 : removes element
        ele = int(input("Enter element to remove: "))
        a.remove(ele)
        print("Element removed.")

    elif choice == 4:       
        print("Search: ")                           # choice 4 : checks presence of element
        ele = int(input("Enter element: "))
        if a.contain(ele):
            print("Element present")
        else:
            print("Element not present")

    elif choice == 5:
        print("Size: ")                             # choice 5 : Returns the size of set
        print("SET 'A' has", a.size(), "elements.")
        print("SET 'B' has", b.size(), "elements.")

    elif choice == 6:                              # choice 6 : intersection
        c = a.intersection(b)
        print("Intersection: " , c)

    elif choice == 7:                             # choice 7 : union
        c = a.union(b)
        print("Union: " , c)

    elif choice == 8:                             # choice 8 : difference
        c = a.difference(b)
        print("Difference (A-B): " , c)

    elif choice == 9:                             # choice 9 : issubset
        if (a.issubset(b)):
            print("set 'A' is subset of set 'B'.")
        else:
            print("set 'A' is not a subset of set 'B'.")
    
    elif choice == 10:                            # choice 10 : EXIT
        break

    else :
        print("Enter a valid choice.")           # invalid choice
    

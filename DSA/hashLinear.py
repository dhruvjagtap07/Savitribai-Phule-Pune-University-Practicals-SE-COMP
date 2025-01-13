
# Consider telephone book database of N clients. Make use of a hash table implementation 
# to quickly look up client‘s telephone number. Make use of two collision handling 
# techniques and compare them using number of comparisons required to find a set 
# of telephone numbers

def hashFun(key, n):
    return key % n


def insert(hashTable, n, probing):
    print("< < Insert > >")
    key = int(input("Enter Element: "))
    idx = hashFun(key, n)
    if probing == 1:  # Linear Probing
        if hashTable[idx] == -1:
            hashTable[idx] = key
        else:
            cnt = 0
            while hashTable[idx] != -1 and cnt < n:
                idx = (idx + 1) % n
                cnt += 1
            if cnt == n:
                print("Hash table is full!")
            else:
                hashTable[idx] = key
    elif probing == 2:  # Quadratic Probing
        i = 0
        while i < n:
            new_idx = (idx + i ** 2) % n
            if hashTable[new_idx] == -1:
                hashTable[new_idx] = key
                break
            i += 1
        if i == n:
            print("Hash table is full!")
    else:
        print("Invalid probing choice!")


def display(hashTable):
    print("< < Display > >")
    print("Hash Table: ", hashTable)


def search(hashTable, n, probing):
    print("< < Search > >")
    key = int(input("Enter Element: "))
    idx = hashFun(key, n)
    if probing == 1:  # Linear Probing
        cnt = 0
        while cnt < n:
            if hashTable[idx] == key:
                return True
            idx = (idx + 1) % n
            cnt += 1
    elif probing == 2:  # Quadratic Probing
        i = 0
        while i < n:
            new_idx = (idx + i ** 2) % n
            if hashTable[new_idx] == key:
                return True
            if hashTable[new_idx] == -1:  # Stop searching if empty slot found
                break
            i += 1
    return False


def delete(hashTable, n, probing):
    print("< < Delete > >")
    key = int(input("Enter Element: "))
    idx = hashFun(key, n)
    if probing == 1:  # Linear Probing
        cnt = 0
        while cnt < n:
            if hashTable[idx] == key:
                hashTable[idx] = -1
                return
            idx = (idx + 1) % n
            cnt += 1
    elif probing == 2:  # Quadratic Probing
        i = 0
        while i < n:
            new_idx = (idx + i ** 2) % n
            if hashTable[new_idx] == key:
                hashTable[new_idx] = -1
                return
            if hashTable[new_idx] == -1:  # Stop searching if empty slot found
                break
            i += 1
    print("Key not found!")


if __name__ == '__main__':
    n = int(input("Enter the size for Hash Table: "))
    hashTable = [-1] * n
    probing = int(input("Choose Probing Method:\n1. Linear Probing\n2. Quadratic Probing\nYour choice: "))
    while True:
        print("======== < MENU > =========")
        print("1. Insert.")
        print("2. Display.")
        print("3. Search.")
        print("4. Delete.")
        print("5. EXIT.")
        print("===========================")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            insert(hashTable, n, probing)
            display(hashTable)
        elif choice == 2:
            display(hashTable)
        elif choice == 3:
            if search(hashTable, n, probing):
                print("Key Found.")
            else:
                print("Key not Found.")
        elif choice == 4:
            delete(hashTable, n, probing)
            display(hashTable)
        elif choice == 5:
            break
        else:
            print("Enter valid choice.")

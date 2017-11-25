# Print all permutations of given elements

# Inserts the element into collection at each possible position. Returns the list of possibilities.
def insert_into(collection, element):
    collection = str(collection)
    element = str(element)
    perm_len = len(collection) + 1
    result = []
    for insert_idx in range(perm_len):
        perm = []
        c_idx = 0
        for perm_idx in range(perm_len):
            if perm_idx == insert_idx:
                perm.append(element)
            else:
                perm.append(collection[c_idx])
                c_idx += 1
        result.append(''.join(perm))
    return result

# Returns a list of all permutations of elements in collection
def permutations_of(collection):
    collection = str(collection)
    if(len(collection) == 2):
        return insert_into(collection[1], collection[0])
    part_result = permutations_of(collection[1:])
    result = []
    for i in part_result:
        result.extend(insert_into(i, collection[0]))
    return result

def main():
    perms = permutations_of(1234)
    print(perms)
    print(len(perms))

if __name__ == '__main__':
    main()

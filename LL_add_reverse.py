from LL_linked_list import Node, LinkedList

# Add 2 numbers using linked lists

# Takes two linked lists with integer data and returns a linked list containing their sum.
# If both linked lists are empty returns an empty list. If any one list is empty, returns the other
# list.
def add_reverse(first, second):
    # If any of the lists are empty then return the other list
    if first.head is None:
        return second
    if second.head is None:
        return first

    node_first = first.head
    node_second = second.head
    sum_list = LinkedList()
    node_sum = sum_list.head
    carry = 0

    while node_first is not None or node_second is not None:
        digit_first = node_first.data if node_first is not None else 0
        digit_second = node_second.data if node_second is not None else 0
        
        _sum = digit_first + digit_second + carry
        if _sum >= 10:
            carry = 1
            _sum = _sum % 10
        else:
            carry = 0

        if node_sum is None:
            sum_list.head = Node(_sum)
            node_sum = sum_list.head
        else:
            node_sum.next = Node(_sum)
            node_sum = node_sum.next

        if node_first is not None:
            node_first = node_first.next
        if node_second is not None:
            node_second = node_second.next

    if carry is 1:
        node_sum.next = Node(1)

    return sum_list

def main():
    list1 = LinkedList()
    list1.prepend(1)
    list1.prepend(9)
    list1.prepend(9)
    list1.prepend(0)
    list1.print()

    list2 = LinkedList()
    list2.prepend(8)
    list2.prepend(9)
    list2.prepend(0)
    list2.prepend(9)
    list2.print()

    add_reverse(list1, list2).print()

if __name__ == '__main__':
    main()
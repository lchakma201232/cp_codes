class Node(object):
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

def duplicate_largest(node):
    current=node
    largest=node
    while current.next:
        if current.data>largest.data:
            largest=current
        current=current.next
    temp = largest.next
    largest.next = Node(largest.data, temp)
    largest.next.next = temp
    return largest.next.value


class Array:
    def __init__(self, list):
        self.list = list

    def delete_items_from_list(self, values_to_delete):
        for value in values_to_delete:
            while value in self.list:
                self.list.remove(value)


def array_diff(a, b):
    my_array = Array(a)
    my_array.delete_items_from_list(b)

    return my_array.list


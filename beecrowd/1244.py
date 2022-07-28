class SetOfStrings:

    def __init__(self, set_of_strings):
        self.set_of_strings = set_of_strings
        self.list_of_strings = set_of_strings.split()
        self.number_of_strings = len(self.list_of_strings)
        self.list_of_strings_with_string_size = []

    def get_size_of_each_string(self):
        for index in range(self.number_of_strings):
            size_of_that_string = len(self.list_of_strings[index])
            self.list_of_strings_with_string_size.append((self.list_of_strings[index], size_of_that_string))

    def sort_list_of_strings_with_string_size(self):
        self.list_of_strings_with_string_size.sort(reverse=True, key=lambda y: y[1])

    def print_list_of_strings_in_order(self):
        for index in range(self.number_of_strings):
            if index != self.number_of_strings-1:
                print(f"{self.list_of_strings_with_string_size[index][0]}", end=" ")
            else:
                print(self.list_of_strings_with_string_size[index][0])


if __name__ == "__main__":

    number_of_sets_of_strings = int(input())

    while number_of_sets_of_strings>0:
        string_set = input()
        string_set = SetOfStrings(string_set)

        string_set.get_size_of_each_string()
        string_set.sort_list_of_strings_with_string_size()
        string_set.print_list_of_strings_in_order()

        number_of_sets_of_strings -=1
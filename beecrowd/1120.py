
class ContractValue:

    def __init__(self, failed_digit, true_value, value_is_null=True):
        self.failed_digit = failed_digit
        self.true_value = true_value
        self.value_is_null = value_is_null
        self.final_value = ""

    def get_final_value(self):
        for number in self.true_value:
            if number != self.failed_digit:
                self.value_is_null = False
                self.final_value += number

        return self.final_value




if __name__ == "__main__":

    flawed_digit_and_agreed_value = input()

    while flawed_digit_and_agreed_value != "0 0":

        flawed_digit_and_agreed_value = flawed_digit_and_agreed_value.split()
        flawed_digit = flawed_digit_and_agreed_value[0]
        agreed_value = flawed_digit_and_agreed_value[1]

        trueContract = ContractValue(flawed_digit, agreed_value)

        final_value = trueContract.get_final_value()


        if trueContract.value_is_null:
            print(0)
        else:
            final_value = int(final_value)
            print(final_value)



        flawed_digit_and_agreed_value = input()
number_of_states = int(input())
alphabet = input().split(' ')
alphabet.pop(0)

alphabet_size = len(alphabet)

number_of_transitions = alphabet_size * number_of_states
transitions = {}

while number_of_transitions > 0:
    transition = input().split(' ')
    transition_function = (transition[0], transition[1])
    transitions[transition_function] = transition[2]
    number_of_transitions -= 1 

initial_state = input()
accepted_states = input().split(' ')
accepted_states.pop(0)

input_symbols = input()

state = initial_state

for symbol in input_symbols:
    state = transitions[(state, symbol)]

if state in accepted_states:
    print("Aceito")
else:
    print("Rejeito")

from typing import Set


number_of_states = int(input())
alphabet = input().split(' ')
alphabet.pop(0)

alphabet_size = len(alphabet)

number_of_transitions = alphabet_size * number_of_states
transitions = {}

states = []

while number_of_transitions > 0:
    transition = input().split(' ')

    if transition[0] not in states:
        states.append(transition[0])

    transition_function_dec = (transition[0], transition[1])
    if transition[2] != 0:
        transitions[transition_function_dec] = set(transition[3:len(transition)])
    number_of_transitions -= 1 

initial_state = input()
accepted_states = input().split(' ')
accepted_states.pop(0)

input_symbols = input()

current_states = {initial_state}

for symbol in input_symbols:
    possible_states = []
    cur_states_buf = []
    for state in current_states:
        cur_states_buf.append(state)
        possible_states += transitions[(state, symbol)]

    for state in cur_states_buf:
        current_states.remove(state)

    current_states.update(possible_states)

accepted = False

for state in current_states:
    if state in accepted_states:
        print("Aceito")
        accepted = True
        break
        
if not accepted:
    print("Rejeito")


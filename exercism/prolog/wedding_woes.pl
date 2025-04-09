% Define the 'chatty' fact

chatty(gustavo).
chatty(valeria).

% Define the 'likes' fact

likes(esteban, malena).
likes(malena, esteban).
likes(gustavo, valeria).

% Define the 'pairing' rule

pairing(A, B) :-
    chatty(A) ;
    chatty(B).

pairing(A,B) :- 
    likes(A,B) ,
    likes(B,A) .

% Define the 'seating' rule
seating(A,B,C,D,E) :-
    is_set([A,B,C,D,E]),
    pairing(A,B),
    pairing(B,C),
    pairing(C,D),
    pairing(D,E),
    pairing(E,A).



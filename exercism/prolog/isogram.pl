isogram(Phrase) :-
    string_lower(Phrase, Y),
    atom_string(Y, X), % turns the phrase into a string
    split_string(X, - , - , Res), % now I have a list of strings without non-letter characters
    atomics_to_string(Res, String) ,
    string_codes(String, SingleChars), 
    is_set(SingleChars) .


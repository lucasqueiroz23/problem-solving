male(abraham).
male(clancy).
male(herb).
male(homer).
male(bart).

female(mona).
female(jackie).
female(marge).
female(patty).
female(selma).
female(lisa).
female(maggie).
female(ling).

father(abraham, herb).
father(abraham, homer).
father(clancy, marge).
father(clancy, patty).
father(clancy, selma).
father(homer, bart).
father(homer, lisa).
father(homer, maggie).

mother(mona, herb).
mother(mona, homer).
mother(jackie, marge).
mother(jackie, patty).
mother(jackie, selma).
mother(marge, bart).
mother(marge, lisa).
mother(marge, maggie).
mother(selma, ling).

uncle(Unc, Neph) :-
    father(F, Unc), father(F, Dad), Unc \= Dad, father(Dad, Neph).

grandmother(Grandma, Person) :-
    mother(Grandma, Mother),
    Grandma \= Mother,
    mother(Mother, Person).

grandmother(Grandma, Person) :-
    mother(Grandma, Father),
    father(Father, Person).

estudante(ana, 3, 'Engenharia de Software').
estudante(beto, 1, 'Engenharias').
estudante(carlos, 4, 'Engenharia de Energia').
estudante(diane, 2, 'Engenharias').
estudante(euler, 1, 'Engenharias').
estudante(fabio, 5, 'Engenharia de Software').
estudante(gustavo, 8, 'Engenharia de Software').
estudante(heitor, 7, 'Engenharia de Energia').
estudante(ian, 3, 'Engenharias').

matricula('C´alculo 1', ana).
matricula('C´alculo 1', fabio).
matricula('C´alculo 1', diane).
matricula('C´alculo 1', euler).
matricula('C´alculo 1', gustavo).
matricula('C´alculo 1', ian).

matricula('IAL', beto).
matricula('IAL', diane).
matricula('IAL', euler).

matricula('APC', carlos).
matricula('APC', fabio).
matricula('APC', gustavo).
matricula('APC', ian).

software :- estudante(Estudante,_, 'Engenharia de Software'), write(Estudante), nl.

tem_calouros(Materia) :- 
    estudante(Aluno, 1, _),
    matricula(Materia, Aluno).

turma_mista(Materia) :-
    matricula(Materia, A),
    matricula(Materia, B),
    matricula(Materia, C),
    Curso1 \= Curso2,
    Curso2 \= Curso3,
    Curso3 \= Curso1,
    estudante(A, _, Curso1),
    estudante(B,_, Curso2),
    estudante(C,_, Curso3).

% triangle(Side, Side, Side, Type) .

valid_triangle(A,B,C) :- 
    A + B >= C,
    C + B >= A,
    A + C >= B,
    A > 0 ,
    B > 0 ,
    C > 0 .

% equilatero
triangle(S,S,S, "equilateral") :- S > 0.
% isoceles
triangle(A,A,B,"isosceles") :- valid_triangle(A,A,B).
triangle(A,B,A,"isosceles") :- valid_triangle(A,A,B).
triangle(B,A,A,"isosceles") :- valid_triangle(A,A,B).
% escaleno

triangle(A,B,C,"scalene") :- valid_triangle(A,B,C), A \= B, B \= C, C \= A. 


descompone(N,X,Y) :-
    between(1,N,A),  % A candidato
    X is A*A*A,
    X =< N,
    Y is N - X,
    round(Y**(1/3))**3 =:= Y.  % Verificar si Y es cubo


mcd(X,0,X) :- X > 0, !.
mcd(X,Y,Z) :-
    Y > 0,
    R is X mod Y,
    mcd(Y,R,Z).


sumacubos(0,0).
sumacubos(N,R) :-
    N > 0,
    N1 is N - 1,
    sumacubos(N1,R1),
    R is R1 + N*N*N.


fac_in(1,1).
fac_in(2,2).
fac_in(N,R) :-
    










fac(1,1).           % Caso base
fac(N,R) :-
    N > 1,
    N1 is N - 1,
    fac(N1,R1),
    R is N1 * R1.   % Se calcula

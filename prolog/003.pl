suma_lista([],0).

suma_lista([Head|Tail],Suma) :-
    suma_lista(Tail,Suma1),
    Suma is Suma1 + Head.
%_________________________________/

fibo(0, 0).
fibo(1, 1).

fibo(Q,Fi) :-
    Q > 1,
    Q1 is Q - 1,
    Q2 is Q - 2,
    fibo(Q1,Fi1),
    fibo(Q2,Fi2),
    Fi is Fi1 + Fi2.
%_______________________/

fac(0,1).
fac(1,1).

fac(N,F) :-
    N > 1,
    N1 is N - 1,
    fac(N1,F1),
    F is N * F1.
%____________________/

betuin_final(A,B,Z) :-
    A =:= B,
    Z is A;
    A > B,
    A =:= B + 1,
    Z is B.

betuin(A,B,Z) :-
    (A =:= B,
    Z is A,
    !);
    A1 is A + 1,
    B1 is B - 1,
    (
        (betuin_final(A1,B1,Z1),
        Z is Z1,
        !);
        betuin(A1,B1,Z)
    ).

arimetic_betuin(A,B,Z) :-
    A =< B,
    Z is floor((A + B) / 2).
%___________________________________/

maximo(X,Y,X) :- X >= Y.
maximo(_,Y,Y).
%___________________________/
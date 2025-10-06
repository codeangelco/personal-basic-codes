padre(homero,bart).
padre(abraham,homero).
padre(abraham,herbert).
padre(homero,lisa).
padre(homero,maggie).
padre(clancy,marge).
padre(clancy,patty).
padre(clancy,selma).
madre(mona,homero).
madre(mona,herbert).
madre(marge,bart).
madre(marge,lisa).
madre(marge,maggie).
madre(jacqueline,marge).
madre(jacqueline,selma).
madre(jacqueline,patty).
madre(selma,ling).

abuelo(X,Y) :-
    padre(X,Z), padre(Z,Y).

abuela(X,Y) :-
    madre(X,Z), madre(Z,Y).

hermanos(X, Y) :-
    (padre(P, X); madre(P, X)), (padre(P, Y); madre(P, Y)),
    X \= Y.

tios(Y,X) :-
    hermanos(P,Y), (padre(P,X); madre(P,X)).

primos(X,Y) :-
    tios(T,X), (padre(T,Y); madre(T,Y)).



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


estadounidense(west).
asiatico(chingchang).
enemigo(usa,ksur).
armas(misiles).
vende(west,misiles,ksur).

culpable(X):-
    estadounidense(X),vende(X,Y,Z),armas(Y),enemigo(usa,Z).


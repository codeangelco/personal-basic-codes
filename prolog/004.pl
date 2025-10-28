% Ejercicio 1: Árbol Genealógico de los Simpson con Listas

% Hechos - Relaciones directas usando listas
padres([abraham, [homero, herbert]]).
padres([homero, [bart, lisa, maggie]]).
padres([clancy, [marge]]).

madres([mona, [homero]]).
madres([marge, [bart, lisa, maggie]]).
madres([jackie, [marge]]).

% Predicado auxiliar para verificar si X es miembro de una lista
miembro(X, [X|_]).
miembro(X, [_|T]) :- miembro(X, T).

% Reglas con listas
padre(X, Y) :- padres([X, Hijos]), miembro(Y, Hijos).
madre(X, Y) :- madres([X, Hijos]), miembro(Y, Hijos).

progenitor(X, Y) :- padre(X, Y).
progenitor(X, Y) :- madre(X, Y).

abuelo(X, Y) :- padre(X, Z), progenitor(Z, Y).
abuela(X, Y) :- madre(X, Z), progenitor(Z, Y).

hermanos(X, Y) :- padre(P, X), padre(P, Y), X \= Y.
hermanos(X, Y) :- madre(M, X), madre(M, Y), X \= Y.

tio(X, Y) :- hermanos(X, Z), progenitor(Z, Y).

ancestros(X, [X]).
ancestros(X, [X|Lista]) :- progenitor(P, X), ancestros(P, Lista).

% Ejercicio 2: Coronel West con Listas

% Hechos usando listas
estadounidenses([west]).
enemigos_usa([corea_sur, irak, iran]).
misiles([m1, m2, m3]).
ventas([[west, m1, corea_sur], [west, m2, corea_sur]]).

% Predicado auxiliar
es_miembro(X, [X|_]).
es_miembro(X, [_|T]) :- es_miembro(X, T).

% Reglas
estadounidense(X) :- estadounidenses(Lista), es_miembro(X, Lista).
nacion_hostil(X) :- enemigos_usa(Lista), es_miembro(X, Lista).
misil(X) :- misiles(Lista), es_miembro(X, Lista).

vendio(Vendedor, Arma, Comprador) :- 
    ventas(Lista), 
    es_miembro([Vendedor, Arma, Comprador], Lista).

arma(X) :- misil(X).

vendio_armas(Vendedor, Comprador) :- 
    vendio(Vendedor, Arma, Comprador),
    arma(Arma).

criminal(X) :- 
    estadounidense(X),
    vendio_armas(X, Y),
    nacion_hostil(Y).

% Consulta: ?- criminal(west).
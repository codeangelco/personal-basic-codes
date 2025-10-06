progenitor(clara,jose).
progenitor(tomas,jose).
progenitor(tomas,isabel).
progenitor(jose,ana).
progenitor(jose,patricia).
progenitor(patricia,jaime).


/* 

### 1.1
progenitor(jaime,X). -> false
Jaime tiene un hijo o hija?

progenitor(X,jaime). -> X = patricia
Quien es el progenitor de jaime?

progenitor(clara,X), progenitor(X,patricia). -> X = jose
Quien es el progenitor de patricia, que al mismo tiempo es decendiente de clara?

progenitor(ana,X), progenitor(X,Y), progenitor(X,Z). -> X = jose ...
Quienes son los niet@s de ana? 

_________________________________________________________________________________________
### 1.2
Quien es el progenitor de patricia?
progenitor(X,patricia). -> X = jose

Tiene isabel un hijo o una hija?
progenitor(isabel,X). -> false

Quien es el abuelo de isabel?
progenitor(X,Y), progenitor(Y,isabel). -> false

Cuales son los tios de patricia. (no excluir al padre)
progenitor(X,patricia), progenitor(P,X), progenitor(P,Z), Z \= X. -> X = jose, P = tomas, Z = isabel .

 */

% ___________________________________________________________________________________
% 1.3
hombre(jose).
hombre(tomas).
hombre(jaime).
mujer(patricia).
mujer(ana).
mujer(clara).
mujer(isabel).

dif(X,Y) :- X \= Y.

es_madre(X) :-
    mujer(X), progenitor(X,_).

es_padre(X) :-
    hombre(X), progenitor(X,_).

es_hijo(X) :-
    hombre(X), progenitor(_,X).

hermana_de(Hermana,Hermano) :-
    dif(Hermana,Hermano), progenitor(Padre,Hermana), progenitor(Padre,Hermano), mujer(Hermana).

abuelo_de(Abuelo,Nieto) :-
    progenitor(Abuelo,Padre), progenitor(Padre,Nieto), hombre(Abuelo), !.

abuela_de(Abuela,Nieto) :-
    progenitor(Abuela,Padre), progenitor(Padre,Nieto), mujer(Abuela), !.

hermanos(Hermano,Hermana) :-
    progenitor(Progenitor,Hermano), progenitor(Progenitor,Hermana), dif(Hermano,Hermana).

tia(Tia,Sobrino) :-
    mujer(Tia), progenitor(Progenitor,Sobrino), hermanos(Progenitor,Tia).

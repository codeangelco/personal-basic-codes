estadounidense(west).
asiatico(chingchang).
enemigo(usa,ksur).
armas(misiles).
vende(west,misiles,ksur).

culpable(X):-
    estadounidense(X),vende(X,Y,Z),armas(Y),enemigo(usa,Z).



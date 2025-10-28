% A continuación les relaciono los enunciados de los puntos a ser resueltos como segundo parcial de la asignatura.

% Punto 1. Ensamblaje de una bicicleta (modelado con estructuras y listas)

% Construir un programa en Prolog que modele la relación de piezas necesarias para construir una
% bicicleta utilizando estructuras y listas.
%    1. Defina los hechos necesarios que representen las piezas y sus componentes.
%    2. Defina las reglas que permitan consultar el conjunto de piezas básicas necesarias para construiruna pieza compuesta.
%    3. Las piezas básicas deben corresponder a los nodos hoja del árbol.

% Ejemplo:
% ?- componentes(bicicleta, ListaPiezas).
% ListaPiezas = [rueda_delantera, rueda_trasera, cuadro, sillin, cadena, pedal].

% Justificación Punto 1:
% a) Representacion de relaciones: Basicamente use componente/2 donde pongo primero la pieza grande
%    y despues una lista con las partes que la forman. Me parecio la forma mas facil de organizar
%    todo porque asi cada pieza se va dividiendo en sus partes mas chicas de manera natural.
% b) Uso de listas: Decidi usar listas porque una pieza puede tener varias partes (por ejemplo la
%    bicicleta tiene 6 cosas). Ademas las listas son mas faciles de recorrer con recursion usando
%    [P|Ps] y puedo ir juntando los resultados con append/3 que ya viene incluido en prolog.
% c) Piezas sin componentes: Para las piezas que no se dividen en mas partes use \+ componente(Pieza, _)
%    que basicamente pregunta si NO existe una definicion de componentes para esa pieza. Si no existe
%    entonces ya es una pieza basica y la devuelvo asi como esta sin seguir buscando mas partes.

% Punto 2. Árboles binarios y generaciones.

% Un árbol binario se representa con:
%     • nil  -> árbol vacío.
%     • t(I,R,D) -> raíz R, subárbol izquierdo I y derecho D.

% Defina la relación generacion(+N,+ListaDeArboles,-ListaDeNodos) que determine la lista de nodos de la generación N.

% Ejemplo:
% ?- generacion(0,[t(t(nil,2,nil),3,nil),t(nil,4,t(nil,5,nil))],L).
% L = [3, 4].
% ?- generacion(1,[t(t(nil,2,nil),3,nil),t(nil,4,t(nil,5,nil))],L).
% L = [2, 5].

% Justificación Punto 2:
% a) Manejo de recursión: La recursion basicamente va bajando nivel por nivel. Primero le resto 1 al
%    numero N hasta que llegue a 0, y tambien voy procesando la lista de arboles. Cuando N es mayor
%    que 0 saco los hijos de todos los arboles y vuelvo a llamar la funcion con N-1, y asi hasta que
%    N sea 0 y ahi ya solo agarro las raices de los arboles.
% b) Combinación de resultados: Use append/3 porque necesitaba juntar todas las listas de hijos en una
%    sola lista grande. En la parte de hijos/2 cada arbol me da [I,D] que son los dos hijos, y con
%    append voy pegando todo eso con el resto de hijos. Es la forma mas facil que encontre para no
%    tener listas dentro de listas y que todo quede plano.
% c) Gestión de árboles vacíos: Los nil los ignoro directamente. Puse reglas especiales que cuando
%    encuentran un nil simplemente lo saltan y siguen con el resto de la lista. Esto pasa tanto en
%    generacion/3 como en hijos/2, asi no tengo que andar validando despues si hay nil en los
%    resultados porque nunca llegan ahi.

% Punto 1: Ensamblaje de bicicleta

% Echos: definicion de componentes
componente(bicicleta, [rueda_delantera, rueda_trasera, cuadro, sillin, manubrio, transmision]).
componente(rueda_delantera, [llanta, rayos, eje]).
componente(rueda_trasera, [llanta, rayos, eje]).
componente(transmision, [cadena, pedal, plato]).

% Regla prinsipal: obtener todas las piesas basicas
% Caso base: piesa basica (sin componentes)
componentes(Pieza, [Pieza]) :- 
    \+ componente(Pieza, _).

componentes(Pieza, ListaPiezas) :- 
    componente(Pieza, Partes),
    componentes_lista(Partes, ListaPiezas).

% Auksilia: procesar lista de partes
componentes_lista([], []).
componentes_lista([P|Ps], Result) :- 
    componentes(P, R1),
    componentes_lista(Ps, R2),
    append(R1, R2, Result).

    % Reglas adicionales para consultas sovre piezas

% Verificar si una piesa es basica (no tienee componentes)
es_basica(Pieza) :- 
    \+ componente(Pieza, _).

% Verificar si una piesa es compuésta
es_compuesta(Pieza) :- 
    componente(Pieza, _).

% Contar numero de piesas basicas nesesarias
cantidad_piezas_basicas(Pieza, Cantidad) :- 
    componentes(Pieza, ListaPiezas),
    length(ListaPiezas, Cantidad).

% Verificar si una piesa basica especifica es nesesaria para construir una piesa compuesta
necesita_pieza(PiezaCompuesta, PiezaBasica) :- 
    componentes(PiezaCompuesta, ListaPiezas),
    member(PiezaBasica, ListaPiezas).

% Punto 2: Jeneraciones en arboles binarios

% Caso base: jeneracion 0 retorna las raices
generacion(0, [], []).
generacion(0, [nil|Rest], L) :- 
    generacion(0, Rest, L).
generacion(0, [t(_,R,_)|Rest], [R|L]) :- 
    generacion(0, Rest, L).

% Caso recursivo: jeneracion N > 0
generacion(N, Arboles, L) :- 
    N > 0,
    N1 is N - 1,
    hijos(Arboles, Hijos),
    generacion(N1, Hijos, L).

% Obtener ijos de una lista de arboles
hijos([], []).
hijos([nil|Rest], Hijos) :- 
    hijos(Rest, Hijos).
hijos([t(I,_,D)|Rest], Hijos) :- 
    hijos(Rest, HijosRest),
    append([I, D], HijosRest, Hijos).

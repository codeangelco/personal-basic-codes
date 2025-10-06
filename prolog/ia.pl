% chat_saludos_corrector.pl
% Mini-chat: detección + corrección ortográfica simple (Levenshtein)
% SWI-Prolog

:- module(chat_saludos_corrector, [chat_saludos/0]).
:- use_module(library(lists)).  % keysort, min_list, etc.

% --- Punto de entrada ---
chat_saludos :-
    writeln('Mini chat de saludos con corrección ortográfica. Escribe "salir" o "adios" para terminar.'),
    chat_loop.

chat_loop :-
    write('Tú: '), flush_output,
    read_line_to_string(user_input, Line),
    ( Line == end_of_file -> nl
    ; string_lower(Line, Low),
      ( contains_exit(Low) ->
          writeln('Bot: ¡Adiós!')
      ;
          process_greeting(Line, Low, Reply),
          format('Bot: ~s~n', [Reply]),
          chat_loop
      )
    ).

% --- Salidas ---
contains_exit(Low) :-
    member(Sub, ["salir","adios","adiós","hasta luego"]),
    sub_string(Low, _, _, _, Sub).

% --- Procesamiento principal ---
process_greeting(Line, Low, Reply) :-
    % Tokens: original (para eco) y versión limpia (para matching)
    split_string(Line, " \t", " \t\n\r", OrigWords),
    strip_punct(Low, CleanLow),
    split_string(CleanLow, " \t", " \t", WordsClean),

    greeting_single_list(Singles),    % lista de pares key-canonical (single-words)
    greeting_multi(MultiList),        % saludos multi-palabra -> canonical

    ( % 1) Si hay un prefijo conocido en alguna palabra -> eco de la palabra original
      find_prefix_match(WordsClean, OrigWords, Singles, OrigToken, _Canon) ->
        strip_surrounding_punct(OrigToken, OT),
        format(string(Reply), '¡~s!', [OT])
    ; % 2) Fuzzy match sobre palabras simples -> devolver canonical corregido
      best_single_fuzzy(WordsClean, Singles, BestKey, BestCanon, BestDist),
      string_length(BestKey, KeyLen),
      threshold_for_key(KeyLen, Th),
      BestDist =< Th ->
        format(string(Reply), '¡~s!', [BestCanon])
    ; % 3) Fuzzy match sobre frases multi-palabra
      best_multi_fuzzy(CleanLow, MultiList, BestMultiKey, BestMultiCanon, Dist2),
      string_length(BestMultiKey, KeyLen2),
      threshold_for_key(KeyLen2, Th2),
      Dist2 =< Th2 ->
        format(string(Reply), '¡~s!', [BestMultiCanon])
    ; % 4) Fallback: eco limpio de la entrada (quita saltos y espacios extremos)
      strip_surrounding_punct(Line, L2),
      format(string(Reply), '¡~s!', [L2])
    ).

% --- Prefijo/exacto (echo) ---
find_prefix_match([C|_Ctail], [O|_Otail], Singles, O, Canon) :-
    strip_surrounding_punct(C, Clean),
    member(Key-Canon, Singles),
    sub_string(Clean, 0, _, _, Key), !.
find_prefix_match([_|Cs], [_|Os], Singles, Orig, Canon) :-
    find_prefix_match(Cs, Os, Singles, Orig, Canon).

% --- Búsqueda fuzzy (single words) ---
best_single_fuzzy(WordsClean, Singles, BestKey, BestCanon, BestDist) :-
    findall(Dist-(Key-Canon), (
        member(W, WordsClean),
        strip_surrounding_punct(W, Wc),
        Wc \= "",
        member(Key-Canon, Singles),
        string_distance(Wc, Key, Dist)
    ), Pairs),
    Pairs \= [],
    keysort(Pairs, Sorted),
    Sorted = [BestDist-(BestKey-BestCanon)|_].

% --- Búsqueda fuzzy (multi-words) ---
best_multi_fuzzy(CleanLow, MultiList, BestKey, BestCanon, BestDist) :-
    findall(Dist-(Key-Canon), (
        member(Key-Canon, MultiList),
        string_distance(CleanLow, Key, Dist)
    ), Pairs),
    Pairs \= [],
    keysort(Pairs, Sorted),
    Sorted = [BestDist-(BestKey-BestCanon)|_].

% --- Umbral según longitud de la key ---
threshold_for_key(KeyLen, Th) :-
    Float is KeyLen * 0.35,
    Round is round(Float),
    ( Round < 1 -> Th = 1 ; Th = Round ).

% --- Utilities: limpiar signos (conserva letras, dígitos y espacios) ---
strip_punct(S, Out) :-
    string_chars(S, Cs),
    include(keep_char, Cs, Ks),
    string_chars(Out, Ks).

keep_char(C) :-
    char_type(C, alnum) ; char_type(C, space).

% Quitar puntuación al principio/fin de una palabra
strip_surrounding_punct(Str, Clean) :-
    string_chars(Str, Cs),
    trim_left(Cs, Cs1),
    reverse(Cs1, R1),
    trim_left(R1, R2),
    reverse(R2, Cs2),
    string_chars(Clean, Cs2).

trim_left([H|T], R) :-
    ( char_type(H, alnum) -> R = [H|T]
    ; trim_left(T, R)
    ).
trim_left([], []).

% --- Distancia de Levenshtein (simple, recursiva) ---
string_distance(S1, S2, D) :-
    string_chars(S1, C1),
    string_chars(S2, C2),
    levenshtein(C1, C2, D).

levenshtein([], [], 0).
levenshtein([], L2, N) :- length(L2, N).
levenshtein(L1, [], N) :- length(L1, N).
levenshtein([H1|T1], [H2|T2], D) :-
    levenshtein(T1, [H2|T2], Ddel),
    levenshtein([H1|T1], T2, Dins),
    levenshtein(T1, T2, Dsub),
    ( H1 == H2 -> Cost = 0 ; Cost = 1 ),
    D1 is Ddel + 1,
    D2 is Dins + 1,
    D3 is Dsub + Cost,
    min_list([D1, D2, D3], D).

% --- Bases de saludos (keys en lowercase) ---
greeting_single_list([
    "hola"-"Hola",
    "hi"-"Hi",
    "hello"-"Hello",
    "hey"-"Hey",
    "ola"-"Hola",
    "alo"-"Aló",
    "holi"-"Holi",
    "quiubo"-"Quiubo",
    "saludos"-"Saludos"
]).

greeting_multi([
    "buenos dias"-"Buenos días",
    "buenos días"-"Buenos días",
    "buen dia"-"Buen día",
    "buen día"-"Buen día",
    "buenas tardes"-"Buenas tardes",
    "buenas noches"-"Buenas noches",
    "que tal"-"Qué tal",
    "qué tal"-"Qué tal",
    "que onda"-"Qué onda",
    "qué onda"-"Qué onda",
    "que pasa"-"¿Qué pasa?",
    "qué pasa"-"¿Qué pasa?"
]).

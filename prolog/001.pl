ultimo([Result],Result).
ultimo([_|L],Result) :- ultimo(L,Result).
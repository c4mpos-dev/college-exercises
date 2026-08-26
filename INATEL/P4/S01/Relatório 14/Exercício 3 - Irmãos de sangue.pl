irmaos_germanos(A, B) :-
    progenitor(Pai, A),
    progenitor(Pai, B),
    progenitor(Mae, A),
    progenitor(Mae, B),
    Pai \= Mae,
    A \= B.
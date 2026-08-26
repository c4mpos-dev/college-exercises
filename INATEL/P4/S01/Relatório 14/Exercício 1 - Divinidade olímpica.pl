divindade_olimpica(Deus) :-
    progenitor(cronos, Deus),
    dominio(Deus, Dom),
    (
        Dom = ceu
    ;
        Dom = mar
    ;
        Dom = submundo
    ).

pai_ou_mae(P, F) :- progenitor(P, F).

genitor(P, F) :- progenitor(P, F).

filho_ou_filha(F, P) :- progenitor(P, F).

irmao_ou_irmao(X, Y) :-
    progenitor(P, X),
    progenitor(P, Y),
    X \= Y.

guerreiro(Deus) :-
    dominio(Deus, Dom),
    (Dom = guerra_estrategica ; Dom = guerra_brutal).

comum_em_olimpo(Deus) :-
    local_principal(Deus, olimpo).

poder_completo(Deus, Dominio, Arma) :-
    dominio(Deus, Dominio),
    arma(Deus, Arma).

ancestral(A, D) :- progenitor(A, D).
ancestral(A, D) :-
    progenitor(A, P),
    ancestral(P, D).

descendente(D, A) :- ancestral(A, D).

amigo(X, Y) :- aliado(X, Y).
amigo(X, Y) :- aliado(Y, X).

aliado_do_aliado(X, Z) :-
    aliado(X, Y),
    aliado(Y, Z),
    X \= Z.

deus_sem_arma(Deus) :-
    progenitor(_, Deus),
    \+ arma(Deus, _).

sem_local_no_olimpo(Deus) :-
    local_principal(Deus, Local),
    Local \= olimpo.
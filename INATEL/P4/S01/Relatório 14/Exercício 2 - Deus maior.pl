deus_maior(Deus) :-
    local_principal(Deus, olimpo),
    findall(Dominio, dominio(Deus, Dominio), Lista_de_dominios),
    length(Lista_de_dominios, Contagem),
    Contagem >= 2.
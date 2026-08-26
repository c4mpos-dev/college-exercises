UPDATE investigacao
SET nivel_suspeita = nivel_suspeita + 1
WHERE estava_na_sala_do_cofre = TRUE;
DELETE FROM investigacao
WHERE possui_alibi = TRUE
AND quantidade_evidencias = 0
AND nivel_suspeita <= 1;
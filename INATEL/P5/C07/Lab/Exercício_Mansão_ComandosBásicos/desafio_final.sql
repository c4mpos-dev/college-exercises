SELECT *
FROM investigacao
WHERE estava_na_sala_do_cofre = TRUE
AND horario_visto = '23:00:00'
AND possui_alibi = FALSE
AND nivel_suspeita > 3
AND quantidade_evidencias >= 2
AND (nome LIKE 'C%' OR nome LIKE 'A%')
ORDER BY nivel_suspeita DESC
LIMIT 1;
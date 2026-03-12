SELECT cidade, AVG(nivel_suspeita) AS media_suspeita
FROM investigacao
GROUP BY cidade;
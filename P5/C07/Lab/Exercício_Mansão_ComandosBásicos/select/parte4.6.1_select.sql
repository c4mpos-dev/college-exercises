SELECT profissao, COUNT(*) AS total
FROM investigacao
GROUP BY profissao;
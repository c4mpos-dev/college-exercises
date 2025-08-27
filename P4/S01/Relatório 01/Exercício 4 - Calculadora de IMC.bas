10 PRINT "Atenção: Os valores decimais devem ser inseridos utilizando ponto, não vírgula. (Ex: 1.75)"
20 INPUT "Digite a altura em metros: "; H
30 INPUT "Digite o peso em quilogramas: "; W

40 IMC = W / (H * H)
50 PRINT "Seu IMC é: " + IMC

60 IF IMC < 18.5 THEN GOTO 200
70 IF IMC < 25 THEN GOTO 210
80 IF IMC < 30 THEN GOTO 220
90 IF IMC < 35 THEN GOTO 230
100 GOTO 240

200 PRINT "Classificação: Abaixo do peso"
205 END
210 PRINT "Classificação: Peso normal"
215 END
220 PRINT "Classificação: Sobrepeso"
225 END
230 PRINT "Classificação: Obesidade grau I"
235 END
240 PRINT "Classificação: Obesidade grau II ou maior"
245 END
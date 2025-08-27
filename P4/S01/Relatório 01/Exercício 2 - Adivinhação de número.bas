10 LET N = rnd(100)

20 PRINT "Tente adivinhar o número de 0 a 100"
30 INPUT "Seu palpite: "; P

40 IF P = N THEN GOTO 100
50 IF P < N THEN PRINT "O numero correto é maior."
60 IF P > N THEN PRINT "O numero correto é menor."
      
70 GOTO 30

100 PRINT "Parabéns! Você acertou o número!"
110 END
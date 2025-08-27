10 INPUT "Digite a primeira nota: "; N1
20 INPUT "Digite a segunda nota: "; N2

30 MEDIA = ((1*N1) + (1*N2)) / 2

40 IF MEDIA >= 60 THEN GOTO 100
50 IF MEDIA < 30 THEN GOTO 200

60 INPUT "Digite a nota da NP3: "; N3

70 MEDIA2 = ((1*MEDIA) + (1*N3)) / 2

80 IF MEDIA2 > 50 THEN GOTO 300 ELSE GOTO 400

100 PRINT "Aprovado direto"
110 END
200 PRINT "Reprovado direto"
210 END
300 PRINT "Aprovado pela NP3"
310 END
400 PRINT "Reprovado na NP3"
410 END
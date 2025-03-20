import re

txt = "Viver é acalentar sonhos e esperanças, fazendo da fé a nossa inspiração maior. É buscar nas pequenas coisas, um grande motivo para ser feliz."

match = re.findall(r"[a-zA-ZáéíóúâêîôûãõçÀÉÍÓÚÂÊÎÔÛÃÕÇ]*as\b", txt)

if match:
    print(match)
else: 
    print("Nenhum match!")
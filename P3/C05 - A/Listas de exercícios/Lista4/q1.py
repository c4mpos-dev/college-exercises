import re

txt = "Viver é acalentar sonhos e esperanças, fazendo da fé a nossa inspiração maior. É buscar nas pequenas coisas, um grande motivo para ser feliz."

match = re.search(r"\bsonhos\b", txt)

if match:
    print("Match!")
else: 
    print("Nenhum match!")
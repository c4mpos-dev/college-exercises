import re

txt = "Viver é acalentar sonhos e esperanças, fazendo da fé a nossa inspiração maior. É buscar nas pequenas coisas, um grande motivo para ser feliz."

new_txt = re.sub(r"\bmaior|grande\b", "surreal", txt)

print(new_txt)
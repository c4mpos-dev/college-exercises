(defstruct criatura nome ambiente periculosidade vida-media)

(defparameter *catalogo-fauna* (list
  (make-criatura :nome "Peeper" :ambiente "Safe Shallows" :periculosidade "Baixa" :vida-media 5)
  (make-criatura :nome "Reaper Leviathan" :ambiente "Dunes" :periculosidade "Alta" :vida-media 100)
  (make-criatura :nome "Crabsquid" :ambiente "Deep" :periculosidade "Media" :vida-media 40)
  (make-criatura :nome "Ghost Leviathan" :ambiente "Deep" :periculosidade "Alta" :vida-media 200)))

(defun filtra-por-perigo (catalogo)
  (remove-if-not (lambda (c) (not (string-equal (criatura-periculosidade c) "Baixa"))) catalogo))

(defun relatorio-profundidade (catalogo)
  (mapcar (lambda (c) (format nil "[~a]: Vive em [~a]" (criatura-nome c) (criatura-ambiente c)))
          (remove-if-not (lambda (c) (string-equal (criatura-ambiente c) "Deep")) catalogo)))

(print (filtra-por-perigo *catalogo-fauna*))
(print (relatorio-profundidade *catalogo-fauna*))
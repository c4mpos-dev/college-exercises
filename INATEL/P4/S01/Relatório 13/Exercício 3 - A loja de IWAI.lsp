(defstruct item nome tipo preco forca-magica)

(defparameter *loja-itens* (list
  (make-item :nome "Katana das Sombras" :tipo "Arma" :preco 500 :forca-magica 85)
  (make-item :nome "Adaga Velha" :tipo "Arma" :preco 50 :forca-magica 30)
  (make-item :nome "Pocao de Vida" :tipo "Pocao" :preco 20 :forca-magica 10)
  (make-item :nome "Amuleto Antigo" :tipo "Artefato" :preco 150 :forca-magica 100)))

(defun adiciona-imposto (preco)
  (* preco 1.15))

(defun bonus-maldicao (forca)
  (if (> forca 80) (* forca 1.5) forca))

(defun processa-venda (catalogo)
  (let ((armas (remove-if-not (lambda (x) (string-equal (item-tipo x) "Arma")) catalogo)))
    (mapcar (lambda (arma)
              (list (item-nome arma) 
                    (bonus-maldicao (item-forca-magica arma))))
            armas)))

(print (processa-venda *loja-itens*))
(defstruct ocorrencia nome ritual nivel-medo agentes-enviados)

(defparameter *missoes* (list
  (make-ocorrencia :nome "O Segredo na Ilha" :ritual "Conhecimento" :nivel-medo 80 :agentes-enviados 4)
  (make-ocorrencia :nome "Carga Mortal" :ritual "Morte" :nivel-medo 40 :agentes-enviados 2)
  (make-ocorrencia :nome "Desconjuracao" :ritual "Sangue" :nivel-medo 90 :agentes-enviados 5)
  (make-ocorrencia :nome "Sinais do Outro Lado" :ritual "Energia" :nivel-medo 60 :agentes-enviados 4)
  (make-ocorrencia :nome "Iniciacao" :ritual "Medo" :nivel-medo 20 :agentes-enviados 1)))

(defun soma-medo-recursiva (lista-ocorrencias)
  (if (null lista-ocorrencias)
      0
      (+ (ocorrencia-nivel-medo (car lista-ocorrencias))
         (soma-medo-recursiva (cdr lista-ocorrencias)))))

(defun analise-final (lista-ocorrencias)
  (let ((media (/ (soma-medo-recursiva lista-ocorrencias) (length lista-ocorrencias))))
    (mapcar #'ocorrencia-nome
            (remove-if-not (lambda (o)
                             (and (> (ocorrencia-agentes-enviados o) 3)
                                  (> (ocorrencia-nivel-medo o) media)))
                           lista-ocorrencias))))

(print (analise-final *missoes*))
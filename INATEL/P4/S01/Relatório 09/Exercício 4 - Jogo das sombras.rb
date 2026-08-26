module Rastreavel
  def obter_localizacao(hora)
    "Localização às #{hora}: #{@localizacao}"
  end
end

module Perigoso
  def calcular_risco
    raise NotImplementedError, "O método calcular_risco deve ser implementado!"
  end
end

class Participante
  attr_accessor :nome, :localizacao

  def initialize(nome)
    @nome = nome
    @localizacao = "Desconhecida"
  end

  def to_s
    "#{@nome} está em #{@localizacao}"
  end
end

class Detetive < Participante
  include Rastreavel

  def investigar
    "🕵️ #{@nome} está analisando pistas em #{@localizacao}..." #esse emoji quebra dependendo do compilador (aviso pro monitor)
  end
end

class MestreDoCrime < Participante
  include Rastreavel
  include Perigoso

  def initialize(nome, nivel_periculosidade)
    super(nome)
    @nivel_periculosidade = nivel_periculosidade
  end

  def calcular_risco
    base = @nivel_periculosidade * rand(1.5..3.0)
    "⚠️ Risco estimado de #{@nome}: #{base.round(2)} pontos" #esse emoji quebra dependendo do compilador (aviso pro monitor) tambem n entendi se era pra ser random o risco
  end
end


class Cenario
  def initialize(participantes)
    @participantes = participantes
  end

  def identificar_ameacas
    @participantes.select { |p| p.respond_to?(:calcular_risco) }
  end

  def listar_rastreaveis
    @participantes.select { |p| p.is_a?(Rastreavel) }
  end
end


puts "Digite a localização atual de Sherlock Holmes:"
local_sherlock = gets.chomp

puts "Digite a localização atual de Moriarty:"
local_moriarty = gets.chomp

sherlock = Detetive.new("Sherlock Holmes")
sherlock.localizacao = local_sherlock

moriarty = MestreDoCrime.new("Moriarty", 8)
moriarty.localizacao = local_moriarty

cenario = Cenario.new([sherlock, moriarty])

puts "\n=== Localizações ==="
cenario.listar_rastreaveis.each do |p|
  puts p.obter_localizacao("14:30")
end

puts "\n=== Ameaças Detectadas ==="
ameacas = cenario.identificar_ameacas

if ameacas.empty?
  puts "Nenhuma ameaça detectada."
else
  ameacas.each { |a| puts a.calcular_risco }
end
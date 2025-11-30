class Drink
  attr_reader :nome

  def initialize(nome, preco_base)
    @nome = nome
    self.preco_base = preco_base 
  end

  def preco_base
    @preco_base
  end

  def preco_base=(valor)
    if valor.to_f > 0
      @preco_base = valor.to_f
    else
      raise "O preço base deve ser positivo!"
    end
  end

  def to_s
    "Drink: #{@nome} | Preço Base: $#{@preco_base}"
  end
end

class DrinkLenda < Drink
  def initialize(nome, preco_base, anos_desde_criacao)
    super(nome, preco_base)
    @anos_desde_criacao = anos_desde_criacao.to_i
  end

  def preco_final
    @preco_base + (5 * @anos_desde_criacao)
  end

  def to_s
    "Drink Lenda: #{@nome} | Base: $#{@preco_base} | " \
    "Anos: #{@anos_desde_criacao} | Preço Final: $#{preco_final}"
  end
end

puts "Digite o nome do drink:"
nome = gets.chomp

puts "Digite o preço base:"
preco_base = gets.chomp.to_f

puts "Digite quantos anos desde a criação:"
anos = gets.chomp.to_i

drink_lenda = DrinkLenda.new(nome, preco_base, anos)

puts "\n=== Resultado ==="
puts drink_lenda
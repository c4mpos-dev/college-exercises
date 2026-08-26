class Musico
  attr_reader :nome, :instrumento

  def initialize(nome, instrumento)
    @nome = nome
    @instrumento = instrumento
  end

  def tocar_partitura(peca)
    raise NotImplementedError, "O método tocar_partitura deve ser implementado nas subclasses!" #quebrou aqui
  end

  def to_s
    "#{@nome} (#{@instrumento})"
  end
end

class Pianista < Musico
  def initialize(nome)
    super(nome, "Piano")
  end

  def tocar_partitura(peca)
    puts "#{@nome} está tocando a peça '#{peca}' ao piano!"
  end
end

class Violinista < Musico
  def initialize(nome)
    super(nome, "Violino")
  end

  def tocar_partitura(peca)
    puts "#{@nome} está executando a peça '#{peca}' no violino!"
  end
end

class Maestro
  def initialize(nome, musicos)
    @nome = nome
    @musicos = musicos
  end

  def iniciar_ensaio(peca)
    puts "\n🎼 Maestro #{@nome} inicia o ensaio da peça '#{peca}'!"
    @musicos.each { |m| m.tocar_partitura(peca) }
  end

  def mudar_foco(estado)
    @musicos.map { |m| "#{m.nome} agora está #{estado}!" }
  end
end

puts "Digite o nome da peça a ser tocada:"
peca = gets.chomp

musicos = [
  Pianista.new("Kousei Arima"),
  Violinista.new("Kaori Miyazono"),
  Violinista.new("Tsubaki Sawabe")
]

maestro = Maestro.new("Takahiko", musicos)

maestro.iniciar_ensaio(peca)

puts "\nMudando o foco dos músicos..."
mensagens = maestro.mudar_foco("Concentrado")
puts mensagens
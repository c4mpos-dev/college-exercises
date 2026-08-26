class MicroondasUnidade
  def aquecer_por(segundos)
    puts "🔸 Micro-ondas aquecendo por #{segundos} segundos..."
    sleep(1)
    puts "✅ Aquecimento concluído!" #esse emoji quebra dependendo do compilador (aviso pro monitor)
  end
end

class DMail
  attr_reader :conteudo, :hora_envio

  def initialize(conteudo, hora_envio)
    @conteudo = conteudo
    @hora_envio = hora_envio
  end

  def to_s
    "📨 D-Mail: '#{@conteudo}' (Enviado às #{@hora_envio})"
  end
end

class TelefoneDeMicroondas
  def initialize
    @unidade = MicroondasUnidade.new  
    @dmails = []                        
  end

  def enviar_dmail
    puts "\nDigite o conteúdo do D-Mail:"
    conteudo = gets.chomp

    puts "Digite o horário de envio (ex: 10:30):"
    hora = gets.chomp

    puts "Quantos segundos aquecer antes do envio?"
    segundos = gets.chomp.to_i

    @unidade.aquecer_por(segundos)

    dmail = DMail.new(conteudo, hora)
    @dmails << dmail

    puts "\n✅ D-Mail enviado com sucesso!" #esse emoji quebra dependendo do compilador (aviso pro monitor)
    puts dmail
  end

  def listar_dmails(horario_corte)
    puts "\n📅 D-Mails após #{horario_corte}:" #esse emoji quebra dependendo do compilador (aviso pro monitor)
    selecionados = @dmails.select { |d| d.hora_envio > horario_corte }

    if selecionados.empty?
      puts "Nenhum D-Mail encontrado após #{horario_corte}."
    else
      selecionados.each { |d| puts d }
    end
  end
end

telefone = TelefoneDeMicroondas.new

loop do
  puts "\n📱 MENU TELEFONE DE MICROONDAS"
  puts "1. Enviar D-Mail"
  puts "2. Listar D-Mails após um horário"
  puts "3. Sair"
  print "Escolha: "
  opcao = gets.chomp

  case opcao
  when "1"
    telefone.enviar_dmail
  when "2"
    print "\nDigite o horário de corte (ex: 11:00): "
    corte = gets.chomp
    telefone.listar_dmails(corte)
  when "3"
    puts "Encerrando programa..."
    break
  else
    puts "Opção inválida!"
  end
end
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { Tabs, TabsContent, TabsList, TabsTrigger } from "@/components/ui/tabs";
import { ListChecks, Network, GitBranch, DownloadCloud } from "lucide-react";
import { Button } from "@/components/ui/button";

const AnalysisSection = () => {
  const downloadImage = async (src: string, filename?: string) => {
    try {
      const res = await fetch(src);
      if (!res.ok) throw new Error("Falha ao buscar a imagem");
      const blob = await res.blob();
      const url = URL.createObjectURL(blob);
      const a = document.createElement("a");
      a.href = url;
      a.download = filename || src.split("/").pop() || "image.png";
      document.body.appendChild(a);
      a.click();
      a.remove();
      URL.revokeObjectURL(url);
    } catch (err) {
      console.error("Erro ao baixar imagem:", err);
    }
  };
  return (
    <section id="analysis" className="section-padding">
      <div className="container-width">
        <div className="text-center max-w-3xl mx-auto mb-16 animate-fade-in-up">
          <h2 className="font-heading font-bold text-3xl md:text-5xl mb-4">
            Análise Técnica
          </h2>
          <p className="text-lg text-muted-foreground">
            Documentação detalhada da análise de tarefas e fluxo de informação
          </p>
        </div>

        <Tabs defaultValue="task" className="max-w-7xl mx-auto animate-fade-in-up">
          <TabsList className="grid w-full grid-cols-2 mb-8">
            <TabsTrigger value="task" className="text-base">
              Análise da Tarefa
            </TabsTrigger>
            <TabsTrigger value="flow" className="text-base">
              Diagrama de classes
            </TabsTrigger>
          </TabsList>

          <TabsContent value="task">
            <Card className="border-2 hover:border-primary/50 transition-all shadow-elegant">
              <CardHeader className="bg-gradient-to-r from-primary/5 to-transparent">
                <div className="flex items-center gap-3">
                  <div className="w-12 h-12 rounded-lg bg-primary/10 flex items-center justify-center">
                    <ListChecks className="h-6 w-6 text-primary" />
                  </div>
                  <CardTitle className="font-heading text-2xl">
                    Análise da Tarefa
                  </CardTitle>
                </div>
              </CardHeader>
              <CardContent className="pt-6 space-y-6">
                <div>
                  <h3 className="font-heading font-semibold text-xl mb-3">
                    Meta: Entrar em contato rapidamente com professores e setores acadêmicos
                  </h3>
                  <p className="text-muted-foreground mb-6">
                    Persona: Cauã (Usuário do App INATEL)
                  </p>
                  
                  <div className="space-y-4">
                    <div className="border-l-4 border-primary pl-4 py-2 bg-muted/30 rounded-r-lg">
                      <h4 className="font-semibold text-lg mb-2">0. Realizar Contato com Professor ou Setor</h4>
                    </div>

                    <div className="ml-4 space-y-3">
                      <div className="border-l-2 border-primary/50 pl-4 py-2">
                        <h5 className="font-semibold mb-2">1. Acessar a Funcionalidade de Contatos</h5>
                        <ul className="space-y-2 text-muted-foreground">
                          <li className="flex items-start gap-2">
                            <span className="text-primary mt-1">•</span>
                            <span>1.1. Abrir o menu principal (ou navegar para a home)</span>
                          </li>
                          <li className="flex items-start gap-2">
                            <span className="text-primary mt-1">•</span>
                            <span>1.2. Tocar no botão "Contatos" (ou "Ramal", "Agenda", etc.)</span>
                          </li>
                        </ul>
                      </div>

                      <div className="border-l-2 border-accent/50 pl-4 py-2">
                        <h5 className="font-semibold mb-2">2. Localizar o Contato Desejado</h5>
                        <div className="space-y-3">
                          <div className="ml-2">
                            <p className="font-medium text-sm mb-1">2.1. Buscar por Professor</p>
                            <ul className="space-y-1 text-sm text-muted-foreground">
                              <li className="flex items-start gap-2">
                                <span className="text-accent mt-1">→</span>
                                <span>2.1.1. Selecionar a aba/filtro "Professores"</span>
                              </li>
                              <li className="flex items-start gap-2">
                                <span className="text-accent mt-1">→</span>
                                <span>2.1.2. Digitar o nome do professor na barra de busca</span>
                              </li>
                              <li className="flex items-start gap-2">
                                <span className="text-accent mt-1">→</span>
                                <span>2.1.3. Tocar no nome do professor nos resultados</span>
                              </li>
                            </ul>
                          </div>
                          <div className="ml-2">
                            <p className="font-medium text-sm mb-1">2.2. Buscar por Setor Acadêmico</p>
                            <ul className="space-y-1 text-sm text-muted-foreground">
                              <li className="flex items-start gap-2">
                                <span className="text-accent mt-1">→</span>
                                <span>2.2.1. Selecionar a aba/filtro "Setores"</span>
                              </li>
                              <li className="flex items-start gap-2">
                                <span className="text-accent mt-1">→</span>
                                <span>2.2.2. Rolar a lista de setores (ex: "Secretaria", "Coordenação") ou usar a busca</span>
                              </li>
                              <li className="flex items-start gap-2">
                                <span className="text-accent mt-1">→</span>
                                <span>2.2.3. Tocar no nome do setor desejado</span>
                              </li>
                            </ul>
                          </div>
                        </div>
                      </div>

                      <div className="border-l-2 border-primary/50 pl-4 py-2">
                        <h5 className="font-semibold mb-2">3. Iniciar a Comunicação</h5>
                        <ul className="space-y-2 text-muted-foreground">
                          <li className="flex items-start gap-2">
                            <span className="text-primary mt-1">•</span>
                            <span>A. Enviar E-mail</span>
                          </li>
                          <li className="flex items-start gap-2">
                            <span className="text-primary mt-1">•</span>
                            <span>B. Ligar para o Ramal</span>
                          </li>
                          <li className="flex items-start gap-2">
                            <span className="text-primary mt-1">•</span>
                            <span>C. Iniciar chat interno</span>
                          </li>
                        </ul>
                      </div>
                    </div>
                  </div>
                </div>

                <div className="pt-4 border-t border-border">
                  <h3 className="font-heading font-semibold text-xl mb-3">
                    Coerência com o Desenvolvimento
                  </h3>
                  <p className="text-muted-foreground">
                    A análise de tarefas está mapeada diretamente para as telas desenvolvidas, 
                    com cada passo da hierarquia correspondendo a elementos visuais e interações 
                    específicas na interface do aplicativo.
                  </p>
                  <img src="/Análise Da Tarefa.jpg" alt="" className="w-full"/>
                </div>
              </CardContent>
            </Card>
          </TabsContent>

          <TabsContent value="flow">
            <Card className="border-2 hover:border-primary/50 transition-all shadow-elegant">
              <CardHeader className="bg-gradient-to-r from-accent/5 to-transparent">
                <div className="flex items-center justify-between gap-3">
                  <div className="flex items-center gap-3">
                    <div className="w-12 h-12 rounded-lg bg-accent/10 flex items-center justify-center">
                      <Network className="h-6 w-6 text-accent" />
                    </div>
                    <CardTitle className="font-heading text-2xl">
                      Fluxo de Informação
                    </CardTitle>
                  </div>

                  <div>
                    <Button variant="ghost" size="sm" onClick={() => downloadImage('/classDiagram.svg', 'classDiagram.svg')}>
                      <DownloadCloud className="w-4 h-4 mr-2" />
                      Baixar Diagrama (Se não estiver conseguindo ler)
                    </Button>
                  </div>
                </div>
              </CardHeader>
              <CardContent className="pt-6 space-y-6">
                <div className="space-y-6">
                  <div className="flex justify-center">
                    <img src="/diagrama1.png" alt="Diagrama 1" className="" />
                  </div>

                  <div className="flex justify-center">
                    <img src="/diagrama2.png" alt="Diagrama 2" className="" />
                  </div>
                </div>
              </CardContent>
            </Card>
          </TabsContent>
        </Tabs>
      </div>
    </section>
  );
};

export default AnalysisSection;

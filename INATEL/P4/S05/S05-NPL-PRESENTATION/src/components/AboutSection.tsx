import { Card, CardContent } from "@/components/ui/card";
import { Users, Target, Lightbulb, Code } from "lucide-react";

const AboutSection = () => {
  const features = [
    {
      icon: Users,
      title: "Centrado no Usuário",
      description: "Design focado nas necessidades e expectativas dos usuários do App INATEL.",
    },
    {
      icon: Target,
      title: "Objetivos Claros",
      description: "Funcionalidade desenvolvida com metas bem definidas.",
    },
    {
      icon: Lightbulb,
      title: "Solução Inovadora",
      description: "Abordagem criativa para resolver problemas reais dos usuários.",
    },
    {
      icon: Code,
      title: "Implementação Completa",
      description: "Experiência de uso completa, simulando a tarefa.",
    },
  ];

  return (
    <section id="about" className="section-padding bg-muted/30">
      <div className="container-width">
        <div className="text-center max-w-3xl mx-auto mb-16 animate-fade-in-up">
          <h2 className="font-heading font-bold text-3xl md:text-5xl mb-4">
            Sobre o Projeto
          </h2>
          <p className="text-lg text-muted-foreground">
            Este projeto foi desenvolvido como parte do curso de Interação Homem Máquina
            do INATEL.
          </p>
        </div>

        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-6">
          {features.map((feature, index) => (
            <Card
              key={index}
              className="border-2 hover:border-primary/50 transition-all hover:shadow-elegant group animate-fade-in-up"
              style={{ animationDelay: `${index * 100}ms` }}
            >
              <CardContent className="pt-6">
                <div className="w-12 h-12 rounded-lg bg-primary/10 flex items-center justify-center mb-4 group-hover:scale-110 transition-transform">
                  <feature.icon className="h-6 w-6 text-primary" />
                </div>
                <h3 className="font-heading font-semibold text-xl mb-2">
                  {feature.title}
                </h3>
                <p className="text-muted-foreground">
                  {feature.description}
                </p>
              </CardContent>
            </Card>
          ))}
        </div>
      </div>
    </section>
  );
};

export default AboutSection;

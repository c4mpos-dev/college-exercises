import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { User, Target, Zap } from "lucide-react";

const UserStorySection = () => {
  return (
    <section id="user-story" className="section-padding bg-muted/30">
      <div className="container-width">
        <div className="text-center max-w-3xl mx-auto mb-10 animate-fade-in-up">
          <h2 className="font-heading font-bold text-3xl md:text-5xl mb-4">
            User Story
          </h2>
          <p className="text-lg text-muted-foreground">
            Narrativa centrada no usuário que define o contexto e objetivos da funcionalidade
          </p>
        </div>

        <div className="max-w-4xl mx-auto">
          <Card className="border-2 border-primary/20 shadow-elegant animate-fade-in-up">
            <CardHeader className="flex text-center bg-gradient-to-r from-primary/5 to-accent/5">
              <span>	
                Como Cauã, eu quero entrar em contato rapidamente com professores e setores acadêmicos no Aplicativo Inatel, para que eu consiga resolver pendências e dúvidas sem precisar procurar em vários lugares.
              </span>
            </CardHeader>
            <CardContent className="pt-8 space-y-8">
              <div className="flex items-start gap-4 p-6 rounded-lg bg-background border border-border hover:border-primary/50 transition-all group">
                <div className="w-12 h-12 rounded-full bg-primary/10 flex items-center justify-center flex-shrink-0 group-hover:scale-110 transition-transform">
                  <User className="h-6 w-6 text-primary" />
                </div>
                <div>
                  <h3 className="font-heading font-semibold text-xl mb-2">
                    Como Cauã (usuário do App INATEL)
                  </h3>
                  <p className="text-muted-foreground">
                    Persona: Cauã, estudante do INATEL que precisa se comunicar 
                    frequentemente com professores e setores acadêmicos.
                  </p>
                </div>
              </div>

              <div className="flex items-start gap-4 p-6 rounded-lg bg-background border border-border hover:border-primary/50 transition-all group">
                <div className="w-12 h-12 rounded-full bg-primary/10 flex items-center justify-center flex-shrink-0 group-hover:scale-110 transition-transform">
                  <Target className="h-6 w-6 text-primary" />
                </div>
                <div>
                  <h3 className="font-heading font-semibold text-xl mb-2">
                    Eu quero entrar em contato rapidamente com professores e setores acadêmicos
                  </h3>
                  <p className="text-muted-foreground">
                    Necessidade de localizar e acessar informações de contato (e-mail, ramal, chat) 
                    de forma ágil e centralizada no Aplicativo Inatel.
                  </p>
                </div>
              </div>

              <div className="flex items-start gap-4 p-6 rounded-lg bg-background border border-border hover:border-primary/50 transition-all group">
                <div className="w-12 h-12 rounded-full bg-primary/10 flex items-center justify-center flex-shrink-0 group-hover:scale-110 transition-transform">
                  <Zap className="h-6 w-6 text-primary" />
                </div>
                <div>
                  <h3 className="font-heading font-semibold text-xl mb-2">
                    Para que eu consiga resolver pendências e dúvidas
                  </h3>
                  <p className="text-muted-foreground">
                    Sem precisar procurar em vários lugares, economizando tempo e 
                    facilitando a comunicação acadêmica no dia a dia.
                  </p>
                </div>
              </div>
            </CardContent>
          </Card>
        </div>
      </div>
    </section>
  );
};

export default UserStorySection;

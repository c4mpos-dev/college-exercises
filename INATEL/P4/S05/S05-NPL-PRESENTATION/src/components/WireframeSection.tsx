import { Card } from "@/components/ui/card";

const WireframeSection = () => {
  return (
    <section id="wireframe" className="section-padding bg-muted/30">
      <div className="container-width">
        <div className="text-center max-w-3xl mx-auto mb-10 animate-fade-in-up">
          <h2 className="font-heading font-bold text-3xl md:text-5xl mb-4">
            Wireframes
          </h2>
          <p className="text-lg text-muted-foreground">
            Protótipos e estrutura visual da interface desenvolvida
          </p>
        </div>

        <Card className="border-2 border-primary/20 shadow-elegant animate-fade-in-up">
            <span className="ml-4">Home</span>
            <div className="bg-muted/30 rounded-lg p-8 md:p-12 border-2 border-dashed border-border min-h-[400px] flex flex-col items-center justify-center">
              <img src="/dashboard.png" alt=""/>
            </div>
        </Card>

        <Card className="border-2 border-primary/20 shadow-elegant animate-fade-in-up mt-6">
            <span className="ml-4">Modal Seletor</span>
            <div className="bg-muted/30 rounded-lg p-8 md:p-12 border-2 border-dashed border-border min-h-[400px] flex flex-col items-center justify-center">
              <img src="/modal-seletor.png" alt="" />
              
            </div>
          
        </Card>

        <Card className="border-2 border-primary/20 shadow-elegant animate-fade-in-up mt-6">
            <span className="ml-4">Chat</span>
            <div className="bg-muted/30 rounded-lg p-8 md:p-12 border-2 border-dashed border-border min-h-[400px] flex flex-col items-center justify-center">
              <img src="/chat.png" alt="" />
              
            </div>
          
        </Card>
      </div>
    </section>
  );
};

export default WireframeSection;

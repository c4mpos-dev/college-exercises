import Header from "@/components/Header";
import Hero from "@/components/Hero";
import AboutSection from "@/components/AboutSection";
import FunctionalitySection from "@/components/FunctionalitySection";
import UserStorySection from "@/components/UserStorySection";
import AnalysisSection from "@/components/AnalysisSection";
import WireframeSection from "@/components/WireframeSection";

const Index = () => {
  return (
    <div className="min-h-screen">
      <Header />
      <main>
        <Hero />
        <AboutSection />
        <FunctionalitySection />
        <UserStorySection />
        <AnalysisSection />
        <WireframeSection />
      </main>
    </div>
  );
};

export default Index;

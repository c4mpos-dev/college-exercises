class ArmaCorpoACorpo:
    def __init__(self, nome: str, dano: int):
        self.nome = nome
        self.dano = dano

    def __str__(self):
        return f"Arma: {self.nome} (Dano: {self.dano})"


class PhantomThieves:
    def __init__(self, nome: str, arma: ArmaCorpoACorpo):
        self.nome = nome
        self.arma = arma

    def __str__(self):
        return f"{self.nome} - {self.arma}"


class Joker:
    def __init__(self, nome: str, membros: list["PhantomThieves"]):
        self.nome = nome

        self.arma = ArmaCorpoACorpo("Faca do Rebelde", 75)

        self.membros = membros

    def mostrar_equipe(self):
        print(f"=== Equipe de {self.nome} ===")
        print(f"Arma principal: {self.arma}\n")
        print("Phantom Thieves:")
        for i, membro in enumerate(self.membros, start=1):
            print(f"{i}. {membro}")
        print("=============================\n")


if __name__ == "__main__":
    arma1 = ArmaCorpoACorpo("Catana Carmesim", 68)
    arma2 = ArmaCorpoACorpo("Chicote Espectral", 55)
    arma3 = ArmaCorpoACorpo("Adaga das Sombras", 60)

    membro1 = PhantomThieves("Panther", arma2)
    membro2 = PhantomThieves("Skull", arma1)
    membro3 = PhantomThieves("Fox", arma3)

    equipe = [membro1, membro2, membro3]

    joker = Joker("Joker", equipe)

    joker.mostrar_equipe()
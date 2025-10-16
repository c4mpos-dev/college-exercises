from abc import ABC, abstractmethod

class Heroi(ABC):
    def __init__(self, nome: str, funcao: str):
        self.nome = nome
        self.funcao = funcao

    @abstractmethod
    def usar_ultimate(self):
        pass

    def __str__(self):
        return f"Herói: {self.nome} ({self.funcao})"


class Tanque(Heroi):
    def usar_ultimate(self):
        print(f"{self.nome} ativa seu escudo impenetrável e protege o time!")


class Dano(Heroi):
    def usar_ultimate(self):
        print(f"{self.nome} dispara uma rajada devastadora nos inimigos!")


if __name__ == "__main__":
    heroi1 = Tanque("Reinhardt", "Tanque")
    heroi2 = Dano("Soldado 76", "Dano")
    heroi3 = Dano("Genji", "Dano")

    lista_herois = [heroi1, heroi2, heroi3]

    for heroi in lista_herois:
        print(heroi) 
        heroi.usar_ultimate() 
        print("-" * 50)

from abc import ABC, abstractmethod
from typing import List

class Cibernetico(ABC):
    @abstractmethod
    def realizar_hack(self) -> None:
        pass


class Implante:
    def __init__(self, custo: float, funcao: str):
        self.custo = custo
        self.funcao = funcao

    def descricao(self) -> str:
        return f"Implante(funcao='{self.funcao}', custo={self.custo})"


class NetRunner(Cibernetico):
    def __init__(self, nome: str, nivel: int, implante: Implante):
        self.nome = nome
        self.nivel = nivel
        self.implante = implante

    def realizar_hack(self) -> None:
        print(
            f"[NetRunner] {self.nome} (nível {self.nivel}) usa {self.implante.funcao} "
            f"({self.implante.custo}$) e realiza um hack sofisticado!"
        )

    def __str__(self):
        return (
            f"NetRunner: {self.nome} | "
            f"Nível: {self.nivel} | "
            f"Implante: {self.implante.funcao} (custo: {self.implante.custo}$)"
        )


class Faccao:
    def __init__(self, nome: str, membros: List[Cibernetico] = None):
        self.nome = nome
        self.membros: List[Cibernetico] = membros if membros is not None else []

    def adicionar_membro(self, membro: Cibernetico) -> None:
        self.membros.append(membro)

    def executar_hacks(self) -> None:
        print(f"Faccao '{self.nome}' ordena: todos, executar realizar_hack()!")
        for membro in self.membros:
            membro.realizar_hack()
        print("Todos os hacks da facção foram executados.\n")


if __name__ == "__main__":
    implante1 = Implante(1500.0, "Injetor de backdoors")
    implante2 = Implante(2400.0, "Neuro-interface stealth")
    implante3 = Implante(900.0, "Sniffer de redes")

    nr1 = NetRunner("ZeroCool", nivel=5, implante=implante1)
    nr2 = NetRunner("Glitch", nivel=7, implante=implante2)
    nr3 = NetRunner("Patch", nivel=3, implante=implante3)

    faccao = Faccao("VaporWaif")
    faccao.adicionar_membro(nr1)
    faccao.adicionar_membro(nr2)
    faccao.adicionar_membro(nr3)
    faccao.executar_hacks()

    print("Membros da facção:")
    for m in faccao.membros:
        print(" -", m)

#ATIVIDADE: POO E CLASSES
#ALUNO: LUIZ HENRIQUE CARNEIRO CARVALHO

#8° Atividade
print("\n")
print("8° ATIVIDADE")
print("\n")

class Macaco:
    def __init__(self, nome):
        self.nome = nome
        self.bucho = []

    def comer(self, alimento):
        self.bucho.append(alimento)
        print(f"{self.nome} comeu {alimento}.")

    def verBucho(self):
        print(f"Bucho de {self.nome}: {', '.join(self.bucho)}")

    def digerir(self):
        self.bucho = []
        print(f"{self.nome} digeriu a comida.")

macaco1 = Macaco("Baltazar")
macaco2 = Macaco("Dalva")

rango = (input("\nEscolha algo pro Baltazar comer:\n"))
macaco1.comer(rango)
macaco1.verBucho()
print("\n")

rango = (input("\nEscolha algo pra Dalva comer:\n"))
macaco2.comer(rango)
macaco2.verBucho()
print("\n")

macaco1.comer("Banana")
macaco2.comer("Maçã")
macaco1.verBucho()
macaco2.verBucho()
macaco1.comer("Nozes")
macaco2.comer("Uva")
macaco1.digerir()
macaco2.digerir()
macaco1.verBucho()
macaco2.verBucho()
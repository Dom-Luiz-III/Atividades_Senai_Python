#ATIVIDADE: POO E CLASSES
#ALUNO: LUIZ HENRIQUE CARNEIRO CARVALHO

#3° Atividade
print("\n")
print("3° ATIVIDADE")
print("\n")

class Retangulo:
    def __init__(self, ladoA, ladoB):
        self.ladoA = ladoA
        self.ladoB = ladoB

    def mudarLados(self, novo_ladoA, novo_ladoB):
        self.ladoA = novo_ladoA
        self.ladoB = novo_ladoB

    def retornarLados(self):
        return self.ladoA, self.ladoB

    def calcularArea(self):
        return self.ladoA * self.ladoB

    def calcularPerimetro(self):
        return 2 * (self.ladoA + self.ladoB)

ladoA = float(input("Informe o comprimento do local: "))
ladoB = float(input("Informe a largura do local: "))

local = Retangulo(ladoA, ladoB)

tamanho_piso = 0.25  
tamanho_rodape = 0.10 

area_local = local.calcularArea()
qtd_pisos = area_local / tamanho_piso
qtd_rodapes = (local.calcularPerimetro() / 2) / tamanho_rodape

print(f"\nÁrea do local: {area_local:.2f} metros quadrados")
print(f"\nQuantidade de pisos necessários: {qtd_pisos:.2f}")
print(f"\nQuantidade de rodapés necessários: {qtd_rodapes:.2f}")

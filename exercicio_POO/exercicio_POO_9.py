#ATIVIDADE: POO E CLASSES
#ALUNO: LUIZ HENRIQUE CARNEIRO CARVALHO

#9° Atividade
print("\n")
print("9° ATIVIDADE")
print("\n")

class Ponto:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def imprimir(self):
        print(f"Ponto: ({self.x}, {self.y})")

class Retangulo:
    def __init__(self, ponto_inferior_esquerdo, largura, altura):
        self.ponto_inferior_esquerdo = ponto_inferior_esquerdo
        self.largura = largura
        self.altura = altura

    def encontrar_centro(self):
        centro_x = self.ponto_inferior_esquerdo.x + self.largura / 2
        centro_y = self.ponto_inferior_esquerdo.y + self.altura / 2
        return Ponto(centro_x, centro_y)
    

def imprimir_ponto(ponto):
    ponto.imprimir()

def encontrar_centro_retangular(retangulo):
    return retangulo.encontrar_centro()

retangulo = Retangulo(Ponto(0, 0), 10, 20)

while True:
    print("1. Alterar valores do retângulo")
    print("2. Imprimir centro do retângulo")
    print("3. Sair")
    opcao = int(input("Digite sua opção: "))

    if opcao == 1:
        x = int(input("Digite o valor de x para o ponto inferior esquerdo: "))
        y = int(input("Digite o valor de y para o ponto inferior esquerdo: "))
        largura = int(input("Digite o valor da largura: "))
        altura = int(input("Digite o valor da altura: "))
        retangulo.ponto_inferior_esquerdo = Ponto(x, y)
        retangulo.largura = largura
        retangulo.altura = altura

    elif opcao == 2:
        centro = encontrar_centro_retangular(retangulo)
        imprimir_ponto(centro)

    elif opcao == 3:
        break
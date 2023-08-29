#ATIVIDADE: POO E CLASSES
#ALUNO: LUIZ HENRIQUE CARNEIRO CARVALHO

#2° Atividade
print("\n")
print("2° ATIVIDADE")
print("\n")

class Quadrado:
    def __init__(self, tamanhoLado):
        self.tamanhoLado = tamanhoLado

    def modificarLado(self, novo_lado):
        self.tamanhoLado = novo_lado

    def mostrarLado(self):
        return self.tamanhoLado

    def calcularArea(self):
        return self.tamanhoLado ** 2

quadrado = Quadrado(5)

print("Lado do quadrado:", quadrado.mostrarLado()) 
quadrado.modificarLado(7)
print("Novo lado do quadrado:", quadrado.mostrarLado())  
print("Área do quadrado:", quadrado.calcularArea())  
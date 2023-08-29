#ATIVIDADE: POO E CLASSES
#ALUNO: LUIZ HENRIQUE CARNEIRO CARVALHO

#1° Atividade
print("\n")
print("1° ATIVIDADE")
print("\n")

class Bola:
    def __init__(self, cor, circunferencia, material):
        self.cor = cor
        self.circunferencia = circunferencia
        self.material = material

    def trocaCor(self, nova_cor):
        self.cor = nova_cor

    def mostraCor(self):
        return self.cor
    
    def mostraCircunferencia(self):
        return self.circunferencia
    
    def mostraMaterial(self):
        return self.material

bolas = Bola("LARANJA", 20, "BORRACHA")

print("A COR DA SUA BOLA:", bolas.mostraCor())
print("A CIRCUNFERENCIA DA SUA BOLA:", bolas.mostraCircunferencia())
print("O MATERAL DA SUA BOLA:", bolas.mostraMaterial())
bolas.trocaCor("AZUL")
print("A NOVA COR PARA A SUA BOLA:", bolas.mostraCor())  

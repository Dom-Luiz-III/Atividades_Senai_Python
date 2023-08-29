#ATIVIDADE: POO E CLASSES
#ALUNO: LUIZ HENRIQUE CARNEIRO CARVALHO

#7° Atividade
print("\n")
print("7° ATIVIDADE")
print("\n")

class BichinhoVirtual:
    def __init__(self, nome, fome, saude, idade):
        self.nome = nome
        self.fome = fome
        self.saude = saude
        self.idade = idade

    def alterarNome(self, novo_nome):
        self.nome = novo_nome

    def alterarFome(self, novo_valor):
        self.fome = novo_valor

    def alterarSaude(self, novo_valor):
        self.saude = novo_valor

    def alterarIdade(self, novo_valor):
        self.idade = novo_valor

    def retornarNome(self):
        return self.nome

    def retornarFome(self):
        return self.fome

    def retornarSaude(self):
        return self.saude

    def retornarIdade(self):
        return self.idade

    def calcularHumor(self):
        humor = (self.fome + self.saude) / 2
        return humor


tamagushi = BichinhoVirtual("Ivanidinho", 5, 8, 1)

print("Seu Tamagushi virtual!\n")
print("Nome:", tamagushi.retornarNome())
print("Fome:", tamagushi.retornarFome())
print("Saúde:", tamagushi.retornarSaude())
print("Idade:", tamagushi.retornarIdade())
print("Humor:", tamagushi.calcularHumor())

novo_dado = (input("\nEscolha um novo nome para o seu pet:\n"))
tamagushi.alterarNome(novo_dado)

novo_dado = float(input("Escolha o seu nível de fome:\n"))
tamagushi.alterarFome(novo_dado)

novo_dado = float(input("Escolha o seu nível da sua saúde:\n"))
tamagushi.alterarSaude(novo_dado)

novo_dado = float(input("Escolha a sua idade:\n"))
tamagushi.alterarIdade(novo_dado)

print("Dados atualizados!\n")
print("Nome:", tamagushi.retornarNome())
print("Fome:", tamagushi.retornarFome())
print("Saúde:", tamagushi.retornarSaude())
print("Idade:", tamagushi.retornarIdade())
print("Humor:", tamagushi.calcularHumor())
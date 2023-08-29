#ATIVIDADE: POO E CLASSES
#ALUNO: LUIZ HENRIQUE CARNEIRO CARVALHO

#4° Atividade
print("\n")
print("4° ATIVIDADE")
print("\n")

class Pessoa:
    def __init__(self, nome, idade, peso, altura):
        self.nome = nome
        self.idade = idade
        self.peso = peso
        self.altura = altura

    def envelhecer(self, anos):
        self.idade += anos
        if self.idade < 21:
            self.crescer(0.5 * anos)

    def engordar(self, kg):
        self.peso += kg

    def emagrecer(self, kg):
        self.peso -= kg

    def crescer(self, cm):
        self.altura += cm

    def mostrarInformacoes(self):
        return f"Nome: {self.nome}, Idade: {self.idade}, Peso: {self.peso} kg, Altura: {self.altura} cm"


print("PESSOA MAIOR DE 21 ANOS:")
pessoa = Pessoa("Luiz Henrique", 21, 91, 180)

print(pessoa.mostrarInformacoes())
pessoa.envelhecer(2)
pessoa.engordar(3)
pessoa.emagrecer(2)
print(pessoa.mostrarInformacoes())


print("\nPESSOA MENOR DE 21 ANOS:")
pessoa = Pessoa("Vitinho", 10, 55, 130)

print(pessoa.mostrarInformacoes())
pessoa.envelhecer(5)
pessoa.engordar(3)
pessoa.emagrecer(2)
print(pessoa.mostrarInformacoes())
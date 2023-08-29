#ATIVIDADE: POO E CLASSES
#ALUNO: LUIZ HENRIQUE CARNEIRO CARVALHO

#10° Atividade
print("\n")
print("10° ATIVIDADE")
print("\n")

class BombaCombustivel:
    def __init__(self, tipo_combustivel, valor_litro, quantidade_combustivel):
        self.tipo_combustivel = tipo_combustivel
        self.valor_litro = valor_litro
        self.quantidade_combustivel = quantidade_combustivel

    def abastecer_por_valor(self, valor):
        litros = valor / self.valor_litro
        self.quantidade_combustivel -= litros
        return litros

    def abastecer_por_litro(self, litros):
        custo = litros * self.valor_litro
        self.quantidade_combustivel -= litros
        return custo

    def alterar_valor(self, novo_valor):
        self.valor_litro = novo_valor

    def alterar_combustivel(self, novo_tipo_combustivel):
        self.tipo_combustivel = novo_tipo_combustivel

    def alterar_quantidade_combustivel(self, nova_quantidade_combustivel):
        self.quantidade_combustivel = nova_quantidade_combustivel


bomba = BombaCombustivel("Gasolina", 6.5, 100)

print("Quantidade de combustível disponível:", bomba.quantidade_combustivel)

valor = float(input("Digite o valor a ser abastecido: "))
litros = bomba.abastecer_por_valor(valor)
print("Quantidade de litros abastecida:", litros)
print("Quantidade de combustível disponível:", bomba.quantidade_combustivel)

litros = float(input("Digite a quantidade de litros a ser abastecida: "))
custo = bomba.abastecer_por_litro(litros)
print("Custo do abastecimento:", custo)
print("Quantidade de combustível disponível:", bomba.quantidade_combustivel)

#ATIVIDADE: POO E CLASSES
#ALUNO: LUIZ HENRIQUE CARNEIRO CARVALHO

#5° Atividade
print("\n")
print("5° ATIVIDADE")
print("\n")

class ContaCorrente:
    def __init__(self, numero_conta, nome_correntista, saldo=0):
        self.numero_conta = numero_conta
        self.nome_correntista = nome_correntista
        self.saldo = saldo

    def alterarNome(self, novo_nome):
        self.nome_correntista = novo_nome

    def deposito(self, valor):
        if valor > 0:
            self.saldo += valor
            print(f"Depósito de R${valor:.2f} realizado. Novo saldo: R${self.saldo:.2f}")
        else:
            print("Valor inválido para depósito.")

    def saque(self, valor):
        if 0 < valor <= self.saldo:
            self.saldo -= valor
            print(f"Saque de R${valor:.2f} realizado. Novo saldo: R${self.saldo:.2f}")
        else:
            print("Saldo insuficiente ou valor inválido para saque.")

conta = ContaCorrente("12345", "Alice")

print(f"Conta: {conta.numero_conta}, Correntista: {conta.nome_correntista}, Saldo: R${conta.saldo:.2f}")
print("\n")

conta.deposito(500)
print("\n")

conta.saque(200)
print("\n")

conta.alterarNome("Bob")
print(f"Conta: {conta.numero_conta}, Correntista: {conta.nome_correntista}, Saldo: R${conta.saldo:.2f}")
print("\n")

conta.saque(400)

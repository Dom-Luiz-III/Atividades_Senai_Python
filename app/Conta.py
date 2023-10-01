class Conta:
    def __init__(self, titular, numero):
        self.saldo = 0
        self._numero = numero
        self._titular = titular


    @property
    def get_saldo(self):
        return self.saldo


    def set_saldo(self, saldo):
        if (saldo < 0):
            print("Um saldo não pode possuir um valor negativo!")
        else:
            self._saldo = saldo

    
    def saque(self,valor):
        if (self.saldo>=valor):
            self.saldo -= valor
            print("Saque realizado com sucesso!")
        else:
            print("Saldo insuficiente!")

    
    def deposita(self,valor):
        self.saldo += valor


    def extrato(self):
        print("Cliente: ", self._titular, " Saldo atual: ", self.saldo)
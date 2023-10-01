from Cliente import Cliente
from Conta import Conta


class Main:
    pass


c1 = Cliente('João', '(75) 9 9203-1081')
conta = Conta(c1.get_nome(), 1222)

conta.deposita(100)
conta.saque(50)
conta.extrato()


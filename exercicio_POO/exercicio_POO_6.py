#ATIVIDADE: POO E CLASSES
#ALUNO: LUIZ HENRIQUE CARNEIRO CARVALHO

#6° Atividade
print("\n")
print("6° ATIVIDADE")
print("\n")

class TV:
    def __init__(self):
        self.canal = 1
        self.volume = 10

    def mudarCanal(self, novo_canal):
        if 1 <= novo_canal <= 100:
            self.canal = novo_canal
            print(f"Canal alterado para {self.canal}")
        else:
            print("Canal inválido.")

    def aumentarVolume(self):
        if self.volume < 100:
            self.volume += 1
            print(f"Volume aumentado para {self.volume}")
        else:
            print("Volume máximo atingido.")

    def diminuirVolume(self):
        if self.volume > 0:
            self.volume -= 1
            print(f"Volume diminuído para {self.volume}")
        else:
            print("Volume mínimo atingido.")

    def mostrarStatus(self):
        print(f"Canal: {self.canal}, Volume: {self.volume}")

tv = TV()

while True:
    print("Opções da TV:")
    print("1 - Aumentar volume")
    print("2 - Diminuir volume")
    print("3 - Mudar canal")
    print("4 - Mostrar status")
    print("0 - Sair")
    
    opcao = input("Escolha uma opção: ")
    
    if opcao == "1":
        tv.aumentarVolume()
    elif opcao == "2":
        tv.diminuirVolume()
    elif opcao == "3":
        novo_canal = int(input("Digite o número do novo canal: "))
        tv.mudarCanal(novo_canal)
    elif opcao == "4":
        tv.mostrarStatus()
    elif opcao == "0":
        break
    else:
        print("Opção inválida. Escolha novamente.")

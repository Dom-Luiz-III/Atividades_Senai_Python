print("================================================")
print("          CENTRO DE DOAÇÃO DE SANGUE")
print("================================================")
print("\n")

idade = int(input("Informe sua idade: \n"))
peso = int(input("Informe o seu peso: \n"))
sono = int(input("Informe o quanto você dormiu nas últimas 24 horas: \n"))

if idade >= 16 and peso >= 50 and sono >= 6:
    print("\n")
    print('==========================================')
    print("    Parabéns, você pode doar Sangue!")
    print("==========================================")
    print("\n")

else:
    print("\n")
    print('============================================')
    print("  Infelizmente você não pode doar sangue.")
    print("============================================")
    print("\n")
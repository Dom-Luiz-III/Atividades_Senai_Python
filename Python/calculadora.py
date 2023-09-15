def soma(x, y):
    return x + y

def subtracao(x, y):
    return x - y

def multiplicacao(x, y):
    return x * y

def divisao(x, y):
    if y == 0:
        return "Erro: divisão por zero"
    return x / y

while True:
    print("\nCALCULADORA BÁSICA:\n")
    print("Opções:")
    print("1 - Soma")
    print("2 - Subtração")
    print("3 - Multiplicação")
    print("4 - Divisão")
    print("0 - Sair")

    escolha = input("\nEscolha a operação desejada: ")

    if escolha == "0":
        break

    if escolha in ("1", "2", "3", "4"):
        num1 = float(input("Digite o primeiro número: "))
        num2 = float(input("Digite o segundo número: "))

        if escolha == "1":
            print("Resultado:", soma(num1, num2))

        elif escolha == "2":
            print("Resultado:", subtracao(num1, num2))

        elif escolha == "3":
            print("Resultado:", multiplicacao(num1, num2))

        elif escolha == "4":
            resultado = divisao(num1, num2)
            if isinstance(resultado, str):
                print(resultado)
            else:
                print("Resultado:", resultado)
        else:
            print("Opção inválida.")
    else:
        print("Opção inválida.")

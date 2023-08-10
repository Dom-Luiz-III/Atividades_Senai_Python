dolar = 3.25
real = 0
iof = 0.0638
op = 0

print('================================')
print('      Conversor de Dólar')
print('================================')
print('\n')

print('Você quer converter em Dólares ou em Reais?')
print('Caso seja Dólar, escolha 1, caso seja Reais, escolha 2:')

op = int(input())
print('\n')

if op == 1:
    print('Informe o valor que deseja calcular em Reais:')
    # Valor da questão do professor: 68 reais para conversão

    valor = float(input())
    valor = valor / dolar

    print('O valor em dólares ficou:')
    print(round(valor))
    print('\n')

else:

    print('Informe o valor que deseja calcular em Dólares:')
    # Valor da questão do professor: 411 dólares no total

    valor = float(input())
    valor = valor * dolar

    print('O valor em reais ficou:')
    print(round(valor))
    print('\n')

    iof = valor * iof

    print('O preço a se pagar pelo IOF é:')
    print(round(iof))
    print('\n')

    valor = valor + iof

    print('Com o IOF adicionado no total fica:')
    print(round(valor))
    print('\n')
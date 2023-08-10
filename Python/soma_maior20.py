a = int(input("Informe o número A: \n"))
b = int(input("Informe o número B: \n"))

a = a + b

if a > 20:
    a = a + 8
    print("Pelo soma do número ser maior que 20, ele agora é %d" % a)

else:
    a = a - 5
    print("Pelo soma do número ser menor que 20, ele teve subtração e agora é %d" % a)
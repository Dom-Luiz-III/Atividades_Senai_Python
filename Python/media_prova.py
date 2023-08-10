notaA = float(input("Informe a primeira nota: "))
notaB = float(input("Informe a segunda nota: "))

media = (notaA + notaB) / 2

if media >= 7:
    print("A média: %.1f - Aprovado" % media)   
else:
    print("A média: %.1f - Reprovado" % media)
#ATIVIDADE 1 (DESENVOLVIMENTO DE SISTEMAS 2 - SENAI)
#ALUNO: LUIZ HENRIQUE CARNEIRO CARVALHO


#1° Atividade
print("\n")
print("1° ATIVIDADE")
print("\n")

lista_cinco = [1, 2, 3, 4, 5]

print(lista_cinco)


#2° Atividade
print("\n")
print("2° ATIVIDADE")
print("\n")

lista_reais = [1.2, 2.3, 3.4, 4.5, 5.2, 6.4, 7.3, 8.5, 9.2, 10.1] 
lista_reais.reverse()

print(lista_reais)


#3° Atividade
print("\n")
print("3° ATIVIDADE")
print("\n")

nota = [4.2,8.9,6.9,7.1]
print('Notas tiradas:')
print(nota)

soma = sum(nota)

soma = soma/4

print('Média das notas:')
print(soma)


#4° Atividade
print("\n")
print("4° ATIVIDADE")
print("\n")

idades = [14,16,17,11,21,20,32,45,90,43,66,52,44,48,64,36,32,33,71,94]
idades.sort()

print(idades)


#5° Atividade
print("\n")
print("5° ATIVIDADE")
print("\n")

#help()
idades_copia = idades.copy()

for idade in idades_copia:
    if isinstance(idade, int):
        del idades[idades.index(idade)]

print(idades)


#7° Atividade
print("\n")
print("7° ATIVIDADE")
print("\n")

lista = ['detergente', 'sabão', 'chocolate', 'feijão', 'café', 'sorvete', 'água sanitária']

print(lista)

#8° Atividade
print("\n")
print("8° ATIVIDADE")
print("\n")

del lista[0]
del lista[0]
del lista[4]

print(lista)

#9° Atividade
print("\n")
print("9° ATIVIDADE")
print("\n")

del lista[3]

print(lista)


#10° Atividade
print("\n")
print("10° ATIVIDADE")
print("\n")

def verificar_par_impar(numero):
    if numero % 2 == 0:
        return "Par"
    else:
        return "Ímpar"

numero1 = 3
numero2 = 4
numero3 = 7
numero4 = 9

resultado1 = verificar_par_impar(numero1)
resultado2 = verificar_par_impar(numero2)
resultado3 = verificar_par_impar(numero3)
resultado4 = verificar_par_impar(numero4)


print(f"O número {numero1} é {resultado1}.")
print(f"O número {numero2} é {resultado2}.")
print(f"O número {numero3} é {resultado3}.")
print(f"O número {numero4} é {resultado4}.")


#11° Atividade
print("\n")
print("11° ATIVIDADE")
print("\n")

def sao_pares_inversos(palavra1, palavra2):
    if len(palavra1) != len(palavra2):
        return False

    return palavra1 == palavra2[::-1]

palavra1 = "roma"
palavra2 = "amor"

resultado1 = sao_pares_inversos(palavra1, palavra2)

palavra3 = "python"
palavra4 = "nohtyp"

resultado2 = sao_pares_inversos(palavra3, palavra4)

palavra5 = "arara"
palavra6 = "aaaaa"

resultado3 = sao_pares_inversos(palavra5, palavra6)

print(f"As palavras '{palavra1}' e '{palavra2}' são pares inversos? {resultado1}")
print(f"As palavras '{palavra3}' e '{palavra4}' são pares inversos? {resultado2}")
print(f"As palavras '{palavra5}' e '{palavra6}' são pares inversos? {resultado3}")


#12° Atividade
print("\n")
print("12° ATIVIDADE")
print("\n")


def eh_primo(numero):
    if numero <= 1:
        return False
    if numero <= 3:
        return True
    if numero % 2 == 0 or numero % 3 == 0:
        return False
    i = 5
    while i * i <= numero:
        if numero % i == 0 or numero % (i + 2) == 0:
            return False
        i += 6
    return True

def imprimir_primos_ate_50():
    for num in range(1, 51):
        if eh_primo(num):
            print(num)

imprimir_primos_ate_50()
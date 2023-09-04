#ATIVIDADE 2
#ALUNO: LUIZ HENRIQUE, LAÍQUE


#1° Atividade

numero = float(input("Digite um número real: ")) 

quadrado = numero ** 2 

print("O quadrado do número é:", quadrado) 


#2° Atividade

numero_exemplo1 = 8
numero_exemplo2 = 10
numero_exemplo3 = 11

print("Numeros escolhidos:\n",  numero_exemplo1, numero_exemplo2, numero_exemplo3)

numero_exemplo1 = numero_exemplo1 / 5
numero_exemplo2 = numero_exemplo2 / 5
numero_exemplo3 = numero_exemplo3 / 5

print("Quinta parte dos numeros escolhidos:\n",  numero_exemplo1, numero_exemplo2, numero_exemplo3)


#3° Atividade

numero_exemplo1 = 5

def antecessor(x):
    adicao = x + 1
    subtracao = x - 1

    print("Numeros escolhido: ", x)
    print("Seu sucessor: ", adicao)
    print("Seu antecessor: ", subtracao)

antecessor(numero_exemplo1)


#4° Atividade

altura = 7
base = 4

p = base * altura

resultado = p/2

print("Altura e base do Triângulo: ", altura, base)
print("Área do triângulo: ", resultado)


#5° Atividade

n = int(input("Me informe o seu número escolhido: \n"))

if n == 0:
    print("O número escolhido é nulo")
elif n >  0:
    print("O número escolhido é positivo")
else:
    print("O número escolhido é negativo")

    
#6° Atividade

numero = int(input("Digite um número: ")) 

if numero % 3 == 0:
    print("É múltiplo de 3")
else:
    print("Não é múltiplo de 3")

#7° Atividade

n = int(input("Me informe o seu número escolhido: \n"))

if n % 5 == 0:  
    print("É divisível por 5")
else:
    print("Não é divisível por 5")


#8° Atividade

numero_A = int(input("Digite o número A: ")) 
numero_B = int(input("Digite o número B: "))  

if numero_A % numero_B == 0:
    print("O número A é divisível por B")
else:
    print("O número A não é divisível por B")
    

#9° Atividade

altura = float(input("Digite a altura em metros:\n"))
sexo = input("Digite o sexo (M para masculino, F para feminino):\n") 

if sexo.upper() == "M":
    peso_ideal = (72.7 * altura) - 58
elif sexo.upper() == "F":
    peso_ideal = (62.1 * altura) - 44.7
else:
    print("Sexo inválido.")
    peso_ideal = None

if peso_ideal is not None:
    print("O peso ideal é:", peso_ideal)

#10° e 11° Atividade

A = 41
B = 98
C = 11

print("Valores escolhidos:", A, B, C)

lista = [A, B, C]
lista.sort()

print("Lista ordenada dos valores:", lista)

lista.reverse()
print("Lista inversa dos valores:", lista)


#12° Atividade
soma = 0 

for numero in range(0, 501, 2):  
    soma += numero

print("O somatório dos valores pares de 0 a 500 é:", soma)


#13° Atividade

lista = [22.2, 44.4, 46.8, 51.4, 80.4, 63.1, 66.7, 61.9, 80.3, 73.7,22.2, 44.4, 46.8, 51.4, 80.4, 63.1, 66.7, 61.9, 80.3, 73.7,22.2, 44.4, 46.8, 51.4, 80.4, 63.1, 66.7, 61.9, 80.3, 73.7,22.2, 44.4, 46.8, 51.4, 80.4, 63.1, 66.7, 61.9, 80.3, 73.7,22.2, 44.4, 46.8, 51.4, 80.4, 63.1, 66.7, 61.9, 80.3, 73.7,22.2, 44.4, 46.8, 51.4, 80.4, 63.1, 66.7, 61.9, 80.3, 73.7,]

print ("Lista aleatória da altura das pessoas:", lista)

lista.sort()

print ("Lista ordenada da altura das pessoas:", lista)


#14° Atividade

bois = [
    {"numero": "001", "peso": 450},
    {"numero": "002", "peso": 520},
    {"numero": "003", "peso": 480},
    {"numero": "090", "peso": 510}
]

boi_mais_gordo = None
boi_mais_magro = None

for boi in bois:
    numero_identificacao = boi["numero"]
    peso = boi["peso"]

    if boi_mais_gordo is None or peso > boi_mais_gordo["peso"]:
        boi_mais_gordo = boi

    if boi_mais_magro is None or peso < boi_mais_magro["peso"]:
        boi_mais_magro = boi

print("Boi mais gordo:")
print("Número de identificação:", boi_mais_gordo["numero"])
print("Peso:", boi_mais_gordo["peso"])

print("Boi mais magro:")
print("Número de identificação:", boi_mais_magro["numero"])
print("Peso:", boi_mais_magro["peso"])

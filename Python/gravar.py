#Comando para criar um arquivo txt utilizando python
arquivo = open('arqText.txt', 'w')
#O "w" que esta no comando serve para reescrever o arquivo já existente, caso ele já tenha sido criado, caso eu queira que ele sirva apenas para leitura, eu coloco um "r"

#Comando para digitar conteúdos dentro do arquivo txt criado
arquivo.write('Curso Python Test \n')
arquivo.write('Aula Prática 2')

#Comando para fechar o arquivo
arquivo.close()

leitura = open('arqText.txt', 'r')
print(leitura.read())
leitura.close()
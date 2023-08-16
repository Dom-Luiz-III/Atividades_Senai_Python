amigos = {
    "João": 25,
    "Maria": 30,
    "Pedro": 28,
    "Julia": 12
}

# Acessando a idade do João
idade_do_joao = amigos["João"]
print("A idade do João é:", idade_do_joao)

# Verificando se a chave "Maria" existe no dicionário
if "Maria" in amigos:
    print("A chave 'Maria' existe no dicionário")

# Iterando sobre as chaves e valores do dicionário
for nome, idade in amigos.items():
    print("Nome:", nome)
    print("Idade:", idade)
    print("---")

    
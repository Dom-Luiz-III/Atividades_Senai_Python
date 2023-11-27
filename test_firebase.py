import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore

# Configurações do Firebase
cred = credentials.Certificate("path/to/serviceAccountKey.json")
firebase_admin.initialize_app(cred)
db = firestore.client()

def inserir_produto(nome, preco, quantidade):
    try:
        produto_ref = db.collection('produto').document()
        produto_ref.set({
            'nome': nome,
            'preco': preco,
            'quantidade': quantidade
        })
        print('Produto inserido com sucesso!')
    except Exception as e:
        print('Erro ao inserir produto:', e)

def listar_produtos():
    try:
        produtos_ref = db.collection('produto').stream()
        for produto in produtos_ref:
            print(f'{produto.id}: {produto.to_dict()}')
    except Exception as e:
        print('Erro ao listar produtos:', e)

def atualizar_produto(produto_id, novo_preco):
    try:
        produto_ref = db.collection('produto').document(produto_id)
        produto_ref.update({
            'preco': novo_preco
        })
        print('Produto atualizado com sucesso!')
    except Exception as e:
        print('Erro ao atualizar produto:', e)

def deletar_produto(produto_id):
    try:
        produto_ref = db.collection('veiculo').document(produto_id)
        produto_ref.delete()
        print('Produto deletado com sucesso!')
    except Exception as e:
        print('Erro ao deletar produto:', e)

while True:
    print('Menu de Opções:')
    print('1. Inserir Produto')
    print('2. Listar Produtos')
    print('3. Atualizar Produto')
    print('4. Deletar Produto')
    print('5. Sair')

    escolha = input('Digite o número da opção desejada: ')

    if escolha == '1':
        nome = input('Digite o nome do produto: ')
        preco = float(input('Digite o preço do produto: '))
        quantidade = int(input('Digite a quantidade do produto: '))
        inserir_produto(nome, preco, quantidade)
    elif escolha == '2':
        listar_produtos()
    elif escolha == '3':
        produto_id = input('Digite o ID do produto a ser atualizado: ')
        novo_preco = float(input('Digite o novo preço do produto: '))
        atualizar_produto(produto_id, novo_preco)
    elif escolha == '4':
        produto_id = input('Digite o ID do produto a ser deletado: ')
        deletar_produto(produto_id)
    elif escolha == '5':
        break
    else:
        print('Opção inválida. Por favor, escolha uma opção válida.')
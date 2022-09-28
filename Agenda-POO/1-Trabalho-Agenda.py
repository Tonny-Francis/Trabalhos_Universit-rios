#Bibliotecas
import os
import time

#Class responsável por ler e atribuir valores no txt
class Agenda:

    #Faz apenas a leitura do arquivo e verifica se email se encontra
    def Leitura(email):
        with open('1-Trabalho-Agenda.txt', 'r') as arquivo:
            for linha in arquivo:
                if email in linha:
                    return True
            arquivo.close()
            return False

    #Faz apenas a escrita de dados no arquivo
    def Escrita(nome, numero, email):
        with open('1-Trabalho-Agenda.txt', 'a') as arquivo:
            arquivo.write(str(nome) + '\n')
            arquivo.write(str(numero) + '\n')
            arquivo.write(str(email) + '\n')
        arquivo.close()

    #Essa função tem duas utilidades, sendo remover um contato e retornar uma lista
    #com todos os daddos de um contato
    def Remove(email, utilidade):
        lista = []
        auxiliar = []
        posicao = 0

        with open('1-Trabalho-Agenda.txt', 'r') as arquivo:
            for linha in arquivo:
                lista.append(linha)
            arquivo.close

        for linha in lista:
            if email in linha:
                posicao = posicao +1
                break
            else:
                posicao = posicao +1

        dados = posicao -3

        for controle in range(3):
            auxiliar.append(lista[dados])
            lista.pop(dados)

        if utilidade == True:
            with open('1-Trabalho-Agenda.txt', 'w') as arquivo:
                for linha in lista:
                    arquivo.write(str(linha))
                arquivo.close
        else:
            return auxiliar

#Função responsável por adicionar novos contatos
def Adicionar():
    LimpaTela()
    print('-+-'*10)
    email = str(input('Email do Contato: ')).lower()
    auxiliar = Agenda.Leitura(email)

    while auxiliar != False:
        print('Email já Registrado!!')
        print('Tente Novamente')
        time.sleep(3)
        print('-+-'*10)
        email = str(input('Email do Contato: ')).lower()
        auxiliar = Agenda.Leitura(email)

    nome = str(input('Nome do Contato: ')).lower()
    numero = str(input('Número do Contato: '))
    Agenda.Escrita(nome, numero, email)

    print('-+-'*10)
    print('Contato {}\nRegistrado com Sucessso!!'.format(nome))
    print('-+-'*10)
    time.sleep(3)
    LimpaTela()

#Função responsável por editar contatos
def Editar():
    LimpaTela()
    print('-+-'*10)
    email = str(input('Digite o Email do Contato que\nDeseja Editar: ')).lower()
    auxiliar = Agenda.Leitura(email)

    while auxiliar != True:
        print('Esse Contato não Existe!!')
        print('Tente Novamente')
        time.sleep(2)
        email = str(input('Digite o Email do Contato que\nDeseja Editar\n>> ')).lower()
    
    Agenda.Remove(email, True)
    Adicionar()

#Função responsável por buscar um contato em específico
def Buscar():
    LimpaTela()
    print('-+-'*10)
    contato = []
    email = str(input('Dgite o Email do Contato que\nDeseja Buscar: ')).lower()
    auxiliar = Agenda.Leitura(email)

    while auxiliar != True:
        print('Este Email não Consta nos Contato')
        print('Tente Novamente')
        time.sleep(2)
        email = str(input('Digite o Email do Contato que\nDeseja Buscar\n>> ')).lower

    contato = Agenda.Remove(email, False)
    
    print('\nDados do Contato'.format(contato[0]))
    print('Nome: {}'.format(contato[0]))
    print('Número: {}'.format(contato[1]))
    print('Email: {}\n'.format(contato[2]))

    print('-+-'*10)
    time.sleep(10)
    LimpaTela()

#Função responsável por listar todos os contatos em ordem
def Listar():
    LimpaTela()
    lista = []
    auxiliar = []

    with open('1-Trabalho-Agenda.txt', 'r') as arquivo:
        for linha in arquivo:
            lista.append(linha.rstrip('\n'))
        arquivo.close

    for x in range(int(len(lista)/3)):
        for controle in range(3):
            auxiliar.append(lista[0])
            lista.pop(0)

        print('-+-'*10)
        print('{:>17} {}\n'.format('Contato', x+1))
        print('Nome: {}'.format(auxiliar[0]))
        print('Número: {}'.format(auxiliar[1]))
        print('Email: {}'.format(auxiliar[2]))
        auxiliar.clear()
    
    print('-+-'*10)
    input('\nPressione Enter para Sair...')
    LimpaTela()

#Função responsável por remover um contatos
def Remover():
    LimpaTela()
    email = str(input('Email do Contato a ser Removido:\n')).lower()
    auxiliar = Agenda.Leitura(email)

    while auxiliar != True:
        LimpaTela()
        print('Este Email não Consta nos Contato')
        print('Tente Novamente')
        time.sleep(3)
        LimpaTela()
        email = str(input('Email do Contato a ser Removido:\n')).lower()
    
    Agenda.Remove(email, True)
    LimpaTela()
    print('Contato Removido!!')
    print('-+-'*10)
    time.sleep(3)

#Função responsável por vericar qual o sistema e aplicar os devidos
#comandos para limpar o screen 
def LimpaTela():
    if os.name == "nt":
        os.system("clear")
    else:
        os.system("cls")

#Função responsavel por organizar a agenda com as devidas funções e seleção de menu
def ProgramaPrincipal():
    LimpaTela()
    controle = True
    while controle != False:
        #Titulo
        print('-+-'*10)
        print('{:>22}'.format('Agenda  Pessoal'))
        print('-+-'*10)

        #Menu
        print('\n {:>16}\n'.format('Menu'))
        print('1 - Inserir Contato')
        print('2 - Editar Contato')
        print('3 - Buscar Contato')
        print('4 - Listar Contatos')
        print('5 - Remover Contato')
        print('6 - Sair\n')
        print('-+-'*10)
        
        #Seleção
        menu = int(input('Opção Desejada: '))

        #Verificação
        if menu == 1:
            Adicionar()
        elif menu == 2:
            Editar()
        elif menu == 3:
            Buscar()
        elif menu == 4:
            Listar()
        elif menu == 5:
            Remover()
        elif menu == 6:
            LimpaTela()
            print('-+-'*10)
            print('{:>24}'.format('Fechando Agenda...'))
            print('-+-'*10)
            time.sleep(2)
            LimpaTela()
            controle = False
        else:
            LimpaTela()
            print('-+-'*10)
            print('{:>27}'.format('Opção desejada Inválida!'))
            print('-+-'*10)
            time.sleep(2)
            LimpaTela()

#Programa Principal
ProgramaPrincipal()
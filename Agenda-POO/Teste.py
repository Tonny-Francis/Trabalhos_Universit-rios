def Listar():
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

        print('\nContato {}\n'.format(x+1))
        print('Nome: {}'.format(auxiliar[0]))
        print('Número: {}'.format(auxiliar[1]))
        print('Email: {}'.format(auxiliar[2]))
        auxiliar.clear()

Listar()
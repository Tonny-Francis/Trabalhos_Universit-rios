/*
        ==================== Caça Palavras ==============
        Data:18/02/2021    Ultima Edição:03/03/2021
        Autores: Alessandro Barbosa e Tonny Francis
        Finalidade: Criar um Caça Palvras no Tema Covid-19

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Funçoes
void BemVindo();
void JogadorSolo();
void Configuracoes();
void CaracteresAleatorios();
void Distribuicao();
void ImprimeMatriz();
void Sair();
void Alternacao();
void Jogador1();
void Jogador2();
void PontSolo();
void PontMult();
void Nomes();
void PontFinal();
void Pergunta1();
void Pergunta2();
void Dicas();

//Structs
struct nivel
{
    char Texto[500];
};

//Variáveis Globais
int Menu, i, m, Proximo = 0, Encontrou = 0, j, n, Segundos = 5, Dificuldade;
char Matriz[15][15], Busca[50], Dica1[50], S[10] = "sair";

//Variáveis Modo Solo
int LevelSolo = 1, TentativaSolo = 1, AcertosSolo, ErrosSolo, LevelEndSolo;

//Variaveis Modo Multiplayer
int LevelMult = 1, TentativaMult = 1, AcertosMult1, AcertosMult2, ErrosMult1,
    ErrosMult2, LevelEndMult;

char NomeMult1[50], NomeMult2[50];

//Variaveis Auxiliares
int AcertosMult1level1 = 0, AcertosMult1level2 = 0, AcertosMult1level3 = 0,
    ErrosMult1level1 = 0, ErrosMult1level2 = 0; ErrosMult1level3 = 0;

int AcertosMult2level1 = 0, AcertosMult2level2 = 0, AcertosMult2level3 = 0,
    ErrosMult2level1 = 0, ErrosMult2level2 = 0; ErrosMult2level3 = 0;

int AcertosSololevel1 = 0, AcertosSololevel2 = 0, AcertosSololevel3 = 0,
    ErrosSololevel1 = 0, ErrosSololevel2 = 0; ErrosSololevel3 = 0;

int main ()
{
    //Definindo Idioma
    setlocale(LC_ALL, "Portuguese");

    //Chamando a função Bem-Vindo
    BemVindo();

    //Geração de Numeros Aleatorios
    CaracteresAleatorios();

    //Seleção de Menu
    switch (Menu)
    {
        //Modo Jogador Solo
        case 1:

        //Chamando JogadorSolo
        Configuracoes();
        JogadorSolo();

        break;

        //Modo de Dois Jogadores
        case 2:

        Nomes();

        //Chamando Função Alternação
        Alternacao();
        //faz a liberação da memoria alocada para a variavel nome1
        free(NomeMult1);
        //faz a liberação da memoria alocada para a variavel nome2
        free(NomeMult2);
        
        break;

        //Opção de Sair
        case 3:

        //Chamando Função Sair
        Sair();
        //Comando Responsavel por fechar o programa
        exit(0);

        break;

        default:
        printf("\n");

    }
    return 0;

}
void BemVindo()
{
    //Bem Vindo
    system("clear || cls");
    printf("\n==============================\n");
    printf("          Bem-Vindo               ");
    printf("\n==============================\n");
    printf("\n            Menu            \n\n");
    printf("       1- Jogo Solo             \n");
    printf("       2- Jogo Multiplayer      \n");
    printf("       3- Sair                  \n");
    printf("==============================  \n");
    printf("\nOpção Escolhida: ");
    scanf("%d", &Menu);
    system("clear || cls");

    //Caso o jogador digite uma opção inválida
    if(Menu < 1 || Menu > 3)
    {
        printf("\n==============================\n");
        printf("         Opção Inválida           ");
        printf("\n==============================\n");
        sleep(3);
        system("clear || cls");
        return main ();
    }
}
void JogadorSolo()
{
    Distribuicao();

    for(int u = 0; u < 50; u++)
    {
        //Estrutura de Visualização de rodadas, erros etc...
        system("clear || cls");
        printf("\n==============================\n");
        printf("         Caça Palavras            ");
        printf("\n==============================\n");
        printf("Nivel %d\n", LevelSolo);
        printf("Rodada de N°: %d\n", TentativaSolo);
        printf("Acertos: %d   Erros: %d\n", AcertosSolo, ErrosSolo);
        printf("Para Sair Digite (Sair)\n");
        printf("==============================\n");

        //Criando Struct dicas de cada nivel
        struct nivel dicas[3];
        strcpy(dicas[0].Texto, "Sintomas");
        strcpy(dicas[1].Texto, "Formas de Contagio");
        strcpy(dicas[2].Texto, "Primeiros Países a serem Contagiados");

        //Faz a comparação para saber em que nivel esta e assim imprimir a dica correta
        if(LevelSolo == 1 )
        {
            printf("Dica:\n");
            printf("%s", dicas[0].Texto);
        }

        else if(LevelSolo == 2)
        {
            printf("Dica:\n");
            printf("%s", dicas[1].Texto);
        }

        else
        {
            printf("Dica:\n");
            printf("%s", dicas[2].Texto);
        }

        printf("\n");

        printf("\nCaça Palavras:\n\n");
        ImprimeMatriz();
        printf("\nQual a Palavra Encontrada?\n");
        scanf("%s", &Busca);

        //Passa todos os caracteres digitados para minusculo
        m = strlen(Busca);

        for( int g = 0; g < n; g++)
        {
            if( (Busca[g] >= 'A') && (Busca[g] <= 'Z') )
            {
                Busca[g] = Busca[g] + 32;
            }
        }

        //Faz a comparação para ver se o jogador digitou sair, caso sim retorna ao menu principal
        if( strcmp(S, Busca) == 0 )
        {
            Reset();
            return main();
        }

        //Estrutura do Nivel 1
        struct nivel nivel[50];
        struct nivel nivel2[50];
        struct nivel nivel3[50];

        //Lista do Nivel 1
        strcpy(nivel[0].Texto, "cansaço");
        strcpy(nivel[1].Texto, "diarreia");
        strcpy(nivel[2].Texto, "dores");
        strcpy(nivel[3].Texto, "febre");
        strcpy(nivel[4].Texto, "tosse");

        //Lista do Nivel 2
        strcpy(nivel2[0].Texto, "contato");
        strcpy(nivel2[1].Texto, "saliva");
        strcpy(nivel2[2].Texto, "espirro");
        strcpy(nivel2[3].Texto, "tosse");
        strcpy(nivel2[4].Texto, "catarro");
        strcpy(nivel2[5].Texto, "objetos");

        //Lista do Nivel 3
        strcpy(nivel3[0].Texto, "alemanha");
        strcpy(nivel3[1].Texto, "china");
        strcpy(nivel3[2].Texto, "espanha");
        strcpy(nivel3[3].Texto, "estadosunidos");
        strcpy(nivel3[4].Texto, "india");
        strcpy(nivel3[5].Texto, "italia");
        strcpy(nivel3[6].Texto, "japao");
        strcpy(nivel3[7].Texto, "reinounido");
        strcpy(nivel3[8].Texto, "frança");

        Encontrou = 0;

        //Percorre cada linha da matriz, fazendo comparações para ver se a palavra digitada ta na lista-Nivel 1
        if(LevelSolo == 1 )
        {
            for( int a = 0; a < 5; a++)
            {
                if( strcmp(nivel[a].Texto, Busca) == 0 )
                {
                    AcertosSolo++;
                    Encontrou = 1;
                }
            }
        }

        //Percorre cada linha da matriz, fazendo comparações para ver se a palavra digitada ta na lista-Nivel 2
        if(LevelSolo == 2 )
        {
            for( int a = 0; a < 6; a++)
            {
                if( strcmp(nivel2[a].Texto, Busca) == 0 )
                {
                    AcertosSolo++;
                    Encontrou = 1;
                }
            }
        }

        //Percorre cada linha da matriz, fazendo comparações para ver se a palavra digitada ta na lista-Nivel 3
        if(LevelSolo == 3 )
        {
            for( int a = 0; a < 9; a++)
            {
                if( strcmp(nivel3[a].Texto, Busca) == 0 )
                {
                    AcertosSolo++;
                    Encontrou = 1;
                }
            }
        }

        //Faz a distribuição de letras maiusculas na matriz caso tenha acertado alguma
        DistribuicaoDestaque();

        //Se os acertos do jogador solo forem iguais a quantidade de palavras maxima o jogo e encerrada e chama o sistema de pontuação
        if ( AcertosSolo == LevelEndSolo)
        {
            PontSolo();
        }

        //Se a variavel 'encontrou' estiver com '0' significa que a palavra digitada não foi encontrada.
        if(!Encontrou)
        {
            ErrosSolo++;
        }

        //Numero de rodadas
        TentativaSolo++;
    }
}
void Configuracoes()
{
    for(i = 0; i < Segundos; i++)
    {
        printf("\n==============================");
        printf("\n   Configurações Escolhidas   ");
        printf("\n   1- Modo %d                 ", Menu);
        printf("\n   2- Nivel %d                 ", LevelSolo);
        printf("\n==============================");
        printf("\n   Iniciando o Jogo em %d     ", i+1);
        printf("\n==============================");
        printf("\n");
        sleep(1);
        system("clear || cls");

    }
}
void CaracteresAleatorios()
{
    //Geração de Caracteres Aleatorios
    srand((unsigned)time(NULL));

    for(int k = 0; k < 15; k++)
    {
        for(int h = 0; h < 15; h++)
        {
            n = 'a' + (rand()%20);

            Matriz[k][h] = n;
        }
    }
}
void ImprimeMatriz()
{
    //Imprime matriz
    for(int k = 0; k < 15; k++)
    {
        for(int h = 0; h < 15; h++)
        {
            printf("%c ", Matriz[k][h]);
        }

        printf("\n");
    }
}
void Sair()
{
    //Agradeçe por jogasr o jogo
    printf("\n==============================\n");
    printf("    Obrigado Por Jogar +_+        ");
    printf("\n==============================\n");
    sleep(3);
    system("clear || cls");

}
void Alternacao()
{   
    TentativaMult = 1;

    Distribuicao();
    //Laço Responsável por repetir o jogo e fazer alternação entre jogador 1 e jogador 2
    for ( i = 0; i < 50; i++ )
    {
        //Sistema de Pontuação
        for ( int z = 0; z < 1; z++ )
        {   
            //Jogador 1
            PontMult();
            Jogador1();
                
            for ( int s = 0; s < 1; s++)
            {   
                //PontMult();

                for ( int x = 0; x < 1; x++ )
                {
                    //Jogador 2
                    PontMult();
                    Jogador2();
                }
            }
        }   
        TentativaMult++;
    }

}
void Jogador1()
{   
    //Estrutura de Visualização de rodadas, erros etc...
    system("clear || cls");
    printf("\n==============================\n");
    printf("         Caça Palavras            ");
    printf("\n==============================\n");
    printf("Vez de %s\n", NomeMult1);
    printf("Nivel %d\n", LevelMult);
    printf("Rodada de N°: %d\n", TentativaMult);
    printf("Acertos: %d   Erros: %d\n", AcertosMult1, ErrosMult1);
    printf("Para Sair Digite (Sair)\n");
    printf("==============================\n");

    //Criando Struct dicas de cada nivel
    struct nivel dicas[3];
    strcpy(dicas[0].Texto, "Sintomas");
    strcpy(dicas[1].Texto, "Formas de Contagio");
    strcpy(dicas[2].Texto, "Primeiros Países a serem Contagiados");

    //Faz a comparação para saber em que nivel esta e assim imprimir a dica correta
    if(LevelMult == 1 )
    {
        printf("Dica:\n");
        printf("%s", dicas[0].Texto);
    }

    else if(LevelMult == 2)
    {
        printf("Dica:\n");
        printf("%s", dicas[1].Texto);
    }

    else
    {
        printf("Dica:\n");
        printf("%s", dicas[2].Texto);
    }

    printf("\n");

    printf("\nCaça Palavras:\n\n");
    ImprimeMatriz();
    printf("\nQual a Palavra Encontrada?\n");
    scanf("%s", &Busca);

    //Passa todos os caracteres digitados para minusculo
    m = strlen(Busca);

    for( int g = 0; g < n; g++)
    {
        if( (Busca[g] >= 'A') && (Busca[g] <= 'Z') )
        {
            Busca[g] = Busca[g] + 32;
        }
    }

    //Faz a comparação para ver se o jogador digitou sair, caso sim retorna ao menu principal
    if( strcmp(S, Busca) == 0 )
    {
        Reset();
        return main();
    }

    //Chama a função responsável por fazer pergunta e comparações
    Pergunta1();
}
void Jogador2()
{
    //Estrutura de Visualização de rodadas, erros etc...
    system("clear || cls");
    printf("\n==============================\n");
    printf("         Caça Palavras            ");
    printf("\n==============================\n");
    printf("Vez de %s\n", NomeMult2);
    printf("Nivel %d\n", LevelMult);
    printf("Rodada de N°: %d\n", TentativaMult);
    printf("Acertos: %d   Erros: %d\n", AcertosMult2, ErrosMult2);
    printf("Para Sair Digite (Sair)\n");
    printf("==============================\n");

    //Criando Struct dicas de cada nivel
    struct nivel dicas[3];
    strcpy(dicas[0].Texto, "Sintomas");
    strcpy(dicas[1].Texto, "Formas de Contagio");
    strcpy(dicas[2].Texto, "Primeiros Países a serem Contagiados");

    //Faz a comparação para saber em que nivel esta e assim imprimir a dica correta
    if(LevelMult == 1 )
    {
        printf("Dica:\n");
        printf("%s", dicas[0].Texto);
    }

    else if(LevelMult == 2)
    {
        printf("Dica:\n");
        printf("%s", dicas[1].Texto);
    }

    else
    {
        printf("Dica:\n");
        printf("%s", dicas[2].Texto);
    }

    printf("\n");

    printf("\nCaça Palavras:\n\n");
    ImprimeMatriz();
    printf("\nQual a Palavra Encontrada?\n");
    scanf("%s", &Busca);

    //Passa todos os caracteres digitados para minusculo
    m = strlen(Busca);

    for( int g = 0; g < n; g++)
    {
        if( (Busca[g] >= 'A') && (Busca[g] <= 'Z') )
        {
            Busca[g] = Busca[g] + 32;
        }
    }

    //Faz a comparação para ver se o jogador digitou sair, caso sim retorna ao menu principal
    if( strcmp(S, Busca) == 0 )
    {
        Reset();
        return main();
    }

    //Chama a função responsável por fazer pergunta e comparações
    Pergunta2();

}
void PontSolo()
{
    //Sistema de Pontuação
    system("clear || cls");
    printf("\n==============================\n");
    printf("            Pontuação             ");
    printf("\n==============================\n");
    printf("Rodadas Jogadas: %d\n", TentativaSolo);
    printf("Acertos: %d   Erros: %d\n", AcertosSolo, ErrosSolo);

    if ( LevelSolo < 3 )
    {
    printf("Deseja ir Para o Proximo Nivel? 1 - SIM ou 2- NÃO");
    printf("\nResposta: ");
    scanf("%d", &Proximo);

    //Armazen os acertos e erros de cada nivel
    if( LevelSolo == 1 )
    {
        //Passando os valores para variaveis auxiliares
        AcertosSololevel1 = AcertosSolo;
        ErrosSololevel1 = ErrosSolo;
    }

    else if( LevelSolo == 2 )
    {
        //Passando os valores para variaveis auxiliares
        AcertosSololevel2 =(AcertosSolo*2)+AcertosSololevel1;
        ErrosSololevel2 = (ErrosSolo*2)+ErrosSololevel1;
    }

    else
    {
        //Passando os valores para variaveis auxiliares
        AcertosSololevel3=(AcertosSolo*3)+AcertosSololevel2;
        ErrosSololevel3=(ErrosSolo*3)+ErrosSololevel2;
    }

    //Pergunta se quer ir para o proximo nivel, caso contrario retorna ao menu principal
    if( Proximo == 1 )
    {
        AcertosSolo = 0;
        ErrosSolo = 0;
        LevelSolo++;
        TentativaSolo = 0;
        return JogadorSolo();
    }

    else
    {
        Sair();
        return main();
    }
    }

    else
    {   
        PontFinalSolo();
        return main();
    }

}
void PontMult()
{   
    //Faz a comparação se algum dos dois jogadores chegou a pontuação maxima 
    if ( (AcertosMult1 + AcertosMult2 == 5) || ( AcertosMult1 == 5 ) || ( AcertosMult2 == 5 ) && LevelMult == 1 )
    {
        complementoPontMult();
    }

    if ( AcertosMult1 + AcertosMult2 == 6 || ( AcertosMult1 == 6 ) || ( AcertosMult2 == 6 ) && LevelEndSolo == 2 )
    {
        complementoPontMult();
    }

    if ( AcertosMult1 + AcertosMult2 == 9 || ( AcertosMult1 == 9 ) || ( AcertosMult2 == 9 ) && LevelEndMult == 3 )
    {
        complementoPontMult();
    }
}
void Nomes()
{
    //Pergunta os nomes no modo Mult
    printf("Digite o Nome do Jogador 1:\n");
    printf("Resposta: ");
    scanf("%s", NomeMult1);

    //Faz a alocação dinamica do nome 1
    char *NomeMult1= (char*)malloc(sizeof(char));
    printf("\n");
    printf("Digite o Nome do Jogador 2:\n");
    printf("Resposta: ");
    scanf("%s", NomeMult2);

    //Faz a alocação dinamica do nome 2
    char  *NomeMult2= (char *)malloc(sizeof(char));
}
void PontFinal()
{
    //Mostra a pontuação de cada nivel jogado
    system("clear || cls");
    printf("\n==============================\n");
    printf("          Pontuação Final         ");
    printf("\n==============================\n");
    printf("              Nivel 1             ");
    printf("\nJogador 1: %s",NomeMult1);
    printf("\nAcertos: %d   Erros: %d", AcertosMult1level1, ErrosMult1level1);
    printf("\nJogador 2: %s",NomeMult2);
    printf("\nAcertos: %d   Erros: %d", AcertosMult2level1, ErrosMult2level1);
    printf("\n==============================\n");
    printf("              Nivel 2             ");
    printf("\nJogador 1: %s",NomeMult1);
    printf("\nAcertos: %d   Erros: %d", AcertosMult1level2, ErrosMult1level2);
    printf("\nJogador 2: %s",NomeMult2);
    printf("\nAcertos: %d   Erros: %d", AcertosMult2level2, ErrosMult2level2);
    printf("\n==============================\n");
    printf("              Nivel 3             ");
    printf("\nJogador 1: %s",NomeMult1);
    printf("\nAcertos: %d   Erros: %d", AcertosMult1level3, ErrosMult1level3);
    printf("\nJogador 2: %s",NomeMult2);
    printf("\nAcertos: %d   Erros: %d", AcertosMult2level3, ErrosMult2level3);
    printf("\n==============================\n");
    sleep(6);
    system("clear || cls");
    return main ();
    //Após o periodo de 6 segundos retorna ao menu principal
}
void Pergunta1()
{
    //Criando uma struct para cada nivel
    struct nivel nivel[50];
    struct nivel nivel2[50];
    struct nivel nivel3[50];

        //Lista do Nivel 1
        strcpy(nivel[0].Texto, "cansaço");
        strcpy(nivel[1].Texto, "diarreia");
        strcpy(nivel[2].Texto, "dores");
        strcpy(nivel[3].Texto, "febre");
        strcpy(nivel[4].Texto, "tosse");

        //Lista do Nivel 2
        strcpy(nivel2[0].Texto, "contato");
        strcpy(nivel2[1].Texto, "saliva");
        strcpy(nivel2[2].Texto, "espirro");
        strcpy(nivel2[3].Texto, "tosse");
        strcpy(nivel2[4].Texto, "catarro");
        strcpy(nivel2[5].Texto, "objetos");
    
        //Lista do Nivel 3
        strcpy(nivel3[0].Texto, "alemanha");
        strcpy(nivel3[1].Texto, "china");
        strcpy(nivel3[2].Texto, "espanha");
        strcpy(nivel3[3].Texto, "estadosunidos");
        strcpy(nivel3[4].Texto, "india");
        strcpy(nivel3[5].Texto, "italia");
        strcpy(nivel3[6].Texto, "japao");
        strcpy(nivel3[7].Texto, "reinounido");
        strcpy(nivel3[8].Texto, "frança");
    

    Encontrou = 0;

    //Percorre cada linha da matriz, fazendo comparações para ver se a palavra digitada ta na lista-Nivel 1
    if(LevelMult == 1 )
    {
        for( int a = 0; a < 5; a++)
        {
            if( strcmp(nivel[a].Texto, Busca) == 0 )
            {
                AcertosMult1++;
                Encontrou = 1;
            }
        }
    }

        //Percorre cada linha da matriz, fazendo comparações para ver se a palavra digitada ta na lista-Nivel 2
    if(LevelMult == 2 )
    {
        for( int a = 0; a < 6; a++)
        {
            if( strcmp(nivel2[a].Texto, Busca) == 0 )
            {
                AcertosMult1++;
                Encontrou = 1;
            }
        }
    }

    //Percorre cada linha da matriz, fazendo comparações para ver se a palavra digitada ta na lista-Nivel 3
    if(LevelMult == 3 )
    {
        for( int a = 0; a < 9; a++)
        {
            if( strcmp(nivel3[a].Texto, Busca) == 0 )
            {
                AcertosMult1++;
                Encontrou = 1;
            }
        }
    }

    //Faz a distribuição de letras maiusculas na matriz caso tenha acertado alguma
    DistribuicaoDestaque();

    //Se a variavel 'encontrou' estiver com '0' significa que a palavra digitada não foi encontrada.
    if(!Encontrou)
    {
        ErrosMult1++;
    }
}
void Pergunta2()
{
    struct nivel nivel[50];
    struct nivel nivel2[50];
    struct nivel nivel3[50];

        //Lista do Nivel 1
        strcpy(nivel[0].Texto, "cansaço");
        strcpy(nivel[1].Texto, "diarreia");
        strcpy(nivel[2].Texto, "dores");
        strcpy(nivel[3].Texto, "febre");
        strcpy(nivel[4].Texto, "tosse");
    
        //Lista do Nivel 2
        strcpy(nivel2[0].Texto, "contato");
        strcpy(nivel2[1].Texto, "saliva");
        strcpy(nivel2[2].Texto, "espirro");
        strcpy(nivel2[3].Texto, "tosse");
        strcpy(nivel2[4].Texto, "catarro");
        strcpy(nivel2[5].Texto, "objetos");

        //Lista do Nivel 3
        strcpy(nivel3[0].Texto, "alemanha");
        strcpy(nivel3[1].Texto, "china");
        strcpy(nivel3[2].Texto, "espanha");
        strcpy(nivel3[3].Texto, "estadosunidos");
        strcpy(nivel3[4].Texto, "india");
        strcpy(nivel3[5].Texto, "italia");
        strcpy(nivel3[6].Texto, "japao");
        strcpy(nivel3[7].Texto, "reinounido");
        strcpy(nivel3[8].Texto, "frança");


    Encontrou = 0;

    //Percorre cada linha da matriz, fazendo comparações para ver se a palavra digitada ta na lista-Nivel 1
    if(LevelMult == 1 )
    {
        for( int a = 0; a < 5; a++)
        {
            if( strcmp(nivel[a].Texto, Busca) == 0 )
            {
                AcertosMult2++;
                Encontrou = 1;
            }
        }
    }

    //Percorre cada linha da matriz, fazendo comparações para ver se a palavra digitada ta na lista-Nivel 2
    if(LevelMult == 2 )
    {
        for( int a = 0; a < 6; a++)
        {
            if( strcmp(nivel2[a].Texto, Busca) == 0 )
            {
                AcertosMult2++;
                Encontrou = 1;
            }
        }
    }

    //Percorre cada linha da matriz, fazendo comparações para ver se a palavra digitada ta na lista-Nivel 3
    if(LevelMult == 3 )
    {
        for( int a = 0; a < 9; a++)
        {
            if( strcmp(nivel3[a].Texto, Busca) == 0 )
            {
                AcertosMult2++;
                Encontrou = 1;
            }
        }
    }

    //Faz a distribuição de letras maiusculas na matriz caso tenha acertado alguma
    DistribuicaoDestaque();

    //Se a variavel 'encontrou' estiver com '0' significa que a palavra digitada não foi encontrada.
    if(!Encontrou)
    {
        ErrosMult2++;
    }
}
void DistribuicaoDestaque()
{
    //Criando uma struct para cada nivel
    struct nivel nivel[50];
    struct nivel nivel2[50];
    struct nivel nivel3[50];

    //Verifica o nivel e Coloca as palavras na lista

    //Lista do Nivel 1
    strcpy(nivel[0].Texto, "cansaço");
    strcpy(nivel[1].Texto, "diarreia");
    strcpy(nivel[2].Texto, "dores");
    strcpy(nivel[3].Texto, "febre");
    strcpy(nivel[4].Texto, "tosse");

    //Lista do Nivel 2
    strcpy(nivel2[0].Texto, "contato");
    strcpy(nivel2[1].Texto, "saliva");
    strcpy(nivel2[2].Texto, "espirro");
    strcpy(nivel2[3].Texto, "tosse");
    strcpy(nivel2[4].Texto, "catarro");
    strcpy(nivel2[5].Texto, "objetos");

    //Lista do Nivel 3
    strcpy(nivel3[0].Texto, "alemanha");
    strcpy(nivel3[1].Texto, "china");
    strcpy(nivel3[2].Texto, "espanha");
    strcpy(nivel3[3].Texto, "estadosunidos");
    strcpy(nivel3[4].Texto, "india");
    strcpy(nivel3[5].Texto, "italia");
    strcpy(nivel3[6].Texto, "japao");
    strcpy(nivel3[7].Texto, "reinounido");
    strcpy(nivel3[8].Texto, "frança");

    //Passando Caracteres para Maiusculo, nivel 1
    if( (LevelSolo == 1) || (LevelMult == 1 ) )
    {
        if( strcmp(nivel[0].Texto, Busca) == 0 )
        {
            //Cansaço
            Matriz[1][1] = 'c'- 32;
            Matriz[2][2] = 'a'- 32;
            Matriz[3][3] = 'n'- 32;
            Matriz[4][4] = 's'- 32;
            Matriz[5][5] = 'a'- 32;
            Matriz[6][6] = 'c'- 32;
            Matriz[7][7] = 'o'- 32;
        }

        if( strcmp(nivel[1].Texto, Busca) == 0 )
        {
            //Diarreia
            Matriz[3][9] = 'd'- 32;
            Matriz[4][9] = 'i'- 32;
            Matriz[5][9] = 'a'- 32;
            Matriz[6][9] = 'r'- 32;
            Matriz[7][9] = 'r'- 32;
            Matriz[8][9] = 'e'- 32;
            Matriz[9][9] = 'i'- 32;
            Matriz[10][9] = 'a'- 32;
        }

        if( strcmp(nivel[2].Texto, Busca) == 0 )
        {
            //Dores
            Matriz[9][5] = 'd'- 32;
            Matriz[10][5] = 'o'- 32;
            Matriz[11][5] = 'r'- 32;
            Matriz[12][5] = 'e'- 32;
            Matriz[13][5] = 's'- 32;
        }

        if( strcmp(nivel[3].Texto, Busca) == 0 )
        {
            //Febre
            Matriz[10][10] = 'f'- 32;
            Matriz[11][10] = 'e'- 32;
            Matriz[12][10] = 'b'- 32;
            Matriz[13][10] = 'r'- 32;
            Matriz[14][10] = 'e'- 32;
        }

        if( strcmp(nivel[4].Texto, Busca) == 0 )
        {
            //Tosse
            Matriz[14][5] = 't'- 32;
            Matriz[14][6] = 'o'- 32;
            Matriz[14][7] = 's'- 32;
            Matriz[14][8] = 's'- 32;
            Matriz[14][9] = 'e'- 32;
        }

    }

    //Passando Caracteres para Maiusculo, nivel 2
    if( (LevelSolo == 2) || (LevelMult == 2 ) )
    {
        if( strcmp(nivel2[0].Texto, Busca) == 0 )
        {
            //Contato
            Matriz[9][6] = 'c'- 32;
            Matriz[8][6] = 'o'- 32;
            Matriz[7][6] = 'n'- 32;
            Matriz[6][6] = 't'- 32;
            Matriz[5][6] = 'a'- 32;
            Matriz[4][6] = 't'- 32;
            Matriz[3][6] = 'o'- 32;
        }

        if( strcmp(nivel2[1].Texto, Busca) == 0 )
        {
            //Saliva
            Matriz[2][1] = 's'- 32;
            Matriz[2][2] = 'a'- 32;
            Matriz[2][3] = 'l'- 32;
            Matriz[2][4] = 'i'- 32;
            Matriz[2][5] = 'v'- 32;
            Matriz[2][6] = 'a'- 32;
        }

        if( strcmp(nivel2[2].Texto, Busca) == 0 )
        {
            //Espirro
            Matriz[14][8] = 'e'- 32;
            Matriz[13][7] = 's'- 32;
            Matriz[12][6] = 'p'- 32;
            Matriz[11][5] = 'i'- 32;
            Matriz[10][4] = 'r'- 32;
            Matriz[9][3] = 'r'- 32;
            Matriz[8][2] = 'o'- 32;
        }

        if( strcmp(nivel2[3].Texto, Busca) == 0 )
        {
            //Tosse
            Matriz[14][10] = 't'- 32;
            Matriz[14][11] = 'o'- 32;
            Matriz[14][12] = 's'- 32;
            Matriz[14][13] = 's'- 32;
            Matriz[14][14] = 'e'- 32;
        }

        if( strcmp(nivel2[4].Texto, Busca) == 0 )
        {
            //Catarro
            Matriz[14][0] = 'c'- 32;
            Matriz[13][1] = 'a'- 32;
            Matriz[12][2] = 't'- 32;
            Matriz[11][3] = 'r'- 32;
            Matriz[10][4] = 'r'- 32;
            Matriz[9][5] = 'o'- 32;
        }

        if( strcmp(nivel2[5].Texto, Busca) == 0 )
        {
            //Objetos
            Matriz[1][13] = 'o'- 32;
            Matriz[2][12] = 'b'- 32;
            Matriz[3][11] = 'j'- 32;
            Matriz[4][10] = 'e'- 32;
            Matriz[5][9] = 't'- 32;
            Matriz[6][8] = 'o'- 32;
            Matriz[7][7] = 's'- 32;
        }
    }

    //Passando Caracteres para Maiusculo, nivel 3
    if( (LevelSolo == 3) || (LevelMult == 3) )
    {
        if( strcmp(nivel3[1].Texto, Busca) == 0 )
        {
            //China
            Matriz[14][4] = 'c'- 32;
            Matriz[14][5] = 'h'- 32;
            Matriz[14][6] = 'i'- 32;
            Matriz[14][7] = 'n'- 32;
            Matriz[14][8] = 'a'- 32;
        }

        if( strcmp(nivel3[0].Texto, Busca) == 0 )
        {
            //Alemanha
            Matriz[2][0] = 'a'- 32;
            Matriz[3][0] = 'l'- 32;
            Matriz[4][0] = 'e'- 32;
            Matriz[5][0] = 'm'- 32;
            Matriz[6][0] = 'a'- 32;
            Matriz[7][0] = 'n'- 32;
            Matriz[8][0] = 'h'- 32;
            Matriz[9][0] = 'a'- 32;
        }

        if( strcmp(nivel3[5].Texto, Busca) == 0 )
        {
            //Italia
            Matriz[9][1] = 'i'- 32;
            Matriz[8][1] = 't'- 32;
            Matriz[7][1] = 'a'- 32;
            Matriz[6][1] = 'l'- 32;
            Matriz[5][1] = 'i'- 32;
            Matriz[4][1] = 'a'- 32;
        }

        if( strcmp(nivel3[6].Texto, Busca) == 0 )
        {
            //Japão
            Matriz[8][10] = 'j'- 32;
            Matriz[9][11] = 'a'- 32;
            Matriz[10][12] = 'p'- 32;
            Matriz[11][13] = 'a'- 32;
            Matriz[12][14] = 'o'- 32;
        }

        if( strcmp(nivel3[8].Texto, Busca) == 0 )
        {
            //Françã
            Matriz[1][3] = 'f'- 32;
            Matriz[1][4] = 'r'- 32;
            Matriz[1][5] = 'a'- 32;
            Matriz[1][6] = 'n'- 32;
            Matriz[1][7] = 'c'- 32;
            Matriz[1][8] = 'a'- 32;
        }

        if( strcmp(nivel3[4].Texto, Busca) == 0 )
        {
            //India
            Matriz[9][1] = 'i'- 32;
            Matriz[8][2] = 'n'- 32;
            Matriz[7][3] = 'd'- 32;
            Matriz[6][4] = 'i'- 32;
            Matriz[5][5] = 'a'- 32;
        }

        if( strcmp(nivel3[3].Texto, Busca) == 0 )
        {
            //Estados Unidos
            Matriz[12][2] = 'e'- 32;
            Matriz[11][3] = 's'- 32;
            Matriz[10][4] = 't'- 32;
            Matriz[9][5] = 'a'- 32;
            Matriz[8][6] = 'd'- 32;
            Matriz[7][7] = 'o'- 32;
            Matriz[6][8] = 's'- 32;
            Matriz[5][9] = 'u'- 32;
            Matriz[4][10] = 'n'- 32;
            Matriz[3][11] = 'i'- 32;
            Matriz[2][12] = 'd'- 32;
            Matriz[1][13] = 'o'- 32;
            Matriz[0][14] = 's'- 32;
        }

        if( strcmp(nivel3[7].Texto, Busca) == 0 )
        {
            //Reino Unido
            Matriz[3][4] = 'r'- 32;
            Matriz[3][5] = 'e'- 32;
            Matriz[3][6] = 'i'- 32;
            Matriz[3][7] = 'n'- 32;
            Matriz[3][8] = 'o'- 32;
            Matriz[3][9] = 'u'- 32;
            Matriz[3][10] = 'n'- 32;
            Matriz[3][11] = 'i'- 32;
            Matriz[3][12] = 'd'- 32;
            Matriz[3][13] = 'o'- 32;
        }
        if( strcmp(nivel3[2].Texto, Busca) == 0 )
        {
            //Espanha
            Matriz[0][9] = 'e'- 32;
            Matriz[0][8] = 's'- 32;
            Matriz[0][7] = 'p'- 32;
            Matriz[0][6] = 'a'- 32;
            Matriz[0][5] = 'n'- 32;
            Matriz[0][4] = 'h'- 32;
            Matriz[0][3] = 'a'- 32;
        }
    }
}
void Distribuicao()
{
    if(LevelSolo == 1 || LevelMult == 1)
    {
        LevelEndSolo = 5;
        LevelEndMult = 5;

        for(int k = 0; k < 15; k++)
        {
            for(int h = 0; h < 15; h++)
            {
                n = 'a' + (rand()%20);

                Matriz[k][h] = n;
            }
        }

        //Cansaço
        Matriz[1][1] = 'c';
        Matriz[2][2] = 'a';
        Matriz[3][3] = 'n';
        Matriz[4][4] = 's';
        Matriz[5][5] = 'a';
        Matriz[6][6] = 'c';
        Matriz[7][7] = 'o';

        //Diarreia
        Matriz[3][9] = 'd';
        Matriz[4][9] = 'i';
        Matriz[5][9] = 'a';
        Matriz[6][9] = 'r';
        Matriz[7][9] = 'r';
        Matriz[8][9] = 'e';
        Matriz[9][9] = 'i';
        Matriz[10][9] = 'a';

        //Dores
        Matriz[9][5] = 'd';
        Matriz[10][5] = 'o';
        Matriz[11][5] = 'r';
        Matriz[12][5] = 'e';
        Matriz[13][5] = 's';

        //Febre
        Matriz[10][10] = 'f';
        Matriz[11][10] = 'e';
        Matriz[12][10] = 'b';
        Matriz[13][10] = 'r';
        Matriz[14][10] = 'e';

        //Tosse
        Matriz[14][5] = 't';
        Matriz[14][6] = 'o';
        Matriz[14][7] = 's';
        Matriz[14][8] = 's';
        Matriz[14][9] = 'e';
    }

    if(LevelSolo == 2 || LevelMult == 2)
    {

        LevelEndSolo = 6;
        LevelEndMult = 6;

        for(int k = 0; k < 15; k++)
        {
            for(int h = 0; h < 15; h++)
            {
                n = 'a' + (rand()%20);

                Matriz[k][h] = n;
            }
        }

        //Contato
        Matriz[9][6] = 'c';
        Matriz[8][6] = 'o';
        Matriz[7][6] = 'n';
        Matriz[6][6] = 't';
        Matriz[5][6] = 'a';
        Matriz[4][6] = 't';
        Matriz[3][6] = 'o';

        //Saliva
        Matriz[2][1] = 's';
        Matriz[2][2] = 'a';
        Matriz[2][3] = 'l';
        Matriz[2][4] = 'i';
        Matriz[2][5] = 'v';
        Matriz[2][6] = 'a';

        //Espirro
        Matriz[14][8] = 'e';
        Matriz[13][7] = 's';
        Matriz[12][6] = 'p';
        Matriz[11][5] = 'i';
        Matriz[10][4] = 'r';
        Matriz[9][3] = 'r';
        Matriz[8][2] = 'o';

        //Tosse
        Matriz[14][10] = 't';
        Matriz[14][11] = 'o';
        Matriz[14][12] = 's';
        Matriz[14][13] = 's';
        Matriz[14][14] = 'e';

        //Catarro
        Matriz[14][0] = 'c';
        Matriz[13][1] = 'a';
        Matriz[12][2] = 't';
        Matriz[11][3] = 'a';
        Matriz[10][4] = 'r';
        Matriz[9][5] = 'r';
        Matriz[8][4] = '0';

        //Objetos
        Matriz[1][13] = 'o';
        Matriz[2][12] = 'b';
        Matriz[3][11] = 'j';
        Matriz[4][10] = 'e';
        Matriz[5][9] = 't';
        Matriz[6][8] = 'o';
        Matriz[7][7] = 's';
    }

    else if( LevelSolo == 3 || LevelMult == 3)
    {
        LevelEndSolo = 9;
        LevelEndMult = 9;

        for(int k = 0; k < 15; k++)
        {
            for(int h = 0; h < 15; h++)
            {
                n = 'a' + (rand()%20);

                Matriz[k][h] = n;
            }
        }

        //China
        Matriz[14][4] = 'c';
        Matriz[14][5] = 'h';
        Matriz[14][6] = 'i';
        Matriz[14][7] = 'n';
        Matriz[14][8] = 'a';

        //Alemanha
        Matriz[2][0] = 'a';
        Matriz[3][0] = 'l';
        Matriz[4][0] = 'e';
        Matriz[5][0] = 'm';
        Matriz[6][0] = 'a';
        Matriz[7][0] = 'n';
        Matriz[8][0] = 'h';
        Matriz[9][0] = 'a';

        //Italia
        Matriz[9][1] = 'i';
        Matriz[8][1] = 't';
        Matriz[7][1] = 'a';
        Matriz[6][1] = 'l';
        Matriz[5][1] = 'i';
        Matriz[4][1] = 'a';

        //Japão
        Matriz[8][10] = 'j';
        Matriz[9][11] = 'a';
        Matriz[10][12] = 'p';
        Matriz[11][13] = 'a';
        Matriz[12][14] = 'o';

        //Françã
        Matriz[1][3] = 'f';
        Matriz[1][4] = 'r';
        Matriz[1][5] = 'a';
        Matriz[1][6] = 'n';
        Matriz[1][7] = 'c';
        Matriz[1][8] = 'a';

        //India
        Matriz[9][1] = 'i';
        Matriz[8][2] = 'n';
        Matriz[7][3] = 'd';
        Matriz[6][4] = 'i';
        Matriz[5][5] = 'a';

        //Estados Unidos
        Matriz[12][2] = 'e';
        Matriz[11][3] = 's';
        Matriz[10][4] = 't';
        Matriz[9][5] = 'a';
        Matriz[8][6] = 'd';
        Matriz[7][7] = 'o';
        Matriz[6][8] = 's';
        Matriz[5][9] = 'u';
        Matriz[4][10] = 'n';
        Matriz[3][11] = 'i';
        Matriz[2][12] = 'd';
        Matriz[1][13] = 'o';
        Matriz[0][14] = 's';

        //Reino Unido
        Matriz[3][4] = 'r';
        Matriz[3][5] = 'e';
        Matriz[3][6] = 'i';
        Matriz[3][7] = 'n';
        Matriz[3][8] = 'o';
        Matriz[3][9] = 'u';
        Matriz[3][10] = 'n';
        Matriz[3][11] = 'i';
        Matriz[3][12] = 'd';
        Matriz[3][13] = 'o';

        //Espanha
        Matriz[0][9] = 'e';
        Matriz[0][8] = 's';
        Matriz[0][7] = 'p';
        Matriz[0][6] = 'a';
        Matriz[0][5] = 'n';
        Matriz[0][4] = 'h';
        Matriz[0][3] = 'a';
        
    }
}
void PontFinalSolo()
{
    //Mostra a pontuação de cada nivel jogado
    system("clear || cls");
    printf("\n==============================\n");
    printf("          Pontuação Final         ");
    printf("\n==============================\n");
    printf("              Nivel 1             ");
    printf("\nAcertos: %d   Erros: %d", AcertosSololevel1, ErrosSololevel1);
    printf("\n==============================\n");
    printf("              Nivel 2             ");
    printf("\nAcertos: %d   Erros: %d", AcertosSololevel2, ErrosSololevel2);
    printf("\n==============================\n");
    printf("              Nivel 3             ");
    printf("\nAcertos: %d   Erros: %d", AcertosSololevel3, ErrosSololevel3);
    printf("\n==============================\n");
    sleep(6);
    system("clear || cls");
    return main ();
    //Após o periodo de 6 segundos retorna ao menu principal
}
void complementoPontMult()
{
    //Pontuação final
        system("clear || cls");
        printf("\n==============================\n");
        printf("            Pontuação             ");
        printf("\n==============================\n");

        //Faz a comparação de quem ficou em 1° lugar e 2° lugar
        if( AcertosMult1 > AcertosMult2 )
        {
            printf("1° Lugar %s\n", NomeMult1);
            printf("Rodadas Jogadas: %d\n", TentativaMult);
            printf("Acertos: %d   Erros: %d\n", AcertosMult1, ErrosMult1);
            printf("\n");
            printf("2° Lugar %s\n", NomeMult2);
            printf("Rodadas Jogadas: %d\n", TentativaMult);
            printf("Acertos: %d   Erros: %d\n", AcertosMult2, ErrosMult2);
            printf("\n==============================\n");

        }

        else if( AcertosMult2 > AcertosMult1 )
        {
            printf("1° Lugar %s\n", NomeMult2);
            printf("Rodadas Jogadas: %d\n", TentativaMult);
            printf("Acertos: %d   Erros: %d\n", AcertosMult2, ErrosMult2);
            printf("\n");
            printf("2° Lugar %s\n", NomeMult1);
            printf("Rodadas Jogadas: %d\n", TentativaMult);
            printf("Acertos: %d   Erros: %d\n", AcertosMult1, ErrosMult1);
            printf("\n==============================\n");
        }

        //Caso tenha os mesmo pontos empate
        if( (AcertosMult1 == LevelEndMult) && (AcertosMult2 == LevelEndMult))
        {
            printf("Empate!!\n");
        }

        //Armazen os acertos e erros de cada nivel
        if( LevelMult == 1 )
        {
            //Passando os valores para variaveis auxiliares
            AcertosMult1level1 = AcertosMult1;
            ErrosMult1level1 = ErrosMult1;

            AcertosMult2level1 = AcertosMult2;
            ErrosMult2level1 = ErrosMult2;
        }

        else if( LevelMult == 2 )
        {
            //Passando os valores para variaveis auxiliares
            AcertosMult1level2 =(AcertosMult1*2)+AcertosMult1level1;
            ErrosMult1level2 = (ErrosMult1*2)+ErrosMult1level1;

            AcertosMult2level2 = (AcertosMult2*2)+AcertosMult2level1;
            ErrosMult2level2 = (ErrosMult2*2)+ErrosMult2level1;
        }

        else
        {
            //Passando os valores para variaveis auxiliares
            AcertosMult1level3 =(AcertosMult1*3)+AcertosMult1level2;
            ErrosMult1level3 =(ErrosMult1*3)+ErrosMult1level2;

            AcertosMult2level3 = (AcertosMult2*3)+AcertosMult2level2;
            ErrosMult2level3 = (ErrosMult2*3)+ErrosMult2level2;
        }

        //Pergunto se quer ir para o proximo nivel
        
        if ( LevelMult < 3 )
        {
        printf("Deseja ir Para o Proximo Nivel?\n\n1- SIM\n2- NÃO\n");
        printf("\nResposta: ");
        scanf("%d", &Proximo);

            //Se proximo for igual 1 passa para o proximo nivel, caso contrario retorna ao menu
            if( Proximo == 1 )
            {
                LevelMult++;

                //Zerando as Variaveis
                AcertosMult1 = 0;
                ErrosMult1 = 0;
                AcertosMult2 = 0;
                ErrosMult2 = 0;
                return Alternacao();
            }

            else
            {   
                Sair();
                return main();
            }


        }
        //Chama a função responsável por mostrar todos os pontos de cada nivel jogado
        else
        {
            PontFinal();
        }
}
void Reset()
{
    //Reseta Todas as Variaveis que foram alteradas
    LevelEndMult = 0;
    LevelEndSolo = 0;
    LevelMult = 1;
    LevelSolo = 1;
    AcertosSolo = 0;
    ErrosSolo = 0;
    AcertosMult1 = 0;
    AcertosMult2 = 0;
    ErrosMult1 = 0;
    ErrosMult2 = 0;
    AcertosSololevel1 = 0;
    AcertosSololevel2 = 0;
    AcertosSololevel3 = 0;
    ErrosSololevel1 = 0;
    ErrosSololevel2 = 0;
    ErrosSololevel3 = 0;
    AcertosMult1level1 = 0;
    AcertosMult1level2 = 0;
    AcertosMult1level3 = 0;
    AcertosMult2level1 = 0;
    AcertosMult2level2 = 0;
    AcertosMult2level3 = 0;
    TentativaSolo = 0;
    TentativaMult = 0;
}
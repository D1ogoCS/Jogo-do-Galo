#include<iostream>
#include <random>
using namespace std;

int opcao,a,b,c,d,e,f,g,h,w,verificarResultado=0,t=0,jogadas=9,contadorEspaco=0,escolherNumero,linha,coluna,naoEncontrouLinhaColuna=1,naoEncontrouDiagonais=1,aleatorio=0,verificar=0,novamente;
string array[3][3]={"1","2","3","4","5","6","7","8","9"},somaLinha,somaDiagSec,somaColuna,somaDiagPrin,sequencia,simbolo;
string arraySimular[3][3],jogador="Jogador",numeroString;

void mostrarJogo(){ //Mostra o Jogo a cada jogada, com as respetivas jogadas "X" ou "O"

    for (a = 0; a< 3; a++){
            for ( b= 0; b<3; b++){
       
            cout<<" "<<array[a][b]<<" ";
            if (b<3-1){
                cout << '|';
            }
        }
        if (a<3-1){
            cout << endl << "---+---+---" << endl;
        }
    }
    cout<<""<<endl;
    cout<<""<<endl;

}

void verificarResultados(){ //Faz as somas de todas as linhas e colunas dos respetives jogadores para se verificar se existe algum possivel vencedor, a cada jogada

    for (a = 0; a < 3; a++){
        for (b = 0; b<3; b++){
            somaLinha=somaLinha+array[a][b];
            somaColuna=somaColuna+array[b][a];
            
        }
        if (somaLinha=="XXX"||somaColuna=="XXX")
        {
            verificarResultado=1; //Atribui um valor a variavel para indicar qual a sequencia que ganhou
        }
        if (somaLinha=="OOO"||somaColuna=="OOO")
        {
            verificarResultado=2; //Atribui um valor a variavel para indicar qual a sequencia que ganhou
        }
            
        w=2;
        somaDiagPrin=somaDiagPrin+array[a][a];
        somaDiagSec=somaDiagSec+array[a][w-a];
        somaLinha="";
        somaColuna="";
    }

    if (somaDiagPrin=="XXX"||somaDiagSec=="XXX")
    {
        verificarResultado=1; //Atribui um valor a variavel para indicar qual a sequencia que ganhou
    }
    if (somaDiagPrin=="OOO"||somaDiagSec=="OOO")
    {
        verificarResultado=2; //Atribui um valor a variavel para indicar qual a sequencia que ganhou
    }
        
    somaDiagPrin="";
    somaDiagSec="";

}

void resultado(){ //Mostra na tela o respetivo vencedor, de acordo com o valor atribuido a variavel "verificarResultado", faz acabar o jogo e iguala as jogadas as zero

    if (verificarResultado==1){
        cout<<"O jogador 1 GANHOU!!!!!"<<endl;
        t=1; //Quando t=1 o jogo acaba
        jogadas=0;
    }
    if (verificarResultado==2){
        cout<<"O Jogador 2 GANHOU!!!!!"<<endl;
        t=1;
        jogadas=0;
    }
    if (jogadas==0&&verificarResultado==0){
        cout<<"Houve um empate!"<<endl;
        t=1;
    }

}

void escolha(){ //Escolher um numero inteiro, do jogo do galo entre 1 e 9

    cout<<"Escolha um numero:";
    cin>>escolherNumero;

    while (escolherNumero<1||escolherNumero>9){ //Ativa se o valor estiver fora de 1 e 9
        cout<<"O numero introduzido nao e valido!"<<endl;
        cout<<"Escolha um numero:";
        cin>>escolherNumero; 
    }

}

void verificaNumeroEscolhido() { //Apos escolher o numero onde jogar, como esta em inteiro e necessario saber qual a sua posicao

    for (a = 0; a < 3; a++){
        for (b = 0; b < 3; b++){
            contadorEspaco++; //Este contador faz indicar a posicao do numero escolhido
            if (escolherNumero==contadorEspaco){
                linha=a;
                coluna=b;
            }
        }
    }

}

void carregarArraySimular() { //Carrega a arraySimular com os valores da array principal

    for (e = 0; e < 3; e++){
        for (f = 0; f<3; f++){
            arraySimular[e][f]=array[e][f];
        }
    }

}

void simular(){ //Simula as possiveis vitorias do computador ou os sitios onde o computador possa jogar para bloquear o jogador, isso depende da variavel simbolo e sequencia

    if (arraySimular[a][b]!="X"&&arraySimular[a][b]!="O"){
        arraySimular[a][b]=simbolo; //Se o simbolo for "O" o computado simula onde possa ganhar, se for "X" simula onde bloquear o jogador

        for (c = 0; c < 3; c++){
            for (d = 0; d<3; d++){
                somaLinha=somaLinha+arraySimular[c][d];
                somaColuna=somaColuna+arraySimular[d][c];
                      
            }
            if (somaLinha==sequencia||somaColuna==sequencia){ //A sequncia pode ser "XXX" ou "OOO" dependendo do simbolo
                linha=a;
                coluna=b;
                naoEncontrouLinhaColuna=0; //Se o computador encontrar um combinacao seguida atribui valor 0 a esta variavel para indicar que encontrou uma sequencia, funciona como se fosse um true ou false, mas com inteiros(1 ou 0)
            }
                    
            w=2;
            somaDiagPrin=somaDiagPrin+arraySimular[c][c];
            somaDiagSec=somaDiagSec+arraySimular[c][w-c];
            somaLinha="";
            somaColuna="";
        }

        if (somaDiagPrin==sequencia||somaDiagSec==sequencia){
            linha=a;
            coluna=b;
            naoEncontrouDiagonais=0; 
        }

        somaDiagPrin="";
        somaDiagSec="";

        carregarArraySimular(); //Carrega a arraySimular com os valores da array principal cada vez que avança uma "casa" na arraySimular
    }

}

void jogarNovamente(){ //Quando o jogo acaba é necessario perguntar se quer jogar novamente
    cout<<""<<endl;
    cout<<"1-Sim\n2-Nao\nDeseja jogar novamente?";
    cin>>novamente;
    while (novamente<1||novamente>2){
        cout<<""<<endl;
        cout<<"Essa opcao nao e valida!"<<endl;
        cout<<""<<endl;
        cout<<"1-Sim\n2-Nao\nDeseja jogar novamente?";
        cin>>novamente;
    }

    for (a = 0; a < 3; a++){
        for (b = 0; b < 3; b++){
            h++;
            numeroString=numeroString+to_string(h);
            array[a][b]=numeroString; //Apaga a array e volta a carrega-la com numeros de 1 a 9
            numeroString="";
        }
    }

    if (novamente==1){ //Se o jogador jogar novamente é necessario voltar a dar reset as variaveis principais 

        jogadas=9; 
        t=0;
        verificarResultado=0;
        h=0;
        cout<<""<<endl;
        mostrarJogo();
    }

}

int main(){

    cout<<"Bem vindo ao jogo do galo!"<<endl;

    while (opcao!=1){
        
        jogadas=9; 
        t=0;
        verificarResultado=0;
        h=0;

        cout<<"1-Sair\n2-Jogar contra o PC\n3-Jogar com amigo"<<endl;
        cout<<"O que deseja:";
        cin>>opcao;
        cout<<""<<endl;

        while (opcao<1||opcao>3){
            cout<<""<<endl;
            cout<<"Opcao invalida!"<<endl;
            cout<<""<<endl;
            cout<<"1-Sair\n2-Jogar contra o PC\n3-Jogar com amigo"<<endl;
            cout<<"O que deseja:";
            cin>>opcao;
            cout<<""<<endl;
        }


        switch (opcao){
        case (2):

            cout<<"O jogador 1 joga com o X"<<endl;
            cout<<"O jogador 2 (Computador) joga com o O"<<endl;
            cout<<""<<endl;

            mostrarJogo();

            while (t==0){

                //PARTE DO JOGADOR HUMANO
                
                escolha();

                verificaNumeroEscolhido();
                contadorEspaco=0;

                while (array[linha][coluna]=="X"||array[linha][coluna]=="O"){
                    cout<<"Esse numero nao e valido porque ja esta ocupado."<<endl;
                    escolha();
                    verificaNumeroEscolhido();
                    contadorEspaco=0;
                }

                contadorEspaco=0;

                array[linha][coluna]="X";

                jogadas--;

                verificarResultados();
                cout<<""<<endl;
                mostrarJogo(); 

                resultado();

                //PARTE DO COMPUTADOR

                carregarArraySimular(); 

                if (t==0){
                    cout<<"O jogador 2 (Computador) ja jogou!"<<endl;
                    for (a = 0; a< 3; a++){
                        for (b = 0; b < 3; b++){
                            simbolo="O";
                            sequencia="OOO";
                            simular();
                            
                            if (naoEncontrouDiagonais==1&&naoEncontrouLinhaColuna==1){
                                carregarArraySimular();
                                simbolo="X";
                                sequencia="XXX";
                                simular();
                            
                            }
                        }
                    }

                    if (naoEncontrouDiagonais==1&&naoEncontrouLinhaColuna==1){
                
                        if (jogadas==8){ //Na primeira jogada do computador se o espaço 5 estiver livre ele joga no 5 senao joga no espaco 9
                            if (array[1][1]=="5"){
                                linha=1;
                                coluna=1;
                            }
                            if (array[1][1]!="5"){
                                linha=2;
                                coluna=2;
                                verificar=1;
                            }
                        }

                        if (jogadas!=8&&jogadas!=0){
                            
                            if (verificar==1&&jogadas==6){
                
                                linha=2;
                                coluna=0;  
                                    
                                verificar=0;
                
                            }
                            else{ //Serve para quando o computador nao encontra nenhuma sequencia e necessita de escolher um espaco aleatoriamente 
                            
                                aleatorio=rand() % 9+1;
                                escolherNumero=aleatorio;

                                verificaNumeroEscolhido();
                                contadorEspaco=0;

                                while (array[linha][coluna]=="X"||array[linha][coluna]=="O"){

                                    contadorEspaco=0;

                                    aleatorio=rand() % 9+1;
                                    escolherNumero=aleatorio;

                                    verificaNumeroEscolhido();
                                    contadorEspaco=0;
                                }
                            }
                        }
                    }

                    naoEncontrouDiagonais=1;
                    naoEncontrouLinhaColuna=1;

                    array[linha][coluna]="O";
                    jogadas--;

                    cout<<""<<endl;
                    mostrarJogo();
                    verificarResultados();
                    resultado();
                    
                }

                if (t==1){
                    jogarNovamente();
                }
            }
            
            break;

        case (3):

            cout<<"O jogador 1 joga com o X\nO jogador 2 joga com o O"<<endl;
            cout<<""<<endl;

            mostrarJogo();

            while (t==0){
                
                for (g = 0; g < 2; g++){
                    if (jogadas>0){
                        jogador=jogador+to_string(g);

                        cout<<"Jogador "<<g+1<<" e a sua vez de jogar!"<<endl;;
                        escolha();

                        verificaNumeroEscolhido();
                        contadorEspaco=0;

                        while (array[linha][coluna]=="X"||array[linha][coluna]=="O"){
                            cout<<"Esse numero nao e valido porque ja esta ocupado."<<endl;
                            escolha();
                            verificaNumeroEscolhido();
                            contadorEspaco=0;
                        }

                        if (jogador=="Jogador0"){

                            array[linha][coluna]="X";
                            jogadas--;
                        }
                        else{

                            array[linha][coluna]="O";
                            jogadas--;

                        }

                        jogador="Jogador";

                        cout<<""<<endl;
                        mostrarJogo();

                        verificarResultados();
                        resultado();

                        if (t==1){
                            jogarNovamente(); //Se jogar novamente, no inicio os jogadores alteram, independentemente do resultado ou seja se comecou o Jogador 1 agora comeca o Jogador 2
                        }
                    }
                }
            }

            break;

        default:
            break;
        }
    }
}

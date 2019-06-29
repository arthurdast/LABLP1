//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//END INCLUDES

//STRUCTS
typedef struct casa
{
    int pavimentos;
    int quartos;
}TP_CASA;

typedef struct apartamento
{
    int quartos;
    char posicao[50];
    int andar;
    int vagas;
    float vDOcondominio;
}TP_APARTAMENTO;

typedef struct imovel
{
    int id;
    char anucio[254];
    char rua[50];
    char bairro[50];
    char cidade[50];
    char tipo[1];  //Aluguel(A) ou venda (V)
    int numero;
    int cep;
    int valor;
    int area;
    TP_CASA str_casa;
    TP_APARTAMENTO str_apartamento;
}TP_IMOVEL;
//END STRUCTS


//FUNCTIONS
void inicilizaImoveis(TP_IMOVEL *imoveis)
{
    for(int count = 0; count<150 ;count++){
        imoveis[count].valor = 0;
        imoveis[count].str_apartamento.quartos = 0;
        imoveis[count].str_casa.quartos = 0;
    }
}
int espacoLista(TP_IMOVEL *imoveis)
{
    for(int count = 0; count<150 ;count++){
        if(imoveis[count].valor== 0){
            return count;
        }
    }
    return 150;
}
int menu(){
    float r = 0;
    printf(" Porfavor escolha qual operacao deseja.\n \n");
    printf("             (1.Cadastro) (2.Editar)   (3.Remover) \n");
    printf("   Consulta: (4.Todos)    (5.Vendendo) (6.Alugando) \n");
    printf("  Busca por: (7.Titulo)   (8.Bairro)   (9.Valor)  \n");
    printf("     (10.Salvar em arquivo)      (11.Ler em arquivo)\n");
    printf("                                            (0.Sair)\n");
    do{
    printf("Digite o numero da opcao desejada:\n");
    fflush(stdin);
    scanf("%f",&r);
    }while(r<=0 && r>=11 );
    return r;
}
void cadastro(TP_IMOVEL *imoveis, int espaco)
{
    //variavel cadastro
    int tImovel= 0;
    char anucio[254];
    char rua[50];
    char bairro[50];
    char cidade[50];
    char tipo[1];  //Aluguel(A) ou venda (V)
    int numero=0;
    int cep=0;
    int valor=0;
    int area=0;
    //casa
    int pavimentos=0;
    int quartosC=0;
    //apartamento
    int quartosA=0;
    char posicao[50];
    int andar=0;
    int vagas=0;
    float vDOcondominio=0;
    //end variavel cadastro

    if (espaco == 150){
        printf("SEM ESPAÇO PARA CADASTRAMENTO DE NOVO IMOVEL \n");
        return;
    }else{
        printf("\nVamos inicia o cadastramento.\n");
        do{
            printf("Digite qual tipo de imovel.\n");
            printf("(1. Terreno)  (2.Casa)  (3.Apartamento) (0.Sair)\n");
            fflush(stdin);
            scanf("%d",&tImovel);
            if(tImovel==0)break; //Sai do cadastramento
        }while(!(tImovel== 1 ||tImovel== 2 ||tImovel== 3));
        //Terreno
        printf("Digite o anucio do imovel.(Max 250 Letras)  \n");
        fflush(stdin);
        gets(anucio);
        printf("Digite a Rua do imovel.(Max 50 Letras)  \n");
        fflush(stdin);
        gets(rua);
        printf("Digite a bairro do imovel.(Max 50 Letras)  \n");
        fflush(stdin);
        gets(bairro);
        printf("Digite a cidade do imovel.(Max 50 Letras)  \n");
        fflush(stdin);
        gets(cidade);
        printf("Digite o numero do imovel.\n");
        fflush(stdin);
        scanf("%d",&numero);
        printf("Digite o CEP do imovel.\n");
        fflush(stdin);
        scanf("%d",&cep);
        printf("Digite o area do imovel.\n");
        fflush(stdin);
        scanf("%d",&area);
        printf("Digite o valor do imovel.\n");
        fflush(stdin);
        scanf("%d",&valor);
        printf("Digite o tipo do imovel Aluguel(A) ou venda (V). (1 Letra)\n");
        fflush(stdin);
        gets(tipo);
        //cria o imovel
        imoveis[espaco].id  = espaco+1;
        strcpy(imoveis[espaco].anucio,anucio);
        strcpy(imoveis[espaco].rua,rua);
        strcpy(imoveis[espaco].bairro,bairro);
        strcpy(imoveis[espaco].cidade,cidade);
        strcpy(imoveis[espaco].tipo,tipo);
        imoveis[espaco].numero  =numero;
        imoveis[espaco].cep     =cep;
        imoveis[espaco].valor   =valor;
        imoveis[espaco].area    =area;


        //Casa
        if(tImovel==2){
            printf("Digite a quantidade de pavimentos do casa.\n");
            fflush(stdin);
            scanf("%d",&pavimentos);
            printf("Digite a quantidade de quartos do casa.\n");
            fflush(stdin);
            scanf("%d",&quartosC);

            imoveis[espaco].str_casa.pavimentos=pavimentos;
            imoveis[espaco].str_casa.quartos   =quartosC;

        }
        //Apartamento
        if(tImovel==3){
            printf("Digite a quantidade de quartos do apartamento.\n");
            fflush(stdin);
            scanf("%d",&quartosA);
            printf("Digite o andar do apartamento.\n");
            fflush(stdin);
            scanf("%d",&andar);
            printf("Digite a quantidade de vaga de garagem do apartamento.\n");
            fflush(stdin);
            scanf("%d",&vagas);
            printf("Digite o valor do condominio do apartamento.\n");
            fflush(stdin);
            scanf("%f",&vDOcondominio);
            printf("Digite a posicao do apartamento.(ex: nascente sul, nascente norte)\n");
            fflush(stdin);
            gets(posicao);

            imoveis[espaco].str_apartamento.quartos =quartosA;
            imoveis[espaco].str_apartamento.andar   =andar;
            imoveis[espaco].str_apartamento.vagas   =vagas;
            imoveis[espaco].str_apartamento.vDOcondominio=vDOcondominio;
            strcpy(imoveis[espaco].str_apartamento.posicao,posicao);
        }


    }
}
void editar(TP_IMOVEL *imoveis){
    printf("Qual id deseja editar?\n");
    int id;
    fflush(stdin);
    scanf("%d",&id);
    cadastro(imoveis,id);

}
void remover(TP_IMOVEL *imoveis)
{
    printf("Qual id deseja remover?\n");
    int id;
    fflush(stdin);
    scanf("%d",&id);

    for(int count = 0; count<150 ;count++){
        if(imoveis[count].id == id){
            imoveis[count].valor = 0;
            printf("\n id %d remover com sucesso\n",id);
        }
    }
}
void consultaTodos(TP_IMOVEL *imoveis){
    for(int count = 0; count<150 ;count++){
        if(imoveis[count].valor!= 0){
            //Terreno
            printf("\nId:%d Titulo: %s\n",imoveis[count].id,imoveis[count].anucio);
            printf("Rua: %s Numero: %d Bairro: %s Cidade: %s CEP: %d\n",imoveis[count].rua,imoveis[count].numero,imoveis[count].bairro,imoveis[count].cidade,imoveis[count].cep);
            printf("Tipo: %s Area: %d Valor:%d\n",imoveis[count].tipo,imoveis[count].area,imoveis[count].valor);
            //Apartamento
            if(imoveis[count].str_apartamento.quartos == 0){
                printf("Apartamento-> Andar: %d Posicao: %s Quatos: %d \n        Valor do condominio: %f Vagas de garagem:%d \n",imoveis[count].str_apartamento.andar,imoveis[count].str_apartamento.posicao,imoveis[count].str_apartamento.quartos,imoveis[count].str_apartamento.vDOcondominio,imoveis[count].str_apartamento.vagas);
            }
            //Casa
            if(imoveis[count].str_casa.quartos == 0){
                printf("Casa-> Pavimento: %d Quartos:%d\n",imoveis[count].str_casa.pavimentos,imoveis[count].str_casa.quartos);
            }
            printf("\n---------------------------------------------------------------\n");
        }
    }
}
void consultaVendendo(TP_IMOVEL *imoveis){
    for(int count = 0; count<150 ;count++){
        if(imoveis[count].valor!= 0 && strcmp(imoveis[count].tipo,"V") == 0  ){
            //Terreno
            printf("\nId:%d Titulo: %s\n",imoveis[count].id,imoveis[count].anucio);
            printf("Rua: %s Numero: %d Bairro: %s Cidade: %s CEP: %d\n",imoveis[count].rua,imoveis[count].numero,imoveis[count].bairro,imoveis[count].cidade,imoveis[count].cep);
            printf("Tipo: %s Area: %d Valor:%d\n",imoveis[count].tipo,imoveis[count].area,imoveis[count].valor);
            //Apartamento
            if(imoveis[count].str_apartamento.quartos == 0){
                printf("Apartamento-> Andar: %d Posicao: %s Quatos: %d \n        Valor do condominio: %f Vagas de garagem:%d \n",imoveis[count].str_apartamento.andar,imoveis[count].str_apartamento.posicao,imoveis[count].str_apartamento.quartos,imoveis[count].str_apartamento.vDOcondominio,imoveis[count].str_apartamento.vagas);
            }
            //Casa
            if(imoveis[count].str_casa.quartos == 0){
                printf("Casa-> Pavimento: %d Quartos:%d\n",imoveis[count].str_casa.pavimentos,imoveis[count].str_casa.quartos);
            }
            printf("\n---------------------------------------------------------------\n");
        }
    }
}
void consultaAlugando(TP_IMOVEL *imoveis){
    for(int count = 0; count<150 ;count++){
        if(imoveis[count].valor!= 0 && strcmp(imoveis[count].tipo,"A") == 0  ){
            //Terreno
            printf("\nId:%d Titulo: %s\n",imoveis[count].id,imoveis[count].anucio);
            printf("Rua: %s Numero: %d Bairro: %s Cidade: %s CEP: %d\n",imoveis[count].rua,imoveis[count].numero,imoveis[count].bairro,imoveis[count].cidade,imoveis[count].cep);
            printf("Tipo: %s Area: %d Valor:%d\n",imoveis[count].tipo,imoveis[count].area,imoveis[count].valor);
            //Apartamento
            if(imoveis[count].str_apartamento.quartos == 0){
                printf("Apartamento-> Andar: %d Posicao: %s Quatos: %d \n        Valor do condominio: %f Vagas de garagem:%d \n",imoveis[count].str_apartamento.andar,imoveis[count].str_apartamento.posicao,imoveis[count].str_apartamento.quartos,imoveis[count].str_apartamento.vDOcondominio,imoveis[count].str_apartamento.vagas);
            }
            //Casa
            if(imoveis[count].str_casa.quartos == 0){
                printf("Casa-> Pavimento: %d Quartos:%d\n",imoveis[count].str_casa.pavimentos,imoveis[count].str_casa.quartos);
            }
            printf("\n---------------------------------------------------------------\n");
        }
    }
}
void buscarTitulo(TP_IMOVEL *imoveis){
    char tituloB[254];
    printf("Qual Titulo deseja buscar?");
    fflush(stdin);
    gets(tituloB);

    for(int count = 0; count<150 ;count++){
        if(imoveis[count].valor!= 0 && strcmp(imoveis[count].anucio,tituloB) == 0  ){
            //Terreno
            printf("\nId:%d Titulo: %s\n",imoveis[count].id,imoveis[count].anucio);
            printf("Rua: %s Numero: %d Bairro: %s Cidade: %s CEP: %d\n",imoveis[count].rua,imoveis[count].numero,imoveis[count].bairro,imoveis[count].cidade,imoveis[count].cep);
            printf("Tipo: %s Area: %d Valor:%d\n",imoveis[count].tipo,imoveis[count].area,imoveis[count].valor);
            //Apartamento
            if(imoveis[count].str_apartamento.quartos == 0){
                printf("Apartamento-> Andar: %d Posicao: %s Quatos: %d \n        Valor do condominio: %f Vagas de garagem:%d \n",imoveis[count].str_apartamento.andar,imoveis[count].str_apartamento.posicao,imoveis[count].str_apartamento.quartos,imoveis[count].str_apartamento.vDOcondominio,imoveis[count].str_apartamento.vagas);
            }
            //Casa
            if(imoveis[count].str_casa.quartos == 0){
                printf("Casa-> Pavimento: %d Quartos:%d\n",imoveis[count].str_casa.pavimentos,imoveis[count].str_casa.quartos);
            }
            printf("\n---------------------------------------------------------------\n");
        }
    }
}
void buscarBairro(TP_IMOVEL *imoveis){
    char bairroB[50];
    printf("Qual o Bairro deseja buscar?");
    fflush(stdin);
    gets(bairroB);
    for(int count = 0; count<150 ;count++){
        if(imoveis[count].valor!= 0 && strcmp(imoveis[count].bairro,bairroB) == 0  ){
            //Terreno
            printf("\nId:%d Titulo: %s\n",imoveis[count].id,imoveis[count].anucio);
            printf("Rua: %s Numero: %d Bairro: %s Cidade: %s CEP: %d\n",imoveis[count].rua,imoveis[count].numero,imoveis[count].bairro,imoveis[count].cidade,imoveis[count].cep);
            printf("Tipo: %s Area: %d Valor:%d\n",imoveis[count].tipo,imoveis[count].area,imoveis[count].valor);
            //Apartamento
            if(imoveis[count].str_apartamento.quartos == 0){
                printf("Apartamento-> Andar: %d Posicao: %s Quatos: %d \n        Valor do condominio: %f Vagas de garagem:%d \n",imoveis[count].str_apartamento.andar,imoveis[count].str_apartamento.posicao,imoveis[count].str_apartamento.quartos,imoveis[count].str_apartamento.vDOcondominio,imoveis[count].str_apartamento.vagas);
            }
            //Casa
            if(imoveis[count].str_casa.quartos == 0){
                printf("Casa-> Pavimento: %d Quartos:%d\n",imoveis[count].str_casa.pavimentos,imoveis[count].str_casa.quartos);
            }
            printf("\n---------------------------------------------------------------\n");
        }
    }
}
void buscarValor(TP_IMOVEL *imoveis){
    float valorD;
    printf("Acima de qual valor deseja buscar?");
    fflush(stdin);
    scanf("%f",&valorD);
    for(int count = 0; count<150 ;count++){
        if(imoveis[count].valor>= valorD  ){
            //Terreno
            printf("\nId:%d Titulo: %s\n",imoveis[count].id,imoveis[count].anucio);
            printf("Rua: %s Numero: %d Bairro: %s Cidade: %s CEP: %d\n",imoveis[count].rua,imoveis[count].numero,imoveis[count].bairro,imoveis[count].cidade,imoveis[count].cep);
            printf("Tipo: %s Area: %d Valor:%d\n",imoveis[count].tipo,imoveis[count].area,imoveis[count].valor);
            //Apartamento
            if(imoveis[count].str_apartamento.quartos == 0){
                printf("Apartamento-> Andar: %d Posicao: %s Quatos: %d \n        Valor do condominio: %f Vagas de garagem:%d \n",imoveis[count].str_apartamento.andar,imoveis[count].str_apartamento.posicao,imoveis[count].str_apartamento.quartos,imoveis[count].str_apartamento.vDOcondominio,imoveis[count].str_apartamento.vagas);
            }
            //Casa
            if(imoveis[count].str_casa.quartos == 0){
                printf("Casa-> Pavimento: %d Quartos:%d\n",imoveis[count].str_casa.pavimentos,imoveis[count].str_casa.quartos);
            }
            printf("\n---------------------------------------------------------------\n");
        }
    }
}
void salvarLista(TP_IMOVEL *imoveis)
{
    FILE *imoveisFile;
    imoveisFile= fopen("imoveisFile.txt","w");
    fwrite(imoveis,sizeof(TP_IMOVEL),150,imoveisFile);
    fclose(imoveisFile);
}

void lerLista()
{
    FILE *imoveisFile;
    TP_IMOVEL imoveis[150];
    inicilizaImoveis(imoveis);
    imoveisFile= fopen("imoveisFile.txt","r");
    if (imoveisFile == NULL)
    {
        fprintf(stderr, "\nErro ao abri o arquivo.\n");

    }else{
    fread(&imoveis,sizeof(TP_IMOVEL),150,imoveisFile);
    fclose(imoveisFile);
    consultaTodos(imoveis);

    }
}


//END FUNCTIONS

// MAIN
int main()
{
    //VARIABLES
    TP_IMOVEL imoveis[150];
    //END VARIABLES
    inicilizaImoveis(imoveis); //Lista de struct

    while(true)//Loop do menu
    {
        switch (menu())
        {
            case 0:
                printf("0c");
                return 0;
            case 1:
                printf("1c");
                cadastro(imoveis,espacoLista(imoveis));
                break;
            case 2:
                printf("2c");
                editar(imoveis);
                break;
            case 3:
                printf("3c");
                remover(imoveis);
                break;
            case 4:
                printf("4c");
                consultaTodos(imoveis);
                break;
            case 5:
                printf("5c");
                consultaVendendo(imoveis);
                break;
            case 6:
                printf("6c");
                consultaAlugando(imoveis);
                break;
            case 7:
                printf("7c");
                buscarTitulo(imoveis);
                break;
            case 8:
                printf("8c");
                buscarBairro(imoveis);
                break;
            case 9:
                printf("9c");
                buscarValor(imoveis);
                break;
            case 10:
                printf("10c");
                salvarLista(imoveis);
                break;
            case 11:
                printf("11c");
                lerLista();
                break;
            default:
                printf("Operacao invalida");
        }
    system("PAUSE");
    system("cls"); //limpa a tela
    }//END LOOP MENU
    return 0;
}
//END MAIN

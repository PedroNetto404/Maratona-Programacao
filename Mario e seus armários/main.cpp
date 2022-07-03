#include <iostream> 
using namespace std; 
int Calc_MaxSet(int ListaArmarios[10*5], int ); 
void Calc_BestMov(int ListaArmarios[10*5], int lastPos, int *IndexOrigem, int *IndexDestino); 
int main()
{   
    int qntRequerida, qntFreeSpace;
    int IndexOrigem, IndexDestino; 
    int indexEmpty, maxSet; 
    int ListaArmarios[10*5] = {}; 
    int contadorDeMovimentos = 0; 

    cin >> qntRequerida >> qntFreeSpace; 


    for (int i = 0; i < qntFreeSpace; i++)  // Monta a representação da lista de armários
    {
        cin >> indexEmpty;
        ListaArmarios[indexEmpty - 1] = 1; 
    }

    maxSet = Calc_MaxSet(ListaArmarios, indexEmpty); //Calcula primeiro maior subconjunto de espaços vazios

    while (maxSet < qntRequerida)
    {
        Calc_BestMov(ListaArmarios, indexEmpty, &IndexOrigem, &IndexDestino); 

        ListaArmarios[IndexOrigem]  = 0;
        ListaArmarios[IndexDestino] = 1;

        maxSet = Calc_MaxSet(ListaArmarios, indexEmpty);

        contadorDeMovimentos++;
    }

    cout << contadorDeMovimentos; 
    
    return 0; 
}
void Calc_BestMov(int ListaArmarios[10*5], int lastPos, int *IndexOrigem, int *IndexDestino)
{
    int valorJogada; 
    int maiorValorJogada;

    maiorValorJogada = Calc_MaxSet(ListaArmarios, lastPos);

    for(int i = 0; i <= lastPos; i++)
    {
        if(ListaArmarios[i] == 1)
        {
            for(int j = 0; j < lastPos; j++)
            {
                if(ListaArmarios[j] == 0)
                {
                    ListaArmarios[j] = 1; 
                    ListaArmarios[i] = 0;
                    
                    valorJogada = Calc_MaxSet(ListaArmarios, lastPos);

                    if(valorJogada > maiorValorJogada)
                    {
                        maiorValorJogada = valorJogada; 
                        *IndexOrigem = i; 
                        *IndexDestino = j;
                    }
                
                    ListaArmarios[j] = 0;
                    ListaArmarios[i] = 1;
                    
                }
            }
        }
    }
}
int Calc_MaxSet(int ListaArmarios[10*5], int lastPos)
{
    int maxSet = 0; 
    int count_MaxSet = 0;

    for(int i = 0; i <= lastPos; i++)
    {
        if(ListaArmarios[i] == 1)
        {
            count_MaxSet++;
        }
        else
        {
            if(count_MaxSet > maxSet)
            {
                maxSet = count_MaxSet; 
            }
            count_MaxSet = 0; 
        }
    }

    return maxSet; 
}
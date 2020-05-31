# Simulador-AFND
Simulador de Automatos finitos não deterministicos.

# Instruções de Compilação
Linux: Use o comando make dentro do diretório src, o programa executavel estará no diretório acima de src (../src)

# Arquivo de entrada

Linha - Descricao

1: alfabeto  
2: quantidade de estados  
3: quantidade de estados finais  
4: numero de transicoes N  
5 até N:  
  Em seguida deve-se digitar as transições no formato X S Y onde X e Y são estados e S pertence ao alfabeto. A notacao indica que       ao receber o simbolo S ocorre uma transicao de X para Y, serao lidas N transições sendo N o numero de transições especificado na linha 4.  
N+1: número de palavras P a serem analisadas pelo automato descrito acima  
N+2 até P: palavras a serem analisadas (uma por linha)  



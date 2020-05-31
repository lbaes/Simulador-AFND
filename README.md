# Simulador-AFND
Simulador de autômato finitos não deterministicos.

# Compilação
Linux: Use o comando make dentro do diretório src, o programa executavel estará no diretório acima de src (../src)

# Arquivo de entrada

Linha - Descrição

1: alfabeto  
2: quantidade de estados  
3: quantidade de estados finais  
4: número de transições N  
5 até N:  
  Em seguida deve-se digitar as transições no formato X S Y onde X e Y são estados(0 até quatidade de estados -1) e S pertence ao alfabeto. A notação indica que ao receber o simbolo S ocorre uma transição do estado X para o estado Y, serão lidas N transições sendo N o número de transições especificado na linha 4.  
N+1: número de palavras P a serem analisadas pelo autômato descrito acima  
N+2 até P: palavras a serem analisadas (uma por linha)  



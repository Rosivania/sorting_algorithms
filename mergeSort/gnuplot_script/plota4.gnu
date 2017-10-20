# ----------------------------------------------------------
# Arquivo de comandos GnuPlot para a plotagem da curva de 
# Complexidade de Tempo do Algoritmo MergeSort 
#
# Este programa GnuPlot seta uma janela grafica e le varios
# arquivos de dados.
# ----------------------------------------------------------
set title "Tempo de Execução - Merge Sort"
#
#Seta tamanho da janela automaticamente de acordo com os dados
set autoscale

set style data linespoints


set xlabel "Tamanho do Vetor"
set ylabel "Tempo de Execução"
#
#Seta posicao em coordenadas dos dados, onde vao aparecer os titulos
#Isto voce DEVE adaptar aos seus dados
set key default
#
#Seta grade
set grid

plot \
	"reports/Merge-sort-rand.dat" title "Randomicos" w linespoints,\
        "reports/Merge-sort-ord.dat" title "Ordenados" w linespoints, \
        "reports/Merge-sort-inv.dat" title "Invertidos" w linespoints
	
	
#
# Para que voce possa chamar o gnuplot diretamente de dentro de seu 
# programa em C usando o comando system(). Se voce nao colocar uma
# pausa no final de seu plot, a janela fecha imediatamente apos 
# ter sido desenhada.
pause -1 "Tecle enter para sair..."

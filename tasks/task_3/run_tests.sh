# Executar ./run_tests.sh <nome_executavel> <intervalo de tempo (em segundos)>
# Exemplo: ./run_tests.sh main 2
for input in ../testes/*.in; do 
	answer=${input%.in}.out
	output=$(basename -- $input .in).out
	echo "Executando para a entrada $input e gerando a saída $output..."
	./$1 < $input > $output
	echo "Comparando os arquivos $answer e $output..."
	diff -q "$answer" "$output" > /dev/null
    ret=$?
    if [[ $ret -eq 0 ]]; then
        echo "Teste CERTO:"
    else
        echo "Teste ERRADO:"
    fi
	diff --report-identical-files "$answer" "$output"
	echo ""

	sleep $2
done

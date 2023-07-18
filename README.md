# Campeonato de Futebol

Este é um programa em C desenvolvido como parte de um exercício programa da faculdade. O programa simula um campeonato de futebol entre vários times, utilizando os dados de pontos ganhos, gols marcados, gols sofridos, saldo de gols, vitórias e gol average de cada time.

## Funcionalidades

O programa possui as seguintes funcionalidades:

1. **Gerar tabela de resultados:** O usuário pode inserir os resultados de m jogos através do teclado, e o programa gera uma tabela com os resultados dos jogos. Cada resultado é representado na forma `(t1, t2, n1, n2)`, onde `t1` e `t2` são os nomes dos times e `n1` e `n2` são os números de gols marcados por cada time no jogo.

   Exemplo: `(Corinthians, Chelsea, 1, 0)`, que representa a vitória do Corinthians por 1 a 0 sobre o Chelsea, conquistando o bicampeonato mundial.

2. **Gerar tabela completa de dados:** Utilizando a tabela de resultados gerada anteriormente, o programa gera uma tabela completa com todos os dados (pontos ganhos, gols marcados, gols sofridos, saldo de gols, vitórias e gol average) de cada time.

3. **Imprimir classificação dos times:** Com base nos dados da tabela completa, o programa gera e imprime a classificação dos times no campeonato, ordenando-os pelo número de pontos ganhos (PontosGanhos) e, em caso de empate, pelo saldo de gols (SaldoDeGols).

4. **Buscar informações de um time:** O programa permite buscar informações de um time específico, fornecendo o nome do time como entrada. A função retorna as informações associadas a esse time, como pontos ganhos, gols marcados, gols sofridos, saldo de gols, vitórias e gol average.

5. **Salva a classificação dos times em um arquivo DAT:** O programa salva a classificação dos times do campeonato, em ordem decrescente, em um arquivo.dat com todas as informações de cada time (pontos ganhos, gols marcados, gols sofridos, saldo de gols, vitórias e gol average).

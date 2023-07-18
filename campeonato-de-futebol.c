/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2023                          **/
/**   Turma 02 - Prof. Marcos Lordello Chaim                        **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                    **/
/**                                                                 **/
/**   Vitória Moreira Bentes                      14612030          **/
/**                                                                 **/
/**   21/07/2023                                                    **/
/**                                                                 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NumeroMaxTimes 20
#define NumeroMaxRodadas 38
#define NumeroMaxJogos NumeroMaxTimes * NumeroMaxRodadas

typedef struct auxtime {
  int PontosGanhos;
  int GolsMarcados;
  int GolsSofridos;
  int SaldoDeGols;
  int Vitorias;
  int Empates;
  int Derrotas;
  float GolAverage;
  char nome[31];
} time;

typedef struct auxjogo {
  char local[30];
  char visitante[30];
  int golslocal;
  int golsvisitante;
} jogo;

void lenometime(char * s) {
  int i;
  s[0] = '\0';
  char c;
  c = getchar();
  for(i = 0; c != ',' && i < 30;++i)
    {
      // if(c == '\n')
      //   continue;
      s[i] = c;
      c = getchar();
    }
  s[i] = '\0';
  //printf("%s\n",s);
}

// Ordena por Pontos
void ordenaPontos(time * timescampeonato, int notimes){
  // Adicione seu código para ordenar em ordem decrescente de pontos ganhos
  time auxiliar;
  for (int i = 1; i < notimes; i++){
    for(int j = 0; j < notimes - 1; j++){
      if(timescampeonato[j].PontosGanhos < timescampeonato[j + 1].PontosGanhos){
        auxiliar = timescampeonato[j];
        timescampeonato[j]     = timescampeonato[j + 1];
        timescampeonato[j + 1] = auxiliar;

      }else if (timescampeonato[j].PontosGanhos == timescampeonato[j + 1].PontosGanhos) {
        if (timescampeonato[j].SaldoDeGols < timescampeonato[j + 1].SaldoDeGols) {
          auxiliar = timescampeonato[j];
          timescampeonato[j] = timescampeonato[j + 1];
          timescampeonato[j + 1] = auxiliar;
        }
    }
  }
}
}
// Ordena por saldo de gols
void ordenaSaldoGols(time * timescampeonato, int notimes){
  // Adicione seu código para ordenar em ordem decrescente de saldo de gols
  time auxiliar;
  for (int i = 1; i < notimes; i++){
    for(int j = 0; j < notimes - 1; j++){
      if(timescampeonato[j].SaldoDeGols < timescampeonato[j + 1].SaldoDeGols){
        auxiliar = timescampeonato[j];
        timescampeonato[j]     = timescampeonato[j + 1];
        timescampeonato[j + 1] = auxiliar;

      }
    }
  }
}


// Encontra se o time já está no arranjo de times do campeonato
int encontratime(time *timescampeonato, char* nome, int notimes) {
  // Retorna a posição do arranjo times de campeonato
  // Adicione seu código
  for(int i = 0; i < notimes; i++){
    if(strcmp(timescampeonato[i].nome, nome) == 0){
        return i;
      }
  }
  return -1; // retorna -1 se o time com o nome "nome" não existe
}

// Cria a lista de times do campeonato a partir dos nojogos
int crialistatimes(time * timescampeonato, jogo * dadosjogos, int numerojogos){
  // Preenche o arranjo timescampeonato com os times
  // Adicione seu código
  int notimes = 0;
  for(int i = 0; i < numerojogos; i++){
    if(encontratime(timescampeonato, dadosjogos[i].local, notimes) == -1){
      strncpy(timescampeonato[notimes].nome, dadosjogos[i].local, 30);
      timescampeonato[notimes].PontosGanhos = 0;
      timescampeonato[notimes].GolsMarcados = 0;
      timescampeonato[notimes].GolsSofridos = 0;
      timescampeonato[notimes].SaldoDeGols = 0;
      timescampeonato[notimes].Vitorias = 0;
      timescampeonato[notimes].Empates = 0;
      timescampeonato[notimes].Derrotas = 0;
      timescampeonato[notimes].GolAverage = 0;
      notimes++;
    }
    if(encontratime(timescampeonato, dadosjogos[i].visitante, notimes) == -1){
      strncpy(timescampeonato[notimes].nome, dadosjogos[i].visitante, 30);
      timescampeonato[notimes].PontosGanhos = 0;
      timescampeonato[notimes].GolsMarcados = 0;
      timescampeonato[notimes].GolsSofridos = 0;
      timescampeonato[notimes].SaldoDeGols = 0;
      timescampeonato[notimes].Vitorias = 0;
      timescampeonato[notimes].Empates = 0;
      timescampeonato[notimes].Derrotas = 0;
      timescampeonato[notimes].GolAverage = 0;
      notimes++;
    }
  }
  return notimes; // retorna o número de times. O zero é só para compilar
}

// Computa dados times
void computadadostimes(time * timescampeonato,int notimes,jogo * dadosjogos,int numerojogos) {
// Preenche os campos dos elementos do arranjo timescampeonato: Vitorias,
// GolsSofridos, GolsMarcados, Golsaverage, SaldoDeGols, PontosGanhos.
// Adicione seu código
  for (int i = 0; i < numerojogos; i++) {
    int time_local = encontratime(timescampeonato, dadosjogos[i].local, notimes);
    int time_visitante = encontratime(timescampeonato, dadosjogos[i].visitante, notimes);

    if (time_local != -1 && time_visitante != -1) {
      timescampeonato[time_local].GolsMarcados += dadosjogos[i].golslocal;
      timescampeonato[time_local].GolsSofridos += dadosjogos[i].golsvisitante;
      
      timescampeonato[time_visitante].GolsMarcados += dadosjogos[i].golsvisitante;
      timescampeonato[time_visitante].GolsSofridos += dadosjogos[i].golslocal;

      if (dadosjogos[i].golslocal > dadosjogos[i].golsvisitante){
          timescampeonato[time_local].Vitorias ++;
          timescampeonato[time_visitante].Derrotas ++;
          timescampeonato[time_local].PontosGanhos += 3;
      }
      
      else if (dadosjogos[i].golslocal == dadosjogos[i].golsvisitante){
        timescampeonato[time_local].Empates ++;
        timescampeonato[time_visitante].Empates ++;
        timescampeonato[time_local].PontosGanhos ++;
        timescampeonato[time_visitante].PontosGanhos ++;
      }
      
      else if (dadosjogos[i].golslocal < dadosjogos[i].golsvisitante){
          timescampeonato[time_local].Derrotas ++;
          timescampeonato[time_visitante].Vitorias ++;
          timescampeonato[time_visitante].PontosGanhos += 3;
      }
    }
	}
  for(int i = 0; i < notimes; i++){
    timescampeonato[i].GolAverage = (float) timescampeonato[i].GolsMarcados / timescampeonato[i].GolsSofridos;
    timescampeonato[i].SaldoDeGols = timescampeonato[i].GolsMarcados - timescampeonato[i].GolsSofridos;
  }
}

// Imprime classificação

void imprimeclassificacao(time * timescampeonato,int notimes){
 // Adicione seu código
 ordenaPontos(timescampeonato, notimes);
 printf("Posicao,Nome,Pontos Ganhos,Vitorias,Empates,Derrotas,Saldo de Gols,Gol Average\n");
 for(int i = 0; i < notimes; i++){
  printf("%d,%s,%d,%d,%d,%d,%d,%.3f\n", i + 1, timescampeonato[i].nome, timescampeonato[i].PontosGanhos,
           timescampeonato[i].Vitorias, timescampeonato[i].Empates, timescampeonato[i].Derrotas, timescampeonato[i].SaldoDeGols,
           timescampeonato[i].GolAverage);
 }
}

// Salva os dados da classificação dos tipos em arquivo no disco
void salvaclassificacao(time * timescampeonato,int notimes, char * arquivo){
  FILE *arq;
  char times[1000];
  arq = fopen(arquivo, "wt");
  if (arq == NULL) {
    printf("Erro ao abrir o arquivo.\n");
  }else{
    for(int i = 0; i < notimes; i++){
      sprintf(times, "%d,%s,%d,%d,%d,%d,%d,%.3f\n", i + 1, timescampeonato[i].nome, timescampeonato[i].PontosGanhos,
           timescampeonato[i].Vitorias, timescampeonato[i].Empates, timescampeonato[i].Derrotas, timescampeonato[i].SaldoDeGols,
           timescampeonato[i].GolAverage);
      fputs(times, arq);
    }
    fclose(arq);
  }
}

int main() {
  time times[NumeroMaxTimes];
  jogo jogos[NumeroMaxJogos];
  int i, nojogos, golslocal = 0, golsvisitante = 0;
  char local[30],visitante[30];

  printf("Entre os jogos no formato \"time local, time visitante, golslocal, golsvisitante\" (gols local negativo encerra a entrada de dados)\n");
  for(i = 0; i < NumeroMaxJogos; ++i) {
    lenometime(local);
    lenometime(visitante);
    scanf("%d,%d",&golslocal,&golsvisitante);
    getchar(); // consome o enter do scanf
    // printf("local %s visitante %s ", local, visitante);
    // printf("golslocal %d, golsvisitante %d\n", golslocal,golsvisitante);
    if (golslocal < 0)
      break; // termina a entrada de dados

    if(strcmp(local,visitante) == 0)
      continue; // possui o mesmo nome time local e visitante

    strncpy(jogos[i].local,local,30);
    strncpy(jogos[i].visitante,visitante,30);

    jogos[i].golslocal = golslocal;
    jogos[i].golsvisitante = golsvisitante;
  }
  nojogos = i;

  int notimes = crialistatimes(times,jogos,nojogos);

  computadadostimes(times,notimes,jogos,nojogos);

  imprimeclassificacao(times,notimes);

  // Opcional
  salvaclassificacao(times,notimes,"campeonatoIP.dat");
}
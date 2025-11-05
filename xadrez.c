#include <stdio.h>

/*
  Desafio – Movimentos com Recursão e Loops

  Regras de impressão:
    - "Cima", "Baixo", "Esquerda", "Direita"
    - Uma linha em branco separa a saída de cada peça.

  Peças:
    - Torre (recursivo): move em linha reta (ex.: para cima)
    - Bispo (recursivo): move em diagonal (up-right) imprimindo a cada casa:
        "Cima" e "Direita"
    - Bispo (loops aninhados): laço externo = vertical; interno = horizontal
    - Rainha (recursivo): demonstra 3 sequências (diag up-right, esquerda, baixo)
    - Cavalo (loops aninhados com break/continue):
        movimento em L: 2 para cima + 1 para direita (por N movimentos)

  Observações:
    - Entradas (passos/condições) são definidas como constantes inteiras.
    - Evitamos recursões muito profundas para não arriscar stack overflow.
*/

/* ===================== Configurações (editáveis) ======================= */
const int TORRE_PASSOS_CIMA     = 4;  // torre: quantas casas "Cima"
const int BISPO_PASSOS_DIAG     = 3;  // bispo (diag up-right): quantas casas
const int RAINHA_DIAG_UPRIGHT   = 2;  // rainha: diagonal up-right
const int RAINHA_HOR_ESQ        = 3;  // rainha: depois, horizontal para a esquerda
const int RAINHA_VER_BAIXO      = 2;  // rainha: depois, vertical para baixo
const int CAVALO_QTD_MOVIMENTOS = 4;  // quantos movimentos em L (2Cima + 1Direita)
/* ====================================================================== */

/* ======================= Impressores utilitários ======================= */
static void imprimeCima(int vezes) {
  for (int i = 0; i < vezes; i++) printf("Cima\n");
}
static void imprimeBaixo(int vezes) {
  for (int i = 0; i < vezes; i++) printf("Baixo\n");
}
static void imprimeEsquerda(int vezes) {
  for (int i = 0; i < vezes; i++) printf("Esquerda\n");
}
static void imprimeDireita(int vezes) {
  for (int i = 0; i < vezes; i++) printf("Direita\n");
}
/* ====================================================================== */

/* =========================== Recursividade ============================= */
/* Torre recursiva: empilha "Cima" N vezes (exemplo). */
void torre_rec_cima(int passos) {
  if (passos <= 0) return;
  printf("Cima\n");
  torre_rec_cima(passos - 1);
}

/* Bispo recursivo: diagonal up-right = (Cima + Direita) por casa */
void bispo_rec_up_right(int passos) {
  if (passos <= 0) return;
  printf("Cima\n");
  printf("Direita\n");
  bispo_rec_up_right(passos - 1);
}

/* Rainha recursiva:
   Demonstra três segmentos:
     1) diagonal up-right (Cima + Direita)
     2) horizontal para a Esquerda
     3) vertical para Baixo
   Cada segmento é implementado recursivamente. */
void rainha_rec_diag_upright(int passos) {
  if (passos <= 0) return;
  printf("Cima\n");
  printf("Direita\n");
  rainha_rec_diag_upright(passos - 1);
}
void rainha_rec_esquerda(int passos) {
  if (passos <= 0) return;
  printf("Esquerda\n");
  rainha_rec_esquerda(passos - 1);
}
void rainha_rec_baixo(int passos) {
  if (passos <= 0) return;
  printf("Baixo\n");
  rainha_rec_baixo(passos - 1);
}
/* ====================================================================== */

/* ==================== Bispo com loops aninhados ======================== */
/*
  Bispo loops:
    - Laço externo = componente vertical (Cima por 'passos')
    - Para cada avanço vertical, faz 1 avanço horizontal à Direita (interno)
  Resultado prático: para cada casa diagonal, imprime "Cima" e "Direita".
*/
void bispo_loops_up_right(int passos) {
  for (int v = 0; v < passos; v++) {   // vertical (externo)
    printf("Cima\n");
    for (int h = 0; h < 1; h++) {      // horizontal (interno)
      printf("Direita\n");
    }
  }
}
/* ====================================================================== */

/* ================= Cavalo com loops aninhados + break/continue ========= */
/*
  Cavalo (para cima e direita em "L"): 2x Cima + 1x Direita, repetido N vezes.
  Requisitos: usar loops aninhados, múltiplas variáveis/condições e break/continue.
*/
void cavalo_loops_L_cima_direita(int movimentos) {
  for (int m = 0; m < movimentos; m++) {
    // primeiro, subir 2 (usando um laço que poderia subir até 3, mas quebra cedo)
    for (int up = 0; up < 3; up++) {
      if (up == 2) { // já subimos 2 casas (up=0 e up=1); quebramos antes de imprimir a terceira
        break;       // demonstra uso de 'break'
      }
      printf("Cima\n");
    }
    // agora, 1 para a direita (usando um laço que roda 2 iterações para demonstrar 'continue')
    for (int r = 0; r < 2; r++) {
      if (r == 1) {
        continue;    // na segunda iteração, "pula" (não imprime); fica só 1 Direita
      }
      printf("Direita\n");
    }
  }
}
/* ====================================================================== */

int main(void) {
  /* TORRE (recursivo) */
  printf("=== Torre (recursivo): %d casas para Cima ===\n", TORRE_PASSOS_CIMA);
  torre_rec_cima(TORRE_PASSOS_CIMA);
  printf("\n");

  /* BISPO (recursivo) */
  printf("=== Bispo (recursivo) – diagonal up-right: %d casas ===\n", BISPO_PASSOS_DIAG);
  bispo_rec_up_right(BISPO_PASSOS_DIAG);
  printf("\n");

  /* BISPO (loops aninhados) */
  printf("=== Bispo (loops aninhados) – externo vertical / interno horizontal: %d casas ===\n", BISPO_PASSOS_DIAG);
  bispo_loops_up_right(BISPO_PASSOS_DIAG);
  printf("\n");

  /* RAINHA (recursivo) */
  printf("=== Rainha (recursivo) ===\n");
  printf("-- Diagonal up-right: %d casas --\n", RAINHA_DIAG_UPRIGHT);
  rainha_rec_diag_upright(RAINHA_DIAG_UPRIGHT);
  printf("-- Esquerda: %d casas --\n", RAINHA_HOR_ESQ);
  rainha_rec_esquerda(RAINHA_HOR_ESQ);
  printf("-- Baixo: %d casas --\n", RAINHA_VER_BAIXO);
  rainha_rec_baixo(RAINHA_VER_BAIXO);
  printf("\n");

  /* CAVALO (loops aninhados com break/continue) */
  printf("=== Cavalo (loops aninhados; 2x Cima + 1x Direita) – %d movimentos ===\n", CAVALO_QTD_MOVIMENTOS);
  cavalo_loops_L_cima_direita(CAVALO_QTD_MOVIMENTOS);
  printf("\n");

  return 0;
}

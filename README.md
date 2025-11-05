## Desafio – Movimentos com Recursividade e Loops (xadrez.c)

- **Torre (recursivo):** N passos para **Cima**.
- **Bispo (recursivo):** diagonal **up-right** (imprime "Cima" e "Direita" por casa).
- **Bispo (loops aninhados):** laço externo vertical e interno horizontal.
- **Rainha (recursivo):** sequência de movimentos (diag up-right, esquerda, baixo).
- **Cavalo (loops):** 2x **Cima** + 1x **Direita** por movimento, com `break/continue`.

### Compilar
```bash
gcc xadrez.c -o xadrez
./xadrez

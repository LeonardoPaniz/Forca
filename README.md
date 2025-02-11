### README - Jogo da Forca

#### 1. Trabalho Prático - Jogo da Forca

---

#### 1.1 Introdução

Este projeto tem como objetivo a criação de um programa em linguagem C que simula o clássico **Jogo da Forca**. No jogo:

- O jogador possui **6 chances** para adivinhar as letras de uma palavra.
- A palavra é sorteada de um conjunto de **10 palavras distintas**, cada uma com no mínimo **5 letras**.
- Todas as palavras estão armazenadas em um arquivo **binário**.

**Dinâmica do Jogo:**
1. A palavra sorteada aparece inicialmente como traços (`_`) correspondentes às suas letras.
2. O jogador tenta adivinhar uma letra:
   - Se a letra estiver na palavra, todas as suas ocorrências são reveladas, e o jogador ganha pontos.
   - Se a letra não estiver na palavra, o jogador perde uma chance e pontos.
3. Letras já utilizadas são exibidas na tela.
4. O jogo termina quando:
   - O jogador acerta todas as letras da palavra.
   - O jogador perde todas as chances.
5. Ao final, o programa exibe a **pontuação do jogador** e apresenta um menu com as opções:
   - **Novo Jogo**: inicia uma nova partida.
   - **Menu Inicial**: retorna ao menu principal.
   - **Sair**: encerra o programa.

---

#### 1.2 Requisitos do Programa

- Seguir as regras descritas acima.
- Apresentar um **menu inicial** com as opções:
  1. **Novo Jogo**: inicia um novo jogo, desde que haja pelo menos 10 palavras no arquivo.
  2. **Cadastrar Palavra**: permite cadastrar uma nova palavra (mínimo de 5 letras), garantindo que não seja duplicada.
  3. **Atualizar Palavra**: possibilita atualizar uma palavra existente no arquivo.
  4. **Apagar Palavra**: remove uma palavra do arquivo.
  5. **Mostrar Palavras**: exibe todas as palavras salvas no arquivo.
  6. **Sair**: encerra o programa.

---

#### 1.3 Desenvolvimento do Programa

O programa será desenvolvido utilizando os seguintes conceitos de programação em C:

- **Funções**
- **Ponteiros**
- **Alocação de Memória**
- **Recursão**
- **Registros (structs)**
- **Manipulação de Arquivos Binários**

**Parceria:** O projeto deve ser desenvolvido em **duplas**.

---

#### 1.4 Entrega

- O código deve ser **organizado e comentado**, com explicações claras sobre cada parte do programa.
- A entrega será feita na data e horário estabelecidos pelo professor.

---

#### 1.5 Apresentação e Avaliação

A apresentação será realizada conforme cronograma definido pelo professor. Todos os integrantes serão arguidos sobre o desenvolvimento do programa. 

**Critérios de Avaliação:**
- **Programa (6,0 pontos)**: Funcionalidade, organização e clareza do código.
- **Apresentação (4,0 pontos)**: Clareza na explicação e domínio do projeto.

---

#### 1.6 Considerações Finais

Este trabalho tem como objetivo:

- Desenvolver habilidades de programação em C.
- Promover o aprendizado de lógica de programação e conceitos de manipulação e armazenamento de dados.

**Dúvidas:** Para quaisquer dificuldades, entre em contato com o professor responsável para orientações.

---

**Status do Projeto:** Concluido 
**Autores:** [Leonardo Paniz Aguiar](https://github.com/LeonardoPaniz), Vitoria saibt 
**Licença:** MIT
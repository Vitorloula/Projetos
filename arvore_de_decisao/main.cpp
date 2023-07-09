#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#include "arvore_binaria.h"

using namespace std;

vector<string> doencas, perguntas;
unordered_map<string, unordered_set<int>> codigo_doencas;

int Num_doencas, Num_perguntas;

Arvore_binaria<int> *doencas_Tree = new Arvore_binaria<int>(1);

// obter os dados do arquivo de entrada
void getArquivo_entrada() {
  ifstream arquivo("teste.txt");

  if (arquivo.is_open()) {
    string linha;
    getline(arquivo, linha);

    // número de doenças e perguntas do arquivo
    Num_doencas = stoi(linha.substr(0, linha.find(" ")));
    Num_perguntas = stoi(linha.substr(linha.find(" ") + 1, linha.size()));

    int qt_doencas = 0, qt_perguntas = 0;

    if (arquivo.is_open()) {
      while (getline(arquivo, linha)) {
        if (qt_doencas < Num_doencas) {
          // lista de doenças
          doencas.push_back(linha);
          ++qt_doencas;
        } else if (qt_perguntas < Num_perguntas) {
          // lista de perguntas
          perguntas.push_back(linha);
          ++qt_perguntas;
        } else {
          int firstTab = linha.find(9);
          int Chave_doenca = stoi(linha.substr(0, firstTab));

          string code = linha.substr(firstTab + 1, linha.size());
          string::iterator end_pos = remove(code.begin(), code.end(), 9);
          code.erase(end_pos, code.end());

          codigo_doencas[code].insert(Chave_doenca);
        }
      }

      arquivo.close();
    } else {
      cout << "Não foi possível abrir o arquivo informado!" << "\n";
    }
  }
}
// árvore de doenças
void arvore_de_Doencas() {
  No<int> *raiz = new No<int>(1, nullptr, nullptr);

  No<int> *left = nullptr;
  No<int> *right = nullptr;

  queue<No<int> *> nos;

  nos.push(raiz);

  while (!nos.empty()) {
    No<int> *current = nos.front();
    nos.pop();

    if (current->getValor() == Num_perguntas)
      continue;

    left = new No<int>(current->getValor() + 1, nullptr, nullptr);
    right = new No<int>(current->getValor() + 1, nullptr, nullptr);

    current->setLeft(left);
    current->setRight(right);

    nos.push(left);
    nos.push(right);
  }

  doencas_Tree->setRaiz(raiz);
}
// (S ou N)
char doPerguntas(No<int> *root) {
  cout << "Pergunta: " << perguntas[root->getValor() - 1] << " (S/N)" << "\n";

  char answer;
  cin >> answer;

  if (toupper(answer) == 'S') {
    return '1';
  } else {
    return '0';
  }
}
// pesquisar a doença com base nas respostas
void pesquisar_Doencas(No<int> *raiz, string sqr) {
  if (raiz->getEsquerda() == nullptr && raiz->getDireita() == nullptr) {
    if (doPerguntas(raiz) == '1') {
      sqr[raiz->getValor() - 1] = '1';
      raiz = raiz->getEsquerda();
    } else {
      sqr[raiz->getValor() - 1] = '0';
      raiz = raiz->getDireita();
    }

    unordered_set<int> chaves_Doencas = codigo_doencas[sqr];

    if (chaves_Doencas.size()) {
      for (int i : chaves_Doencas) {
        cout << "Doença: " << doencas[i - 1] << "\n";
      }

      return;
    }

    cout << "Doença não identificada!" << "\n";

    return;
  }
  if (doPerguntas(raiz) == '1') {
    sqr[raiz->getValor() - 1] = '1';
    raiz = raiz->getEsquerda();
  } else {
    sqr[raiz->getValor() - 1] = '0';
    raiz = raiz->getDireita();
  }

  return pesquisar_Doencas(raiz, sqr);
}

int main() {
  getArquivo_entrada();
  arvore_de_Doencas();

  bool continuar = true;

  while (continuar) {
    cout << "Pesquisar doenças?" << "\n";
    cout << "Digite 0 para continuar ou 1 para sair: ";

    char aux;
    cin >> aux;

    switch (aux) {
    case '0': {
      string ans = "";

      for (int i = 0; i < Num_perguntas; i++)
        ans += "0";

      // pesquisar a doença com base nas respostas
      pesquisar_Doencas(doencas_Tree->getRaiz(), ans);
      break;
    }
    case '1':
      continuar = false;
      break;
    default:
      cout << "Opção inválida. Por favor, tente novamente." << "\n";
      break;
    }
  }

  return 0;
}
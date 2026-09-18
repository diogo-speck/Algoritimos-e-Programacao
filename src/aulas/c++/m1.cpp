#include <iostream>
#include <string>

using namespace std;

struct Encomenda {
    int codigo = -1; // precisa ser unicos
    string destinatario;
    double peso;
    double valorFrete;
    bool entregue = false;
};

void cadastrarEncomenda(Encomenda (&encomendas)[10]); // done
void exibirEncomenda(const Encomenda (&encomendas)[10], int codigo); // done
void exibirEncomendas(const Encomenda (&encomendas)[10]); // done
int buscarEncomenda(const Encomenda (&encomendas)[10]); // done
void registrarEntrega(Encomenda (&encomendas)[10], int codigo); // done
void exibirPendentes(const Encomenda (&encomendas)[10]); // done
double calcularTotalFretes(const Encomenda (&encomendas)[10]); // done
int contarEntregues(const Encomenda (&encomendas)[10]); // done

template <typename T>
bool intervalo(T valor1, T valor2, T valor);


int main()
{
    Encomenda encomendas[10];
    int escolha;
    int codigo;



    while (escolha!=0){
        cout << "1 - Cadastrar encomenda" << endl
        << "2 - Exibir encomendas" << endl
        << "3 - Buscar encomenda por código" << endl
        << "4 - Registrar entrega" << endl
        << "5 - Exibir encomendas pendentes" << endl
        << "6 - Calcular total arrecadado com fretes" << endl
        << "7 - Contar encomendas entregues" << endl
        << "0 - Sair" << endl
        << "Escolha: ";
        cin >> escolha;

        switch (escolha){
            case 1:
                cadastrarEncomenda(encomendas);
                break;
            case 2:
                exibirEncomendas(encomendas);
                break;
            case 3:
                codigo = buscarEncomenda(encomendas);
                if (codigo != -1) {
                    exibirEncomenda(encomendas, codigo);
                }
                break;
            case 4:
                codigo = buscarEncomenda(encomendas);
                if (codigo != -1) {
                    registrarEntrega(encomendas, codigo);
                }
                break;
            case 5:
                cout << "Falta entregar: " << endl;
                exibirPendentes(encomendas);
                break;
            case 6:
                cout << "Total arrecadado dos fretes: " << calcularTotalFretes(encomendas) << endl;
                break;
            case 7:
                cout << "Total de encomendas entregues: " << contarEntregues(encomendas) << endl;
                break;
            case 0:
                cout << "Tchau.... :(" << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    }

    return 0;
}

void cadastrarEncomenda(Encomenda (&encomendas)[10]) {
    int codigo = -1;
    string destinatario;
    double peso;
    double valorFrete;
    bool duplicado = true;
    bool grande = true;
    cout << "Digite o código:  " << endl;
    while (duplicado) {
        cin >> codigo;
        for (int i = 0; i < 10; i++) {
            if (encomendas[i].codigo == codigo || !intervalo(0, 9999, codigo)) {
                cout << "Código já existe, ou é muito grande!" << endl;
                duplicado = true;
                break;
            } else if (encomendas[i].codigo != codigo && intervalo(0, 9999, codigo)) {
                duplicado = false;
            }
        }
    }
    cout << "Destinatario:  " << endl;
    cin >> destinatario;
    cout << "Peso:  " << endl;
    cin >> peso;
    cout << "Valor do Frete:  " << endl;
    while (grande) {
        cin >> valorFrete;
        for (int i = 0; i < 10; i++) {
            if (!intervalo(0.0, 999.9, valorFrete)) {
                cout << "Valor precisa ser entre 0 e 999." << endl;
                grande = true;
                break;
            } else if (intervalo(0.0, 999.9, valorFrete)) {
                grande = false;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        if (encomendas[i].codigo == -1) {
            encomendas[i].codigo = codigo;
            encomendas[i].destinatario = destinatario;
            encomendas[i].peso = peso;
            encomendas[i].valorFrete = valorFrete;
            encomendas[i].entregue = false;
            cout << "Encomenda cadastrada com sucesso!" << endl;
            break;
        } else if (i == 9) {
            cout << "Não tem posições livres!" << endl;
        }
    }

}

void exibirEncomenda(const Encomenda (&encomendas)[10], int codigo) {
    for (int i = 0; i < 10; i++) {
        if (encomendas[i].codigo == codigo) {
                cout << encomendas[i].codigo << endl;
                cout << encomendas[i].destinatario << endl;
                cout << encomendas[i].peso << endl;
                cout << encomendas[i].valorFrete << endl;
        }
    }
}

void exibirEncomendas(const Encomenda (&encomendas)[10]) {
    for (int i = 0; i < 10; i++) {
        if (encomendas[i].codigo != -1) {
                cout << encomendas[i].codigo << endl;
                cout << encomendas[i].destinatario << endl;
                cout << encomendas[i].peso << endl;
                cout << encomendas[i].valorFrete << endl;
                if (encomendas[i].entregue){
                    cout << "Já foi entregue" << endl;
                }else{
                    cout << "Não foi entregue" << endl;
                }
        }
    }

}

int buscarEncomenda(const Encomenda (&encomendas)[10]){
    int codigo = 0;
    cout << "Código:  " << endl;
    while (true) {
        cin >> codigo;
        for (int i = 0; i < 10; i++) {
            if (encomendas[i].codigo == codigo && codigo != -1) {
                cout << "Código encontrado." << endl;
                return codigo;
            }
        }
        cout << "Codigo não encontrado, digite outro." << endl;
        return -1;
    }
}


void registrarEntrega(Encomenda (&encomendas)[10], int codigo){
    for (int i = 0; i < 10; i++) {
        if (encomendas[i].codigo == codigo && encomendas[i].entregue == false) {
            encomendas[i].entregue = true;
            cout << "Encomenda entregue." << endl;
            break;
        }else if(i==9){
            cout << "A encomenda já foi entregue ou se perdeu no caminho :<." << endl;
        }
    }
}

void exibirPendentes(const Encomenda (&encomendas)[10]) {
    for (int i = 0; i < 10; i++) {
        if (!encomendas[i].entregue && encomendas[i].codigo != -1) {
                cout << encomendas[i].codigo << endl;
                cout << encomendas[i].destinatario << endl;
                cout << encomendas[i].peso << endl;
                cout << encomendas[i].valorFrete << endl;
                cout << "Não foi entregue !!!! Ainda.." << endl;
        }
    }
}

double calcularTotalFretes(const Encomenda (&encomendas)[10]) {
    double total = 0;
    for (int i = 0; i < 10; i++) {
        if (encomendas[i].entregue && encomendas[i].codigo != -1)
            total += encomendas[i].valorFrete;
    }

    return total;
}

int contarEntregues(const Encomenda (&encomendas)[10]) {
    int total = 0;
    for (int i = 0; i < 10; i++) {
        if (encomendas[i].entregue && encomendas[i].codigo != -1)
            total += 1;
    }

    return total;
}

template <typename T>
bool intervalo(T valor1, T valor2, T valor){
    if(valor1<=valor&&valor<=valor2){
        return true;
    }else{
        return false;
    }
}
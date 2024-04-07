#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

int main() {
    // Cria um socket do servidor
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == -1) { //verifica se tem erro
        cerr << "Erro ao criar o socket do servidor." << endl;
        return 1;
    }

    // Configura o endereço do servidor
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080); // Porta 
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Liga o socket ao endereço
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        cerr << "Erro ao vincular o socket a um endereço." << endl;
        close(serverSocket);
        return 1;
    }

    // Aguarda por conexões do cliente
    if (listen(serverSocket, 5) == -1) {
        cerr << "Erro ao aguardar por conexões." << endl;
        close(serverSocket);
        return 1;
    }

    cout << "Servidor aguardando conexões na porta 8080..." << endl;

    while (true) {
        // Aceita uma conexão de cliente
        int clientSocket = accept(serverSocket, nullptr, nullptr);

        if (clientSocket == -1) {
            cerr << "Erro ao aceitar a conexão do cliente." << endl;
            close(serverSocket);
            return 1;
        }

        cout << "Cliente conectado." << endl;

        // Recebe os dados cliente
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);

        if (bytesRead == -1) {
            cerr << "Erro ao receber dados do cliente." << endl;
            close(clientSocket);
            close(serverSocket);
            return 1;
        }

        // Processa os dados (cálculo de IMC) com os dados recebidos
        double peso, altura;
        sscanf(buffer, "%lf %lf", &peso, &altura);
        double imc = peso / (altura * altura);

        // Envia a resposta ao cliente,depois de ter um resultado
        string resposta = "Seu IMC é: " + to_string(imc);
        send(clientSocket, resposta.c_str(), resposta.length(), 0);

        // Fecha o socket do cliente
        close(clientSocket);

        cout << "Cliente desconectado." << endl;
    }

    // !!!!Fecha o socket do servidor !!!!!!
    close(serverSocket);

    return 0;
}

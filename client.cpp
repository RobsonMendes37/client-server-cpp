#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

int main() {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocket == -1) {
        cerr << "Erro ao criar o socket do cliente." << endl;
        return 1;
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        cerr << "Erro ao se conectar ao servidor." << endl;
        close(clientSocket);
        return 1;
    }

    double peso, altura, cintura;
    cout << "Digite seu peso (em kg): ";
    cin >> peso;
    cout << "Digite sua altura (em centimetros): ";
    cin >> altura;
    cout << "Digite sua circunferência da cintura (em centimetros): ";
    cin >> cintura;

    string dados = to_string(peso) + " " + to_string(altura/100) + " " + to_string(cintura/100);
    send(clientSocket, dados.c_str(), dados.length(), 0);

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);

    if (bytesRead == -1) {
        cerr << "Erro ao receber resposta do servidor." << endl;
        close(clientSocket);
        return 1;
    }

    cout << "Resposta do servidor:\n" << buffer << endl;

    close(clientSocket);

    return 0;
}

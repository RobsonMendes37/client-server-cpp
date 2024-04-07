# Aplicação de Troca de Informações Cliente-Servidor em C++

Este projeto consiste em uma aplicação simples de troca de informações cliente-servidor em C++, utilizando sockets TCP/IP. O principal objetivo é demonstrar como criar uma comunicação básica entre um cliente e um servidor, onde o cliente envia dados para o servidor, que os processa e envia uma resposta de volta ao cliente.

## Aprendizado Demonstrado

Este projeto demonstra os seguintes conceitos e técnicas em C++:

- Utilização de sockets para comunicação em rede.
- Implementação de um servidor que aguarda por conexões de clientes.
- Implementação de um cliente que se conecta a um servidor.
- Troca de dados entre cliente e servidor utilizando sockets.
- Manipulação básica de strings e conversão de tipos de dados.

## Funcionamento

1. **Compilação e Execução:**

   Para compilar os arquivos `server.cpp` e `client.cpp`, utilize um compilador C++ compatível com C++11. Por exemplo:

   ```
   g++ -o server server.cpp
   g++ -o client client.cpp
   ```

   Em seguida, execute o servidor e o cliente em terminais separados:

   ```
   ./server
   ```

   ```
   ./client
   ```

2. **Interação Cliente-Servidor:**

   - O cliente solicitará ao usuário que insira informações, como peso, altura, etc.
   - Esses dados são enviados ao servidor.
   - O servidor recebe os dados, realiza algum processamento (como cálculo de índices de saúde, por exemplo) e envia uma resposta de volta ao cliente.
   - O cliente exibe a resposta recebida do servidor.

## Contribuição

Contribuições são bem-vindas! Se você tiver ideias para melhorar este projeto, sinta-se à vontade para abrir uma issue ou enviar um pull request.

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).


#include "common.h"
void HandleClient(int client_fd){
    char buffer[BUFSIZE];
    while (true)
    {
        int  bytes_read=recv(client_fd,buffer,BUFSIZE,0);
        if(bytes_read<=0){
            perror("recv error");
            close(client_fd);
            return;
        }
        std::cout<<"Client:"<<buffer<<std::endl;
        send(client_fd,buffer,bytes_read,0);
    }
    
}

int main()
{
    int server_fd, client_fd;
    if ((server_fd =socket(AF_INET, SOCK_STREAM, 0) )< 0)
    {
        perror("socket error");
        return -1;
    }
    int opt = 1;

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        perror("setsockopt error");
        return -1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind error");
        close(server_fd);
        return -1;
    }
    if (listen(server_fd, 5) < 0)
    {
        perror("listen error");
        close(server_fd);
        return -1;
    }
    std::cout << "server is running,listening on port" << PORT<<std::endl;
    std::vector<std::thread> clients;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len=sizeof(client_addr);
    while(true){
        client_fd=accept(server_fd,(struct sockaddr *)&client_addr, &client_addr_len);
        if(client_fd<0){
            perror("accept error");
            continue;
        }
        std::cout<<"client connected"<<std::endl;
        clients.emplace_back(HandleClient,client_fd);
    }

    for(auto &t:clients){
        if(t.joinable()){
            t.join();
        }
    }
    close(server_fd);
    return 0;
}

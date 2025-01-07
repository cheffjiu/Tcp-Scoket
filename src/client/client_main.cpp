#include"common.h"
int main(){
    int client_fd;
    client_fd=socket(AF_INET,SOCK_STREAM,0);
    if(client_fd<0){
        perror("socket error");
        close(client_fd);
        return -1;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(PORT);
    
    if(inet_pton(AF_INET,SERVER_IP,&server_addr.sin_addr)!=1){
        perror("inet_pton error");
        return -1;
    }
    if(connect(client_fd,(const struct sockaddr*)&server_addr,sizeof(server_addr))<0){
        perror("connect error");
        close(client_fd);
        return -1;
    }
    std::cout<<"connect  server success"<<std::endl;
     char buffer[BUFSIZE]={0};
     while (true)
     {
        std::cout<<"please input your message:";
        std::cin.getline(buffer,BUFSIZE);
        send(client_fd,buffer,strlen(buffer),0);

        memset(buffer,0,BUFSIZE);
        int receive_len=recv(client_fd,buffer,BUFSIZE,0);
        if(receive_len<0){
            perror("recv error");
            return -1;
        }
        std::cout<<"server say:"<<buffer<<std::endl;
     }
     close(client_fd);
     
    return 0;
}
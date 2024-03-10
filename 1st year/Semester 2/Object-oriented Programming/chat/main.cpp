//#include "chat.h"
#include <QtWidgets/QApplication>
#include "chat_session.h"
#include "chat_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ChatSession chatSession; 

    User user1("User1", "u1");
    ChatWindow* chatWindow1 = new ChatWindow(user1, chatSession);
    chatWindow1->show();

    User user2("User2", "u2");
    ChatWindow* chatWindow2 = new ChatWindow(user2, chatSession); 
    chatWindow2->show();

    User user3("User3", "u3");
    ChatWindow* chatWindow3 = new ChatWindow(user3, chatSession);
    chatWindow3->show();


    return a.exec();
}

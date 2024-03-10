#pragma once

#include <QWidget>
#include "observer.h"
#include "user.h"
#include "chat_session.h"
#include "qlistwidget.h"
#include "qlineedit.h"
#include "qpushbutton.h"
#include "qboxlayout.h"

class ChatWindow : public Observer, public QWidget
{
private:
	QListWidget* messagesList = new QListWidget{};
	QLineEdit* messageInput = new QLineEdit{};
	QPushButton* sendButton = new QPushButton{ "Send" };

public:
	User& user;
	ChatSession& chatSession;

	ChatWindow(User& user, ChatSession& chatSession) : user(user), chatSession(chatSession)
	{
		this->init();
		this->connectSignals(); 
		chatSession.addObserver(this); 
	}
	~ChatWindow()
	{
		chatSession.deleteObserver(this);
	}

	void update() override 
	{
		messagesList->clear();
		for (auto message : chatSession.getMessages())
		{
			messagesList->addItem(QString::fromStdString(message.second.getName() + ": " + message.first.getMessage()));
		}
	}
	void sendMessage()
	{
		chatSession.addMessage(Message{ messageInput->text().toStdString() }, user); 
		messageInput->clear(); 
	}

	void init()
	{
		QVBoxLayout* main = new QVBoxLayout{};
		setLayout(main);
		
		main->addWidget(messagesList);

		QHBoxLayout* inputLayout = new QHBoxLayout{};
		inputLayout->addWidget(messageInput);
		inputLayout->addWidget(sendButton);
		main->addLayout(inputLayout);
	}

	void connectSignals()
	{
		QObject::connect(sendButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
	}

};
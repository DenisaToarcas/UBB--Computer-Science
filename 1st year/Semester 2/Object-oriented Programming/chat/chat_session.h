#pragma once

#include <string>
#include <vector>
#include "message.h"
#include "user.h"
#include "subject.h" 

typedef std::pair<Message, User> userMessage;

class ChatSession : public Subject
{
private:
	std::vector<userMessage> messages; 

public:
	ChatSession() {};
	~ChatSession() {};
	void addMessage(Message message, User user)
	{
		messages.push_back(std::make_pair(message, user));
		this->notify();
	}
	std::vector<userMessage> getMessages()
	{
		return messages;
	}
};
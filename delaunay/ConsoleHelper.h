#pragma once
#include "IMessage.h"
class ConsoleHelper : public IMessage
{

public:
	ConsoleHelper(){

	}
	virtual bool Greeting() const override;
	virtual bool sendMsg(std::string) const override;
	virtual std::string getMsg() const override;
	virtual bool Parting() const override;
};


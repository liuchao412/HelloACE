#ifdef _DEBUG
#pragma comment(lib,"ACED.lib")
#else
#pragma comment(lib,"ACE.lib")
#endif

#include <ace/OS_main.h>
#include <ace/ACE.h>
#include <ace/Log_Msg.h>
#include <ace/SOCK_Connector.h>

int main(int argc, char *argv[])
{
	ACE_INET_Addr addr(1500, "127.0.0.1"); //remote address
	ACE_SOCK_Connector con; // connector for socket client
	ACE_SOCK_Stream stream; // stream is for socket read/write

	if (con.connect(stream, addr) == -1) //connect to remote address
	{
		ACE_DEBUG((LM_DEBUG,
			ACE_TEXT("(%P|%t) %p\n"),
			ACE_TEXT("connection failed")));
		return 1;
	}

	const char msg[] = "Hello,ACE!";

	stream.send_n(msg, sizeof(msg)); // send_n function send exactly n bytes

	char buffer[1024] = { 0 };

	if (stream.recv(buffer, sizeof(buffer) - 1) == -1) // just call socket recv
	{
		ACE_DEBUG((LM_DEBUG,
			ACE_TEXT("(%P|%t) %p\n"),
			ACE_TEXT("recv failed")));
		return 1;
	}
	ACE_DEBUG((LM_DEBUG,
		ACE_TEXT("(%P|%t) recv:%s\n"),
		buffer));

	if (stream.close() == -1) //close the connection
	{
		ACE_ERROR((LM_ERROR,
			ACE_TEXT("(%P|%t) %p\n"),
			ACE_TEXT("close")));
		return 1;
	}

	return 0;
}

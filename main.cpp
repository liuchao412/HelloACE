#include <ace/OS_main.h>
#include <ace/ACE.h>
#include <ace/Log_Msg.h>

int main(int argc, char *argv[])
{
	const char msg[] = "Hello,ACE!";

	ACE_DEBUG((LM_DEBUG,ACE_TEXT("(%P|%t) msg:%s\n"),msg));
	ACE_DEBUG((LM_DEBUG,("Hello World\n")));
	return 0;
}

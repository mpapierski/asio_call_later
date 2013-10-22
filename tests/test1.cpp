#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "call_later.hpp"

int
main()
{
	boost::asio::io_service svc;
	call_later(svc, 1000, boost::bind(&boost::asio::io_service::stop, &svc));
	svc.run();
}
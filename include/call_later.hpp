#if !defined(BOOST_ASIO_CALL_LATER_HPP_)
#define BOOST_ASIO_CALL_LATER_HPP_

#include <boost/asio.hpp>

/**
 * Call later specified function after `msec" milliseconds.
 * @param io_service Service to work on.
 * @param msec Milliseconds
 * @param callback Function to call. This function should not
 * contain any arguments.
 */
template <typename Callback>
void call_later(boost::asio::io_service & io_service, unsigned int msec, Callback callback)
{
	boost::shared_ptr<boost::asio::deadline_timer> dt(new boost::asio::deadline_timer(io_service));
	dt->expires_from_now(boost::posix_time::millisec(msec));
	// This will hopefully extend life of a deadline_timer.
	dt->async_wait(boost::bind(callback, dt));
}

#endif /* BOOST_ASIO_HPP_CALL_LATER_HPP_ */
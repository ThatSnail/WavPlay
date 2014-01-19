#ifndef SERIALHANDLER_UNIX_H
#define SERIALHANDLER_UNIX_H

#include "boost/asio.hpp"

class SerialHandler
{
public:
	SerialHandler(std::string port, unsigned int baudRate) : io(), serial(io, port)
	{
		serial.set_option(boost::asio::serial_port_base::baud_rate(baudRate));
	}

	void writeSerial(unsigned char* data, size_t count) {
		boost::asio::write(serial, boost::asio::buffer(data, count));
	}

private:
	boost::asio::io_service io;
	boost::asio::serial_port serial;
};

#endif
